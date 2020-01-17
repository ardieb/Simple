//
// Created by Arthur Burke on 2020-01-15.
//

#ifndef SIMPLE_EVENT_HPP
#define SIMPLE_EVENT_HPP

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
        KeyRelease,
        KeyTyped, // Keyboard events
        MouseButtonPressed,
        MouseButtonRelease,
        MouseMoved,
        MouseScrolled // Mouse events
    };

    enum EventCategory {
        None = 0,
        CategoryApplication   = BIT(0),
        CategoryInput         = BIT(1),
        CategoryKeyboard      = BIT(2),
        CategoryMouse         = BIT(3),
        CategoryMouseButton   = BIT(4)
    };

    enum class Severity { // Used in the DropPolicy for the messaging queue
        None = 0,
        LOW,
        MEDIUM,
        HIGH,
        CRITICAL,
    };

    #define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::type; }\
                               virtual EventType getEventType() const override { return getStaticType(); }\
                               virtual const char* getName() const override { return #type; }
    #define EVENT_CLASS_CATEGORY(category) virtual unsigned int getCategoryFlags() const override { return category; }

    // Events must be move constructable
    class Event {
        friend class EventDispatcher;
    public:
        [[nodiscard]] virtual EventType getEventType() const = 0;

        [[nodiscard]] virtual const char* getName() const = 0;

        [[nodiscard]] virtual unsigned int getCategoryFlags() const = 0;

        virtual std::string toString() const {
            return getName();
        }

        inline bool inCategory(EventCategory category) {
            return getCategoryFlags() & category;
        }
    protected:
        bool wasHandled = false;
    };
}

#endif //SIMPLE_EVENT_HPP
