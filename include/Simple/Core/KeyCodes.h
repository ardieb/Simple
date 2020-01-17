//
// Created by Arthur Burke on 2020-01-17.
//

#ifndef SIMPLE_KEYCODES_H
#define SIMPLE_KEYCODES_H

namespace Simple {
    typedef enum class KeyCode : uint16_t {
        // From glfw3.h
        Space               = 32,
        Apostrophe          = 39, /* ' */
        Comma               = 44, /* , */
        Minus               = 45, /* - */
        Period              = 46, /* . */
        Slash               = 47, /* / */

        D0                  = 48, /* 0 */
        D1                  = 49, /* 1 */
        D2                  = 50, /* 2 */
        D3                  = 51, /* 3 */
        D4                  = 52, /* 4 */
        D5                  = 53, /* 5 */
        D6                  = 54, /* 6 */
        D7                  = 55, /* 7 */
        D8                  = 56, /* 8 */
        D9                  = 57, /* 9 */

        Semicolon           = 59, /* ; */
        Equal               = 61, /* = */

        A                   = 65,
        B                   = 66,
        C                   = 67,
        D                   = 68,
        E                   = 69,
        F                   = 70,
        G                   = 71,
        H                   = 72,
        I                   = 73,
        J                   = 74,
        K                   = 75,
        L                   = 76,
        M                   = 77,
        N                   = 78,
        O                   = 79,
        P                   = 80,
        Q                   = 81,
        R                   = 82,
        S                   = 83,
        T                   = 84,
        U                   = 85,
        V                   = 86,
        W                   = 87,
        X                   = 88,
        Y                   = 89,
        Z                   = 90,

        LeftBracket         = 91,  /* [ */
        Backslash           = 92,  /* \ */
        RightBracket        = 93,  /* ] */
        GraveAccent         = 96,  /* ` */

        World1              = 161, /* non-US #1 */
        World2              = 162, /* non-US #2 */

        /* Function keys */
                Escape              = 256,
        Enter               = 257,
        Tab                 = 258,
        Backspace           = 259,
        Insert              = 260,
        Delete              = 261,
        Right               = 262,
        Left                = 263,
        Down                = 264,
        Up                  = 265,
        PageUp              = 266,
        PageDown            = 267,
        Home                = 268,
        End                 = 269,
        CapsLock            = 280,
        ScrollLock          = 281,
        NumLock             = 282,
        PrintScreen         = 283,
        Pause               = 284,
        F1                  = 290,
        F2                  = 291,
        F3                  = 292,
        F4                  = 293,
        F5                  = 294,
        F6                  = 295,
        F7                  = 296,
        F8                  = 297,
        F9                  = 298,
        F10                 = 299,
        F11                 = 300,
        F12                 = 301,
        F13                 = 302,
        F14                 = 303,
        F15                 = 304,
        F16                 = 305,
        F17                 = 306,
        F18                 = 307,
        F19                 = 308,
        F20                 = 309,
        F21                 = 310,
        F22                 = 311,
        F23                 = 312,
        F24                 = 313,
        F25                 = 314,

        /* Keypad */
        KP0                 = 320,
        KP1                 = 321,
        KP2                 = 322,
        KP3                 = 323,
        KP4                 = 324,
        KP5                 = 325,
        KP6                 = 326,
        KP7                 = 327,
        KP8                 = 328,
        KP9                 = 329,
        KPDecimal           = 330,
        KPDivide            = 331,
        KPMultiply          = 332,
        KPSubtract          = 333,
        KPAdd               = 334,
        KPEnter             = 335,
        KPEqual             = 336,

        LeftShift           = 340,
        LeftControl         = 341,
        LeftAlt             = 342,
        LeftSuper           = 343,
        RightShift          = 344,
        RightControl        = 345,
        RightAlt            = 346,
        RightSuper          = 347,
        Menu                = 348
    } Key;

    inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode) {
        os << static_cast<int32_t>(keyCode);
        return os;
    }
}

// From glfw3.h
#define SM_KEY_SPACE           ::Simple::Key::Space
#define SM_KEY_APOSTROPHE      ::Simple::Key::Apostrophe    /* ' */
#define SM_KEY_COMMA           ::Simple::Key::Comma         /* , */
#define SM_KEY_MINUS           ::Simple::Key::Minus         /* - */
#define SM_KEY_PERIOD          ::Simple::Key::Period        /* . */
#define SM_KEY_SLASH           ::Simple::Key::Slash         /* / */
#define SM_KEY_0               ::Simple::Key::D0
#define SM_KEY_1               ::Simple::Key::D1
#define SM_KEY_2               ::Simple::Key::D2
#define SM_KEY_3               ::Simple::Key::D3
#define SM_KEY_4               ::Simple::Key::D4
#define SM_KEY_5               ::Simple::Key::D5
#define SM_KEY_6               ::Simple::Key::D6
#define SM_KEY_7               ::Simple::Key::D7
#define SM_KEY_8               ::Simple::Key::D8
#define SM_KEY_9               ::Simple::Key::D9
#define SM_KEY_SEMICOLON       ::Simple::Key::Semicolon     /* ; */
#define SM_KEY_EQUAL           ::Simple::Key::Equal         /* = */
#define SM_KEY_A               ::Simple::Key::A
#define SM_KEY_B               ::Simple::Key::B
#define SM_KEY_C               ::Simple::Key::C
#define SM_KEY_D               ::Simple::Key::D
#define SM_KEY_E               ::Simple::Key::E
#define SM_KEY_F               ::Simple::Key::F
#define SM_KEY_G               ::Simple::Key::G
#define SM_KEY_H               ::Simple::Key::H
#define SM_KEY_I               ::Simple::Key::I
#define SM_KEY_J               ::Simple::Key::J
#define SM_KEY_K               ::Simple::Key::K
#define SM_KEY_L               ::Simple::Key::L
#define SM_KEY_M               ::Simple::Key::M
#define SM_KEY_N               ::Simple::Key::N
#define SM_KEY_O               ::Simple::Key::O
#define SM_KEY_P               ::Simple::Key::P
#define SM_KEY_Q               ::Simple::Key::Q
#define SM_KEY_R               ::Simple::Key::R
#define SM_KEY_S               ::Simple::Key::S
#define SM_KEY_T               ::Simple::Key::T
#define SM_KEY_U               ::Simple::Key::U
#define SM_KEY_V               ::Simple::Key::V
#define SM_KEY_W               ::Simple::Key::W
#define SM_KEY_X               ::Simple::Key::X
#define SM_KEY_Y               ::Simple::Key::Y
#define SM_KEY_Z               ::Simple::Key::Z
#define SM_KEY_LEFT_BRACKET    ::Simple::Key::LeftBracket   /* [ */
#define SM_KEY_BACKSLASH       ::Simple::Key::Backslash     /* \ */
#define SM_KEY_RIGHT_BRACKET   ::Simple::Key::RightBracket  /* ] */
#define SM_KEY_GRAVE_ACCENT    ::Simple::Key::GraveAccent   /* ` */
#define SM_KEY_WORLD_1         ::Simple::Key::World1        /* non-US #1 */
#define SM_KEY_WORLD_2         ::Simple::Key::World2        /* non-US #2 */

/* Function keys */
#define SM_KEY_ESCAPE          ::Simple::Key::Escape
#define SM_KEY_ENTER           ::Simple::Key::Enter
#define SM_KEY_TAB             ::Simple::Key::Tab
#define SM_KEY_BACKSPACE       ::Simple::Key::Backspace
#define SM_KEY_INSERT          ::Simple::Key::Insert
#define SM_KEY_DELETE          ::Simple::Key::Delete
#define SM_KEY_RIGHT           ::Simple::Key::Right
#define SM_KEY_LEFT            ::Simple::Key::Left
#define SM_KEY_DOWN            ::Simple::Key::Down
#define SM_KEY_UP              ::Simple::Key::Up
#define SM_KEY_PAGE_UP         ::Simple::Key::PageUp
#define SM_KEY_PAGE_DOWN       ::Simple::Key::PageDown
#define SM_KEY_HOME            ::Simple::Key::Home
#define SM_KEY_END             ::Simple::Key::End
#define SM_KEY_CAPS_LOCK       ::Simple::Key::CapsLock
#define SM_KEY_SCROLL_LOCK     ::Simple::Key::ScrollLock
#define SM_KEY_NUM_LOCK        ::Simple::Key::NumLock
#define SM_KEY_PRINT_SCREEN    ::Simple::Key::PrintScreen
#define SM_KEY_PAUSE           ::Simple::Key::Pause
#define SM_KEY_F1              ::Simple::Key::F1
#define SM_KEY_F2              ::Simple::Key::F2
#define SM_KEY_F3              ::Simple::Key::F3
#define SM_KEY_F4              ::Simple::Key::F4
#define SM_KEY_F5              ::Simple::Key::F5
#define SM_KEY_F6              ::Simple::Key::F6
#define SM_KEY_F7              ::Simple::Key::F7
#define SM_KEY_F8              ::Simple::Key::F8
#define SM_KEY_F9              ::Simple::Key::F9
#define SM_KEY_F10             ::Simple::Key::F10
#define SM_KEY_F11             ::Simple::Key::F11
#define SM_KEY_F12             ::Simple::Key::F12
#define SM_KEY_F13             ::Simple::Key::F13
#define SM_KEY_F14             ::Simple::Key::F14
#define SM_KEY_F15             ::Simple::Key::F15
#define SM_KEY_F16             ::Simple::Key::F16
#define SM_KEY_F17             ::Simple::Key::F17
#define SM_KEY_F18             ::Simple::Key::F18
#define SM_KEY_F19             ::Simple::Key::F19
#define SM_KEY_F20             ::Simple::Key::F20
#define SM_KEY_F21             ::Simple::Key::F21
#define SM_KEY_F22             ::Simple::Key::F22
#define SM_KEY_F23             ::Simple::Key::F23
#define SM_KEY_F24             ::Simple::Key::F24
#define SM_KEY_F25             ::Simple::Key::F25

/* Keypad */
#define SM_KEY_KP_0            ::Simple::Key::KP0
#define SM_KEY_KP_1            ::Simple::Key::KP1
#define SM_KEY_KP_2            ::Simple::Key::KP2
#define SM_KEY_KP_3            ::Simple::Key::KP3
#define SM_KEY_KP_4            ::Simple::Key::KP4
#define SM_KEY_KP_5            ::Simple::Key::KP5
#define SM_KEY_KP_6            ::Simple::Key::KP6
#define SM_KEY_KP_7            ::Simple::Key::KP7
#define SM_KEY_KP_8            ::Simple::Key::KP8
#define SM_KEY_KP_9            ::Simple::Key::KP9
#define SM_KEY_KP_DECIMAL      ::Simple::Key::KPDecimal
#define SM_KEY_KP_DIVIDE       ::Simple::Key::KPDivide
#define SM_KEY_KP_MULTIPLY     ::Simple::Key::KPMultiply
#define SM_KEY_KP_SUBTRACT     ::Simple::Key::KPSubtract
#define SM_KEY_KP_ADD          ::Simple::Key::KPAdd
#define SM_KEY_KP_ENTER        ::Simple::Key::KPEnter
#define SM_KEY_KP_EQUAL        ::Simple::Key::KPEqual

#define SM_KEY_LEFT_SHIFT      ::Simple::Key::LeftShift
#define SM_KEY_LEFT_CONTROL    ::Simple::Key::LeftControl
#define SM_KEY_LEFT_ALT        ::Simple::Key::LeftAlt
#define SM_KEY_LEFT_SUPER      ::Simple::Key::LeftSuper
#define SM_KEY_RIGHT_SHIFT     ::Simple::Key::RightShift
#define SM_KEY_RIGHT_CONTROL   ::Simple::Key::RightControl
#define SM_KEY_RIGHT_ALT       ::Simple::Key::RightAlt
#define SM_KEY_RIGHT_SUPER     ::Simple::Key::RightSuper
#define SM_KEY_MENU            ::Simple::Key::Menu

#endif //SIMPLE_KEYCODES_H
