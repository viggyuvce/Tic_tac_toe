#include<stdio.h>
#include<stdlib.h>

struct player
{
 char name[20];
 char piece;
 int value;
};

typedef struct player player;
int board[3][3],moves=0;
player p1,p2;
void createboard()
{
 int i,j;
 for(i=0;i<3;++i)
  for(j=0;j<3;++j)
   board[i][j]=0;
}

void toss()
{
 int n;
 srand(time(NULL));
 n=rand();
 if(n%3==0)
 {
  printf("\n%s has won and he is assigned the value x",p1.name);
  p1.piece='x';
  p2.piece='o';
 }
 else
 {
  printf("\n%s has won the toss and he is assigned the value x",p2.name);
  p1.piece='o';
  p2.piece='x';
 }
}
void display();
void input()
{
  int pos1,pos2,row,col,cont;
  player1game:
  display();
  
  printf("\nEnter the position for %s:",p1.name);
  scanf("%d",&pos1);
  if(pos1<1||pos1>9) 
  {
  printf("\nEnter a proper position\n");
  goto player1game;
  }
  row=(pos1-1)/3;
  col=(pos1-1)%3;
  board[row][col]=1;
  moves++;
  if(moves==9) return;
  cont=check();
if(cont==0) return;
  player2game:
  display();
  printf("\nEnter the position for %s:",p2.name);
  scanf("%d",&pos2);
  if(pos2<1||pos2>9)
  {
  printf("\nEnter a proper position:");
  goto player2game;
  }

  row=(pos2-1)/3;
  col=(pos2-1)%3;
  board[row][col]=2;
  moves++;
  if(moves==9) return;
  
}

int check()
{
 //rows checked
 int i;
 for(i=0;i<3;i++)
 {
  if(board[i][0]==1&& board[i][1]==1&& board[i][2]==1)
   {printf("\n%s won the game from the %d row",p1.name,i+1);return 0;}
 }
  for(i=0;i<3;i++)
 {
  if(board[i][0]==2&&board[i][1]==2&&board[i][2]==2)
   {printf("\n%s won the game from the %d row",p2.name,i+1);return 0;}
 }
 //cols checked
   for(i=0;i<3;i++)
 {
  if(board[0][i]==2&&board[1][i]==2&&board[2][i]==2)
   {printf("\n%s won the game from the %d col",p2.name,i+1);return 0;}
 }
  for(i=0;i<3;i++)
 {
  if(board[0][i]==1&&board[1][i]==1&&board[2][i]==1)
   {printf("\n%s won the game from the %d col",p1.name,i+1);return 0;}
 }
 //diagonals checking
  for(i=0;i<3;i++)
 {
  if(board[0][0]==2&&board[1][1]==2&&board[2][2]==2)
   {printf("\n%s won the game from the main diagonal",p2.name);return 0;}
 }
   for(i=0;i<3;i++)
 {
  if(board[0][0]==1&&board[1][1]==1&&board[2][2]==1)
   {printf("\n%s won the game from the main diagonal",p1.name);return 0;}
 }
   for(i=0;i<3;i++)
 {
  if(board[0][2]==2&&board[1][1]==2&&board[2][0]==2)
   {printf("\n%s won the game from the antidiagonal",p2.name);return 0;}
 }
  for(i=0;i<3;i++)
 {
  if(board[2][0]==1&&board[1][1]==1&&board[0][2]==1)
   {printf("\n%s won the game from the antidiagonal",p1.name);return 0;}
 }
 return 1;
}

void display()
{
 int pos,i,j;
 for(i=0;i<3;i++)
 {
   printf("\n");
  for(j=0;j<3;j++)
  {
   if(board[i][j]==1) printf("\t%c",p1.piece);
   else if(board[i][j]==2) printf("\t%c",p2.piece);
   else 
   {
    pos=i*3+1+j;
    printf("\t%d",pos);
   }
  }
  
 }
}
 
void main()
{
 int cont=1,ch;
 do
 {
 cont=1;
 createboard();
 printf("\nEnter player 1 name:");
 scanf("%s",p1.name);
 printf("\nEnter player 2 name:");
 scanf("%s",p2.name);
 toss();
 while(cont)
 {
  
  input(); 
  if(moves>4)
  cont=check();
  if(moves==9)
  {
   printf("\nMatch drawn");
   break;
  }
 }
 printf("\nDo you want to play again?:");
 scanf("%d",&ch);
 }while(ch==1);
}
