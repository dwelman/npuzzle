#include <npuzzle.h>

vector<string>	readFile(string fileName)
{
	ifstream		file;
	string			line;
	vector<string>	fileData;
	int				i;

	i = 0;
	file.open(fileName);
	if (!file)
	{
		cout << "ERROR: File could not be opened" << endl;
		exit (-1);
	}
	while (!file.eof())
	{
		getline(file, line);
		if (line.empty() && i == 0)
		{
			cout << "ERROR: File cannot be empty" << endl;
			exit (-1);
		}
		if (!line.empty())
			fileData.push_back(line);
		i++;
	}
	file.close();
	return (fileData);
}