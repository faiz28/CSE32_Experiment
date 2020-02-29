#include<graphics.h>
#include<stdio.h>

double xmin,xmax,ymin,ymax;

int INSIDE=0,LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;
int computeCode(double x,double y)
{
    int code=INSIDE;
    if(x<xmin) code|=LEFT;
    if(x>xmax) code|=RIGHT;
    if(y<ymin) code|=BOTTOM;
    if(y>ymax) code|=TOP;

    return code;
}

void cohenSuterlandLineCliping(double x1,double y1,double x2,double y2)
{
    int code1=computeCode(x1,y1);
    int code2=computeCode(x2,y2);

    int accept=0;
    while (1)
    {
        if(code1==0 && code2==0) 
        {
            accept=1;
            break;
        }
        else if(code1 & code2)
        {
            break;
        }
        else{
            int code_out;
            double x,y;

            if(code_out!=0) code_out=code1;
            else code_out=code2;

            if(code_out & TOP)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1); 
                y=ymax;
            }
            else if(code_out & BOTTOM)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1); 
                y=ymin;
            }
            else if(code_out & RIGHT)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1); 
                x=xmax;
            }
            else if(code_out & LEFT){
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1); 
                x=xmin;
            }

            if(code_out==code1)
            {
                x1=x;
                y1=y;
                code1=computeCode(x1,y1);
            }
            else{
                x2=x;
                y2=y;
                code2=computeCode(x2,y2);
            }
        }


    }

    if(accept==1)
    {
        line(x1,y1,x2,y2);
    }
    else 
    {
        printf("receted\n");
    }
    
}
int main()
{
    int gd=DETECT,gm=DETECT;
    initgraph(&gd,&gm,"");

    setbkcolor(WHITE);


    setcolor(BLACK);
    xmin=100,xmax=500,ymin=10,ymax=300;
    rectangle(xmin,ymin,xmax,ymax);
    double x0=50,y0=60,x1=600,y1=90;
    cohenSuterlandLineCliping(x0,y0,x1,y1);

    delay(1000);
    closegraph();
}