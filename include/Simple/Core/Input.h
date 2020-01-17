//
// Created by Arthur Burke on 2020-01-17.
//

#ifndef SIMPLE_INPUT_H
#define SIMPLE_INPUT_H

#include <Simple/Core/KeyCodes.h>
#include <Simple/Core/MouseCodes.h>

namespace Simple {

    // Singleton class
    class Input {
    protected:
        Input() = default;
    public:
        Input(const Input&) = delete;
        Input& operator=(const Input&) = delete;

        inline static bool isKeyPressed(KeyCode key) { return instance->isKeyPressedImpl(key); }

        inline static bool isMouseButtonPressed(MouseCode button) { return instance->isMouseButtonPressedImpl(button); }
        inline static std::pair<float, float> getMousePosition() { return instance->getMousePositionImpl(); }
        inline static float getMouseX() { return instance->getMouseXImpl(); }
        inline static float getMouseY() { return instance->getMouseYImpl(); }

        static Scope<Input> create();
    protected:
        virtual bool isKeyPressedImpl(KeyCode key) = 0;
        virtual bool isMouseButtonPressedImpl(MouseCode button) = 0;
        virtual std::pair<float, float> getMousePositionImpl() = 0;
        virtual float getMouseXImpl() = 0;
        virtual float getMouseYImpl() = 0;
    private:
        static Scope<Input> instance;
    };
}
#endif //SIMPLE_INPUT_H
