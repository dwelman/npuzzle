#include <Node.class.h>

void	Node::setCost()
{
	switch (this->heuristic)
	{
		case Node::EUCLIDIAN :
			euclidianCost();
			break ;
		case Node::TOOP :
			toopCost();
			break ;
		case Node::MANHATTAN :
			manhattanCost();
			break ;
		default :
		return;
	}
}

int     Node::manhattanCostTile(int tile)
{
    int deltaX;
    int deltaY;

    deltaX = this->finalState->getX(tile) - this->getX(tile);
    deltaY = this->finalState->getY(tile) - this->getY(tile);
    deltaX = (deltaX < 0) ? deltaX *= -1 : deltaX;
    deltaY = (deltaY < 0) ? deltaY *= -1 : deltaY;  
    return (deltaX + deltaY);
}

void	Node::manhattanCost(void)
{
    int x;
    int y;
    int cost;
    int totalCost;

    x = 0;
    y = 0;
    totalCost = 0;
    while (y < this->size)
    {
        x = 0;
        while (x < this->size)
        {
            if (this->tiles[y][x] == 0)
            {
                x++;
                continue ;
            }
            cost = manhattanCostTile(this->tiles[y][x]);
            totalCost += cost;
            x++;
        }
        y++;
    }
    cout << "----------------------------" << endl << "Total Cost :" << totalCost << endl;
}

void	Node::euclidianCost(void)
{
    int x;
    int y;
    int cost;
    int totalCost;

    x = 0;
    y = 0;
    totalCost = 0;
    while (y < this->size)
    {
        x = 0;
        while (x < this->size)
        {
            if (this->tiles[y][x] == 0)
            {
                x++;
                continue ;
            }
            cost = manhattanCostTile(this->tiles[y][x]);
            totalCost += cost;
            x++;
        }
        y++;
    }
    setCostToGoal(totalCost);
    cout << "----------------------------" << endl << "Total Cost :" << totalCost << endl;
}

void	Node::toopCost(void)
{
}
