#include <npuzzle.h>

Node	*makeFinalNode(Node *initialNode)
{
	int	size;
	int	highestNum;
	int	currentNum;
	int	x;
	int	y;
	int	**grid;

	size = initialNode->getSize();
	highestNum = pow(size, 2) - 1;
	currentNum = 1;
	x = 0;
	y = 0;
	grid = (int **)malloc(sizeof(int *) * size);
	while (y < size)
	{
		grid[y] = (int *)malloc(sizeof(int) * size);
		x = 0;
		while (x < size)
		{
			grid[y][x] = 0;
			x++;
		}
		y++;
	}
	x = -1;
	y = 0;
	while (currentNum <= highestNum)
	{
		x += 1;
		while (x < size)
		{
			if (grid[y][x] == 0)
			{
				if (currentNum <= highestNum)
				{
					cout << currentNum << endl;
					grid[y][x] = currentNum;
					currentNum++;
				}
			}
			else
			{
				x--;
				break ;
			}
			x++;
		}
		if (x == size)
			x--;
		y += 1;
		while (y < size)
		{
			if (grid[y][x] == 0)
			{
				if (currentNum <= highestNum)
				{
					grid[y][x] = currentNum;
					currentNum++;
				}
			}
			else
			{
				y--;
				break ;
			}
			y++;
		}
		if (y == size)
			y--;
		if (x > 0)
			x -= 1;
		while (x > -1)
		{
			if (grid[y][x] == 0)
			{
				if (currentNum <= highestNum)
				{
					grid[y][x] = currentNum;
					currentNum++;
				}
			}
			else
			{
				x++;
				break ;
			}
			x--;
		}
		if (x < 0)
			x++;
		if (y > 0)
			y -= 1;
		while (y > -1)
		{
			if (grid[y][x] == 0)
			{
				if (currentNum <= highestNum)
				{
					grid[y][x] = currentNum;
					currentNum++;
				}
			}
			else
			{
				y++;
				break ;
			}
			y--;
		}
		if (y < 0)
			y++;
	}
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			cout << grid[y][x] << "\t";
			x++;
		}
		cout << endl;
		y++;
	}
}