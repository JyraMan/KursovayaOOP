#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>
int score=0;
void clear();
void main()
{
system ("cls");
int b,a=DETECT;
initgraph(&a,&b,â€ â€œ);
struct tetris
{
int rno[100];
int score;
int rectl,rectu,rectr,rectd;
int sql,squ,sqr,sqd;
int ll,lu,lr,ld;
int boxl,boxu,boxr,boxd;
int l1l,l1u,l1r,l1d;
int l2l,l2u,l2r,l2d;
int block1l,block1u,block1r,block1d;
int block2l,block2u,block2r,block2d;
char ch;
}t;
int w,x,y,z;
t.score=-20;
t.rectl=179;t.rectu=20;t.rectr=461;t.rectd=461;
t.sql=300;t.squ=-20;t.sqr=340;t.sqd=20;
t.boxl=300;t.boxu=0;t.boxr=320;t.boxd=20;
t.l1l=300;t.l1u=0;t.l1r=320;t.l1d=80;
t.l2l=260;t.l2u=0;t.l2r=340;t.l2d=20;
t.block1l=300;t.block1u=0;t.block1r=340;t.block1d=80;
t.block2l=260;t.block2u=0;t.block2r=340;t.block2d=40;
/*********************************-*/
int i;
randomize();
int col;
/* Tetris*/
{ int j=280;
for(int t=1;t<=5;t++)
{
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-20;
for(i=0;i<=j;i+=20)
{
setfillstyle(1,0);
bar(100,i-40,120,i-20);
setfillstyle(1,col);
bar(100,i-20,120,i);
delay(10);
}}}
{col=random(14)+1;
for(i=0;i<=180;i+=20)
{
setfillstyle(1,0);
bar(80,i-40,100,i-20);
setfillstyle(1,col);
bar(80,i-20,100,i);
delay(10);
}}
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
{col=random(14)+1;
for(i=0;i<=180;i+=20)
{
setfillstyle(1,0);
bar(120,i-40,140,i-20);
setfillstyle(1,col);
bar(120,i-20,140,i);
delay(10);
}}
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
delay(500);
/* tEtris*/
{ int j=280;
for(int t=1;t<=5;t++)
{
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-20;
for(i=0;i<=j;i+=20)
{setfillstyle(1,0);
bar(160,i-40,180,i-20);
setfillstyle(1,col);
bar(160,i-20,180,i);
delay(10);
}}}
{ int j=300;
for(int t=1;t<=3;t++)
{
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-40;
for(i=0;i<=j;i+=20)
{setfillstyle(1,0);
bar(180,i-40,200,i-20);
setfillstyle(1,col);
bar(180,i-20,200,i);
delay(10);
}}}
delay(500);
/* teTris*/
{ int j=280;
for(int t=1;t<=5;t++)
{
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-20;
for(i=0;i<=j;i+=20)
{setfillstyle(1,0);
bar(240,i-40,260,i-20);
setfillstyle(1,col);
bar(240,i-20,260,i);
delay(10);
}}}
{col=random(14)+1;
for(i=0;i<=180;i+=20)
{
setfillstyle(1,0);
bar(220,i-40,240,i-20);
setfillstyle(1,col);
bar(220,i-20,240,i);
delay(10);
}
}
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
{col=random(14)+1;
for(i=0;i<=180;i+=20)
{setfillstyle(1,0);
bar(260,i-40,280,i-20);
setfillstyle(1,col);
bar(260,i-20,280,i);
delay(10);
}
}
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
delay(500);
/* tetRis*/
{ int j=280;
for(int t=1;t<=5;t++)
{
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-20;
for(i=0;i<=j;i+=20)
{setfillstyle(1,0);
bar(300,i-40,320,i-20);
setfillstyle(1,col);
bar(300,i-20,320,i);
delay(10);
}}}
{
col=random(14)+1;
for(i=0;i<=260;i+=20)
{setfillstyle(1,0);
bar(340,i-40,360,i-20);
setfillstyle(1,col);
bar(340,i-20,360,i);
delay(10);
}
}
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
{col=random(14)+1;
for(i=0;i<=240;i+=20)
{setfillstyle(1,0);
bar(320,i-40,340,i-20);
setfillstyle(1,col);
bar(320,i-20,340,i);
delay(10);
}
}
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
{ int j=240;
for(int t=1;t<=3;t++)
{
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-20;
for(i=0;i<=j;i+=20)
{setfillstyle(1,0);
bar(340,i-40,360,i-20);
setfillstyle(1,col);
bar(340,i-20,360,i);
delay(10);
}}}
{ int j=260;
for(int t=1;t<=2;t++)
{
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-40;
for(i=0;i<=j;i+=20)
{setfillstyle(1,0);
bar(320,i-40,340,i-20);
setfillstyle(1,col);
bar(320,i-20,340,i);
delay(10);
}}}
delay(500);
/* tetrIs*/
{ int j=280;
for(int t=1;t<=5;t++)
{
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-20;
for(i=0;i<=j;i+=20)
{setfillstyle(1,0);
bar(400,i-40,420,i-20);
setfillstyle(1,col);
bar(400,i-20,420,i);
delay(10);
}}}
{ int j=340;
for(int t=1;t<=2;t++)
{
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-80;
for(i=0;i<=j;i+=20)
{setfillstyle(1,0);
bar(380,i-40,400,i-20);
setfillstyle(1,col);
bar(380,i-20,400,i);
delay(10);
}}}
{ int j=340;
for(int t=1;t<=2;t++)
{setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-80;
for(i=0;i<=j;i+=20)
{setfillstyle(1,0);
bar(420,i-40,440,i-20);
setfillstyle(1,col);
bar(420,i-20,440,i);
delay(10);
}}}
delay(500);
/*tetriS*/
{col=random(14)+1;
for(i=0;i<=260;i+=20)
{setfillstyle(1,0);
bar(460,i-40,480,i-20);
setfillstyle(1,col);
bar(460,i-20,480,i);
delay(10);
}
}
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
{ int j=240;
for(int t=1;t<=3;t++)
{
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-20;
for(i=0;i<=j;i+=20)
{setfillstyle(1,0);
bar(460,i-40,480,i-20);
setfillstyle(1,col);
bar(460,i-20,480,i);
delay(10);
}}}
{ int j=300;
for(int t=1;t<=3;t++)
{
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-40;
for(i=0;i<=j;i+=20)
{setfillstyle(1,0);
bar(480,i-40,500,i-20);
setfillstyle(1,col);
bar(480,i-20,500,i);
delay(10);
}}}
{ int j=280;
for(int t=1;t<=3;t++)
{
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
col=random(14)+1;
j=j-20;
for(i=0;i<=j;i+=20)
{setfillstyle(1,0);
bar(500,i-40,520,i-20);
setfillstyle(1,col);
bar(500,i-20,520,i);
delay(10);
}}}
{col=random(14)+1;
for(i=0;i<=180;i+=20)
{setfillstyle(1,0);
bar(500,i-40,520,i-20);
setfillstyle(1,col);
bar(500,i-20,520,i);
delay(10);
}}
setcolor(0);
for(i=0;i<=660;i+=20)
{
line(0,i,800,i) ;
line(i,0,i,600);
}
delay(100);
settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
setcolor(1);
outtextxy(200,400,â€PRESS ANY KEY TO CONTINUEâ€);
char cover=std::cin.get();
cover+=1;
cleardevice();
/*â€”â€”â€”â€”â€”â€”â€”â€”â€”â€“ending of coverâ€”â€”â€”â€”â€”â€”â€”*/
/*â€”â€”â€”â€”â€”â€”â€”â€”starting of instructionsâ€”â€”â€”â€”â€”â€”â€”*/
setcolor(2);
settextstyle(TRIPLEX_FONT,0,5);
outtextxy(200,20,â€Instructionsâ€);
setcolor(3);
settextstyle(TRIPLEX_FONT,0,2);
outtextxy(0,80,â€Probably everyone knows how play tetris game as the rulesâ€);
outtextxy(0,110,â€of the tetris are known to everyone.Tetris Game is a puzzleâ€);
outtextxy(0,140,â€with the shapes each consisting of several squares,that areâ€);
outtextxy(0,170,â€falling down the well.When playing a tetris game,â€);
outtextxy(0,200,â€one moves them left and right,trying to arrange the shapesâ€);
outtextxy(0,230,â€in a line.When a line of squares makes a line from edge toâ€);
outtextxy(0,260,â€edge,it disappears and and all the pieces move down by a â€œ);
outtextxy(0,290,â€square.When the well is filled up, the player loses. Seemsâ€);
outtextxy(0,320,â€like it is quite easy to play tetris game,but â€œ);
outtextxy(0,350,â€as levels progress, you feel that playing tetris game may â€œ);
outtextxy(0,380,â€be a real challenge.Want to play Tetris Game?â€);
setcolor(1);
settextstyle(GOTHIC_FONT,0,3);
outtextxy(180,410,â€Press any key to continueâ€);
char ins=std::cin.get();
ins+=1;
/*â€”â€”â€”â€”â€”â€”â€”â€”â€”â€“ending of instructionsâ€”â€”â€”â€”â€”â€”â€”*/
/*â€”â€”â€”â€”â€”â€”â€”â€”â€”â€“starting of controlsâ€”â€”â€”â€”â€”â€”â€”*/
cleardevice();
setcolor(2);
settextstyle(TRIPLEX_FONT,0,5);
outtextxy(230,20,â€CONTROLSâ€);
setcolor(3);
settextstyle(TRIPLEX_FONT,0,2);
outtextxy(100,150,â€To Move Left â€“ Press Aâ€);
outtextxy(100,190,â€To Move Left â€“ Press Dâ€);
setcolor(1);
settextstyle(GOTHIC_FONT,0,3);
outtextxy(180,400,â€Press any key to continueâ€);
char ctrl=std::cin.get();
ctrl+=1;
/*â€”â€”â€”â€”â€”â€”â€”â€”â€”â€“ending of coverâ€”â€”â€”â€”â€”â€”â€”*/
/*â€”â€”â€”â€”â€”â€”â€”â€”â€”â€“starting of levelâ€”â€”â€”â€”â€”â€”â€”*/
cleardevice();
setcolor(2);
settextstyle(TRIPLEX_FONT,0,5);
outtextxy(200,20,â€NEW GAMEâ€);
setcolor(5);
settextstyle(TRIPLEX_FONT,0,3);
outtextxy(150,80,â€(Select Level of difficulty)â€);
setcolor(3);
settextstyle(TRIPLEX_FONT,0,2);
outtextxy(100,150,â€1. Easyâ€);
outtextxy(100,190,â€2. Mediumâ€);
outtextxy(100,230,â€3. Hardâ€);
outtextxy(70,270,â€Default â€“ Mediumâ€);
setcolor(1);
settextstyle(GOTHIC_FONT,0,4);
outtextxy(150,350,â€Enter the level of difficulty:â€);
int del;
char level=std::cin.get();
cleardevice();
/*â€”â€”â€”â€”â€”â€”â€”â€”â€”â€“ending of levelâ€”â€”â€”â€”â€”â€”â€”*/
/*â€”â€”â€”â€”â€”â€”â€“edit the no. of bricks fallingâ€”â€”â€”â€”â€”*/
int n=100;
/*â€”â€”â€”â€”â€”â€”â€“editing of bricks completeâ€”â€”â€”â€”â€”â€”-*/
{setcolor(2);
rectangle(t.rectl,t.rectu,t.rectr,t.rectd);
}
/*â€”â€”â€”â€”â€”â€”â€“generation of random nos.â€”â€”â€”â€”â€”â€”â€“*/
randomize();
for(int r=1;r<=n;r++)
{t.rno[r]=random(6); }
/*â€”â€”â€”â€”â€”â€“random nos. generation completeâ€”â€”â€”â€”â€”â€“*/
for(int main=1;main<=n;main++)
/*â€”â€”â€”â€”â€”â€”â€”â€”-initialisationâ€”â€”â€”â€”â€”â€”â€”â€”â€“*/
{ t.score=-20;
t.rectl=179;t.rectu=20;t.rectr=461;t.rectd=461;
t.sql=300;t.squ=-20;t.sqr=340;t.sqd=20;
t.boxl=300;t.boxu=0;t.boxr=320;t.boxd=20;
t.l1l=300;t.l1u=0;t.l1r=320;t.l1d=80;
t.l2l=260;t.l2u=0;t.l2r=340;t.l2d=20;
t.block1l=300;t.block1u=0;t.block1r=340;t.block1d=80;
t.block2l=260;t.block2u=0;t.block2r=340;t.block2d=40;
/*â€”â€”â€”â€”â€”â€”â€”â€”initialisation completeâ€”â€”â€”â€”â€”â€”*/
/*â€”â€”â€”â€“side display(display of next brick)â€”â€”â€”â€”â€”â€”-*/
setfillstyle(1,0);
bar(500,360,600,460);
setcolor(15);
rectangle(500,360,600,460);
switch(t.rno[main+1])
{
case 0:
setfillstyle(1,2);
bar(530,390,570,430);
setcolor(0);
line(510,410,590,410);
line(550,370,550,450);
break;
case 1:
setfillstyle(1,3);
bar(540,400,560,420);
break;
case 2:
setfillstyle(1,4);
bar(540,370,560,450);
setcolor(0);
line(510,390,590,390);
line(510,410,590,410);
line(510,430,590,430);
break;
case 3:
setfillstyle(1,5);
bar(510,400,590,420);
setcolor(0);
line(530,380,530,450);
line(550,380,550,450);
line(570,380,570,450);
break;
case 4:
setfillstyle(1,6);
bar(530,370,570,450);
setcolor(0);
line(510,390,590,390);
line(510,410,590,410);
line(510,430,590,430);
line(550,370,550,450);
break;
case 5:
setfillstyle(1,7);
bar(510,390,590,430);
setcolor(0);
line(530,380,530,450);
line(550,380,550,450);
line(570,380,570,450);
line(510,410,590,410);
break;
}
/*â€”â€”â€”â€”â€”â€”â€”â€”side display completeâ€”â€”â€”â€”â€”-*/
/*â€”â€”â€”â€”â€”â€”â€”â€”starting of main gameâ€”â€”â€”â€”â€”-*/
setfillstyle(1,2);
switch(t.rno[main])
{/*â€”â€”â€”â€”â€”â€”â€”â€”â€”square brickâ€”â€”â€”â€”â€”â€”â€”-*/
case 0: clear();
while(t.sqd!=460)
{
x=getpixel(t.sqr-25,t.sqd+5);
y=getpixel(t.sqr-5,t.sqd+5);
if(x!=0||y!=0)
break;
setfillstyle(1,0);
bar(t.sql,t.squ,t.sqr,t.sqd);
setfillstyle(1,2);
{bar(t.sql,t.squ+=20,t.sqr,t.sqd+=20);
}
setfillstyle(1,2);
if(kbhit())
{
int ch=std::cin.get();
if(ch==â€™aâ€™&& t.sql!=180)
{
x=getpixel(t.sqr-45,t.sqd-5);
y=getpixel(t.sqr-45,t.sqd-25);
if(x==0&&y==0)
{
setfillstyle(1,0);
bar(t.sql,t.squ,t.sqr,t.sqd);
setfillstyle(1,2);
bar(t.sql-=20,t.squ,t.sqr-=20,t.sqd);
sound(300);
delay(20);
nosound();
}
}
if(ch==â€™dâ€™&& t.sqr!=460)
{
x=getpixel(t.sqr+5,t.sqd-5);
y=getpixel(t.sqr+5,t.sqd-25);
if(x==0&&y==0)
{
setfillstyle(1,0);
bar(t.sql,t.squ,t.sqr,t.sqd);
setfillstyle(1,2);
bar(t.sql+=20,t.squ,t.sqr+=20,t.sqd);
sound(300);
delay(20);
nosound();
}} }
setcolor(0);
for(i=20;i<=440;i+=20)
line(180,i,460,i);
for(i=200;i<=440;i+=20)
line(i,0,i,460);
switch(level)
{
case 1:del=200;
break;
case 2:del=150;
break;
case 3:del=100;
break;
default:del=150;
}
delay(del);
}
clear();
break;
/*â€”â€”â€”â€”â€”â€”-small boxâ€”â€”â€”â€”â€”â€”â€”â€”â€“*/
case 1: clear();
while(t.boxd!=460)
{
x=getpixel(t.boxr-5,t.boxd+5);
if(x!=0)
break;
setfillstyle(1,0);
bar(t.boxl,t.boxu,t.boxr,t.boxd);
setfillstyle(1,3);
{bar(t.boxl,t.boxu+=20,t.boxr,t.boxd+=20);
}
setfillstyle(1,3);
if(kbhit())
{
int ch=std::cin.get();
if(ch==â€™aâ€™&& t.boxl!=180)
{
x=getpixel(t.boxr-25,t.boxd-5);
if(x==0)
{
setfillstyle(1,0);
bar(t.boxl,t.boxu,t.boxr,t.boxd);
setfillstyle(1,3);
bar(t.boxl-=20,t.boxu,t.boxr-=20,t.boxd);
sound(300);
delay(20);
nosound();
}
}
if(ch==â€™dâ€™&& t.boxr!=460)
{x=getpixel(t.boxr+5,t.boxd-5);
if(x==0)
{
setfillstyle(1,0);
bar(t.boxl,t.boxu,t.boxr,t.boxd);
setfillstyle(1,3);
bar(t.boxl+=20,t.boxu,t.boxr+=20,t.boxd);
sound(300);
delay(20);
nosound();
}} }
setcolor(0);
for(i=20;i<=440;i+=20)
line(180,i,460,i);
for(i=200;i<=440;i+=20)
line(i,0,i,460);
switch(level)
{
case 1:del=200;
break;
case 2:del=150;
break;
case 3:del=100;
break;
default:del=150;
}
delay(del);
}
clear();
break;
/*â€”â€”â€”â€”â€”â€”vertical lineâ€”â€”â€”â€”â€”â€”â€“*/
case 2: clear();
while(t.l1d!=460)
{
x=getpixel(t.l1r-5,t.l1d+5);
if(x!=0)
break;
setfillstyle(1,0);
bar(t.l1l,t.l1u,t.l1r,t.l1d)
setfillstyle(1,4);
{bar(t.l1l,t.l1u+=20,t.l1r,t.l1d+=20);
}
setfillstyle(1,4);
if(kbhit())
{
int ch=std::cin.get();
if(ch==â€™aâ€™&& t.l1l!=180)
{
x=getpixel(t.l1r-25,t.l1d-5);
y=getpixel(t.l1r-25,t.l1d-25);
z=getpixel(t.l1r-25,t.l1d-45);
w=getpixel(t.l1r-25,t.l1d-65);
if(x==0&&y==0&&z==0&&w==0)
{
setfillstyle(1,0);
bar(t.l1l,t.l1u,t.l1r,t.l1d)
setfillstyle(1,4);
bar(t.l1l-=20,t.l1u,t.l1r-=20,t.l1d);
sound(300);
delay(20);
nosound();
}}
if(ch==â€™dâ€™&& t.l1r!=460)
{
x=getpixel(t.l1r+5,t.l1d-5);
y=getpixel(t.l1r+5,t.l1d-25);
z=getpixel(t.l1r+5,t.l1d-45);
w=getpixel(t.l1r+5,t.l1d-65);
if(x==0&&y==0&&z==0&&w==0)
{
setfillstyle(1,0);
bar(t.l1l,t.l1u,t.l1r,t.l1d);
setfillstyle(1,4);
bar(t.l1l+=20,t.l1u,t.l1r+=20,t.l1d);
sound(300);
delay(20);
nosound();
}} }
setcolor(0);
for(i=20;i<=440;i+=20)
line(180,i,460,i);
for(i=200;i<=440;i+=20)
line(i,0,i,460);
switch(level)
{
case 1:del=200;
break;
case 2:del=150;
break;
case 3:del=100;
break;
default:del=150;
}
delay(del);
}
clear();
break;
/*â€”â€”â€”â€”â€”â€”â€”-horizontal lineâ€”â€”â€”â€”-*/
case 3: clear();
while(t.l2d!=460)
{
w=getpixel(t.l2r-5,t.l2d+5);
x=getpixel(t.l2r-25,t.l2d+5);
y=getpixel(t.l2r-45,t.l2d+5);
z=getpixel(t.l2r-65,t.l2d+5);
if(w!=0||y!=0||x!=0||z!=0)
break;
setfillstyle(1,0);
bar(t.l2l,t.l2u,t.l2r,t.l2d)
setfillstyle(1,5);
{bar(t.l2l,t.l2u+=20,t.l2r,t.l2d+=20);
}
setfillstyle(1,5);
if(kbhit())
{
int ch=std::cin.get();
if(ch==â€™aâ€™&& t.l2l!=180)
{
x=getpixel(t.l2r-85,t.l2d-5);
if(x==0)
{
setfillstyle(1,0);
bar(t.l2l,t.l2u,t.l2r,t.l2d)
setfillstyle(1,5);
bar(t.l2l-=20,t.l2u,t.l2r-=20,t.l2d);
sound(300);
delay(20);
nosound();
}}
if(ch==â€™dâ€™&& t.l2r!=460)
{
x=getpixel(t.l2r+5,t.l2d-5);
if(x==0)
{
setfillstyle(1,0);
bar(t.l2l,t.l2u,t.l2r,t.l2d);
setfillstyle(1,5);
bar(t.l2l+=20,t.l2u,t.l2r+=20,t.l2d);
sound(300);
delay(20);
nosound();
}} }
setcolor(0);
for(i=20;i<=440;i+=20)
line(180,i,460,i);
for(i=200;i<=440;i+=20)
line(i,0,i,460);
switch(level)
{
case 1:del=200;
break;
case 2:del=150;
break;
case 3:del=100;
break;
default:del=150;
}
delay(del);
}
clear();
break;
/*â€”â€”â€”â€”â€”â€”vertical blockâ€”â€”â€”â€”â€”â€”-*/
case 4: clear();
while(t.block1d!=460)
{
x=getpixel(t.block1r-5,t.block1d+5);
y=getpixel(t.block1r-25,t.block1d+5);
if(x!=0||y!=0)
break;
setfillstyle(1,0);
bar(t.block1l,t.block1u,t.block1r,t.block1d);
setfillstyle(1,6);
{bar(t.block1l,t.block1u+=20,t.block1r,t.block1d+=20);
}
setfillstyle(1,6);
if(kbhit())
{
int ch=std::cin.get();
if(ch==â€™aâ€™&& t.block1l!=180)
{
x=getpixel(t.block1r-45,t.block1d-5);
y=getpixel(t.block1r-45,t.block1d-25);
z=getpixel(t.block1r-45,t.block1d-45);
w=getpixel(t.block1r-45,t.block1d-65);
if(x==0&&y==0&&z==0&&w==0)
{
setfillstyle(1,0);
bar(t.block1l,t.block1u,t.block1r,t.block1d);
setfillstyle(1,6);
bar(t.block1l-=20,t.block1u,t.block1r-=20,t.block1d);
sound(300);
delay(20);
nosound();
}
}
if(ch==â€™dâ€™&& t.block1r!=460)
{
x=getpixel(t.block1r+5,t.block1d-5);
y=getpixel(t.block1r+5,t.block1d-25);
z=getpixel(t.block1r+5,t.block1d-45);
w=getpixel(t.block1r+5,t.block1d-65);
if(x==0&&y==0&&z==0&&w==0)
{
setfillstyle(1,0);
bar(t.block1l,t.block1u,t.block1r,t.block1d)
setfillstyle(1,6);
bar(t.block1l+=20,t.block1u,t.block1r+=20,t.block1d);
sound(300);
delay(20);
nosound();
}} }
setcolor(0);
for(i=20;i<=440;i+=20)
line(180,i,460,i);
for(i=200;i<=440;i+=20)
line(i,0,i,460);
switch(level)
{
case 1:del=200;
break;
case 2:del=150;
break;
case 3:del=100;
break;
default:del=150;
}
delay(del);
}
clear();
break;
/*â€”â€”â€”â€”â€”â€”â€”horizontal blockâ€”â€”â€”â€“*/
case 5: clear();
while(t.block2d!=460)
{
w=getpixel(t.block2r-5,t.block2d+5);
x=getpixel(t.block2r-25,t.block2d+5);
y=getpixel(t.block2r-45,t.block2d+5);
z=getpixel(t.block2r-65,t.block2d+5);
if(w!=0||y!=0||x!=0||z!=0)
break;
setfillstyle(1,0);
bar(t.block2l,t.block2u,t.block2r,t.block2d);
setfillstyle(1,7);
{bar(t.block2l,t.block2u+=20,t.block2r,t.block2d+=20);
}
setfillstyle(1,7);
if(kbhit())
{
int ch=std::cin.get();
if(ch==â€™aâ€™&& t.block2l!=180)
{
x=getpixel(t.block2r-85,t.block2d-5);
y=getpixel(t.block2r-85,t.block2d-25);
if(x==0&&y==0)
{
setfillstyle(1,0);
bar(t.block2l,t.block2u,t.block2r,t.block2d);
setfillstyle(1,7);
bar(t.block2l-=20,t.block2u,t.block2r-=20,t.block2d);
sound(300);
delay(20);
nosound();
}
}
if(ch==â€™dâ€™&& t.block2r!=460)
{x=getpixel(t.block2r+5,t.block2d-5);
y=getpixel(t.block2r+5,t.block2d-25);
if(x==0&&y==0)
{
setfillstyle(1,0);
bar(t.block2l,t.block2u,t.block2r,t.block2d);
setfillstyle(1,7);
bar(t.block2l+=20,t.block2u,t.block2r+=20,t.block2d);
sound(300);
delay(20);
nosound();
}} }
setcolor(0);
for(i=20;i<=440;i+=20)
line(180,i,460,i);
for(i=200;i<=440;i+=20)
line(i,0,i,460);
switch(level)
{
case 1:del=200;
break;
case 2:del=150;
break;
case 3:del=100;
break;
default:del=150;
}
delay(del);
}
clear();
/*============================game complete======================*/
}}
delay(2000);
/* cleardevice();
setcolor(3);
settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
outtextxy(200,140,â€YOUR SCOREâ€);
cout<<â€œnnnnnnnnnnnnttttâ€<<score; */
cleardevice();
setcolor(1);
settextstyle(GOTHIC_FONT,0,5);
for(int over=1;over<=500;over++)
{cleardevice();
outtextxy(200,over,â€Game Overâ€);
delay(30);
}
std::cin.get();
}
void clear()
{
score+=10;
int a[14][22],i,j,k,l,res=1;
for(i=0;i<14;i++)
{
for(j=0;j<22;j++)
{
a[i][j]=getpixel(185+(i*20),25+(j*20));
}
}
for(j=0;j<22;j++)
{
for(i=0;i<14;i++)
{
if(a[i][j]!=0)
res=0;
else
{
res=1;
break;
}
}
if(res==0)
{
score+=200;
for(k=0;k<14;k++)
{
setfillstyle(1,0);
bar(180+(k*20),20+(j*20),200+k*20,40+(j*20));
delay(50);
}
delay(100);
for(k=0;k<14;k++)
{
for(l=j-1;l>=0;lâ€“)
{
setfillstyle(1,0);
bar(180+(k*20),20+(l*20),200+(k*20),40+(l*20));
setfillstyle(1,a[k][l]);
bar(180+(k*20),40+(l*20),200+(k*20),60+(l*20));
}}
}
}
}