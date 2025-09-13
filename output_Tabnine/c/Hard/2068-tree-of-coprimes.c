/**https://leetcode.com/problems/tree-of-coprimes/ */
//There is a tree (i.e., a connected, undirected graph that has no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. Each node has a value associated with it, and the root of the tree is node 0.
//To represent this tree, you are given an integer array nums and a 2D array edges. Each nums[i] represents the ith node's value, and each edges[j] = [uj, vj] represents an edge between nodes uj and vj in the tree.
//Two values x and y are coprime if gcd(x, y) == 1 where gcd(x, y) is the greatest common divisor of x and y.
//An ancestor of a node i is any other node on the shortest path from node i to the root. A node is not considered an ancestor of itself.
//Return an array ans of size n, where ans[i] is the closest ancestor to node i such that nums[i] and nums[ans[i]] are coprime, or -1 if there is no such ancestor.
// 
//Example 1:
//Input: nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
//Output: [-1,0,0,1]
//Explanation: In the above figure, each node's value is in parentheses.
//- Node 0 has no coprime ancestors.
//- Node 1 has only one ancestor, node 0. Their values are coprime (gcd(2,3) == 1).
//- Node 2 has two ancestors, nodes 1 and 0. Node 1's value is not coprime (gcd(3,3) == 3), but node 0's
//  value is (gcd(2,3) == 1), so node 0 is the closest valid ancestor.
//- Node 3 has two ancestors, nodes 1 and 0. It is coprime with node 1 (gcd(3,2) == 1), so node 1 is its
//  closest valid ancestor.
//Example 2:
//Input: nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
//Output: [-1,0,-1,0,0,0,-1]
// 
//Constraints:
//	nums.length == n
//	1 <= nums[i] <= 50
//	1 <= n <= 105
//	edges.length == n - 1
//	edges[j].length == 2
//	0 <= uj, vj < n
//	uj != vj
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getCoprimes(int* nums, int numsSize, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    // Build adjacency list
    int** adj = malloc(numsSize * sizeof(int*));
    for (int i = 0; i < numsSize; i++) {
        adj[i] = malloc(numsSize * sizeof(int));
        for (int j = 0; j < numsSize; j++) {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < edgesSize; i++) {
        adj[edges[i][0]][edges[i][1]] = 1;
        adj[edges[i][1]][edges[i][0]] = 1;
    }
    
    // Initialize distance and ancestor arrays
    int* distance = malloc(numsSize * sizeof(int));
    int* ancestor = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        distance[i] = INT_MAX;
        ancestor[i] = -1;
    }
    // Perform BFS
    distance[0] = 0;
    queue_t* queue = queue_create();
    queue_enqueue(queue, 0);
    while (!queue_empty(queue)) {
        int u = queue_dequeue(queue);
        for (int v = 0; v < numsSize; v++) {
            if (adj[u][v] && distance[v] > distance[u] + 1) {
                distance[v] = distance[u] + 1;
                ancestor[v] = u;
                queue_enqueue(queue, v);
            }
        }
    }
    // Find closest ancestor for each node
    int* ans = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        int closestAncestor = -1;
        for (int j = 0; j < numsSize; j++) {
            if (distance[i]!= INT_MAX && distance[j]!= INT_MAX && gcd(nums[i], nums[j]) == 1 &&
                (closestAncestor == -1 || distance[j] < distance[closestAncestor])) {
                closestAncestor = j;
            }
        }
        ans[i] = closestAncestor;
    }
    
    // Free memory
    queue_destroy(queue);
    for (int i = 0; i < numsSize; i++) {
        free(adj[i]);
    }
    free(adj);
    free(distance);
    free(ancestor);
    
    return ans;
    
}