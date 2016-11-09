#include <npuzzle.h>

void	printUsage(void)
{
	cout << "ERROR: Usage: ./n_puzzle -h [heuristic method] [puzzle file name]" << endl;
	cout << "heuristic method :" << endl;
	cout << "\t1 : Manhattan" << endl;
	cout << "\t2 : Euclidian" << endl;
	cout << "\t3 : TOOP" << endl;
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

int	main(int argc, char **argv)
{
	vector<string>	fileContents;
	Node	*initialState;
	Node	*finalState;
	int		heuristic;

	if (argc == 4)
	{
		if (strlen(argv[1]) != 2 || strcmp(argv[1],  "-h") != 0)
			printUsage();
		heuristic = atoi(argv[2]); 
		if (heuristic != MANHATTAN && heuristic != EUCLIDIAN && heuristic != TOOP)
			printUsage();
		fileContents = readFile(argv[3]);
		initialState = makeInitialNode(fileContents, heuristic);
		finalState = makeFinalNode(initialState->getSize(), heuristic);
		initialState->setFinalState(finalState);
		initialState->printNode();
		cout << "--------------------" << endl;
		cout << "Final State : " << endl;
		finalState->printNode();
		cout << "Using heuristic :" << heuristicString(initialState->getHeuristic()) << endl; 
	}
	else
	{
		printUsage();
	}
}