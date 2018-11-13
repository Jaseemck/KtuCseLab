**S3 Datastructures Lab\
Experiment 14**
-----------------------------------------------------------------

Question:
Implementation of Depth First Search (DFS)

Solution:

Depth First Search
The vertex 0 is the starting vertex in our case. We start our traversal from the vertex 0. Then we will visit all vertices adjacent to vertex 0 i.e., 1, 4, 3. Here, we can visit these three vertices in any order. Suppose we visit the vertices in order 1,3,4.

The traversal would be: 0 1 3 4

Now, we shall visit all the vertices adjacent to 1, then all the vertices adjacent to 3 and then all the vertices adjacent to 4. So first we shall visit 2 (since it is adjacent to 1), then 6 (since it is adjacent to 3) and 5, 7 (since these are adjacent to 4).

Note: Vertex 4 is adjacent to vertices 1 and 3, but it has already been visited so we’ve ignored it.

The traversal would be: 0 1 3 4 2 6 5 7

Now, we shall visit all the vertices adjacent to 2, 6, 5, and 7 one by one. We can see that vertex 5 is adjacent to vertex 2. Since, it has already been traversed upon before, we have don’t need to traverse through it again and move on to the next vertex. Now, the vertices 4 and 7 are adjacent to the vertex 6. Since, they have been traversed upon before, we will not traverse on them again. Vertex 5 does not have any adjacent vertices. Vertices 5 and 8 are adjacent to vertex 7. Since, vertex 5 has been traversed upon before, we will not traverse it again. However, vertex 8 has not yet been visited. So we will traverse on vertex 8.

The traversal would be: 0 1 3 4 2 6 5 7 8

Now, we need to visit vertices adjacent to vertex 8. However, there is no vertex adjacent to vertex 8 and hence we will have to stop the traversal here.

Note: There’s no unique traversal and it can be different based on the order of the successors.

We shall look at a BFS program in C for directed Graph using a Queue. This program reaches only those vertices that are reachable from the start vertex.


Input and Output
----------------
Enter number of vertices : 8
Enter number of edges : 10
Enter an edge(u,v) :0 1
Enter an edge(u,v) :0 2
Enter an edge(u,v) :0 3
Enter an edge(u,v) :0 4
Enter an edge(u,v) :0 5
Enter an edge(u,v) :0 5
Enter an edge(u,v) :0 6
Enter an edge(u,v) :0 6
Enter an edge(u,v) :0 7
Enter an edge(u,v) :0 7

0
1
5
7
2
3
6
4

--------------------------------------------------------------------

