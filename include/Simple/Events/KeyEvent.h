//
// Created by Arthur Burke on 2020-01-17.
//

#ifndef SIMPLE_KEYEVENT_H
#define SIMPLE_KEYEVENT_H

#include <Simple/Core/Input.h>
#include <Simple/Events/Event.h>

namespace Simple {
    class KeyEvent : public Event {
    public:
        inline KeyCode getKeyCode() { return keyCode; }
        EVENT_CLASS_CATEGORY(CategoryKeyboard | CategoryInput);
    protected:
        KeyEvent(KeyCode keyCode)
            : keyCode(keyCode) { }

        KeyEvent(KeyEvent&& event) noexcept {
            keyCode = event.keyCode;
        }

        KeyCode keyCode;
    };
    class KeyPressedEvent : public KeyEvent {
    private:
        unsigned int repeatCount;
    public:
        KeyPressedEvent(KeyCode keyCode, unsigned int repeatCount)
            : KeyEvent(keyCode), repeatCount(repeatCount) { }

        KeyPressedEvent(KeyPressedEvent&& event) noexcept
            : KeyEvent(reinterpret_cast<KeyEvent&&>(event)) {
            repeatCount = event.repeatCount;
        }

        inline unsigned int getRepeatCount() { return repeatCount; }

        [[nodiscard]] std::string toString() const override {
            std::stringstream builder;
            builder << "KeyPressedEvent: (" << keyCode << ", " << repeatCount << ")";
            return builder.str();
        }

        EVENT_CLASS_TYPE(KeyPressed);
    };

    class KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(KeyCode keyCode)
            : KeyEvent(keyCode) { }

        KeyReleasedEvent(KeyReleasedEvent&& event) noexcept
            : KeyEvent(reinterpret_cast<KeyEvent&&>(event)) { }

        [[nodiscard]] std::string toString() const override {
            std::stringstream builder;
            builder << "KeyReleasedEvent: " << keyCode;
            return builder.str();
        }

        EVENT_CLASS_TYPE(KeyRelease);
    };

    class KeyTypedEvent : public KeyEvent {
    public:
        KeyTypedEvent(KeyCode keyCode)
            : KeyEvent(keyCode) { }

        KeyTypedEvent(KeyTypedEvent&& event) noexcept
            : KeyEvent(reinterpret_cast<KeyEvent&&>(event)) { }

        [[nodiscard]] std::string toString() const override {
            std::stringstream builder;
            builder << "KeyTypedEvent: " << keyCode;
            return builder.str();
        }

        EVENT_CLASS_TYPE(KeyTyped);
    };
}

#endif //SIMPLE_KEYEVENT_H
