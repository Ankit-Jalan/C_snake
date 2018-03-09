#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
union REGS in,out;
void show_mouse()
{
	in.x.ax=1;
	int86(0x33,&in,&out);
}
void hide_mouse()
{
	in.x.ax=2;
	int86(0x33,&in,&out);
}
void get_mouse_pos(int *x,int *y,int *i)
{
	in.x.ax=3;
	int86(0x33,&in,&out);
	*x=out.x.cx;
	*y=out.x.dx;
	*i=out.x.bx&1;
}
void main()
{
int gd=DETECT,gmode;
int midX,midY,p,q,o=0;
int i,x,y,dsx,dsy,x1,y1,x2,y2,ch=2,m,n,p1,p2;
initgraph(&gd,&gmode,"");
midX=getmaxx()/2;
midY=getmaxy()/2;
x1=midX;
y1=midY;
x2=x1+20;
y2=y1;
setbkcolor(2);
outtextxy(60,20,"Press left mouse and drag in the direction in which you want to move");
outtextxy(60,60,"After game start press any key to exit!!!");
delay(3000);
p1=240;
p2=320;
show_mouse();
while(!kbhit())
{
	setcolor(4);
	get_mouse_pos(&x,&y,&i);
	delay(330);
	get_mouse_pos(&m,&n,&i);
   if(i==1)
   {
     dsx = x - m;
     dsy = y - n;
     if(dsx>30&&ch!=2)
     {  y1=y2;
	x1=x2;
	x2=x1-20;
	line(x1,y1-1,x2,y2-1);
	line(x1,y1,x2,y2);
	line(x1,y1+1,x2,y2+1);
	delay(40);
	cleardevice();
     ch=1;
     }
     else if(dsx<-30&&ch!=1)
     {  y1=y2;
	x1=x2;
	x2=x1+20;
	line(x1,y1,x2,y2);
	line(x1,y1-1,x2,y2-1);
	line(x1,y1+1,x2,y2+1);
	delay(40);
	cleardevice();
     ch=2;}
     else if (dsy>30&&ch!=4)
     { x1=x2;
       y1=y2;
       y2=y1-20;
	line(x1,y1,x2,y2);
	line(x1-1,y1,x2-1,y2);
	line(x1+1,y1,x2+1,y2);
	delay(40);
	cleardevice();
      ch=3;
     }
     else if (dsy<-30&&ch!=3)
     { x1=x2;
       y1=y2;
       y2=y1+20;
     line(x1,y1,x2,y2);
     line(x1-1,y1,x2-1,y2);
     line(x1+1,y1,x2+1,y2);
     delay(40);
     cleardevice();
      ch=4;
     }
   }
 switch(ch)
 {
 case 1:if(x2<10)
	{
	  x2=580;
	  x1=600;
	}
	x1=x1-3;
	x2=x2-3;
	line(x1,y1-1,x2,y2-1);
	line(x1,y1,x2,y2);
	line(x1,y1+1,x2,y2+1);
      delay(30);
	cleardevice();
	break;
 case 2:if(x2>600)
	{
	x2= 40;
	x1=20;
	}
	x1=x1+3;
	x2=x2+3;
	line(x1,y1,x2,y2);
	line(x1,y1-1,x2,y2-1);
	line(x1,y1+1,x2,y2+1);
	delay(30);
	cleardevice();
	break;
 case 3:if(y2<10)
	{
	y2=430;
	y1=450;
	}
	y1=y1-3;
	y2=y2-3;
	line(x1,y1,x2,y2);
	line(x1-1,y1,x2-1,y2);
	line(x1+1,y1,x2+1,y2);
	delay(30);
	cleardevice();
	break;
 case 4:if(y2>450)
	{
	y2=30;
	y1=10;
	}

	y1=y1+3;
	y2=y2+3;
	line(x1,y1,x2,y2);
	line(x1-1,y1,x2-1,y2);
	line(x1+1,y1,x2+1,y2);
	delay(30);
	cleardevice();
	break;
}
 setcolor(15);
 /*putpixel(p1,p2,0);
 putpixel(p1+1,p2,0);
 putpixel(p1,p2+1,0);
 putpixel(p1+1,p2+1,0);*/
 circle(p1,p2,2);
 delay(200);
// if((p1==x2&&p2==y2)||(p1+1==x2&&p2==y2)||(p1-1==x2&&p2==y2)||(p1+1==x2&&p2+1==y2)||(p1+2==x2&&p2+2==y2)||(p1+2==x2&&p2==y2)||(p1-2==x2&&p2==y2)||(p1+1==x2&&p2+2==y2))
 p=p1-x2;
 q=p2-y2;
 if(p<4&&q<4&&p>-4&&q>-4)
 {o++;
  printf("Score : %d",o);
  delay(2000);
 while(p1>0&&p2>0)
 {
 p1=random(580);
p2=random(430);
if(p1>150&&p2>100)
break;
}
 }

 }
getch();

closegraph();

}