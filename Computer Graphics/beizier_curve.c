#include <stdio.h>
#include <graphics.h>
#include <math.h>

double power(double a,double b)
{
    double result=1;
    for(int i=0;i<b;i++)
    {
        result*=a;
    }
    return result;
}

void beizier(int x[],int y[])
{
    for(double i=0;i<1.0;i+=0.00005)
    {
        double x1=x[0]*power(1-i,3)+x[1]*3*power(1-i,2)*i+x[2]*3*power(1-i,1)*i*i+x[3]*power(i,3);
        double y1=y[0]*power(1-i,3)+y[1]*3*power(1-i,2)*i+y[2]*3*power(1-i,1)*i*i+y[3]*power(i,3);
        putpixel(x1,y1,RED);
    }

    for(int i=0;i<4;i++)
        putpixel(x[0],y[0],BLACK);

    delay(5000);
}

int main()
{
    int gd=DETECT,gm=DETECT;
    initgraph(&gd,&gm,"");

    setbkcolor(WHITE);

    int x[10],y[10];

    x[0]=0,y[0]=10;
    x[1]=100,y[1]=200;
    x[2]=400,y[2]=400;
    x[3]=600,y[3]=100;

    beizier(x,y);
}