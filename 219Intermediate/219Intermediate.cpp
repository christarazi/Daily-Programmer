#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

/*
class ToDoList
{
	private:
		map<string, vector<string>> toDoMap;
	public:
		void ToDoList() {}

		void addItem(string item)
		{
			toDoMap[""].push_back(item);
		}
	
		template<typename... Args>
		void addItem(string item, Args... category)
		{

		}
}*/


int adder(int first)
{
	cout << "First" << endl;
	return first;
}

template<typename... Types>
int adder(int first, Types ... rest)
{
	cout << "second" << endl;
    return first + adder(rest...);
}

void addItem(map<string, vector<string>> & toDoMap, string item)
{
	toDoMap[""].push_back(item);
}
	
template<typename... Args>
void addItem(map<string, vector<string>> & toDoMap, string item, Args... category)
{
	//vector<string> a = {category...};
	toDoMap.insert(make_pair(category, item)...);
	cout << "Exiting fucn" << endl;
}

int main()
{
	//cout << adder(1,4,10,30) << endl;

	map<string, vector<string>> toDoMap;

	addItem(toDoMap, "Testing this shit", "programming", "c++");

	return 0;
}