/**https://leetcode.com/problems/maximum-genetic-difference-query/ */
//There is a rooted tree consisting of n nodes numbered 0 to n - 1. Each node's number denotes its unique genetic value (i.e. the genetic value of node x is x). The genetic difference between two genetic values is defined as the bitwise-XOR of their values. You are given the integer array parents, where parents[i] is the parent for node i. If node x is the root of the tree, then parents[x] == -1.
//You are also given the array queries where queries[i] = [nodei, vali]. For each query i, find the maximum genetic difference between vali and pi, where pi is the genetic value of any node that is on the path between nodei and the root (including nodei and the root). More formally, you want to maximize vali XOR pi.
//Return an array ans where ans[i] is the answer to the ith query.
// 
//Example 1:
//Input: parents = [-1,0,1,1], queries = [[0,2],[3,2],[2,5]]
//Output: [2,3,7]
//Explanation: The queries are processed as follows:
//- [0,2]: The node with the maximum genetic difference is 0, with a difference of 2 XOR 0 = 2.
//- [3,2]: The node with the maximum genetic difference is 1, with a difference of 2 XOR 1 = 3.
//- [2,5]: The node with the maximum genetic difference is 2, with a difference of 5 XOR 2 = 7.
//Example 2:
//Input: parents = [3,7,-1,2,0,7,0,2], queries = [[4,6],[1,15],[0,5]]
//Output: [6,14,7]
//Explanation: The queries are processed as follows:
//- [4,6]: The node with the maximum genetic difference is 0, with a difference of 6 XOR 0 = 6.
//- [1,15]: The node with the maximum genetic difference is 1, with a difference of 15 XOR 1 = 14.
//- [0,5]: The node with the maximum genetic difference is 2, with a difference of 5 XOR 2 = 7.
// 
//Constraints:
//	2 <= parents.length <= 105
//	0 <= parents[i] <= parents.length - 1 for every node i that is not the root.
//	parents[root] == -1
//	1 <= queries.length <= 3 * 104
//	0 <= nodei <= parents.length - 1
//	0 <= vali <= 2 * 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxGeneticDifference(int* parents, int parentsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int* res = (int*)malloc(sizeof(int) * queriesSize);
    int n = parentsSize;
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (parents[i] == -1) {
            m++;
        }
    }
    int* children[n];
    int childrenSize[n];
    memset(childrenSize, 0, sizeof(childrenSize));
    for (int i = 0; i < n; i++) {
        children[i] = (int*)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < n; i++) {
        if (parents[i] != -1) {
            children[parents[i]][childrenSize[parents[i]]++] = i;
        }
    }
    int* trie = (int*)malloc(sizeof(int) * 2 * n * 20);
    int trieSize = 1;
    int* node = (int*)malloc(sizeof(int) * 2 * n * 20);
    int* val = (int*)malloc(sizeof(int) * 2 * n * 20);
    int* ans = (int*)malloc(sizeof(int) * 2 * n * 20);
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++) {
        node[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (parents[i] == -1) {
            node[i] = 0;
            val[0] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (node[i] == -1) {
            int p = 0;
            for (int j = 19; j >= 0; j--) {
                int b = (i >> j) & 1;
                if (trie[p + b] == 0) {
                    trie[p + b] = trieSize++;
                }
                p = trie[p + b];
            }
            val[p] = i;
        }
    }
    int* stack = (int*)malloc(sizeof(int) * n);
    int stackSize = 0;
    int* visited = (int*)malloc(sizeof(int) * n);
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (parents[i] == -1) {
            stack[stackSize++] = i;
        }
    }
    int* trie = (int*)malloc(sizeof(int) * 2 * n * 20);
    int trieSize = 1;
    int* node = (int*)malloc(sizeof(int) * 2 * n * 20);
    memset(node, -1, sizeof(int) * 2 * n * 20);

    while (stackSize > 0) {
        int curr = stack[--stackSize];
        visited[curr] = 1;

        // Add current node to the trie
        int p = 0;
        for (int j = 19; j >= 0; j--) {
            int b = (curr >> j) & 1;
            if (trie[p + b] == 0) {
                trie[p + b] = trieSize++;
            }
            p = trie[p + b];
        }

        // Process queries for the current node
        for (int i = 0; i < queriesSize; i++) {
            if (queries[i][0] == curr) {
                int val = queries[i][1];
                int maxDiff = 0;
                int q = 0;
                for (int j = 19; j >= 0; j--) {
                    int b = (val >> j) & 1;
                    if (trie[q + (1 - b)] != 0) {
                        maxDiff |= (1 << j);
                        q = trie[q + (1 - b)];
                    } else {
                        q = trie[q + b];
                    }
                }
                res[i] = maxDiff;
            }
        }

        // Add children to the stack
        for (int i = 0; i < childrenSize[curr]; i++) {
            if (!visited[children[curr][i]]) {
                stack[stackSize++] = children[curr][i];
            }
        }

        // Remove current node from the trie
        p = 0;
        for (int j = 19; j >= 0; j--) {
            int b = (curr >> j) & 1;
            p = trie[p + b];
        }
    }

    free(stack);
    free(visited);
    for (int i = 0; i < n; i++) {
        free(children[i]);
    }
    free(trie);
    free(node);
    free(val);
    free(ans);

    return res; 
}