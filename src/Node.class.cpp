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