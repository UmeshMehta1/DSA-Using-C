#include<graphics.h>
#include<conio.h>
void drawball(int x,int y,int r,int c)
{
   int i;
   setcolor(c);
   for(i=0;i<r;i++)
     circle(x,y,i);
}
void main()
{
   int gd=DETECT,gm;
   int i;
   initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
   cleardevice();
   setcolor(RED);
   setbkcolor(BLACK);
   for(i=0;i<getmaxx();i=i+5)
   {
      drawball(i,300,25,RED);
      delay(50);
      drawball(i,300,25,getbkcolor());
   }
   getch();
   closegraph();
}