#include <iostream>
#include<conio.h>
using namespace std;



char grid[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char current_marker;
int current_player;

//for draw 3X3 grid 
void drawgrid()
{
	cout<<" "<<grid[0][0]<<"  |  "<<grid[0][1]<<"  |  "<<grid[0][2]<<endl;
	cout<<"---------------\n";
	cout<<" "<<grid[1][0]<<"  |  "<<grid[1][1]<<"  |  "<<grid[1][2]<<endl;
	cout<<"---------------\n";
	cout<<" "<<grid[2][0]<<"  |  "<<grid[2][1]<<"  |  "<<grid[2][2]<<endl;
	cout<<"---------------\n";
}

//for position of marker
bool marker(int slot)
{
int row,column;
row=slot/3;
if(slot%3==0)
{
	row=row-1;
	column=2;
}
else
{
column=(slot%3)-1;	
}


if(grid[row][column]!='#' && grid[row][column]!='*')
{
grid[row][column]=current_marker;
return true;	
}
else
{
	return false;
}


	
}

//for check winning condition
int winner()
{
	for(int i=0;i<3;i++)
	{
		//for row check
		if(grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2])
		return current_player;
		//for column check
		if(grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i])
		return current_player;
	}
	
	//for diagonal check
	if(grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2])
	{
		return current_player;	
	}

	
	if(grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0])
	{
		return current_player;	
	}

	
	return 0;
	
}

//for players turn

void player_turn()
{
	if(current_marker=='#')
	current_marker='*';
	else
	current_marker='#';
	
	if(current_player==1)
	current_player=2;
	else
	current_player=1;
}



void game()
{
	cout<<"\tHASHTRICK GAME\n";
	 cout<<"Player one,Please choose your Marker (# or *) :\t";
	char player_marker;
	cin>>player_marker;
	if(player_marker!='#'&&player_marker!='*')
	{
	
	cout<<"Invalid marker"<<endl;
    cout<<"Player one,Please choose your Marker (# or *) :\t";
	
	cin>>player_marker;
    }
	current_marker=player_marker;
	
	current_player=1;
	
	drawgrid();
	
	int player_won; 

	for(int i=0;i<9;i++)
	{
			cout<<"\nIt's player"<<current_player<<"'s turn. Please Enter your Slot:\t";
				char slot;
		cin>>slot;
		
		if(slot!='1'  && slot!='2' && slot!='3' && slot!='4' && slot!='5' && slot!='6' && slot!='7' && slot!='8' && slot!='9')
		{
		cout<<"\nThis slot is Invalid! Please, Try another slot ";
		i--;	
		continue;
		}
		
		if(!marker(slot-48))
		{
			cout<<"\nThis slot is occupied ! Please, Try another slot \n"<<endl;
			i--;
			continue;
		}
		
		drawgrid();
		player_won=winner();
		
		
		if(player_won==1)
		{
			cout<<"Player one won! Congratulations!";
			break;
		}
		
		if(player_won==2)
		{
			cout<<"Player two won! Congratulations!";
			break;
		}
		
		player_turn();
	}
		
		if(player_won==0)
	{
		cout<<"That is a tie game!";
			
	}
		
			
}
 




int main() 
{ char a;
	game();
	cout<<"play again if yes enter s key otherwise any other key ";
	cin>>a;
	if(a=='s'||a=='S')
	game();
    getch();
	return 0;
}
