# Greedy Chester
A Python3 solution to [/r/dailyprogrammer's problem #214 [Hard]](http://www.reddit.com/r/dailyprogrammer/comments/3629st/20150515_challenge_214_hard_chester_the_greedy/).

I used two solutions to compare their respectives times: **brute force** and [**k-d tree**](http://en.wikipedia.org/wiki/K-d_tree).

I used [@stefankoegl's implemenation](https://github.com/stefankoegl/kdtree) of the k-d tree. 

*Note: I did change my local copy to compute the squared distances to adhere to the challenge's requirements.*


## Sample Runs

```shell-session
$ python3.4 greedy_chester.py sampleCoords.txt

1) Run using brute force
2) Run using k-d tree
> 1

Total distance traveled:        9.127777855837017
Total time taken:            0.008812554005999118
```

```shell-session
$ python3.4 greedy_chester.py sampleCoords.txt

1) Run using brute force
2) Run using k-d tree
> 2

Total distance traveled:        9.127777855837017
Total time taken:            0.030267530004493892
```

```shell-session
$ python3.4 greedy_chester.py challenge2.txt

1) Run using brute force
2) Run using k-d tree
> 1

Total distance traveled:         89.9225515128112
Total time taken:              47.132453002006514
```

```shell-session
$ python3.4 greedy_chester.py challenge2.txt

1) Run using brute force
2) Run using k-d tree
> 2

Total distance traveled:         89.9225515128112
Total time taken:              3.7528893199923914
```
