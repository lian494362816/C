#ifndef __LCD_CONTROLLER_H__
#define __LCD_CONTROLLER_H__

#include "lcd.h"

typedef struct lcd_controller {
    char *name;
    void (*init)(lcd_param_t *);
    void (*enable)(void);
    void (*disable)(void);
}lcd_controller_t;


#endif
