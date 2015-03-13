#include "pathfinder.cpp"

int main()
{
		Pathfinder pfinder;
		pfinder.createRandomMaze();
		//cout<<pfinder.getMaze()<<endl;
		pfinder.solveMaze();
		for (int i = 0; i < pfinder.solution.size(); ++i)
		{
			cout<<pfinder.solution[i]<<endl;
		}
}