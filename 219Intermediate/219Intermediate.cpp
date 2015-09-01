#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;


class ToDoList
{
	private:
		map<string, vector<string>> toDoMap;
	public:
		ToDoList() {}

		// Recursive base case method for variadic templates.
		map<string, vector<string>> addItem(string item, string category)
		{
			toDoMap[category].push_back(item);
			return toDoMap;
		}

		// Recursing method for variadic templates.
		// Args: template parameter pack 
		// categories: function parameter pack
		// Recursively builds the map as "categories..." iterates with each call.
		template<typename... Args>
		map<string, vector<string>> addItem(string item, string category, Args... categories)
		{
			toDoMap[category].push_back(item);
			return addItem(toDoMap, item, categories...);
		}

};

int main()
{
	//cout << adder(1,4,10,30) << endl;

	map<string, vector<string>> toDoMap;

	return 0;
}