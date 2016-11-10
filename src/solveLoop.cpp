#include <npuzzle.h>

int		findCheapest(vector<Node *> openSet, vector<Node *> closedSet)
{
	int		cheapestInd;
	int		cheapestNum;

	if (openSet.size() == 0)
	{
		return (-1);
	}
	cheapestInd = 0;
	cheapestNum = openSet[0]->getCostToGoal();
	for (int i = 0; i < openSet.size(); i++)
	{
		if (openSet[i] == NULL)
			continue ;
		if (openSet[i]->getCostToGoal() < cheapestNum)
		{
			cheapestInd = i;
			cheapestNum = openSet[i]->getCostToGoal();
		}
	}
	return (cheapestInd);
}

int		generateNewSets(Node *currentNode, vector<Node *> *openSet, vector<Node *> closedSet)
{
	Node	*copiedNode;
	int		tileVal;
	int		ret;
	bool	bCanStore;

	ret = 0;
	if ((tileVal = currentNode->getLeft(0)) != -1)
	{
		bCanStore = true;
		copiedNode = currentNode->slideTile(tileVal);
		copiedNode->setDepth(currentNode->getDepth() + 1);
		for (int k = 0; k < closedSet.size(); k++)
		{
			if (Node::compareGrids(copiedNode->getTiles(), closedSet[k]->getTiles(), copiedNode->getSize()))
			{
				bCanStore = false;
			}
		}
		if (bCanStore)
		{
			copiedNode->setPrevNode(currentNode);
			openSet->push_back(copiedNode);
			ret++;
		}
	}
	if ((tileVal = currentNode->getRight(0)) != -1)
	{
		bCanStore = true;
		copiedNode = currentNode->slideTile(tileVal);
		copiedNode->setDepth(currentNode->getDepth() + 1);
		for (int k = 0; k < closedSet.size(); k++)
		{
			if (Node::compareGrids(copiedNode->getTiles(), closedSet[k]->getTiles(), copiedNode->getSize()))
			{
				bCanStore = false;
			}
		}
		if (bCanStore)
		{
			copiedNode->setPrevNode(currentNode);
			openSet->push_back(copiedNode);
			ret++;
		}
	}
	if ((tileVal = currentNode->getTop(0)) != -1)
	{
		bCanStore = true;
		copiedNode = currentNode->slideTile(tileVal);
		copiedNode->setDepth(currentNode->getDepth() + 1);
		for (int k = 0; k < closedSet.size(); k++)
		{
			if (Node::compareGrids(copiedNode->getTiles(), closedSet[k]->getTiles(), copiedNode->getSize()))
			{
				bCanStore = false;
			}
		}
		if (bCanStore)
		{
			copiedNode->setPrevNode(currentNode);
			openSet->push_back(copiedNode);
			ret++;
		}
	}
	if ((tileVal = currentNode->getBottom(0)) != -1)
	{
		bCanStore = true;
		copiedNode = currentNode->slideTile(tileVal);
		copiedNode->setDepth(currentNode->getDepth() + 1);
		for (int k = 0; k < closedSet.size(); k++)
		{
			if (Node::compareGrids(copiedNode->getTiles(), closedSet[k]->getTiles(), copiedNode->getSize()))
			{
				bCanStore = false;
			}
		}
		if (bCanStore)
		{
			copiedNode->setPrevNode(currentNode);
			openSet->push_back(copiedNode);
			ret++;
		}
	}
	return (ret);
}

void	solveLoop(Node *initialNode, Node *finalNode)
{
	vector<Node *>	closedSet;
	vector<Node *>	openSet;
	vector<Node *>	finalPath;
	Node			*temp;
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
		currentInd = findCheapest(openSet, closedSet);
		if (currentInd == -1)
		{
			bIsDone = true;
			break ;
		}
		if (Node::compareGrids(openSet.at(currentInd)->getTiles(), finalNode->getTiles(), finalNode->getSize()))
		{
			bIsDone = true;
			bIsSolved = true;
			break ;
		}
		currentStates += generateNewSets(openSet.at(currentInd), &openSet, closedSet);
		closedSet.push_back(openSet.at(currentInd));
		swap(openSet[currentInd], openSet.back());
		openSet.pop_back();
		if (openSet.size() > maxOpenSet)
		{
			maxOpenSet = openSet.size();
		}
		moves++;
	}
	if (bIsSolved)
	{
		cout << "Solved in: " << moves << " moves" << endl;
		cout << "There were a maximum of " << maxOpenSet << " open sets at one point" << endl;
		cout << "There were " << currentStates << " sets created in total" << endl;
		cout << endl << "This is how the puzzle was solved:" << endl << endl;
		temp = openSet[currentInd];
		while (temp != NULL)
		{
			finalPath.push_back(temp);
			temp = temp->getPrevNode();
		}
		for (int k = finalPath.size(); k > -1; k--)
		{
			finalPath[k]->printNode();
			cout << "-------------------------------------" << endl;
		}
	}
	else
	{
		cout << "This puzzle could not be solved" << endl;
		cout << "There were a maximum of " << maxOpenSet << " open sets at one point" << endl;
		cout << "There were " << currentStates << " sets created in total" << endl;
	}
}