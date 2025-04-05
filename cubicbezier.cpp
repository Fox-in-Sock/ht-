#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

// Function to calculate a point on the cubic Bezier curve
void bezierCurve(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    float t;
    int x, y;

    for (t = 0.0; t <= 1.0; t += 0.001) {
        x = pow(1 - t, 3) * x0 +
            3 * t * pow(1 - t, 2) * x1 +
            3 * pow(t, 2) * (1 - t) * x2 +
            pow(t, 3) * x3;

        y = pow(1 - t, 3) * y0 +
            3 * t * pow(1 - t, 2) * y1 +
            3 * pow(t, 2) * (1 - t) * y2 +
            pow(t, 3) * y3;

        putpixel(x, y, WHITE);
        delay(1);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x0, y0, x1, y1, x2, y2, x3, y3;

    // Example control points (can be modified or taken as input)
    x0 = 100; y0 = 300;
    x1 = 150; y1 = 100;
    x2 = 250; y2 = 100;
    x3 = 300; y3 = 300;

    // Drawing control polygon
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);

    // Draw control points
    setcolor(RED);
    circle(x0, y0, 3);
    circle(x1, y1, 3);
    circle(x2, y2, 3);
    circle(x3, y3, 3);

    // Draw the bezier curve
    setcolor(WHITE);
    bezierCurve(x0, y0, x1, y1, x2, y2, x3, y3);

    getch();
    closegraph();
    return 0;
}
