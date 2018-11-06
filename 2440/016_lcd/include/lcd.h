#ifndef __LCD_H__
#define __LCD_H__

enum {
    NORMAL = 0,
    INVERT = 1,
};

typedef struct lcd_pin_polarity{
    int vlck; /* normal fetched at failling edge */
    int vline; /* hsync, normal high level */
    int vframe; /* vsync, normal high level */
    int vvd; /* video data, normal '1' means high level */
    int vdec; /* data enable, normal high level  */
    int vpwren; /* power enable, normal high level */
    int vlend; /* line end, normal high level */
}lcd_pin_polarity_t;

typedef struct lcd_time{
    int clk;
    /* vertical control */
    int vbpd;
    int vfpd;
    int vspw;

    /* horizontal control */
    int hbpd;
    int hfpd;
    int hspw;
}lcd_time_t;

typedef struct lcd_param{
    char *name;
    int bpp; /*bpp mode 16, 24*/
    int width;
    int height;
    unsigned int frame_addr;
    lcd_time_t st_time;
    lcd_pin_polarity_t st_pin_polarity;
}lcd_param_t;


#endif
