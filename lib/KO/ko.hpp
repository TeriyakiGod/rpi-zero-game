#ifndef KO_HPP
#define KO_HPP

extern "C"
{
#include <LCD_1in44.h>
#include <DEV_Config.h>
#include <GUI_Paint.h>
#include <GUI_BMP.h>
}

namespace ko
{
    class lcd
    {
    public:
        static void init(LCD_SCAN_DIR Scan_dir) { LCD_1in44_Init(Scan_dir); }
        static void clear(UWORD Color) { LCD_1in44_Clear(Color); }
        static void display(UWORD *Image) { LCD_1in44_Display(Image); }
        static void displayWindows(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD *Image)
        {
            LCD_1in44_DisplayWindows(Xstart, Ystart, Xend, Yend, Image);
        }
        static void displayPoint(UWORD X, UWORD Y, UWORD Color) { LCD_1in44_DisplayPoint(X, Y, Color); }
    };
    class tools
    {
    public:
        static bool moduleInit() { return DEV_ModuleInit(); }
        static void moduleExit() { DEV_ModuleExit(); }
        static void gpioMode(UWORD Pin, UWORD Mode) { DEV_GPIO_Mode(Pin, Mode); }
        static void digitalWrite(UWORD Pin, UBYTE Value) { DEV_Digital_Write(Pin, Value); }
        static UBYTE digitalRead(UWORD Pin) { return DEV_Digital_Read(Pin); }
        static void delayMs(UDOUBLE xms) { DEV_Delay_ms(xms); }
        static void spiWriteByte(UBYTE Value) { DEV_SPI_WriteByte(Value); }
        static void spiWriteNByte(uint8_t *pData, uint32_t Len) { DEV_SPI_Write_nByte(pData, Len); }
        static void setBacklight(UWORD Value) { DEV_SetBacklight(Value); }
    };
    class draw
    {
    public:
        static void newImage(UWORD *image, UWORD Width, UWORD Height, UWORD Rotate, UWORD Color, UWORD Depth)
        {
            Paint_NewImage(image, Width, Height, Rotate, Color, Depth);
        }
        static void selectImage(UWORD *image) { Paint_SelectImage(image); }
        static void setRotate(UWORD Rotate) { Paint_SetRotate(Rotate); }
        static void setMirroring(UBYTE mirror) { Paint_SetMirroring(mirror); }
        static void setPixel(UWORD Xpoint, UWORD Ypoint, UWORD Color) { Paint_SetPixel(Xpoint, Ypoint, Color); }
        static void clearImage(UWORD Color) { Paint_Clear(Color); }
        static void clearWindow(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD Color)
        {
            Paint_ClearWindow(Xstart, Ystart, Xend, Yend, Color);
        }
        static void point(UWORD Xpoint, UWORD Ypoint, UWORD Color, DOT_PIXEL Dot_Pixel, DOT_STYLE Dot_FillWay)
        {
            Paint_DrawPoint(Xpoint, Ypoint, Color, Dot_Pixel, Dot_FillWay);
        }
        static void line(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD Color, DOT_PIXEL Line_width, LINE_STYLE Line_Style)
        {
            Paint_DrawLine(Xstart, Ystart, Xend, Yend, Color, Line_width, Line_Style);
        }
        static void rectangle(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend, UWORD Color, DOT_PIXEL Line_width, DRAW_FILL Draw_Fill)
        {
            Paint_DrawRectangle(Xstart, Ystart, Xend, Yend, Color, Line_width, Draw_Fill);
        }
        static void circle(UWORD X_Center, UWORD Y_Center, UWORD Radius, UWORD Color, DOT_PIXEL Line_width, DRAW_FILL Draw_Fill)
        {
            Paint_DrawCircle(X_Center, Y_Center, Radius, Color, Line_width, Draw_Fill);
        }
        static void character(UWORD Xstart, UWORD Ystart, const char Acsii_Char, sFONT *Font, UWORD Color_Foreground, UWORD Color_Background)
        {
            Paint_DrawChar(Xstart, Ystart, Acsii_Char, Font, Color_Foreground, Color_Background);
        }
        static void text(UWORD Xstart, UWORD Ystart, const char *pString, sFONT *Font, UWORD Color_Foreground, UWORD Color_Background)
        {
            Paint_DrawString_EN(Xstart, Ystart, pString, Font, Color_Foreground, Color_Background);
        }
        static void number(UWORD Xpoint, UWORD Ypoint, int32_t Nummber, sFONT *Font, UWORD Color_Foreground, UWORD Color_Background)
        {
            Paint_DrawNum(Xpoint, Ypoint, Nummber, Font, Color_Foreground, Color_Background);
        }
        static void time(UWORD Xstart, UWORD Ystart, PAINT_TIME *pTime, sFONT *Font, UWORD Color_Foreground, UWORD Color_Background)
        {
            Paint_DrawTime(Xstart, Ystart, pTime, Font, Color_Foreground, Color_Background);
        }
        static void partialRefresh(UWORD Xstart, UWORD Ystart, UWORD Xend, UWORD Yend)
        {
            GUI_Partial_Refresh(Xstart, Ystart, Xend, Yend);
        }
        static UBYTE readBmp(const char *path)
        {
            return GUI_ReadBmp(path);
        }
    };
}

#endif // KO_HPP