#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <utility>

using namespace std;

class ToDoList
{
	private:
		map<string, vector<string>> toDoMap;
	public:
		ToDoList() {}

		// Recursive variadic template add method.
		template<typename... Args>
		void addItem(string item, Args... categories)
		{
			// Brace initialize vector with every category passed in as a parameter.
			vector<string> allCategories{categories...};

			for (auto && category : allCategories)
			{
			    // Transform category to lowercase for consistency.
				transform(category.begin(), category.end(), category.begin(), ::tolower);

				toDoMap[category].push_back(item);
			}
		}

		void updateItem(string oldItem, string newItem)
		{
			for (auto && keyValPair : toDoMap)						// iterate thru every key-val pair
				for (int i = 0; i < keyValPair.second.size(); i++)	// iterate thru the vector of strings
			    	if (keyValPair.second[i].compare(oldItem) == 0)	
			    		keyValPair.second[i] = newItem;
		}

		// Recursive variadic template view method.
		template<typename... Args>
		void viewList(Args... categories)
		{
			// Brace initialize vector with every category passed in as a parameter.
			vector<string> allCategories{categories...};

			if (allCategories.size() == 0)
			{
				for (auto && keyValPair : toDoMap)						// iterate thru every key-val pair
				{
					for (int i = 0; i < keyValPair.second.size(); i++)	// iterate thru the vector of strings
				    {
				    	cout << "----" << keyValPair.first << "----" << "\n";
						cout << " - " << keyValPair.second[i] << "\n";
				    }
				    cout << "\n";
				}
			}
			else if (allCategories.size() == 1)
			{
				cout << "----" << allCategories[0] << "----" << "\n";
				for (auto && elem : toDoMap[allCategories[0]])
				    cout << " - " << elem << "\n";

				cout << "\n";
			}
			else
			{
				// Implement intersection of n sets here.
			}
		}

};

int main()
{
	ToDoList td;

	td.addItem("Go to work", "Programming"); 
	td.addItem("Create Sine Waves in C", "Music", "Programming"); 
	td.updateItem("Create Sine Waves in C", "Create Sine Waves in Python");

	td.viewList("programming");
	td.viewList("music");
	//td.viewList("music", "programming");

	return 0;
}