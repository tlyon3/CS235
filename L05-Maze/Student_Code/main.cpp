#include "pathfinder.cpp"

int main()
{
	Pathfinder pfinder;
	pfinder.createRandomMaze();
	pfinder.importMaze("Solvable1.txt");
	//cout<<pfinder.getMaze()<<endl;
	pfinder.getMaze();
	//vector<string> solution=pfinder.solveMaze();
	pfinder.solveMaze();
	//cout<< "Solution: " <<endl;
	// for(int i=0;i<solution.size();i++)
	// {
	// 	cout<<"testsolution: "<<i<<endl;
	// 	cout<<solution[i]<<endl;
	// }
}