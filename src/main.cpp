#include <npuzzle.h>

void	printUsage(void)
{
	cout << "ERROR: Usage: ./n_puzzle -h [heuristic method] [puzzle file name]" << endl;
	cout << "If no input file is specified a random map will be generated with a specified size." << endl;	
	cout << "heuristic method :" << endl;
	cout << "\t1 : Manhattan" << endl;
	cout << "\t2 : Euclidian" << endl;
	cout << "\t3 : Hamming Distance (Tiles out of place)" << endl;
	exit(1);
}

string	heuristicString(int heuristic)
{
	switch (heuristic)
	{
		case 1 :
			return ("MANHATTAN");
			break ;
		case 2 :
			return ("EUCLIDIAN");
			break ;
		case 3 :
			return ("TOOP");
			break ;
		default :
			return ("UNKNOWN");
	}
}

void	determineIfSolveable(int **tiles, int size)
{
	int	*list;
	int	inversions;
	int	length;
	int	k;

	inversions = 0;
	k = 0;
	length = pow(size, 2) - 1;
	list = (int *)malloc(sizeof(int) * length);
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			if (tiles[y][x] != 0)
			{
				list[k] = tiles[y][x];
				k++;
			}
		}
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (list[j] > list[i])
				inversions++;
		}
	}
	free(list);
	if (inversions % 2 == 1)
	{
		cout << "This puzzle cannot be solved!" << endl;
		exit(0);
	}
	else
	{
		cout << "This puzzle can be solved" << endl;
	}
}

int	main(int argc, char **argv)
{
	vector<string>	fileContents;
	Node	*initialState;
	Node	*finalState;
	int		heuristic;

	if (argc == 4 || argc == 3)
	{
		if (strlen(argv[1]) != 2 || strcmp(argv[1],  "-h") != 0)
			printUsage();
		heuristic = atoi(argv[2]); 
		if (heuristic != MANHATTAN && heuristic != EUCLIDIAN && heuristic != TOOP)
			printUsage();
		if (argc == 3)
		{
			initialState = generateRandomPuzzle(heuristic);
		}
		else
		{
			fileContents = readFile(argv[3]);
			initialState = makeInitialNode(fileContents, heuristic);
		}
		Node *copy = initialState->nodeCopy();
		//determineIfSolveable(copy->getTiles(), copy->getSize());
		cout << "Initial" << endl;
		cout << "InitialNode Main " << initialState->getTiles()[0][0] << endl;
		initialState->printNode();
		//exit(1);
		finalState = makeFinalNode(initialState->getSize(), heuristic);
		initialState->setFinalState(finalState);
		solveLoop(initialState, finalState);
	}
	else
	{
		printUsage();
	}
}