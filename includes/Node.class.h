#pragma once

#include <iostream>
using namespace std;

class Node
{
	public:
		Node(int **array, int size, int depth);

		void	setTiles(int **array){ this->tiles = array; }
		void	setSize(int size){ this->size = size; }
		void	setDepth(int depth){ this->depth = depth; }
		void	setCostToGoal(int cost){ this->costToGoal = cost; }

		int		**getTiles(){ return (this->tiles); }
		int		getSize(){ return (this->size); }
		int		getDepth(){ return (this->depth); }
		int		getCostToGoal(){ return (this->costToGoal); }

		void	printNode();

	private:
		int			**tiles;
		int			size;
		int			depth;
		int			costToGoal;
};