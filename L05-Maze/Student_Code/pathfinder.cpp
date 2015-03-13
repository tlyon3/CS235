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
	//ofstream maze("randomMaze.txt");
	// if(maze.is_open())
	// {
		//srand(time(NULL));
		for(int z=0;z<5;z++)
		{
			for(int y=0;y<5;y++)
			{
				for(int x=0;x<5;x++)
				{
					if((z==0 && y==0 && x==0)
						||(z==4 && y==4 && x==4))
					{
						//maze<<1;
						currentMaze[x][y][z]="1";
					}
					else
					{
						int i=rand()%2;
						currentMaze[x][y][z]=to_string(i);
					}
						//maze<<rand()%2;
					//maze<<" ";
				}
				//maze<<endl;
			}
			mazeAvailable=true;
			//maze<<endl;
		}
		//maze.close();
	//}
}

bool Pathfinder::importMaze(string file_name)
{
	string tempMaze[5][5][5];
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
				//cout<<"INVALID MAZE"<<endl;
				return false;
			}

		}
		myfile.close();
	}
	else
	{
		//cout<<"COULDN'T FIND MAZE"<<endl;
		return false;
	} 
	//cout<<"Count: "<<count<<endl;
	if(count!=125)
	{
		//cout<<"INVALID MAZE"<<endl;
		//cout<<"invalid count"<<endl;
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
					tempMaze[x][y][z]=token;
				}
			}
		}
		myfile.close();
	}
	if(tempMaze[4][4][4]=="0"||tempMaze[0][0][0]=="0")
	{
		//cout<<"invalid entrance/exit"<<endl;
		//mazeAvailable=false;
		return false;
	}
	//cout<<"move to current maze"<<endl;
	for(int z=0;z<5;z++)
	{
		for(int y=0;y<5;y++)
		{
			for(int x=0;x<5;x++)
			{
				currentMaze[x][y][z]=tempMaze[x][y][z];
			}
		}
	}	
	mazeAvailable=true;
	return true;
}

vector<string> Pathfinder::solveMaze()
{
	solution.clear();
	if(!mazeAvailable)
	{
		//cout<<"no maze"<<endl;
		return solution;
	}
	string step;
	for(int z=0;z<5;z++)
	{
		for(int y=0;y<5;y++)
		{
			for(int x=0;x<5;x++)
			{
				this->wasHere[x][y][z]=false;
			}	
		}
	}
	bool b = recursiveSolve(0,0,0);
	if(!b)
	{
		solution.clear();
		return solution;
	}
	// for(int i=0;i<solution.size();i++)
	// {
	// 	//cout<<"solution"<<endl;
	// 	cout<<solution.at(i)<<endl;
	// }
	return solution;
	
}

bool Pathfinder::recursiveSolve(int x, int y, int z)
{

	if(x==4 && y==4 && z==4) 
	{
		//correctPath[x][y][z]=true;
		string end="(4, 4, 4)";
		solution.push_back(end);
		return true;
	}
	if(x<0||x>4||y<0||y>4||z<0||z>4)
	{
		return false;
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
	//cout<<"Solving: "<<x<<","<<y<<","<<z<<endl;
	if(recursiveSolve(x-1,y,z)||recursiveSolve(x+1,y,z)||
			recursiveSolve(x,y-1,z)||recursiveSolve(x,y+1,z)||
			recursiveSolve(x,y,z-1)||recursiveSolve(x,y,z+1))
	{
		
		//correctPath[x][y][z]=true;
		string step="("+
				to_string(x)+", "+
				to_string(y)+", "+
				to_string(z)+")";
		// cout<<"add correct path: ";
		// cout << step << endl;
		solution.insert(solution.begin(),step);
		
		return true;
	}
	//correctPath[x][y][z]=false;
	return false;
}