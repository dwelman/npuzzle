#include <npuzzle.h>

int     getPuzzleSize(void)
{
    int     size;
    string  input;

    do
    {
        cout << "Enter a puzzle size from  3 - 46340 , must be a positive integer." << endl;
        getline(cin, input);
        if (cin.eof())
        {
            cout << "EOF EXCETION : size wil default to 3" << endl;
            return (3);
        }
        size = atoi(input.c_str());
        cout << " size : "  << size << endl;
    }
    while (!size || size < 3 || size > 46340);
    return (size);
}

void    swaps(int swaps, int size, int **arr)
{
    int s;
    int rX1;
    int rY1;
    int rX2;
    int rY2;
    int temp;
    struct timeval tp;
    long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    
    s = 0;
    while (s < swaps)
    {
        gettimeofday(&tp, NULL);
        ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
        srand(ms);
        rX1 = rand() % size;
        rY1 = rand() % size;
        rX2 = rand() % size;
        rY2 = rand() % size;
        temp = arr[rY1][rX1];
        arr[rY1][rX1] = arr[rY2][rX2];
        arr[rY2][rX2] = temp;
        s++;
    }
}

Node    *generateRandomPuzzle(int heuristic)
{
    Node *randomPuzzle;
    int puzzleSize;
    int puzzleMax;
    int **puzzle;
    int num;
    int x;
    int y;

    puzzleSize = getPuzzleSize();
    puzzleMax = puzzleSize * puzzleSize;
    puzzle = (int **)malloc(sizeof(int *) * puzzleSize);
    x = 0;
    y = 0;
    num = 1;
	while (y < puzzleSize && num < puzzleMax)
	{
		puzzle[y] = (int *)malloc(sizeof(int) * puzzleSize);
		x = 0;
		while (x < puzzleSize)
		{
			puzzle[y][x] = num++;
			x++;
		}
		y++;
	}
    randomPuzzle = new Node(puzzle, puzzleSize, 0, heuristic);
    swaps(1000000, puzzleSize, puzzle);
    randomPuzzle->printNode();
    return (randomPuzzle);
}
