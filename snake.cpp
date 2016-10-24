#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<queue>
#include<stdlib.h>
using namespace std;
struct point
{
	int x,y;
	char dir;
};

int main()
{
	cout<<"THE CLASSIC SNAKE GAME!";
	cout<<"\nPress any key to begin.";
	getch();
	srand(time(NULL));
	 int p,q;
	 char a[20][39]={0};
	 for(int i=0;i<20;i++)
	 {
	 	a[0][2*i]='#';
	 	a[19][2*i]='#';
	 	a[i][0]='#';
	 	a[i][38]='#';
	 }
	 point head={10,5,'d'};
	 point tail={10,1,'d'};
	 for(int i=1;i<6;i++)
	 	a[10][i]='@';

	int score=0;
	 queue <point> turnpoint;
	 char chdir;
	 bool flag=false,nofood=true;
	 while(true)
	 {

	 	system("cls");

	 	for(int i=0;i<20;i++)
	 	{
	 		for(int j=0;j<39;j++)
	 		{
	 			cout<<a[i][j];
	 		}
	 		cout<<'\n';
	 	}
	 	
	 	if(kbhit()!=0)
	 	{
	 		chdir=getch();
	 		bool isValid=false;
	 		if((head.dir=='w' || head.dir=='s') && (chdir=='a' || chdir=='d'))
	 			isValid=true;
	 		else if((head.dir=='a' || head.dir=='d') && (chdir=='w' || chdir=='s'))
	 			isValid=true;
	 		if(isValid)
	 		{
	 			head.dir=chdir;
	 			turnpoint.push(head);
	 		}
	 	}

	 	while(nofood)
	 	{
	 		p=rand()%18 +1;
	 		q=rand()%37 +1;
	 		if(a[p][q] != '@')
	 		{
	 			a[p][q]='o';
	 			nofood=false;
	 		}
	 	}

	 	if(head.dir=='d')
	 	{
	 		head.y++;
	 		if(a[head.x][head.y]=='@')
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
	 			tail.dir=turnpoint.front().dir;
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

	 	if(flag==1 || head.x==0 || head.x==19 || head.y==0 || head.y==38)
	 		break;
	 }
	 cout<<"GAME OVER!...Your Score is : "<<score;
	 Sleep(5000);

}