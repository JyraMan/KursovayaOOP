#include <iostream.h>
class Box 
{ 
  private: 
    int map[23][12];// Screen coordinates, recording points with squares, is also the game interface  
    int hotpoint[2];// The current active point against which all graphics are drawn  
    int top;// Current highest position  
    int point;// score  
    int level;// level  
    int ID;// Of the current active graph ID No.  
    int colorID;// The color of the figure ID .  
  public: 
    Box()// Initialize the  
    { 
      int i,j; 
      for(i=0;i<23;i++) 
        for(j=0;j<12;j++) 
          map[i][j]=0; 
      hotpoint[0]=0; 
      hotpoint[1]=5; 
      point=0; 
      level=1; 
      top=99; 
      ID=0; 
    } 
    void SetColor(int color);// color  
    void DrawMap();// Draw the big interface of the game  
    bool Judge(int x,int y);// Determines whether the current position can draw a graph  
    void Welcome();// The welcome screen  
    void DrawBox(int x,int y,int num);// Drawing graphics  
    void Redraw(int x,int y,int num);// Erase the graphics  
    void Run();// run  
    void Turn();// Turn the square  
    void UpdataMap();// Update the picture  
    void Pause();// suspended  
}; 

#define A1 0//A Stands for long bar, B For the square, C for L Type, D For the type of lightning  
#define A2 1 
 
 
#define B 2 
 
 
#define C11 3 
#define C12 4 
#define C13 5 
#define C14 6 
 
 
#define C21 7 
#define C22 8 
#define C23 9 
#define C24 10 
 
 
#define D11 11 
#define D12 12 
 
 
#define D21 13 
#define D22 14 
 
 
void SetPos(int i,int j)// Set cursor position  
{ 
COORD pos={i,j}; 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
} 
 
 
const int sharp[15][8]= 
{ 
{0,0,1,0,2,0,3,0},{0,0,0,1,0,2,0,3}, 
{0,0,1,0,0,1,1,1}, 
{0,0,1,0,1,1,1,2},{0,1,1,1,2,0,2,1},{0,0,0,1,0,2,1,2},{0,0,0,1,1,0,2,0}, 
{1,0,1,1,1,2,0,2},{0,0,0,1,1,1,2,1},{0,0,0,1,0,2,1,0},{0,0,1,0,2,0,2,1}, 
{0,0,0,1,1,1,1,2},{0,1,1,0,1,1,2,0}, 
{0,1,0,2,1,0,1,1},{0,0,1,0,1,1,2,1} 
};// The coordinates of the shape points are first vertical and then horizontal  
 
 
const int high[15]={4,1,2,2,3,2,3,2,3,2,3,2,3,2,3};// This array is used to hold the height of each shape, corresponding to the coordinates above  

void Box::SetColor(int colorID) 
{ 
  int n_color; 
  switch(colorID) 
  { 
    case 0: n_color = 0x08;break; 
    case 1: n_color = 0x0C;break; 
    case 2: n_color = 0x0D;break; 
    case 3: n_color = 0x0E;break; 
    case 4: n_color = 0x0A;break; 
  } 
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n_color); 
} 
void Box::DrawMap()// Draw the interface  
{ 
  int i; 
 
  SetColor(0);// Interface color  
 
  for(i=0;i<14;i++) 
  { 
     SetPos(i*2,0); 
     cout<<" s "; 
  } 
  for(i=1;i<=24;i++) 
  { 
    SetPos(0,i); 
    cout<<" s "; 
    SetPos(13*2,i); 
    cout<<" s "; 
  } 
  for(i=0;i<14;i++) 
  { 
     SetPos(i*2,24); 
     cout<<" s "; 
  } 
   
  i=15; 
  for(i=15;i<=25;i++) 
  { 
     SetPos(i*2,0); 
     cout<<" s "; 
  } 
  for(i=1;i<=8;i++) 
  { 
    SetPos(15*2,i); 
    cout<<" s "; 
    SetPos(25*2,i); 
    cout<<" s "; 
  } 
  for(i=15;i<=25;i++) 
  { 
     SetPos(i*2,9); 
     cout<<" s "; 
  } 
 
  SetPos(16*2,16); 
  cout<<" Tetris "; 
  SetPos(16*2,17); 
  cout<<" Score: "<<point; 
  SetPos(16*2,18); 
  cout<<" Levels: "<<level; 
} 
 
void Box::DrawBox(int x,int y,int num)// Drawing graphics  
{ 
   int i; 
   int nx,ny; 
   if (num<2)SetColor(1);//0 , 1 Is long  
   else if(num<3) SetColor(2);//2  square  
   else if(num<11) SetColor(3);//3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 
   else SetColor(4); 
   for(i=0;i<4;i++) 
  {  
    nx=x+sharp[num][i*2]; 
    ny=y+sharp[num][i*2+1]; 
    SetPos((ny+1)*2,nx+1);// using sharp Array relative to point x,y Draw the shape  
    //SetColor(i+1); 
    cout<<" s "; 
  } 
} 
 
void Box::Redraw(int x,int y,int num)// Erase graphics, same as above  
{ 
   int i; 
   int nx,ny; 
   for(i=0;i<4;i++) 
  {  
    nx=x+sharp[num][i*2]; 
    ny=y+sharp[num][i*2+1]; 
    SetPos((ny+1)*2,nx+1); 
    cout<<" "; 
  } 
} 
 
void Box::Turn()// Turn the graph, pure that ID "  
{ 
  switch(ID) 
  { 
    case A1: ID=A2; break; 
    case A2: ID=A1; break; 
 
    case B: ID=B; break; 
 
    case C11: ID=C12; break; 
    case C12: ID=C13; break; 
    case C13: ID=C14; break; 
    case C14: ID=C11; break; 
 
    case C21: ID=C22; break; 
    case C22: ID=C23; break; 
    case C23: ID=C24; break; 
    case C24: ID=C21; break; 
     
    case D11: ID=D12; break; 
    case D12: ID=D11; break; 
 
    case D21: ID=D22; break; 
    case D22: ID=D21; break; 
  } 
 
} 
 
void Box::Welcome()// The welcome screen  
{ 
  char x; 
  while(1) 
  { 
   system("cls"); 
   cout<<" S s s s s s s s s s s s s s s s s s s "<<endl; 
   cout<<" s      Tetris console edition      s "<<endl; 
   cout<<" S s s s s s s s s s s s s s s s s s s "<<endl; 
   cout<<" s    A,D Or so mobile  S Accelerated down      s "<<endl; 
   cout<<" s    W  Turn the square   P Pause the game      s "<<endl; 
   cout<<" s       Q Quit the game         s "<<endl; 
   cout<<" S s s s s s s s s s s s s s s s s s s "<<endl; 
   cout<<" s                   s "<<endl; 
   cout<<" s      According to the 1-9 Select the level!!       s "<<endl; 
   cout<<" s                   s "<<endl; 
   cout<<" s                   s "<<endl; 
   cout<<" S s s s s s s s s s s s s s s s s s s "<<endl; 
   SetPos(16,9); 
   x=getch(); 
   if(x<='9'&&x>='1')// Set level  
   { 
     level=x-'0'; 
     break; 
   } 
  } 
} 
 
void Box::UpdataMap()// Update screen (key)  
{ 
   int clear; 
   int i,j,k; 
   int nx,ny; 
   int flag; 
   for(i=0;i<4;i++)// update map Array information  
   {  
    nx=hotpoint[0]+sharp[ID][i*2]; 
    ny=hotpoint[1]+sharp[ID][i*2+1]; 
    map[nx][ny]=1; 
   } 
   if(hotpoint[0]<top)// If the hot spot is higher than the vertex, the vertex is updated , Here, 0 It's going to be vertical  
     top=hotpoint[0]; 
   clear=0;// The number of cells eliminated  
   for(i=hotpoint[0];i<hotpoint[0]+high[ID];i++) 
   { 
     flag=0; 
     for(j=0;j<12;j++)// Checks to see if the row can be eliminated  
     { 
       if(map[i][j]==0)// Represents a space that cannot be eliminated  
       { 
         flag=1;//1 Indicates that it cannot be eliminated  
         break; 
       } 
     } 
     if(flag==0)// Can eliminate  
     { 
       for(k=i;k>=top;k--)// Move down all points from the current position 1 line  
       { 
         if(k==0)// Highest point special treatment  
           for(j=0;j<12;j++) 
           { 
             map[k][j]=0; 
             SetPos((j+1)*2,k+1); 
             cout<<" "; 
           } 
         else 
         { 
           for(j=0;j<12;j++) 
           { 
             map[k][j]=map[k-1][j]; 
             SetPos((j+1)*2,k+1); 
             if(map[k][j]==0) 
              cout<<" "; 
             else 
              cout<<" s "; 
           } 
         } 
       } 
       top++;// Remove successfully, the highest point moves down  
       clear++; 
       point+=clear*10*level; 
     } 
   } 
   SetColor(0); 
   SetPos(16*2,17); 
    cout<<" Score: "<<point; 
} 
 
void Box::Run()// Run the game  
{ 
  int i=0; 
  char x; 
  int Count;// counter  
  int nextID; 
  int temp; 
  srand((int)time(0));// Set the starting point of the random number to time ( 0 ) : No seconds  
  ID=rand()%15;// Randomly generated ID And the lower 1 a ID 
  nextID=rand()%15;// And just for the sake of convenience, it turns out that every shape is not equally likely  
  DrawBox(hotpoint[0],hotpoint[1],ID);// Drawing graphics  
  DrawBox(3,17,nextID); 
  Count=1000-level*100;// The level determines the count Count Control time, to control the speed of the fall  
  while(1) 
  { 
    if(i>=Count) 
    { 
      i=0;// Counter clearing  
      if(Judge(hotpoint[0]+1,hotpoint[1]))// If the next position is not valid (bottom)  
      { 
         UpdataMap();// Update the picture  
         ID=nextID;// Generate new ID Wait with the original ID Replace with the current ID 
         hotpoint[0]=0;// Hot update  
         hotpoint[1]=5; 
         Redraw(3,17,nextID); 
         nextID=rand()%15; 
         DrawBox(hotpoint[0],hotpoint[1],ID); 
         DrawBox(3,17,nextID); 
         if(Judge(hotpoint[0],hotpoint[1]))// Unable to draw start graphics, game over  
         { 
           //getch(); 
           system("cls"); 
           SetPos(25,15); 
           cout<<" Game over!! The final score is: "<<point<<endl; 
           system("pause");// It is printed on the command line 1 Rows are like" Press  any  key  to  exit "  
           exit(0);// Close all files, exit the executing program, and return 0 Stands for normal end  
         } 
      } 
      else 
      { 
        Redraw(hotpoint[0],hotpoint[1],ID);// There's no bottom. The square moves down 1 position  
        hotpoint[0]++;// Hot down  
        DrawBox(hotpoint[0],hotpoint[1],ID); 
      } 
    } 
    if(kbhit())// Read keyboard information  
    { 
      x=getch(); 
      if(x=='a'||x=='A')// Shift to the left  
      { 
         if(Judge(hotpoint[0],hotpoint[1]-1)==0) 
         { 
           Redraw(hotpoint[0],hotpoint[1],ID); 
           hotpoint[1]-=1; 
           DrawBox(hotpoint[0],hotpoint[1],ID); 
         } 
      } 
      if(x=='d'||x=='D')// Moves to the right  
      { 
         if(Judge(hotpoint[0],hotpoint[1]+1)==0) 
         { 
           Redraw(hotpoint[0],hotpoint[1],ID); 
           hotpoint[1]+=1; 
           DrawBox(hotpoint[0],hotpoint[1],ID); 
         } 
      } 
      if(x=='s'||x=='S')// Accelerate downward!! You can improve it here, you can improve the acceleration. to +3 After that, it will appear BUG And the last ones don't accelerate  
      { 
         if(Judge(hotpoint[0]+3,hotpoint[1])==0) 
         { 
           Redraw(hotpoint[0],hotpoint[1],ID); 
           hotpoint[0]+=1; 
           DrawBox(hotpoint[0],hotpoint[1],ID); 
         } 
      } 
      if(x=='w'||x=='W')// Turn the square  
      { 
        temp=ID; 
        Turn(); 
        if(!Judge(hotpoint[0],hotpoint[1])) 
         { 
           Redraw(hotpoint[0],hotpoint[1],temp); 
           DrawBox(hotpoint[0],hotpoint[1],ID); 
         } 
        else 
          ID=temp; 
      } 
      if(x=='p'||x=='P') 
      { 
        //getch(); 
        //system("cls"); 
        Pause(); 
      } 
      if(x=='q'||x=='Q') 
      { 
        system("cls"); 
        SetPos(25,15); 
        cout<<" Game over!! The final score is: "<<point<<endl; 
        system("pause"); 
        exit(0); 
      } 
      while(kbhit())// Read the rest of the keyboard information  
        getch(); 
    } 
    Sleep(1);// Waiting for the 1 ms  
    i++;// Counter to add 1 
  } 
} 
 
int Box::Judge(int x,int y)// Determines whether a square can currently be drawn  
{ 
  int i; 
  int nx,ny; 
  for(i=0;i<4;i++) 
  {  
    nx=x+sharp[ID][i*2]; 
    ny=y+sharp[ID][i*2+1]; 
    if(nx<0||nx>=23||ny<0||ny>=12||map[nx][ny]==1)// No, go back 1 
      return 1; 
  } 
  return 0; 
} 
void Box::Pause() 
{ 
  system("cls"); 
  while(1) 
  {   
    SetPos(30,13); 
    cout<<" Pause the wait. Coffee time ^-^"<<endl; 
    if(getch()=='p'||getch()=='P') 
      break; 
  } 
  SetPos(30,13); 
  cout<<"              "<<endl; 
  DrawMap(); 
  int i ,j; 
  for(i=0;i<23;i++) 
    for(j=0;j<12;j++) 
      if(map[i][j]==1) 
      {   
        SetPos((j+1)*2,i+1); 
        cout<<" s "; 
      } 
} 

void main()// The main function  
{ 
  Box game; 
  game.Welcome(); 
  system("cls"); 
  game.DrawMap(); 
  game.Run(); 
} 
