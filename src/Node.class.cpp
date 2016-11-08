#include <Node.class.h>

Node::Node(int **array, int size, int depth)
{
	setTiles(array);
	setSize(size);
	setDepth(depth);
}

void Node::printNode()
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < this->size)
	{
		x = 0;
		while (x < this->size)
		{
			cout << this->tiles[y][x];
			if (x < size -1)
				cout << " ";
			x++;
		}
		cout << endl;		
		y++;
	}
}

int	Node::getX(int tile)
{
	int x;
	int	y;

	y = 0;
	while (y < this->getSize())
	{
		x = 0;
		while (x < this->getSize())
		{
			if (this->tiles[y][x] == tile)
				return (x);
			x++;
		}
		y++;
	}
	return (-1);
}

int	Node::getY(int tile)
{
	int x;
	int	y;

	y = 0;
	while (y < this->getSize())
	{
		x = 0;
		while (x < this->getSize())
		{
			if (this->tiles[y][x] == tile)
				return (y);
			x++;
		}
		y++;
	}
	return (-1);
}

int	Node::getTop(int tile)
{
	int tileX;
	int	tileY;

	tileX = this->getX(tile);
	tileY = this->getY(tile);
	if (tileY == 0 || tileX == -1 || tileY == -1)
		return (-1);
	return (this->tiles[tileY - 1][tileX]);
}

int	Node::getBottom(int tile)
{
	int tileX;
	int	tileY;

	tileX = this->getX(tile);
	tileY = this->getY(tile);
	if (tileY == this->size - 1 || tileX == -1 || tileY == -1)
		return (-1);
	return (this->tiles[tileY + 1][tileX]);
}

int	Node::getLeft(int tile)
{
	int tileX;
	int	tileY;

	tileX = this->getX(tile);
	tileY = this->getY(tile);
	if (tileX == 0 || tileX == -1 || tileY == -1)
		return (-1);
	return (this->tiles[tileY][tileX - 1]);
}

int	Node::getRight(int tile)
{
	int tileX;
	int	tileY;

	tileX = this->getX(tile);
	tileY = this->getY(tile);
	if (tileX == this->size - 1 || tileX == -1 || tileY == -1)
		return (-1);
	return (this->tiles[tileY][tileX + 1]);
}