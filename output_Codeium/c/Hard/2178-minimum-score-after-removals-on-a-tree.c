/**https://leetcode.com/problems/minimum-score-after-removals-on-a-tree/ */
//There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
//You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//Remove two distinct edges of the tree to form three connected components. For a pair of removed edges, the following steps are defined:
//	Get the XOR of all the values of the nodes for each of the three components respectively.
//	The difference between the largest XOR value and the smallest XOR value is the score of the pair.
//	For example, say the three components have the node values: [4,5,7], [1,9], and [3,3,3]. The three XOR values are 4 ^ 5 ^ 7 = 6, 1 ^ 9 = 8, and 3 ^ 3 ^ 3 = 3. The largest XOR value is 8 and the smallest XOR value is 3. The score is then 8 - 3 = 5.
//Return the minimum score of any possible pair of edge removals on the given tree.
// 
//Example 1:
//Input: nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
//Output: 9
//Explanation: The diagram above shows a way to make a pair of removals.
//- The 1st component has nodes [1,3,4] with values [5,4,11]. Its XOR value is 5 ^ 4 ^ 11 = 10.
//- The 2nd component has node [0] with value [1]. Its XOR value is 1 = 1.
//- The 3rd component has node [2] with value [5]. Its XOR value is 5 = 5.
//The score is the difference between the largest and smallest XOR value which is 10 - 1 = 9.
//It can be shown that no other pair of removals will obtain a smaller score than 9.
//Example 2:
//Input: nums = [5,5,2,4,4,2], edges = [[0,1],[1,2],[5,2],[4,3],[1,3]]
//Output: 0
//Explanation: The diagram above shows a way to make a pair of removals.
//- The 1st component has nodes [3,4] with values [4,4]. Its XOR value is 4 ^ 4 = 0.
//- The 2nd component has nodes [1,0] with values [5,5]. Its XOR value is 5 ^ 5 = 0.
//- The 3rd component has nodes [2,5] with values [2,2]. Its XOR value is 2 ^ 2 = 0.
//The score is the difference between the largest and smallest XOR value which is 0 - 0 = 0.
//We cannot obtain a smaller score than 0.
// 
//Constraints:
//	n == nums.length
//	3 <= n <= 1000
//	1 <= nums[i] <= 108
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= ai, bi < n 
//	ai != bi
//	edges represents a valid tree.
int minimumScore(int* nums, int numsSize, int** edges, int edgesSize, int* edgesColSize) {
    int totalXor = 0;
    int* subtreeXor = (int*)malloc(numsSize * sizeof(int));
    bool* visited = (bool*)calloc(numsSize, sizeof(bool));
    int minScore = INT_MAX;

    // Calculate total XOR of all nodes
    for (int i = 0; i < numsSize; i++) {
        totalXor ^= nums[i];
    }

    // DFS to calculate subtree XOR values
    void dfs(int node, int parent) {
        visited[node] = true;
        subtreeXor[node] = nums[node];
        for (int i = 0; i < edgesSize; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if ((u == node && v != parent) || (v == node && u != parent)) {
                int child = (u == node) ? v : u;
                if (!visited[child]) {
                    dfs(child, node);
                    subtreeXor[node] ^= subtreeXor[child];
                }
            }
        }
    }

    dfs(0, -1);

    // Try removing each pair of edges
    for (int i = 0; i < edgesSize; i++) {
        for (int j = i + 1; j < edgesSize; j++) {
            int u1 = edges[i][0], v1 = edges[i][1];
            int u2 = edges[j][0], v2 = edges[j][1];

            // Choose roots for the three components
            int root1 = (subtreeXor[u1] < subtreeXor[v1]) ? u1 : v1;
            int root2 = (subtreeXor[u2] < subtreeXor[v2]) ? u2 : v2;
            int root3 = (subtreeXor[root1] < subtreeXor[root2]) ? root1 : root2;

            int xor1 = subtreeXor[root1];
            int xor2 = subtreeXor[root2];
            int xor3 = totalXor ^ xor1 ^ xor2;

            int maxXor = fmax(fmax(xor1, xor2), xor3);
            int minXor = fmin(fmin(xor1, xor2), xor3);

            minScore = fmin(minScore, maxXor - minXor);
        }
    }

    free(subtreeXor);
    free(visited);
    return minScore;
}
    
