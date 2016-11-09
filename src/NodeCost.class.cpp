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
    int startX;
    int startY;
    int endX;
    int endY;
    int deltaX;
    int deltaY;
    int cost;

    startX = this->getX(tile);
    startY = this->getY(tile);        
    endX = this->finalState->getX(tile);
    endY = this->finalState->getY(tile);
/*    cout << endl << "tile : " <<tile <<endl;
    cout << "start : (" << startX << " ; " << startY << ")" << endl;     
    cout << "end : (" << endX << " ; " << endY << ")" <<endl;
*/  deltaX = endX - startX;
    deltaY = endY - startY;
    if (deltaX < 0)
        deltaX *= -1;
    if (deltaY < 0)
        deltaY *= -1;
    cost = deltaX + deltaY;        
    return (cost);
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
    //cout << "----------------------------" << endl << "Total Cost :" << totalCost << endl;
}

void	Node::euclidianCost(void)
{
}

void	Node::toopCost(void)
{
}
