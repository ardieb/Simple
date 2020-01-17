//
// Created by Arthur Burke on 2020-01-17.
//

#ifndef SIMPLE_MOUSECODES_H
#define SIMPLE_MOUSECODES_H

namespace Simple {
    typedef enum class MouseCode : uint16_t {
        // From glfw3.h
        Button0                = 0,
        Button1                = 1,
        Button2                = 2,
        Button3                = 3,
        Button4                = 4,
        Button5                = 5,
        Button6                = 6,
        Button7                = 7,

        ButtonLast             = Button7,
        ButtonLeft             = Button0,
        ButtonRight            = Button1,
        ButtonMiddle           = Button2
    } Mouse;

    inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode) {
        os << static_cast<int32_t>(mouseCode);
        return os;
    }
}

#define SM_MOUSE_BUTTON_0      ::Simple::Mouse::Button0
#define SM_MOUSE_BUTTON_1      ::Simple::Mouse::Button1
#define SM_MOUSE_BUTTON_2      ::Simple::Mouse::Button2
#define SM_MOUSE_BUTTON_3      ::Simple::Mouse::Button3
#define SM_MOUSE_BUTTON_4      ::Simple::Mouse::Button4
#define SM_MOUSE_BUTTON_5      ::Simple::Mouse::Button5
#define SM_MOUSE_BUTTON_6      ::Simple::Mouse::Button6
#define SM_MOUSE_BUTTON_7      ::Simple::Mouse::Button7
#define SM_MOUSE_BUTTON_LAST   ::Simple::Mouse::ButtonLast
#define SM_MOUSE_BUTTON_LEFT   ::Simple::Mouse::ButtonLeft
#define SM_MOUSE_BUTTON_RIGHT  ::Simple::Mouse::ButtonRight
#define SM_MOUSE_BUTTON_MIDDLE ::Simple::Mouse::ButtonMiddle
© 2020 GitHub, Inc.

#endif //SIMPLE_MOUSECODES_H
