// Key definitions
#define BUTTON_KEY1 KEY_F13
#define BUTTON_KEY2 KEY_F14
#define BUTTON_KEY3 KEY_F15
#define BUTTON_KEY4 KEY_F16
#define BUTTON_KEY5 KEY_F17
#define BUTTON_KEY6 KEY_F18
#define BUTTON_KEY7 KEY_F19
#define BUTTON_KEY8 KEY_F20

// Led
#define BRIGHTNESS  255
#define UPDATES_PER_SECOND 30

#define PRESS_COLOR CRGB::White

enum MODIFIER_KEYS_BITMASK {
  MODIFIER_KEY_LEFT_CTRL = 0x01,
  MODIFIER_KEY_LEFT_SHIFT = 0x02,
  MODIFIER_KEY_LEFT_ALT = 0x04,
  MODIFIER_KEY_LEFT_GUI = 0x08,
  MODIFIER_KEY_RIGHT_CTRL = 0x10,
  MODIFIER_KEY_RIGHT_SHIFT = 0x20,
  MODIFIER_KEY_RIGHT_ALT = 0x40,
  MODIFIER_KEY_RIGHT_GUI = 0x80
};
typedef struct 
{
    byte modifier;
    char key;
} key_t;