//
// Created by Arthur Burke on 2020-01-15.
//

#ifndef SIMPLE_CIRCULARBUFFER_H
#define SIMPLE_CIRCULARBUFFER_H

#include <Simple/SimpleCore.h>

template<class T, std::size_t maxsz_bits>
class CircularBuffer {
    static constexpr std::size_t bufsz = 1 << maxsz_bits;
    static constexpr std::size_t maxsz = bufsz - 1;
    //-1 to make sure that head==tail always means ‘empty’
    static constexpr std::size_t mask = maxsz;
    std::size_t head = 0;
    std::size_t tail = 0;
    alignas(T) uint8_t buffer[bufsz*sizeof(T)];
    //Having buffer as T[bufsz] is possible 
    //  IF we'll replace placement move constructors with move assignments
    //  AND drop explicit destructor calls
    //However, it will require T to have a default constructor,
    //  so at the moment I prefer to deal with pure buffers
    //  and to have the only requirement that T is move-constructible

public:
    std::size_t size() {
        return (head – tail + (((std::size_t)(head>=tail)-(std::size_t)1) & bufsz));
        //trickery to avoid pipeline stalls via arithmetic
        //supposedly equivalent to:
        //if(head >= tail)
        //  return head – tail;
        //else
        //  return head + bufsz - tail;
    }

    void push_back(T&& t) {
        assert(size() < maxsz);
        new(tbuffer(head)) T(std::move(t));
        head = ( head + 1 ) & mask;
    }

    T pop_front() {
        assert(size() > 0);
        T* ttail = tbuffer(tail);
        T ret = std::move(*ttail);
        ttail->~T();
        tail = ( tail + 1 ) & mask;
        return ret;
    }

private:
    T* tbuffer(std::size_t idx) {
        return reinterpret_cast<T*>(buffer + (idx*sizeof(T)));
    }
};

#endif //SIMPLE_CIRCULARBUFFER_H
