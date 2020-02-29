// C-program for circle drawing 
// using Bresenham’s Algorithm 
// in computer-graphics 
#include <stdio.h> 

#include <graphics.h> 

// Function to put pixels 
// at subsequence points 
void drawCircle(int xc, int yc, int x, int y) 
{ 
	putpixel(xc+x, yc+y, RED); 
	putpixel(xc-x, yc+y, RED); 
	putpixel(xc+x, yc-y, RED); 
	putpixel(xc-x, yc-y, RED); 
	putpixel(xc+y, yc+x, RED); 
	putpixel(xc-y, yc+x, RED); 
	putpixel(xc+y, yc-x, RED); 
	putpixel(xc-y, yc-x, RED); 
} 


void circleBres(int xc, int yc, int r) 
{ 
	int x = r, y = 0; 
	int p=1-r;
	drawCircle(xc, yc, x, y); 
	while (x>y) 
	{ 
        y++;

		if (p<= 0) 
		{ 
            p+=2*y+1;
		} 
		else
        {
            x--;
            p+=2*y-2*x+1;
        }


		drawCircle(xc, yc, x, y); 
		delay(50); 
	} 
} 


int main() 
{ 
	int xc = 150, yc = 150, r2 = 30; 
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, ""); 
	circleBres(xc, yc, r2); 
    closegraph(); 
	return 0; 
} 
