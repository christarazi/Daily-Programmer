#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) 
{
	if (argc != 2)
	{
		cerr << "Usage: " << argv[0] << " <file>\n";
		return -1;
	}

	fstream fIn;
	fIn.open(argv[1]);

	vector<string> lines;
	int longest = 0;
	string line;
	while (getline(fIn, line))
	{
		// Gather the input into vector and determine longest line.
		lines.push_back(line);
		if (line.length() > longest)
			longest = line.length();
	}
	
	// Make sure every line has the same length as the longest line.
	for (auto&& elem : lines)
	{
		while (elem.length() != longest)
			elem += ' ';
			
		//cout << elem << endl;
	}

	// Iterate through the columns since every string is the same length.
	for (int i = 0; i < longest; i++)
	{
		// Take the character at each column and append it to line,
		// thus creating a transposed version of the original.
		string line = "";
		for (auto&& elem : lines)
		{
			line += elem[i];
		}
		cout << line << endl;
	}

	
	return 0;
}
