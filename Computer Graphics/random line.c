#include<graphics.h>

int main()
{
    int gd=DETECT,gm=DETECT;
    initgraph(&gd,&gm,"");

    int n=0;
    setbkcolor(WHITE);
    while (1)
    {
        n++;
        setcolor(rand()%40);
        line(rand()%100,rand()%500,rand()%300,rand()%400);
        if(n>25)
        {
            n=0;
            delay(1000);
            cleardevice();

        }
    }
    
}