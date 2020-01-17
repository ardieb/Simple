//
// Created by Arthur Burke on 2020-01-17.
//

#ifndef SIMPLE_WINDOWEVENT_H
#define SIMPLE_WINDOWEVENT_H

#include <Simple/Events/Event.h>

namespace Simple {
    class WindowResizeEvent : public Event {
    private:
        unsigned int width;
        unsigned int height;
    public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : width(width), height(height) { }

        WindowResizeEvent(WindowResizeEvent&& event) noexcept {
            height = event.height;
            width = event.width;
        }

        inline unsigned int getWidth() {
            return width;
        }

        inline unsigned int getHeight() {
            return height;
        }

        [[nodiscard]] std::string toString() const override {
            std::stringstream builder;
            builder << "WindowResizeEvent: (" << width << ", " << height << ")";
            return builder.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(CategoryApplication)
    };

    class AppTickEvent : public Event {
    public:
        AppTickEvent() = default;
        EVENT_CLASS_TYPE( AppTick)
        EVENT_CLASS_CATEGORY(CategoryApplication)
    };

    class AppUpdateEvent : public Event {
    public:
        AppUpdateEvent() = default;
        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(CategoryApplication)
    };

    class AppRenderEvent : public Event {
    public:
        AppRenderEvent() = default;
        EVENT_CLASS_TYPE(AppRender);
        EVENT_CLASS_CATEGORY(CategoryApplication);
    };
}

#endif //SIMPLE_WINDOWEVENT_H
