//
// Created by Arthur Burke on 2020-01-15.
//

#ifndef SIMPLE_EVENT_HPP
#define SIMPLE_EVENT_HPP

#include <Simple/SimpleCore.h>

namespace Simple {

    // Events in Simple are non-blocking (if possible). They are dispatched from multiple sources and read from a single
    // source by an MWSR queue using a fixed size buffer.

    enum class EventType {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved, // Window events
        AppTick,
        AppUpdate,
        AppRender, // App events
        KeyPressed,
        KeyRelease, // Keyboard events
        MouseButtonPressed,
        MouseButtonRelease,
        MouseMoved,
        MouseScrolled // Mouse events
    };

    enum EventCategory {
        None = 0,
        CategoryApplication = BIT(0),
        CategoryInput = BIT(1),
        CategoryKeyboard = BIT(2),
        CategoryMouse = BIT(3),
        CategoryMouseButton = BIT(4)
    };

#define EVENT_CLASS_TYPE(type) static EventType get_static_type() { return EventType::##type; }\
                               virtual EventType get_event_type() const override { return get_static_type(); }\
                               virtual const char* get_name() const override { return #type; }
#define EVENT_CLASS_CATEGORY(category) virtual int get_category_flags() const override { return category; }

    class Event {
        friend class EventDispatcher;

    public:
        virtual EventType get_event_type() const = 0;

        virtual const char *get_name() const = 0;

        virtual int get_category_flags
        const = 0;

        virtual std::string to_string() const { return get_name(); }

        inline bool in_category(EventCategory category) {
            return get_category_flags() & category;
        }

    protected:
        bool handled = false;
    };

    class EventDispatcher {
        template<typename T>
        using Fn = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& event) : event(event) { }

        template<typename T>
        bool dispatch(Fn<T> callback) {

        }
    };
}

#endif //SIMPLE_EVENT_HPP
