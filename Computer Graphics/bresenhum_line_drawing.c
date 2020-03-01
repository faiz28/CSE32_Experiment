#include <graphics.h>

void plotLine(int x0,int y0,int x1,int y1)
{
    int dy=y1-y0;
    int dx=x1-x0;

    
    int y=y0,x=x0;

    if(dx>dy)
    {
        int p=2*dy-dx;
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
    else{
        int p=2*dx-dy;
        for(int y=y0;y<y1;y++)
        {
            putpixel(x,y,RED);
            if(p<0)
            {
                p+=2*dx;
            }
            else {
                p+=2*dx-2*dy;
                x++;
            }
        }
    }
    
}

int main() {
   int gd=DETECT, gm=DETECT;
   initgraph(&gd,&gm,"");
   setbkcolor(WHITE);
    plotLine(3, 30, 300, 550);
    delay(5000);
    closegraph();
    return 0;
}
