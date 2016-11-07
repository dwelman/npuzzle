#include <npuzzle.h>

vector<string> removeComments(vector<string> fileContents)
{
	int 			line;
	string			tempLine;
	int				index;
	vector<string>	returnContents;

	line = 0;
	while (line < fileContents.size())
	{
		fileContents[line] = regex_replace(fileContents[line], regex("[' \t']{2,}"), " ");
		index = fileContents[line].find('#');
		if (index != -1)
		{
			if (index == 0)
			{
				line++;
				continue ;
			}
			else
			{
				tempLine = fileContents[line].substr(0, index);
				returnContents.push_back(tempLine);				
			}
		}
		else 
			returnContents.push_back(fileContents[line]);
			//cout << "line :" << fileContents[line] << endl;
		line++;
	}
	return (returnContents);
}

int		countNumbers(string line)
{
	int	i;
	int len;
	int	count;

	len = line.length();
	count = 0;
	i = 0;
	while (i < len)
	{
		if (isdigit(line[i]))
			count++;
		while (isdigit(line[i]))
			i++;
		i++;
	}
	return (count);
}

Node	*makeInitialNode(vector<string> fileContents)
{
	Node 	*returnNode;
	int		**arr;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fileContents = removeComments(fileContents);
	while (y < fileContents.size())
	{
	//	cout << "count" << countNumbers(fileContents[y]) << endl;
	//	arr[y] = malloc(sizeof(int) * countNumbers(fileContents[y]);
		y++;
	}
}