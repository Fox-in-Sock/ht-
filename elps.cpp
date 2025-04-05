#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

// Function to plot 4 symmetric points of the ellipse
void plotEllipsePoints(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void midpointEllipse(int xc, int yc, int rx, int ry) {
    float dx, dy, d1, d2, x = 0, y = ry;

    // Region 1
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy) {
        plotEllipsePoints(xc, yc, round(x), round(y));
        x++;
        dx = dx + (2 * ry * ry);
        if (d1 < 0) {
            d1 = d1 + dx + (ry * ry);
        } else {
            y--;
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
        delay(10);
    }

    // Region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
         ((rx * rx) * ((y - 1) * (y - 1))) -
         (rx * rx * ry * ry);

    while (y >= 0) {
        plotEllipsePoints(xc, yc, round(x), round(y));
        y--;
        dy = dy - (2 * rx * rx);
        if (d2 > 0) {
            d2 = d2 + (rx * rx) - dy;
        } else {
            x++;
            dx = dx + (2 * ry * ry);
            d2 = d2 + dx - dy + (rx * rx);
        }
        delay(10);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int xc = 250, yc = 200, rx = 100, ry = 60;

    midpointEllipse(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}
