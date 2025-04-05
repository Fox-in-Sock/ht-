#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

void bresenham(int x1, int y1, int x2, int y2) {
    int dx, dy, p, x, y;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    int twoDy = 2 * dy;
    int twoDyDx = 2 * (dy - dx);

    p = 2 * dy - dx;

    // Determine the direction of line
    if (x1 > x2) {
        x = x2;
        y = y2;
        x2 = x1;
        y2 = y1;
    } else {
        x = x1;
        y = y1;
    }

    putpixel(x, y, WHITE);

    for (int i = 0; i < dx; i++) {
        x++;

        if (p < 0)
            p += twoDy;
        else {
            y += (y1 < y2) ? 1 : -1;
            p += twoDyDx;
        }

        putpixel(x, y, WHITE);
        delay(10); // Visualize step-by-step drawing
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x1 = 100, y1 = 100, x2 = 300, y2 = 200;

    bresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
