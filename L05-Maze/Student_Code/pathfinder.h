#include "PathfinderInterface.h"

class Pathfinder: public PathfinderInterface
{
public:
	Pathfinder(){};
	string getMaze();
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
	string currentMaze[5][5][5];
	bool mazeAvailable=false;
	bool recursiveSolve(int x,int y,int z);
	bool wasHere[5][5][5];
	vector<string> solution;
};