#include<iostream.h>
#include <graphics.h>
#include <conio.h>

void floodFill(int x, int y, int old_color, int fill_color) {
    int current = getpixel(x, y);
    if (current == old_color && current != fill_color) {
        putpixel(x, y, fill_color);
        delay(1);
        floodFill(x + 1, y, old_color, fill_color);
        floodFill(x - 1, y, old_color, fill_color);
        floodFill(x, y + 1, old_color, fill_color);
        floodFill(x, y - 1, old_color, fill_color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw a closed shape
    rectangle(100, 100, 200, 200);

    int x = 150, y = 150;
    int old_color = getpixel(x, y);  // Background color
    int fill_color = RED;

    floodFill(x, y, old_color, fill_color);

    getch();
    closegraph();
    return 0;
}
