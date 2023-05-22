Formularizing the problem with maximum flow, we get the following.

The graph has the vertices 
S,
T,
L 
1
​
 ,L 
2
​
 ,⋯,L 
N
​
 ,
R 
1
​
 ,R 
2
​
 ,⋯,R 
M
​
 .

For each 
1≤i≤N, there is an edge 
S→L 
i
​
  with a capacity 
A 
i
​
 .

For each 
1≤i≤N and 
1≤j≤M, there is an edge 
L 
i
​
 →R 
j
​
  with a capacity 
B 
j
​
 .

For each 
1≤j≤M, there is an edge 
R 
j
​
 →T with a capacity 
C 
j
​
 .

The answer is the maximum flow from 
S to 
T.

Naturally, the graph is too large to compute the flow directly. Let us try to find the minimum cut instead, which is equal to the maximum flow.

Assume that we have split the vertices 
L 
i
​
  to the sets 
X and 
Y ― the former sides with 
S in the cut, and the latter sides with 
T.

Then, for each vertex 
R 
j
​
 , we can independently decide whether it sides with 
S or 
T in the cut. That is, we compare the cost when 
R 
j
​
  belongs to 
S, which is 
C 
j
​
 , and the cost when 
R 
j
​
  belongs to 
T, which is 
∣X∣B 
j
​
 , and choose the side with the smaller cost.

Here, after choosing 
X and 
Y, it was just the size of 
X that mattered. Therefore, we can first decide the size of 
X, and then choose the vertices to be used as 
X from 
L 
i
​
  in descending order of 
A 
i
​
 .

We will try all possible sizes of 
X from 
0 to 
N and find the costs of the corresponding cuts. Except for sorting 
A 
i
​
 , this can be done in 
O(N+M) time with prefix sums. Thus, the total time complexity of this solution is 
O(NlogN+M).