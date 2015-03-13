#pragma once;

class Maze
{
private:
	struct Node
	{
		int path;
		Node* north;
		Node* south;
		Node* east;
		Node* west;
		Node* up;
		Node* down;
		bool visited;
	};
	Node* entrance;
	Node* end;
public:
	Maze();
	

};