#include "pathfinder.cpp"

int main()
{
	Pathfinder pfinder;
	pfinder.createRandomMaze();
	pfinder.importMaze("Solvable2.txt");
	cout<<pfinder.getMaze()<<endl;
	vector<string> solution=pfinder.solveMaze();
	cout<< "Solution: " <<endl;
	for(int i=0;i<solution.size();i++)
	{
		cout<<solution[i]<<endl;
	}
}