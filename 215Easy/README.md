# Sad Cycles
A C# solution to [/r/dailyprogrammer's easy problem #215](http://www.reddit.com/r/dailyprogrammer/comments/36cyxf/20150518_challenge_215_easy_sad_cycles/).

Compiled using `$ mcs sadcycles.cs`.

## Sample Runs

```shell-session
$ mono sadcycles.exe 
Enter base: 5
Enter starting number: 117649

Sad cycle:
[10933, 59536, 73318, 50062]

Length of sad cycle: 4
```
```shell-session
$ mono sadcycles.exe 
Enter base: 6
Enter starting number: 2

Sad cycle:
[383890, 1057187, 513069, 594452, 570947, 786460, 477201, 239459, 1083396, 841700]

Length of sad cycle: 10
```
```shell-session
$ mono sadcycles.exe 
Enter base: 7
Enter starting number: 7

Sad cycle:
[5345158, 2350099, 9646378, 8282107, 5018104, 2191663]

Length of sad cycle: 6
```
```shell-session
$ mono sadcycles.exe 
Enter base: 3
Enter starting number: 14

Sad cycle:
[371]

Length of sad cycle: 1
```
```shell-session
$ mono sadcycles.exe 
Enter base: 11
Enter starting number: 2

Sad cycle:
[5410213163, 416175830, 10983257969, 105122244539, 31487287760, 23479019969, 127868735735, 23572659062, 34181820005, 17233070810, 12544944422, 31450865399, 71817055715, 14668399199, 134844138593, 48622871273, 21501697322, 33770194826, 44292995390, 125581636412, 9417560504, 33827228267, 21497682212, 42315320498, 40028569325, 40435823054, 8700530096, 42360123272, 2344680590, 40391187185, 50591455115, 31629394541, 63182489351, 48977104622, 44296837448, 50918009003, 71401059083, 42001520522, 101858747, 21187545101, 10669113941, 63492084785, 50958448520, 48715803824, 27804526448, 19581408116, 48976748282, 61476706631]

Length of sad cycle: 48
```
