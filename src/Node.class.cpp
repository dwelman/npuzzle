#include <Node.class.h>

Node::Node(int **array, int size, int depth, int heuristic)
{
	setTiles(array);
	setSize(size);
	setDepth(depth);
	setHeuristic(heuristic);
}

void Node::printNode()
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (this->getTiles() == NULL || this->getSize() == 0)
	{
		cout << "Empty node" << endl;
		return ;
	}
	while (y < this->size)
	{
		x = 0;
		while (x < this->size)
		{
			cout << this->tiles[y][x];
			if (x < size -1)
				cout << "\t";
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

Node* Node::nodeCopy()
{
	int		**arr;
	Node 	*newNode;
	int		y;

	y = 0;
	if (this->getSize() == 0)
		return (new Node(NULL, this->size, 0, this->heuristic));
	arr = (int**)malloc(sizeof(int*) * this->size);
	while (y < this->getSize())
	{
		arr[y] = (int*)malloc(sizeof(int) * size);
		memcpy(arr[y], this->tiles[y], sizeof(int) * size);
		y++;
	}
	newNode = new Node(arr, this->size, 0, this->heuristic);
	return (newNode);
}

void	Node::setTile(int y, int x, int val)
{
	if (y > this->size || y < 0 || x > this->size || x < 0)
	{
		cerr << "Tile out of bounds" << endl;
		return ;
	}
	this->tiles[y][x] = val;	
}

Node	*Node::slideTile(int tile)
{
	int tileX;
	int	tileY;
	int	zX;
	int	zY;
	Node *returnNode;
	
	tileX = this->getX(tile);
	tileY = this->getY(tile);
	returnNode = new Node(NULL, 0, 0, 0);
	if (this->getTop(tiles[tileY][tileX]) != 0 && this->getBottom(tiles[tileY][tileX]) != 0
	&& this->getLeft(tiles[tileY][tileX]) != 0 && this->getLeft(tiles[tileY][tileX]) != 0)
		return (returnNode);
	zY = this->getY(0);
	zX = this->getX(0);	
	delete(returnNode);
	returnNode = this->nodeCopy();
	returnNode->setTile(zY, zX, returnNode->getTiles()[tileY][tileX]);	
	returnNode->setTile(tileY, tileX, 0);
	return (returnNode);
}

bool	Node::compareGrids(int **a, int **b, int size)
{
	int		x;
	int		y;

	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (a[y][x] != b[y][x])
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}