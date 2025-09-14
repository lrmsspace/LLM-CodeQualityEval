/*
 You are given an undirected tree rooted at node 0, with n nodes numbered from 0 to n - 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates an edge between nodes ui and vi.
 You are also given an integer array nums of length n, where nums[i] represents the value at node i, and an integer k.
 You may perform inversion operations on a subset of nodes subject to the following rules:
 Subtree Inversion Operation:
 When you invert a node, every value in the subtree rooted at that node is multiplied by -1.
 Distance Constraint on Inversions:
 You may only invert a node if it is "sufficiently far" from any other inverted node.
 Specifically, if you invert two nodes a and b such that one is an ancestor of the other (i.e., if LCA(a, b) = a or LCA(a, b) = b), then the distance (the number of edges on the unique path between them) must be at least k.
 Return the maximum possible sum of the tree's node values after applying inversion operations.
 Example 1:
 Input: edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], nums = [4,-8,-6,3,7,-2,5], k = 2
 Output: 27
 Explanation:
 Apply inversion operations at nodes 0, 3, 4 and 6.
 The final nums array is [-4, 8, 6, 3, 7, 2, 5], and the total sum is 27.
 Example 2:
 Input: edges = [[0,1],[1,2],[2,3],[3,4]], nums = [-1,3,-2,4,-5], k = 2
 Output: 9
 Explanation:
 Apply the inversion operation at node 4.
 The final nums array becomes [-1, 3, -2, 4, 5], and the total sum is 9.
 Example 3:
 Input: edges = [[0,1],[0,2]], nums = [0,-1,-2], k = 3
 Output: 3
 Explanation:
 Apply inversion operations at nodes 1 and 2.
 Constraints:
 2 <= n <= 5 * 104
 edges.length == n - 1
 edges[i] = [ui, vi]
 0 <= ui, vi < n
 nums.length == n
 -5 * 104 <= nums[i] <= 5 * 104
 1 <= k <= 50
 The input is generated such that edges represents a valid tree.
*/

typedef struct Node {
    int value;
    bool visited;
    int distance;
    struct Node** neighbors;
    int numNeighbors;
} Node;

int calculateDistance(int** edges, int edgesSize, int* edgesColSize, int node1, int node2) {
    for (int i = 0; i < edgesSize; i++) {
        if ((edges[i][0] == node1 && edges[i][1] == node2) || (edges[i][0] == node2 && edges[i][1] == node1)) {
            return edgesColSize[i] - 1;
        }
    }
    return -1;
}

void dfs(Node* node, int* currentSum, int k, int* maxSum) {
    node->visited = true;
    *currentSum += node->value;

    for (int i = 0; i < node->numNeighbors; i++) {
        Node* neighbor = node->neighbors[i];
        if (!neighbor->visited && calculateDistance(edges, edgesSize, edgesColSize, node - neighbor, neighbor) >= k) {
            dfs(neighbor, currentSum, k, maxSum);
        }
    }

    if (*currentSum > *maxSum) {
        *maxSum = *currentSum;
    }

    node->visited = false;
    *currentSum -= node->value;
}

long long subtreeInversionSum(int** edges, int edgesSize, int* edgesColSize, int* nums, int numsSize, int k) {
    Node* nodes = (Node*)malloc(numsSize * sizeof(Node));
    for (int i = 0; i < numsSize; i++) {
        nodes[i].value = nums[i];
        nodes[i].visited = false;
        nodes[i].neighbors = (Node**)malloc(numsSize * sizeof(Node*));
        nodes[i].numNeighbors = 0;
    }

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        nodes[u].neighbors[nodes[u].numNeighbors++] = &nodes[v];
        nodes[v].neighbors[nodes[v].numNeighbors++] = &nodes[u];
    }

    int maxSum = 0;
    dfs(&nodes[0], &maxSum, k, &maxSum);

    free(nodes);
    return maxSum;
}