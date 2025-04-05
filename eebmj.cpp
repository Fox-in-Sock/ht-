#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

void DDA(int x1, int y1, int x2, int y2) {
    float dx, dy, steps, x, y, xInc, yInc;

    dx = x2 - x1;
    dy = y2 - y1;

    // Replacing the ternary operator with if-else
    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    xInc = dx / steps;
    yInc = dy / steps;

    x = x1;
    y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xInc;
        y += yInc;
        delay(10); // To visualize line drawing step-by-step
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x1, y1, x2, y2;

    // You can take user input or hardcode values
    x1 = 100; y1 = 100;
    x2 = 300; y2 = 200;

    DDA(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
