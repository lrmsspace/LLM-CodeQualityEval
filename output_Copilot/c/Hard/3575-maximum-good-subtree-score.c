/*
 You are given an undirected tree rooted at node 0 with n nodes numbered from 0 to n - 1. Each node i has an integer value vals[i], and its parent is given by par[i].
 A subset of nodes within the subtree of a node is called good if every digit from 0 to 9 appears at most once in the decimal representation of the values of the selected nodes.
 The score of a good subset is the sum of the values of its nodes.
 Define an array maxScore of length n, where maxScore[u] represents the maximum possible sum of values of a good subset of nodes that belong to the subtree rooted at node u, including u itself and all its descendants.
 Return the sum of all values in maxScore.
 Since the answer may be large, return it modulo 109 + 7.
 Example 1:
 Input: vals = [2,3], par = [-1,0]
 Output: 8
 Explanation:
 The subtree rooted at node 0 includes nodes {0, 1}. The subset {2, 3} is good as the digits 2 and 3 appear only once. The score of this subset is 2 + 3 = 5.
 The subtree rooted at node 1 includes only node {1}. The subset {3} is good. The score of this subset is 3.
 The maxScore array is [5, 3], and the sum of all values in maxScore is 5 + 3 = 8. Thus, the answer is 8.
 Example 2:
 Input: vals = [1,5,2], par = [-1,0,0]
 Output: 15
 Explanation:
 The subtree rooted at node 0 includes nodes {0, 1, 2}. The subset {1, 5, 2} is good as the digits 1, 5 and 2 appear only once. The score of this subset is 1 + 5 + 2 = 8.
 The subtree rooted at node 1 includes only node {1}. The subset {5} is good. The score of this subset is 5.
 The subtree rooted at node 2 includes only node {2}. The subset {2} is good. The score of this subset is 2.
 The maxScore array is [8, 5, 2], and the sum of all values in maxScore is 8 + 5 + 2 = 15. Thus, the answer is 15.
 Example 3:
 Input: vals = [34,1,2], par = [-1,0,1]
 Output: 42
 Explanation:
 The subtree rooted at node 0 includes nodes {0, 1, 2}. The subset {34, 1, 2} is good as the digits 3, 4, 1 and 2 appear only once. The score of this subset is 34 + 1 + 2 = 37.
 The subtree rooted at node 1 includes node {1, 2}. The subset {1, 2} is good as the digits 1 and 2 appear only once. The score of this subset is 1 + 2 = 3.
 The subtree rooted at node 2 includes only node {2}. The subset {2} is good. The score of this subset is 2.
 The maxScore array is [37, 3, 2], and the sum of all values in maxScore is 37 + 3 + 2 = 42. Thus, the answer is 42.
 Example 4:
 Input: vals = [3,22,5], par = [-1,0,1]
 Output: 18
 Explanation:
 The subtree rooted at node 0 includes nodes {0, 1, 2}. The subset {3, 22, 5} is not good, as digit 2 appears twice. Therefore, the subset {3, 5} is valid. The score of this subset is 3 + 5 = 8.
 The subtree rooted at node 1 includes nodes {1, 2}. The subset {22, 5} is not good, as digit 2 appears twice. Therefore, the subset {5} is valid. The score of this subset is 5.
 The subtree rooted at node 2 includes {2}. The subset {5} is good. The score of this subset is 5.
 The maxScore array is [8, 5, 5], and the sum of all values in maxScore is 8 + 5 + 5 = 18. Thus, the answer is 18.
 Constraints:
 1 <= n == vals.length <= 500
 1 <= vals[i] <= 109
 par.length == n
 par[0] == -1
 0 <= par[i] < n for i in [1, n - 1]
 The input is generated such that the parent array par represents a valid tree.
*/

int goodSubtreeSum(int* vals, int valsSize, int* par, int parSize) {
    long long totalSum = 0;
    const int MOD = 1000000007;

    // Create an adjacency list for the tree
    int n = valsSize;
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = -1; // Initialize with -1 to indicate no edge
        }
    }

    for (int i = 1; i < n; i++) {
        int u = par[i];
        int v = i;
        graph[u][v] = vals[v]; // Store the value at node v
        graph[v][u] = vals[v]; // Undirected edge
    }

    // DFS function to calculate maxScore for each subtree
    void dfs(int node, int parent, long long currentSum, int* visited) {
        visited[node] = 1;
        currentSum += vals[node];

        // Check if the current path is valid
        int digitCount[10] = {0};
        int isValid = 1;

        for (int i = 0; i < n && isValid; i++) {
            if (visited[i]) {
                int num = vals[i];
                while (num > 0) {
                    int digit = num % 10;
                    if (digitCount[digit] == 1) {
                        isValid = 0; // Digit appears more than once
                        break;
                    }
                    digitCount[digit]++;
                    num /= 10;
                }
            }
        }

        if (isValid) {
            totalSum = (totalSum + currentSum) % MOD;
        }

        // Continue DFS to children
        for (int i = 0; i < n; i++) {
            if (graph[node][i] != -1 && !visited[i] && i != parent) {
                dfs(i, node, currentSum, visited);
            }
        }

        visited[node] = 0; // Backtrack
    }

    int* visited = (int*)calloc(n, sizeof(int));
    dfs(0, -1, 0, visited);
    
    free(visited);
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }

    free(graph);
    return (int)(totalSum % MOD);
    
}