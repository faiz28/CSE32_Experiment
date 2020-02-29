#include <graphics.h>

void plotLine(int x0,int y0,int x1,int y1)
{
    int dy=y1-y0;
    int dx=x1-x0;
    int p=2*dy-dx;
    int y=y0;
    for(int x=x0;x<=x1;x++)
    {
        putpixel(x,y,RED);
        if(p<0)
        {
            p=p+2*dy;
        }
        else{
            p=p+2*dy-2*dx;
            y++;
        }
    }
}

int main() {
   int gd=DETECT, gm=DETECT;
   initgraph(&gd,&gm,"");
   setbkcolor(WHITE);
    plotLine(3, 30, 500, 105);
    delay(5000);
    closegraph();
    return 0;
}
