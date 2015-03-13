#include "maze.h"

Maze::Maze()
{
		entrance->path=1;
		end->path=1;
		entrance->visited=true;
		end->visited=false;
}