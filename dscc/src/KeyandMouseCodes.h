#pragma once


/* The unknown key */
#define DSCC_KEY_UNKNOWN            -1

/* Printable keys */
#define DSCC_KEY_SPACE              32
#define DSCC_KEY_APOSTROPHE         39  /* ' */
#define DSCC_KEY_COMMA              44  /* , */
#define DSCC_KEY_MINUS              45  /* - */
#define DSCC_KEY_PERIOD             46  /* . */
#define DSCC_KEY_SLASH              47  /* / */
#define DSCC_KEY_0                  48
#define DSCC_KEY_1                  49
#define DSCC_KEY_2                  50
#define DSCC_KEY_3                  51
#define DSCC_KEY_4                  52
#define DSCC_KEY_5                  53
#define DSCC_KEY_6                  54
#define DSCC_KEY_7                  55
#define DSCC_KEY_8                  56
#define DSCC_KEY_9                  57
#define DSCC_KEY_SEMICOLON          59  /* ; */
#define DSCC_KEY_EQUAL              61  /* = */
#define DSCC_KEY_A                  65
#define DSCC_KEY_B                  66
#define DSCC_KEY_C                  67
#define DSCC_KEY_D                  68
#define DSCC_KEY_E                  69
#define DSCC_KEY_F                  70
#define DSCC_KEY_G                  71
#define DSCC_KEY_H                  72
#define DSCC_KEY_I                  73
#define DSCC_KEY_J                  74
#define DSCC_KEY_K                  75
#define DSCC_KEY_L                  76
#define DSCC_KEY_M                  77
#define DSCC_KEY_N                  78
#define DSCC_KEY_O                  79
#define DSCC_KEY_P                  80
#define DSCC_KEY_Q                  81
#define DSCC_KEY_R                  82
#define DSCC_KEY_S                  83
#define DSCC_KEY_T                  84
#define DSCC_KEY_U                  85
#define DSCC_KEY_V                  86
#define DSCC_KEY_W                  87
#define DSCC_KEY_X                  88
#define DSCC_KEY_Y                  89
#define DSCC_KEY_Z                  90
#define DSCC_KEY_LEFT_BRACKET       91  /* [ */
#define DSCC_KEY_BACKSLASH          92  /* \ */
#define DSCC_KEY_RIGHT_BRACKET      93  /* ] */
#define DSCC_KEY_GRAVE_ACCENT       96  /* ` */
#define DSCC_KEY_WORLD_1            161 /* non-US #1 */
#define DSCC_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define DSCC_KEY_ESCAPE             256
#define DSCC_KEY_ENTER              257
#define DSCC_KEY_TAB                258
#define DSCC_KEY_BACKSPACE          259
#define DSCC_KEY_INSERT             260
#define DSCC_KEY_DELETE             261
#define DSCC_KEY_RIGHT              262
#define DSCC_KEY_LEFT               263
#define DSCC_KEY_DOWN               264
#define DSCC_KEY_UP                 265
#define DSCC_KEY_PAGE_UP            266
#define DSCC_KEY_PAGE_DOWN          267
#define DSCC_KEY_HOME               268
#define DSCC_KEY_END                269
#define DSCC_KEY_CAPS_LOCK          280
#define DSCC_KEY_SCROLL_LOCK        281
#define DSCC_KEY_NUM_LOCK           282
#define DSCC_KEY_PRINT_SCREEN       283
#define DSCC_KEY_PAUSE              284
#define DSCC_KEY_F1                 290
#define DSCC_KEY_F2                 291
#define DSCC_KEY_F3                 292
#define DSCC_KEY_F4                 293
#define DSCC_KEY_F5                 294
#define DSCC_KEY_F6                 295
#define DSCC_KEY_F7                 296
#define DSCC_KEY_F8                 297
#define DSCC_KEY_F9                 298
#define DSCC_KEY_F10                299
#define DSCC_KEY_F11                300
#define DSCC_KEY_F12                301
#define DSCC_KEY_F13                302
#define DSCC_KEY_F14                303
#define DSCC_KEY_F15                304
#define DSCC_KEY_F16                305
#define DSCC_KEY_F17                306
#define DSCC_KEY_F18                307
#define DSCC_KEY_F19                308
#define DSCC_KEY_F20                309
#define DSCC_KEY_F21                310
#define DSCC_KEY_F22                311
#define DSCC_KEY_F23                312
#define DSCC_KEY_F24                313
#define DSCC_KEY_F25                314
#define DSCC_KEY_KP_0               320
#define DSCC_KEY_KP_1               321
#define DSCC_KEY_KP_2               322
#define DSCC_KEY_KP_3               323
#define DSCC_KEY_KP_4               324
#define DSCC_KEY_KP_5               325
#define DSCC_KEY_KP_6               326
#define DSCC_KEY_KP_7               327
#define DSCC_KEY_KP_8               328
#define DSCC_KEY_KP_9               329
#define DSCC_KEY_KP_DECIMAL         330
#define DSCC_KEY_KP_DIVIDE          331
#define DSCC_KEY_KP_MULTIPLY        332
#define DSCC_KEY_KP_SUBTRACT        333
#define DSCC_KEY_KP_ADD             334
#define DSCC_KEY_KP_ENTER           335
#define DSCC_KEY_KP_EQUAL           336
#define DSCC_KEY_LEFT_SHIFT         340
#define DSCC_KEY_LEFT_CONTROL       341
#define DSCC_KEY_LEFT_ALT           342
#define DSCC_KEY_LEFT_SUPER         343
#define DSCC_KEY_RIGHT_SHIFT        344
#define DSCC_KEY_RIGHT_CONTROL      345
#define DSCC_KEY_RIGHT_ALT          346
#define DSCC_KEY_RIGHT_SUPER        347
#define DSCC_KEY_MENU               348

#define DSCC_KEY_LAST               DSCC_KEY_MENU

/*! @} */

/*! @defgroup mods Modifier key flags
 *
 *  See [key input](@ref input_key) for how these are used.
 *
 *  @ingroup input
 *  @{ */

 /*! @brief If this bit is set one or more Shift keys were held down.
  */
#define DSCC_MOD_SHIFT           0x0001
  /*! @brief If this bit is set one or more Control keys were held down.
   */
#define DSCC_MOD_CONTROL         0x0002
   /*! @brief If this bit is set one or more Alt keys were held down.
	*/
#define DSCC_MOD_ALT             0x0004
	/*! @brief If this bit is set one or more Super keys were held down.
	 */
#define DSCC_MOD_SUPER           0x0008


#define DSCC_MOUSE_BUTTON_1         0
#define DSCC_MOUSE_BUTTON_2         1
#define DSCC_MOUSE_BUTTON_3         2
#define DSCC_MOUSE_BUTTON_4         3
#define DSCC_MOUSE_BUTTON_5         4
#define DSCC_MOUSE_BUTTON_6         5
#define DSCC_MOUSE_BUTTON_7         6
#define DSCC_MOUSE_BUTTON_8         7
#define DSCC_MOUSE_BUTTON_LAST      DSCC_MOUSE_BUTTON_8
#define DSCC_MOUSE_BUTTON_LEFT      DSCC_MOUSE_BUTTON_1
#define DSCC_MOUSE_BUTTON_RIGHT     DSCC_MOUSE_BUTTON_2
#define DSCC_MOUSE_BUTTON_MIDDLE    DSCC_MOUSE_BUTTON_3
