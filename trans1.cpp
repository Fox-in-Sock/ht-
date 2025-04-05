#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <dos.h>

using namespace std;

void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

void translate(int x1, int y1, int x2, int y2) {
    int tx, ty;
    cout << "Enter tx and ty: ";
    cin >> tx >> ty;
    drawRectangle(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
}

void rotate(int x1, int y1, int x2, int y2) {
    int angle, refx = (x1 + x2) / 2, refy = (y1 + y2) / 2; // Use the center of the rectangle as reference
    cout << "Enter angle: ";
    cin >> angle;
    float rad = angle * (3.14159 / 180); // Use a more precise value for pi

    int x[4] = {x1, x1, x2, x2};
    int y[4] = {y1, y2, y2, y1};
    int rx[4], ry[4];
    
    for (int i = 0; i < 4; i++) {
        rx[i] = refx + (x[i] - refx) * cos(rad) - (y[i] - refy) * sin(rad);
        ry[i] = refy + (x[i] - refx) * sin(rad) + (y[i] - refy) * cos(rad);
    }
    
    for (int i = 0; i < 4; i++)
        line(rx[i], ry[i], rx[(i + 1) % 4], ry[(i + 1) % 4]);
}

void scale(int x1, int y1, int x2, int y2) {
    float sx, sy;
    cout << "Enter sx & sy: ";
    cin >> sx >> sy;
    int newx1 = (int)((x1 - (x1 + x2) / 2.0) * sx + (x1 + x2) / 2.0);
    int newy1 = (int)((y1 - (y1 + y2) / 2.0) * sy + (y1 + y2) / 2.0);
    int newx2 = (int)((x2 - (x1 + x2) / 2.0) * sx + (x1 + x2) / 2.0);
    int newy2 = (int)((y2 - (y1 + y2) / 2.0) * sy + (y1 + y2) / 2.0);
    drawRectangle(newx1, newy1, newx2, newy2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    if (graphresult() != grOk) {
        cout << "Graphics initialization failed!" << endl;
        return 1;
    }

    int x1 = 100, y1 = 100, x2 = 150, y2 = 150;
    drawRectangle(x1, y1, x2, y2);
    
    cout << "Enter choice:\n1. Translation\n2. Rotation\n3. Scaling\nChoice: ";
    int choice;
    cin >> choice;
    
    switch (choice) {
        case 1: translate(x1, y1, x2, y2); break;
        case 2: rotate(x1, y1, x2, y2); break;
        case 3: scale(x1, y1, x2, y2); break;
        default: cout << "Invalid choice!" << endl;
    }
    
    getch();
    closegraph();
    return 0;
}
