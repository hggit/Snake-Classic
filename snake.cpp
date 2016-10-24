#include<iostream>
#include<windows.h>	//for Sleep function
#include<conio.h>
#include<ctime>		//to get system time
#include<queue>
#include<stdlib.h>	//for system function
using namespace std;

struct point	//for snake head and tail	
{
	int x,y;
	char dir;	//current direction of motion
};

int main()
{
	cout<<"THE CLASSIC SNAKE GAME!";
	cout<<"\nMake sure CapsLock is OFF!!\nPress any key to begin.";
	getch();
	srand(time(NULL));	//seed srand with system time
	 int p,q;
	 char a[20][39]={0};	//game arnea
	
	 for(int i=0;i<20;i++)		//create boundary
	 {
	 	a[0][2*i]='#';
	 	a[19][2*i]='#';
	 	a[i][0]='#';
	 	a[i][38]='#';
	 }
	
	 point head={10,5,'d'};
	 point tail={10,1,'d'};		//initialize the snake
	 for(int i=1;i<6;i++)
	 	a[10][i]='@';

	int score=0;
	 queue <point> turnpoint;	//keep track of turns made by snake head
	 char chdir;
	 bool flag=false,nofood=true;	
	
	 while(true)
	 {

	 	system("cls");		//clear screen

	 	for(int i=0;i<20;i++)
	 	{
	 		for(int j=0;j<39;j++)
	 		{
	 			cout<<a[i][j];
	 		}
	 		cout<<'\n';
	 	}
	 	
	 	if(kbhit()!=0)		//if user gives some input
	 	{
	 		chdir=getch();		//new direction of snake
	 		bool isValid=false;	//to validate input
			
	 		if((head.dir=='w' || head.dir=='s') && (chdir=='a' || chdir=='d'))
	 			isValid=true;
	 		else if((head.dir=='a' || head.dir=='d') && (chdir=='w' || chdir=='s'))
	 			isValid=true;
			
	 		if(isValid)
	 		{
	 			head.dir=chdir;		//turn snake head
	 			turnpoint.push(head);	//store turning point
	 		}
	 	}

	 	while(nofood)		//randomly generate snake food in arena
	 	{
	 		p=rand()%18 +1;
	 		q=rand()%37 +1;
	 		if(a[p][q] != '@')
	 		{
	 			a[p][q]='o';
	 			nofood=false;
	 		}
	 	}
		 
		//move snake in head direction
		 
	 	if(head.dir=='d')
	 	{
	 		head.y++;
	 		if(a[head.x][head.y]=='@')	//if snake crosses itself game over!!
	 			flag=1;
	 	}
	 	else if(head.dir=='a')
	 	{
	 		head.y--;
	 		if(a[head.x][head.y]=='@')
	 			flag=1;
	 	}
	 	else if(head.dir=='w')
	 	{
	 		head.x--;
	 		if(a[head.x][head.y]=='@')
	 			flag=1;
	 	}
	 	else if(head.dir=='s')
	 	{
	 		head.x++;
	 		if(a[head.x][head.y]=='@')
	 			flag=1;
	 	}


	 	
	 	if(a[head.x][head.y] != 'o')
	 	{
	 		a[tail.x][tail.y]=' ';

		 	if(tail.x==turnpoint.front().x && tail.y==turnpoint.front().y)
		 	{
	 			tail.dir=turnpoint.front().dir;		//turn the tail in the direction which head turned at this point
	 			turnpoint.pop();
	 		}
	 	
	 		if(tail.dir=='d')
	 			tail.y++;
	 		else if(tail.dir=='a')
	 			tail.y--;
	 		else if(tail.dir=='w')
		 		tail.x--;
	 		else if(tail.dir=='s')
	 			tail.x++;
	 	}
	 	else
	 	{
	 		nofood=true;
	 		score++;
	 	}

	 	a[head.x][head.y]='@';

	 	if(flag==1 || head.x==0 || head.x==19 || head.y==0 || head.y==38)	//snake crosses boundary or cuts itself
	 		break;
	 }
	 cout<<"GAME OVER!...Your Score is : "<<score;
	 Sleep(5000);

}
