/*
http://www.reddit.com/r/dailyprogrammer/comments/36m83a/20150520_challenge_215_intermediate_validating/
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

// Convert n to a binary string.
string generateBinary(int n)
{
	string build = "";

	while (n != 0)
	{
		int remain = n % 2;
		build += to_string(remain);
		n /= 2;
	}

	int length = build.length();

	for (int i = 0; i < (n+1)-length; ++i) build += '0';

	reverse(build.begin(), build.end());

	return build;
}

// Validates every binary string in range of 2^n.
// Using the zero-one principle.
bool validate(int n, vector< pair<int,int> > comparators)
{
	for (int i = 1; i <= pow(2, n); ++i)
	{
		string bin = generateBinary(i);

		//cout << i << ": ";
		//cout << bin << endl;

		for (auto && c : comparators)
		{
			// Gets the integer values then compares them.
		    if (('0' - bin[get<0>(c)]) > ('0' - bin[get<1>(c)]))
		    {
	    		swap(bin[get<0>(c)], bin[get<1>(c)]);

	    		/* cout << "\tswap at (" << c.first << ", " << c.second << ")" 
	    			<< ": " << bin << endl; */
		    }
		}

		//cout << bin << endl << endl;	
		for (int j = 0; j < bin.length()-1; ++j)
		{
			if (('0' - bin[j]) > ('0' - bin[j+1])) return false;
		}
	}

	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 2) 
	{
		cout << "usage: " << argv[0] << " <file>" << endl;
		return 1;
	}

	vector< pair<int,int> > comparators;
	fstream fIn;
	fIn.open(argv[1], ios::in);
	int wires, inputs;

	fIn >> wires >> inputs;

	for (int i = 0; i < inputs; ++i)
	{
		int x, y;
		fIn >> x >> y;
		comparators.push_back(make_pair(x, y));
	}

	bool valid = validate(wires, comparators);

	if (valid) cout << "Valid" << endl;
	else cout << "Invalid" << endl;

	return 0;
}
