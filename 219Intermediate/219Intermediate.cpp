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

		// http://www.geeksforgeeks.org/intersection-of-n-sets/
		// Adapted algorithm from the above site to work with the relevant data containers.
		vector<string> getIntersection(vector<string> categories)
		{	
			vector<string> result;  // To store the resultant vector
			int smallSetInd = 0;  // Initialize index of smallest vector
			int minSize = toDoMap[categories[0]].size(); // Initialize size of smallest vector

			// Iterate thru all the categories
			for (int i = 0 ; i < categories.size() ; i++)
			{
				// Sort the vector at categories[i].
				sort(toDoMap[categories[i]].begin(), toDoMap[categories[i]].end());
		 
				// Update minSize, if needed.
				if (minSize > toDoMap[categories[i]].size())
				{
					minSize = toDoMap[categories[i]].size();
					smallSetInd = i;
				}
			}
		 
			map<string, int> elementsMap;
		 
			// Add all the elements of smallest vector to a map, if already present, update the frequency.
			for (int i = 0; i < toDoMap[categories[smallSetInd]].size(); i++)
			{
				if (elementsMap.find( toDoMap[categories[smallSetInd]][i] ) == elementsMap.end())
					elementsMap[ toDoMap[categories[smallSetInd]][i] ] = 1;
				else
					elementsMap[ toDoMap[categories[smallSetInd]][i] ]++;
			}
		 
			// Iterate thru the map elements to see if they are present in remaining vectors.
			for (auto && keyValPair : elementsMap)
			{
				string elem = keyValPair.first;
				int freq = keyValPair.second;
		 
				bool bFound = true;
		 
				// Iterate through all categories.
				for (int j = 0 ; j < categories.size() ; j++)
				{
					// If this vector is not the smallest vector, then do binary search in it.
					if (j != smallSetInd)
					{
						// If the element is found in this vector, then find its frequency.
						if (binary_search( toDoMap[categories[j]].begin(), toDoMap[categories[j]].end(), elem ))
						{
						   int lInd = lower_bound(toDoMap[categories[j]].begin(), toDoMap[categories[j]].end(), elem)
										- toDoMap[categories[j]].begin();
						   int rInd = upper_bound(toDoMap[categories[j]].begin(), toDoMap[categories[j]].end(), elem) 
						   				- toDoMap[categories[j]].begin();
		 
						   // Update the minimum frequency, if needed.
						   if ((rInd - lInd) < freq)
							   freq = rInd - lInd;
						}
						// If the element is not present in any vector, then no need to proceed for this element.
						else
						{
							bFound = false;
							break;
						}
					}
				}
		 
				// If element was found in all vectors, then add it to result 'freq' times.
				if (bFound)
				{
					for (int k = 0; k < freq; k++)
						result.push_back(elem);
				}
			}
			return result;
		}
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

		void removeItem(string item)
		{
			for (auto && keyValPair : toDoMap)
				for (int i = 0; i < keyValPair.second.size(); i++)
					if (keyValPair.second[i].compare(item) == 0)	
						keyValPair.second.erase(keyValPair.second.begin()+i);
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
				vector<string> result = getIntersection(allCategories);

				cout << "----";
				for (int i = 0; i < allCategories.size()-1; i++)
				    cout << allCategories[i] << " & ";
				cout << allCategories[allCategories.size()-1] << "----" << "\n";

				for (auto && elem : result)
				    cout << " - " << elem << "\n";
				cout << "\n";
			}
		}

};

int main()
{
	ToDoList td;

	td.addItem("Go to work", "Programming"); 
	td.addItem("Create Sine Waves in C", "Music", "Programming");

	td.addItem("A pixel is a pixel", "programming", "music");
    td.addItem("The Scheme Programming Language", "programming");
    td.addItem("Modes in Folk Music", "music");
    td.addItem("Memory in C", "programming", "music");
    td.addItem("The use of the Melodic Minor Scale", "music");
    td.addItem("Haskell's School of Music", "programming");

    td.addItem("Better faster stronger", "programming", "music", "life");
    td.addItem("test delete", "programming", "music", "life");

	td.updateItem("Create Sine Waves in C", "Create Sine Waves in Python");

	td.viewList("programming");
	td.viewList("music");
	td.viewList("music", "programming");
	td.viewList("life");
	td.viewList("programming", "life", "music");

	td.removeItem("test delete");
	td.viewList("programming", "life", "music");
	
	return 0;
}