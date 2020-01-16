//
// Created by Arthur Burke on 2020-01-15.
//

#ifndef SIMPLE_MWSRFIXEDSIZEQUEUE_H
#define SIMPLE_MWSRFIXEDSIZEQUEUE_H

template <typename FixedSizeCollection, typename DropPolicy>
//    DropPolicy should have function
//    pushAndDropOne(T&& t, FixedSizeCollection& coll)
//    it MAY either to skip t,
//    OR to drop something from coll, while pushing t
class MWSRFixedSizeQueueWithDropPolicy {
private:
    DropPolicy drop;
    std::mutex mx;
    std::condition_variable waitrd;
    FixedSizeCollection coll;
    bool killflag = false;
    //stats:
    int ndrops = 0;
    std::size_t hwmsize = 0;//high watermark on queue size
public:
    using T = typename FixedSizeCollection::ValueType;

    explicit MWSRFixedSizeQueueWithDropPolicy(const DropPolicy& drop_) : drop(drop_) { }

    void pushBack(T&& item) {
        //if the queue is full, calls drop.pushAndDropOne()
        {//creating a scope for lock
            std::unique_lock<std::mutex> lock(mx);

            if (coll.isFull()) {
                ++ndrops;
                drop.pushAndDropOne(item, coll);
                return;
            }

            assert(!coll.isFull());
            coll.pushBack(std::move(item));
            std::size_t sz = coll.size();
            hwmsize = max(hwmsize,sz);
        }//unlocking mx

        waitrd.notify_one();
    }

    std::pair<bool,T> pop() {
        std::unique_lock<std::mutex> lock(mx);
        while(coll.size() == 0 && !killflag) {
            waitrd.wait(lock);
        }

        if (killflag) {
            return std::pair<bool, T>(false, T());
        }
        assert(coll.size() > 0);
        T ret = std::move(coll.front());
        coll.pop();
        lock.unlock();
        return std::make_pair(true, std::move(ret));
    }

    void kill() {
        {//creating scope for lock
            std::unique_lock<std::mutex> lock(mx);
            killflag = true;
        }//unlocking mx
        waitrd.notify_all();
    }
};

#endif //SIMPLE_MWSRFIXEDSIZEQUEUE_H
