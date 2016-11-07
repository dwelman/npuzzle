#include <Node.class.h>

Node::Node(int **array, int size, int depth)
{
	setTiles(array);
	setSize(size);
	setDepth(depth);
}