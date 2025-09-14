/**https://leetcode.com/problems/minimum-height-trees/ */
//A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
//Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
//Return a list of all MHTs' root labels. You can return the answer in any order.
//The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
// 
//Example 1:
//Input: n = 4, edges = [[1,0],[1,2],[1,3]]
//Output: [1]
//Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
//Example 2:
//Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
//Output: [3,4]
// 
//Constraints:
//	1 <= n <= 2 * 104
//	edges.length == n - 1
//	0 <= ai, bi < n
//	ai != bi
//	All the pairs (ai, bi) are distinct.
//	The given input is guaranteed to be a tree and there will be no repeated edges.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int* res = malloc(n * sizeof(int));
    int* degree = malloc(n * sizeof(int));
    int* queue = malloc(n * sizeof(int));
    int* parent = malloc(n * sizeof(int));
    int* count = malloc(n * sizeof(int));
    int front = 0, rear = 0;
    int i, j, k, min_height = n, min_height_count = 0;
    
    // Initialize
    for (i = 0; i < n; i++) {
        degree[i] = 0;
        parent[i] = -1;
        count[i] = 0;
    }
    
    // Build graph
    for (i = 0; i < edgesSize; i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }
    
    // Find roots
    for (i = 0; i < n; i++) {
        if (degree[i] == 1) {
            queue[rear++] = i;
            parent[i] = -2; // Mark as root
        }
    }
    
    // BFS
    while (front < rear) {
        int u = queue[front++];
        
        for (i = 0; i < edgesSize; i++) {
            if (edges[i][0] == u || edges[i][1] == u) {
                int v = edges[i][0] == u? edges[i][1] : edges[i][0];
                
                degree[v]--;
                
                if (degree[v] == 1) {
                    queue[rear++] = v;
                    parent[v] = u;
                }
            }
        }
    }
    
    // Count the number of MHTs
    for (i = 0; i < n; i++) {
        if (parent[i] == -2) {
            count[i] = 1;
        } else {
            count[parent[i]]++;
        }
    }
    
    // Find MHTs with minimum height
    for (i = 0; i < n; i++) {
        if (parent[i] == -2 && count[i] < min_height) {
            min_height = count[i];
            min_height_count = 1;
        } else if (parent[i] == -2 && count[i] == min_height) {
            min_height_count++;
        }
    }
    
    // Copy MHTs' root labels to the result array
    *returnSize = min_height_count;
    for (i = 0, j = 0; i < n; i++) {
        if (parent[i] == -2 && count[i] == min_height) {
            res[j++] = i;
        }
    }
    
    // Free memory
    free(degree);
    free(queue);
    free(parent);
    free(count);
    
    return res;
    
}