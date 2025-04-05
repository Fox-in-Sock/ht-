#include <graphics.h>
#include <conio.h>

void boundaryFill(int x, int y, int fill_color, int boundary_color) {
    int current = getpixel(x, y);
    if (current != boundary_color && current != fill_color) {
        putpixel(x, y, fill_color);
        delay(1);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Draw a closed shape (rectangle in this case)
    rectangle(100, 100, 200, 200);

    int fill_color = YELLOW;
    int boundary_color = WHITE;

    // Call boundary fill from inside the shape
    boundaryFill(150, 150, fill_color, boundary_color);

    getch();
    closegraph();
    return 0;
}
