# To-Do List
A C++11 solution to [/r/dailyprogrammer's problem #219 [Intermediate]](https://www.reddit.com/r/dailyprogrammer/comments/3a64hq/20150617_challenge_219_intermediate_todo_list/).

Compiled using `$ g++ -std=c++11 219Intermediate.cpp`.

## ToDoList Class

### Private

`toDoMap` is a map which associates a string to a vector of strings; where string is the item to-do, and the vector of strings being the categories the item belongs to.

`.getIntersection()` can find the intersection of `n` sets. 
Input: vector of strings; all the categories.
Output: vector of strings holding the intersecting items.

### Public

`.addItem()`. Self explanatory. Takes a string as the item, then a variable number of strings as the categories the item belongs to. Uses a brace initializer list to grab all the categories.

`.updateItem()`, `.viewList()` are self explanatory.

## Sample Runs

```shell-session

----programming----
 - Go to work
 - Create Sine Waves in Python
 - A pixel is a pixel
 - The Scheme Programming Language
 - Memory in C
 - Haskell's School of Music
 - Better faster stronger

----music----
 - Create Sine Waves in Python
 - A pixel is a pixel
 - Modes in Folk Music
 - Memory in C
 - The use of the Melodic Minor Scale
 - Better faster stronger

----music & programming----
 - A pixel is a pixel
 - Better faster stronger
 - Create Sine Waves in Python
 - Memory in C

----life----
 - Better faster stronger

----programming & life & music----
 - Better faster stronger


```