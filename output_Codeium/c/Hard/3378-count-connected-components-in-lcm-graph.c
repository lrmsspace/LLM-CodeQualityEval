/*
 You are given an array of integers nums of size n and a positive integer threshold.
 There is a graph consisting of n nodes with the ith node having a value of nums[i]. Two nodes i and j in the graph are connected via an undirected edge if lcm(nums[i], nums[j]) <= threshold.
 Return the number of connected components in this graph.
 A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
 The term lcm(a, b) denotes the least common multiple of a and b.
 Example 1:
 Input: nums = [2,4,8,3,9], threshold = 5
 Output: 4
 Explanation: 
 The four connected components are (2, 4), (3), (8), (9).
 Example 2:
 Input: nums = [2,4,8,3,9,12], threshold = 10
 Output: 2
 Explanation: 
 The two connected components are (2, 3, 4, 8, 9), and (12).
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
 All elements of nums are unique.
 1 <= threshold <= 2 * 105
*/

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void unionFindUnion(int* parent, int* rank, int x, int y) {
    int rootX = unionFindFind(parent, x);
    int rootY = unionFindFind(parent, y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int unionFindFind(int* parent, int x) {
    if (parent[x] != x) {
        parent[x] = unionFindFind(parent, parent[x]);
    }
    return parent[x];
}

int countComponents(int* nums, int numsSize, int threshold) {
    int* parent = (int*)malloc(numsSize * sizeof(int));
    int* rank = (int*)calloc(numsSize, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (lcm(nums[i], nums[j]) <= threshold) {
                unionFindUnion(parent, rank, i, j);
            }
        }
    }
    
    int components = 0;
    for (int i = 0; i < numsSize; i++) {
        if (parent[i] == i) {
            components++;
        }
    }
    
    free(parent);
    free(rank);
    
    return components;
}
