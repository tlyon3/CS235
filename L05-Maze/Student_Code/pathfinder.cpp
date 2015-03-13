#include "pathfinder.h"
#include "iostream"
#include "fstream"
#include <cstdlib>

string Pathfinder::getMaze()
{
	string maze;
	if(mazeAvailable)
	{
		for(int z=0;z<5;z++)
		{
			for(int y=0;y<5;y++)
			{
				for(int x=0;x<5;x++)
				{
					maze+=currentMaze[x][y][z];
					maze+=" ";
				}
				maze+="\n";
			}
			maze+="\n";
		}
	}
	else
	{
		for(int z=0;z<5;z++)
		{
			for(int y=0;y<5;y++)
			{
				for(int x=0;x<5;x++)
				{
					maze+="1";
					maze+=" ";
				}
				maze+="\n";
			}
			maze+="\n";
		}
	}
	return maze;
}

void Pathfinder::createRandomMaze()
{
	ofstream maze("randomMaze.txt");
	if(maze.is_open())
	{
		srand(time(NULL));
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				for(int k=0;k<5;k++)
				{
					if((i==0 && j==0 && k==0)
						||(i==4 && j==4 && k==4))
					{
						maze<<1;
					}
					else
						maze<<rand()%2;
					maze<<" ";
				}
				maze<<endl;
			}
			maze<<endl;
		}
		maze.close();
	}
}

bool Pathfinder::importMaze(string file_name)
{
	string maze[5][5][5];
	int count=0;
	char token;
	int one_count=0;
	int zero_count=0;
	int x=0,y=0,z=0;
	ifstream myfile(file_name);
	if(myfile.is_open())
	{
		while(myfile>>token)
		{
			if(token=='1')
			{
				one_count++;
				count++;
			}
			else if(token=='0')
			{
				zero_count++;
				count++;
			}
			else 
			{
				cout<<"INVALID MAZE"<<endl;
				return false;
			}

		}
		myfile.close();
	}
	else
	{
		cout<<"COULDN'T FIND MAZE"<<endl;
		return false;
	} 
	//cout<<"Count: "<<count<<endl;
	if(count!=125)
	{
		cout<<"INVALID MAZE"<<endl;
		return false;
	}
	myfile.open(file_name);
	if(myfile.is_open())
	{
		for(int z=0;z<5;z++)
		{
			for(int y=0;y<5;y++)
			{
				for(int x=0;x<5;x++)
				{
					myfile>>token;
					//cout<<"Token: "<<token<<endl;
					currentMaze[x][y][z]=token;
				}
			}
		}
		myfile.close();
	}
	// cout<<"Printing maze:"<<endl;
	// for(int z=0;z<5;z++)
	// {
	// 	for(int y=0;y<5;y++)
	// 	{
	// 		for(int x=0;x<5;x++)
	// 		{
	// 			cout<<maze[x][y][z]<< " ";
	// 		}
	// 		cout<<endl;
	// 	}
	// 	cout<<endl;
	// }
	//cout<<"finished importing"<<endl;
	mazeAvailable=true;
	return true;

}

vector<string> Pathfinder::solveMaze()
{
	vector<string> solution;
	string step;
	for(int z=0;z<5;z++)
	{
		for(int y=0;y<5;y++)
		{
			for(int x=0;x<5;x++)
			{
				this->wasHere[x][y][z]=false;
				this->correctPath[x][y][z]=false;
			}	
		}
	}
	bool b = recursiveSolve(0,0,0);
	if(!b)
	{
		return solution;
	}
	for(int z=0;z<5;z++)
	{
		for(int y=0;y<5;y++)
		{
			for(int x=0;x<5;x++)
			{
				if(correctPath[x][y][z])
				{
					step="("+
						to_string(x)+","+
						to_string(y)+","+
						to_string(y)+")";
					solution.push_back(step);
				}
			}	
		}
	}
	return solution;
	
}
bool Pathfinder::recursiveSolve(int x, int y, int z)
{
	if(x==4 && y==4 && z==4) 
	{
		correctPath[x][y][z]=true;
		return true;
	}
	if(currentMaze[x][y][z]=="0")
	{
		return false;
	} 
	if(wasHere[x][y][z])
	{
		return false;
	}
	wasHere[x][y][z]=true;
	if(x!=0)
	{
		if(recursiveSolve(x-1,y,z))
		{
			correctPath[x][y][z]=true;
			return true;
		}
	}
	if(x!=4)
	{
		if(recursiveSolve(x+1,y,z))
		{
			correctPath[x][y][z]=true;
			return true;
		}
	}
	if(y!=0)
	{
		if(recursiveSolve(x,y-1,z))
		{
			correctPath[x][y][z]=true;
			return true;
		}
	}
	if(y!=4)
	{
		if(recursiveSolve(x,y+1,z))
		{
			correctPath[x][y][z]=true;
			return true;
		}
	}
	if(z!=0)
	{
		if(recursiveSolve(x,y,z-1))
		{
			correctPath[x][y][z]=true;
			return true;
		}
	}
	if(z!=4)
	{
		if(recursiveSolve(x,y,z+1))
		{
			correctPath[x][y][z]=true;
			return true;
		}
	}
	return false;
}