#include "lcd.h"

int lcd_test(void)
{
    int width = 0;
    int height = 0;
    int bpp_mode = 0;
    unsigned int frame_addr = 0;
    int i = 0;
    int j = 0;
    unsigned short *p_addr;
    unsigned int *p_addr2;


    lcd_init();

    lcd_enable();

    lcd_get_param(&width, &height, &bpp_mode, &frame_addr);
    printf("widht:%d, height:%d, bpp:%d, frame_addr:0x%x\n", width, height, bpp_mode, frame_addr);

    if (16 == bpp_mode)
    {
        //red
        p_addr = (unsigned short *)frame_addr;
        for (i = 0; i < width; i++)
        {
            for (j = 0; j < height; j++)
            {
                *p_addr = 0xF800;
                p_addr ++;
            }
        }
        printf("red===========\n");
        lcd_read_rgb();

        //green
        p_addr = (unsigned short *)frame_addr;
        for (i = 0; i < width; i++)
        {
            for (j = 0; j < height; j++)
            {
                *p_addr = 0x7E0;
                p_addr ++;
            }
        }
        printf("green===========\n");
        lcd_read_rgb();

        //blue
        p_addr = (unsigned short *)frame_addr;
        for (i = 0; i < width; i++)
        {
            for (j = 0; j < height; j++)
            {
                *p_addr = 0x1F;
                p_addr ++;
            }
        }
        printf("blue===========\n");
        lcd_read_rgb();
    }

    if (24 == bpp_mode)
    {
        //red
        p_addr2 = (unsigned int *)frame_addr;
        for (i = 0; i < width; i++)
        {
            for (j = 0; j < height; j++)
            {
                *p_addr2 = 0xFF0000;
                p_addr2 ++;
            }
        }

        //green
        p_addr2 = (unsigned int *)frame_addr;
        for (i = 0; i < width; i++)
        {
            for (j = 0; j < height; j++)
            {
                *p_addr2 = 0xFF00;
                p_addr2 ++;
            }
        }

        //blue
        p_addr2 = (unsigned int *)frame_addr;
        for (i = 0; i < width; i++)
        {
            for (j = 0; j < height; j++)
            {
                *p_addr2 = 0xFF;
                p_addr2 ++;
            }
        }
    }
}
