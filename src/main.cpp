#include <npuzzle.h>

int	main(int argc, char **argv)
{
	vector<string>	fileContents;
	Node	*initialState;
	Node	*finalState;

	if (argc != 1)
	{
		fileContents = readFile(argv[1]);
		initialState = makeInitialNode(fileContents);
		initialState->printNode();
		cout << "--------------" << endl;
		finalState = makeFinalNode(initialState);
	}
	else
	{
		cout << "ERROR: Usage: ./n_puzzle -h [heuristic method] [puzzle file name]" << endl;
	}
}