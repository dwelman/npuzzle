#include <npuzzle.h>

int		findCheapest(vector<Node *> openSet)
{
	int	cheapestInd;
	int	cheapestNum;

	if (openSet.size() == 0)
	{
		return (-1);
	}
	if (openSet.size() == 1)
	{
		return (0);
	}
	cheapestInd = -1;
	cheapestNum = -1;
	for (int i = 0; i < openSet.size(); i++)
	{
		if (openSet[i]->getCostToGoal() < cheapestNum)
		{
			cheapestInd = i;
			cheapestNum = openSet[i]->getCostToGoal();
		}
	}
	return (cheapestInd);
}

int		generateNewSets(Node *currentNode, vector<Node *> *openSet)
{
	Node	*copiedNode;
	int		tileVal;
	int		ret;

	ret = 0;
	if ((tileVal = currentNode->getLeft(0)) != -1)
	{
		copiedNode = currentNode->nodeCopy();
		copiedNode->slideTile(tileVal);
		copiedNode->setDepth(currentNode->getDepth() + 1);
		openSet->push_back(copiedNode);
		ret++;
	}
	if ((tileVal = currentNode->getRight(0)) != -1)
	{
		copiedNode = currentNode->nodeCopy();
		copiedNode->slideTile(tileVal);
		copiedNode->setDepth(currentNode->getDepth() + 1);
		openSet->push_back(copiedNode);
		ret++;
	}
	if ((tileVal = currentNode->getTop(0)) != -1)
	{
		copiedNode = currentNode->nodeCopy();
		copiedNode->slideTile(tileVal);
		copiedNode->setDepth(currentNode->getDepth() + 1);
		openSet->push_back(copiedNode);
		ret++;
	}
	if ((tileVal = currentNode->getBottom(0)) != -1)
	{
		copiedNode = currentNode->nodeCopy();
		copiedNode->slideTile(tileVal);
		copiedNode->setDepth(currentNode->getDepth() + 1);
		openSet->push_back(copiedNode);
		ret++;
	}
	return (ret);
}

void	solveLoop(Node *initialNode, Node *finalNode)
{
	vector<Node *>	closedSet;
	vector<Node *>	openSet;
	bool			bIsDone;
	bool			bIsSolved;
	int				maxOpenSet;
	int				currentStates;
	int				moves;
	int				currentInd;

	openSet.push_back(initialNode);
	maxOpenSet = 1;
	currentStates = 1;
	moves = 0;
	bIsDone = false;
	bIsSolved = false;
	while (!bIsDone)
	{
		currentInd = findCheapest(openSet);
		if (currentInd == -1)
		{
			bIsDone = true;
		}
		//Check if this tile is the final solution, if it is end the loop
		if (finalNode->compareGrids(openSet.at(currentInd)->getTiles(), finalNode->getTiles(), finalNode->getSize()))
		{
			bIsDone = true;
			bIsSolved = true;
		}  
		//Generate all possible solutions from this tile and add them to the open set
		currentStates += generateNewSets(openSet.at(currentInd), &openSet);
		//put this tile in the closed set
		cout << openSet.size() << endl;
		closedSet.push_back(openSet.at(currentInd));
		openSet.erase(openSet.begin() + currentInd);
		cout << openSet.size() << endl;
		if (openSet.size() > maxOpenSet)
		{
			maxOpenSet = openSet.size();
		}
		moves++;
		bIsDone = true;
	}
	if (bIsSolved)
	{
		cout << "YOU ARE A FUCKING GENIUS" << endl;
		cout << "Solved in: " << moves << " moves" << endl;
	}
}