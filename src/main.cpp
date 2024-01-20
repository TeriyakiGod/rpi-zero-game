#include <ko.hpp>
int main()
{
    if (ko::tools::moduleInit() != 0)
        ko::tools::moduleExit();

    LCD_SCAN_DIR lcd_scan_dir = SCAN_DIR_DFT;
    ko::lcd::init(lcd_scan_dir);
    ko::lcd::clear(BLACK);

    UWORD *Image;
    UDOUBLE Imagesize = LCD_HEIGHT * LCD_WIDTH * 2;
    if ((Image = (UWORD *)malloc(Imagesize)) == NULL)
    {
        printf("Failed to apply for black memory...\r\n");
        exit(0);
    }

    ko::draw::newImage(Image, LCD_WIDTH, LCD_HEIGHT, ROTATE_0, WHITE, 16);
    ko::draw::clearImage(BLACK);
    ko::draw::text(0, 0, "Hello World", &Font8, BLACK, WHITE);
    ko::draw::text(0, 9, "Hello World", &Font12, BLACK, WHITE);
    ko::draw::text(0, 21, "Hello World", &Font16, BLACK, WHITE);
    ko::draw::text(0, 38, "Hello World", &Font20, BLACK, WHITE);
    ko::draw::text(0, 60, "Hello World", &Font24, BLACK, WHITE);

    ko::lcd::display(Image);

    ko::tools::moduleExit();
    return 0;
}
