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
		while (fileContents[line][0] == ' ')
			fileContents[line].erase(0, 1);
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
		//cout << fileContents[line] << endl;
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

Node	*makeInitialNode(vector<string> fileContents, int heuristic)
{
	Node 	*returnNode;
	int		**arr;
	int		x;
	int		y;
	int		line;	
	int		size;

	x = 0;
	y = 0;
	fileContents = removeComments(fileContents);
	size = stoi(fileContents[0]);
	fileContents.erase(fileContents.begin());
	arr = (int**)malloc(sizeof(int*) * size);
	while (y < fileContents.size() && y < size)
	{
		x = 0;
		if (countNumbers(fileContents[y]) != size)
		{
			cerr << "INPUT FILE ERROR : size not equal to specified value";
			exit(-1);
		}
		arr[y] = (int*)malloc(sizeof(int) * size);
		do
		{
		//	cout << "file bef " << fileContents[y] << endl;			
			arr[y][x++] = stoi(fileContents[y]);
		//	cout << "val = " << arr[y][x - 1] << endl;
			line = 0;
			while (isdigit(fileContents[y][line]))
				line++;
		//		cout << "line " << line << endl;
			fileContents[y] = fileContents[y].substr(line + 1);
		//	cout << "file " << fileContents[y] << endl;
		}
		while (fileContents[y].find(' ') != -1 && x < size - 1);
		arr[y][x] = stoi(fileContents[y]);
		y++;
	}
	return (new Node(arr, size, 0, heuristic));
}