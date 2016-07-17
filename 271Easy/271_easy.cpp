/*
 * https://www.reddit.com/r/dailyprogrammer/comments/4nvrnx/20160613_challenge_271_easy_critical_hit/
 */

#include <iostream>
using namespace std;

int main() 
{
	int dice, health;
	double total = 1.0;
	
	cin >> dice;
	cin >> health;
	
	while (health >= dice)
	{
		total *= (1.0 / dice);
		health -= dice;
	}
	total *= (double) (dice - health + 1) / dice;
	
	cout << total << endl;
	
	return 0;
}
