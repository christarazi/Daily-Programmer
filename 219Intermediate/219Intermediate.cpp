#include <iostream>
#include <string>
#include <algorithm>
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

		// Recursive base method for variadic templates.
		void addItem(string item, string category)
		{
			// Transform category to lowercase for consistency.
			transform(category.begin(), category.end(), category.begin(), ::tolower);

			toDoMap[category].push_back(item);
		}

		// Recursing method for variadic templates.
		// Args: template parameter pack 
		// categories: function parameter pack
		// Recursively builds the map as "categories..." iterates with each call.
		template<typename... Args>
		void addItem(string item, string category, Args... categories)
		{
			// Transform category to lowercase for consistency.
			transform(category.begin(), category.end(), category.begin(), ::tolower);

			toDoMap[category].push_back(item);
			addItem(item, categories...);		// recursive call iterating thru categories.
		}

		void viewList(string category)
		{
			// Transform category to uppercase.
			transform(category.begin(), category.end(), category.begin(), ::tolower);

			cout << "----" << category << "----" << endl;
			for (auto&& elem : toDoMap[category])
				cout << " - " << elem << endl;
		}

};

int main()
{
	ToDoList td;
	td.addItem("Testing", "c++", "programming", "test category");
	td.viewList("test category");

	return 0;
}