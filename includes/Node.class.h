#pragma once

#include <iostream>
using namespace std;

class Node
{
	public:
		//Constructor
		Node(int **array, int size, int depth, int heuristic);

		//Set methods
		void	setTiles(int **array){ this->tiles = array; }
		void	setSize(int size){ this->size = size; }
		void	setDepth(int depth){ this->depth = depth; }
		void	setCostToGoal(int cost){ this->costToGoal = cost; }
		void	setTile(int, int , int);
		void	setHeuristic(int heuristic){ this->heuristic = heuristic; }

		// Get methods
		int		**getTiles(){ return (this->tiles); }
		int		getSize(){ return (this->size); }
		int		getDepth(){ return (this->depth); }
		int		getCostToGoal(){ return (this->costToGoal); }
		int		getHeuristic(){ return (this->heuristic); }

		//Class functions
		void	printNode();
		int		getX(int);
		int		getY(int);
		int		getTop(int);
		int		getBottom(int);
		int		getLeft(int);
		int		getRight(int);
		Node*	slideTile(int);	
		Node*	nodeCopy();


	private:
		int			**tiles;
		int			size;
		int			depth;
		int			costToGoal;
		int			heuristic;
};