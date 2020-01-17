//
// Created by Arthur Burke on 2020-01-17.
//

#ifndef SIMPLE_MOUSEEVENT_H
#define SIMPLE_MOUSEEVENT_H

#include <Simple/Events/Event.h>
#include <Simple/Core/Input.h>

namespace Simple {

    class MouseMovedEvent : public Event {
    public:
        MouseMovedEvent(float x, float y)
            : mouseX(x), mouseY(y) { }

        MouseMovedEvent(MouseMovedEvent&& event) noexcept
            : mouseX(event.mouseX), mouseY(event.mouseY) { }

        inline float getX() const { return mouseX; }
        inline float getY() const { return mouseY; }

        [[nodiscard]] std::string toString() const override {
            std::stringstream builder;
            builder << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return builder.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(CategoryMouse | CategoryInput)
    private:
        float mouseX, mouseY;
    };

    class MouseScrolledEvent : public Event {
    public:
        MouseScrolledEvent(float xOffset, float yOffset)
            : xOffset(xOffset), yOffset(yOffset) { }

        MouseScrolledEvent(MouseScrolledEvent&& event) noexcept
            : xOffset(event.xOffset), yOffset(event.yOffset) { }

        inline float getXOffset() const { return xOffset; }
        inline float getYOffset() const { return yOffset; }

        [[nodiscard]] std::string toString() const override {
            std::stringstream builder;
            builder << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(CategoryMouse | CategoryInput)
    private:
        float xOffset, yOffset;
    };

    class MouseButtonEvent : public Event {
    public:
        inline MouseCode getMouseButton() const { return button; }

        EVENT_CLASS_CATEGORY(CategoryMouse | CategoryInput)
    protected:
        explicit MouseButtonEvent(MouseCode button)
                : button(button) { }

        MouseButtonEvent(MouseButtonEvent&& event) noexcept
                : button(event.button) { }

        MouseCode button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent {
    public:
        MouseButtonPressedEvent(MouseCode button)
            : MouseButtonEvent(button) { }

        MouseButtonPressedEvent(MouseButtonPressedEvent&& event) noexcept
            : MouseButtonEvent(reinterpret_cast<MouseButtonEvent&&>(event)) { }

        [[nodiscard]] std::string toString() const override {
            std::stringstream builder;
            builder << "MouseButtonPressedEvent: " << button;
            return builder.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(MouseCode button)
            : MouseButtonEvent(button) { }

        MouseButtonReleasedEvent(MouseButtonReleasedEvent&& event) noexcept
            : MouseButtonEvent(reinterpret_cast<MouseButtonEvent&&>(event)) { }

        [[nodiscard]] std::string toString() const override {
            std::stringstream builder;
            builder << "MouseButtonReleasedEvent: " << m_Button;
            return builder.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

}

#endif //SIMPLE_MOUSEEVENT_H
