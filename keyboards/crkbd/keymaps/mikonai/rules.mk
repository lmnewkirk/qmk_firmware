MCU = atmega32u4
BOOTLOADER = atmel-dfu
MOUSEKEY_ENABLE = yes    # Mouse keys
RGBLIGHT_ENABLE = no    # Enable WS2812 RGB underlight.
RGB_MATRIX_ENABLE = yes
NKRO_ENABLE = no
#RGB_MATRIX_DRIVER = WS2812
#SPLIT_KEYBOARD = yes
WPM_ENABLE = yes
SLEEP_LED_ENABLE = yes
VPATH 		+= keyboards/gboards
# these VPATH things are to try to make rgb stuff work. it compiles now, but doesn't exactly... work.
#VPATH		+= quantum/rgb_matrix
#VPATH		+= quantum/rgblight
#VPATH		+= quantum/rgb_matrix/animations
COMBO_ENABLE	= yes
OLED_ENABLE     = no
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes
TAP_DANCE_ENABLE = yes

