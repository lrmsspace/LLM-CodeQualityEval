/**https://leetcode.com/problems/create-components-with-same-value/ */
//There is an undirected tree with n nodes labeled from 0 to n - 1.
//You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//You are allowed to delete some edges, splitting the tree into multiple connected components. Let the value of a component be the sum of all nums[i] for which node i is in the component.
//Return the maximum number of edges you can delete, such that every connected component in the tree has the same value.
// 
//Example 1:
//Input: nums = [6,2,2,2,6], edges = [[0,1],[1,2],[1,3],[3,4]] 
//Output: 2 
//Explanation: The above figure shows how we can delete the edges [0,1] and [3,4]. The created components are nodes [0], [1,2,3] and [4]. The sum of the values in each component equals 6. It can be proven that no better deletion exists, so the answer is 2.
//Example 2:
//Input: nums = [2], edges = []
//Output: 0
//Explanation: There are no edges to be deleted.
// 
//Constraints:
//	1 <= n <= 2 * 104
//	nums.length == n
//	1 <= nums[i] <= 50
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= edges[i][0], edges[i][1] <= n - 1
//	edges represents a valid tree.
int componentValue(int* nums, int numsSize, int** edges, int edgesSize, int* edgesColSize) {
    int n = numsSize;
    int* parent = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int* idx = (int*)malloc(sizeof(int) * edgesSize);
    for (int i = 0; i < edgesSize; i++) {
        idx[i] = i;
    }
    qsort(idx, edgesSize, sizeof(int), cmp);
    int* weight = (int*)malloc(sizeof(int) * edgesSize);
    for (int i = 0; i < edgesSize; i++) {
        weight[i] = nums[edges[idx[i]][1]];
    }
    int* find = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        find[i] = i;
    }
    int* rank = (int*)malloc(sizeof(int) * n);
    memset(rank, 0, sizeof(int) * n);
    int* size = (int*)malloc(sizeof(int) * n);
    memset(size, 1, sizeof(int) * n);
    int* mst = (int*)malloc(sizeof(int) * n);
    int* mstIdx = (int*)malloc(sizeof(int) * n);
    int ans = 0;
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[idx[i]][0];
        int v = edges[idx[i]][1];
        int fu = findSet(u, find);
        int fv = findSet(v, find);
        if (fu != fv) {
            if (size[fu] < size[fv]) {
                int temp = fu;
                fu = fv;
                fv = temp;
            }
            parent[fv] = fu;
            size[fu] += size[fv];
            mst[mstIdx[fu] = mstIdx[fv]] = weight[idx[i]];
            ans += weight[idx[i]];
        }
    }
    int* count = (int*)malloc(sizeof(int) * n);
    memset(count, 0, sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        count[findSet(i, parent)]++;
    }
    for (int i = 0; i < n; i++) {
        if (count[i] > 0 && ans % count[i] == 0) {
            int target = ans / count[i];
            int valid = 1;
            for (int j = 0; j < n; j++) {
                if (findSet(j, parent) == i && nums[j] > target) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                return count[i] - 1;
            }
        }
    }
    return 0;   
}