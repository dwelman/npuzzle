#pragma once

#include <iostream>
using namespace std;

class Node
{
	public:
		static const int MANHATTAN = 1;
		static const int EUCLIDIAN = 2;
		static const int TOOP = 3;

		//Constructor
		Node(int **array, int size, int depth, int heuristic);

		//Set methods
		void	setTiles(int **array){ this->tiles = array; }
		void	setSize(int size){ this->size = size; }
		void	setDepth(int depth){ this->depth = depth; }
		void	setCostToGoal(int cost){ this->costToGoal = cost; }
		void	setTile(int, int , int);
		void	setHeuristic(int heuristic){ this->heuristic = heuristic; }
		void	setFinalState(Node *finalState){ this->finalState = finalState; }
		void	setPrevNode(Node *prevNode){ this->prevNode = prevNode; }
		

		// Get methods
		int		**getTiles(){ return (this->tiles); }
		int		getSize(){ return (this->size); }
		int		getDepth(){ return (this->depth); }
		int		getCostToGoal(){ return (this->costToGoal); }
		int		getHeuristic(){ return (this->heuristic); }
		Node	*getFinalState(){ return (this->finalState); }
		Node	*getPrevNode(){ return (this->prevNode); }

		//Class functions
		void	printNode();
		int		getX(int);
		int		getY(int);
		int		getTop(int);
		int		getBottom(int);
		int		getLeft(int);
		int		getRight(int);
		Node*	slideTile(int);
		Node*	nodeCopy(void);
		void	manhattanCost(void);
		void	euclidianCost(void);
		void	toopCost(void);		
		static bool	compareGrids(int **a, int **b, int size);
		void	setCost(void);


	private:
		int			**tiles;
		int			size;
		int			depth;
		int			costToGoal;
		int			costToGoalSet;		
		int			heuristic;
		Node		*finalState;
		Node		*prevNode;

		//Internal functions
		int			manhattanCostTile(int tile);
		int			euclidianCostTile(int tile);
		
};