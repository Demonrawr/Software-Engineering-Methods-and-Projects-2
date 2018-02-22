#ifndef INPUTMACROS
#define INPUTMACROS

enum class KEYBOARD_KEY { KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M,
                          KEY_N, KEY_O, KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z,
                          KEY_NUM_ROW_0, KEY_NUM_ROW_1, KEY_NUM_ROW_2, KEY_NUM_ROW_3, KEY_NUM_ROW_4,
                          KEY_NUM_ROW_5, KEY_NUM_ROW_6, KEY_NUM_ROW_7, KEY_NUM_ROW_8, KEY_NUM_ROW_9,
                          KEY_NUM_PAD_0, KEY_NUM_PAD_1, KEY_NUM_PAD_2, KEY_NUM_PAD_3, KEY_NUM_PAD_4,
                          KEY_NUM_PAD_5, KEY_NUM_PAD_6, KEY_NUM_PAD_7, KEY_NUM_PAD_8, KEY_NUM_PAD_9,
                          KEY_LEFT_SHIFT  , KEY_RIGHT_SHIFT,
                          KEY_LEFT_CTRL   , KEY_RIGHT_CTRL,
                          KEY_LEFT_ALT    , KEY_RIGHT_ALT,
                          KEY_LEFT_COMMAND, KEY_RIGHT_COMMAND,
                          KEY_SPACE,
                          KEY_CAPS_LOCK,
                          KEY_TAB,
                          KEY_LEFT_ARROW,
                          KEY_RIGHT_ARROW,
                          KEY_UP_ARROW,
                          KEY_DOWN_ARROW,
                          KEY_UNMAPPED
                        };

enum class MOUSE_BUTTON { MOUSE_LEFT, MOUSE_RIGHT, MOUSE_WHEEL };

#endif // INPUTMACROS

