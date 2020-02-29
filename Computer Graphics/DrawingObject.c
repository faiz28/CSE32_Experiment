 
#include <graphics.h>

int main() {
    int gd=DETECT, gm=DETECT;
	initgraph(&gd,&gm,"");

    setbkcolor(WHITE);
    setcolor(RED);



    line(150, 150, 275, 94);
    line(400, 150, 275, 94);
    circle(275, 150, 50);
    rectangle(150, 150, 400, 300);
    delay(5000);
    closegraph();
    return 0;
}