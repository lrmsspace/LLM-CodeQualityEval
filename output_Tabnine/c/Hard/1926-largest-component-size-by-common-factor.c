/**https://leetcode.com/problems/largest-component-size-by-common-factor/ */
//You are given an integer array of unique positive integers nums. Consider the following graph:
//	There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
//	There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
//Return the size of the largest connected component in the graph.
// 
//Example 1:
//Input: nums = [4,6,15,35]
//Output: 4
//Example 2:
//Input: nums = [20,50,9,63]
//Output: 2
//Example 3:
//Input: nums = [2,3,6,7,4,12,21,39]
//Output: 8
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i] <= 105
//	All the values of nums are unique.
int largestComponentSize(int* nums, int numsSize) {
    int n = numsSize;
    int* parent = malloc(n * sizeof(int));
    int* size = malloc(n * sizeof(int));
    
    // Initialize parent and size arrays
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    
    // Union-Find algorithm to find the parent of a number
    int find(int x) {
        if (x!= parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    // Union two numbers by their parent
    void union_(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if (px!= py) {
            if (size[px] < size[py]) {
                parent[px] = py;
                size[py] += size[px];
            } else {
                parent[py] = px;
                size[px] += size[py];
            }
        }
    }
    
    // Sort the numbers based on their prime factors
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Union numbers with common factors greater than 1
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] % nums[i] == 0) {
                union_(i, j);
            }
        }
    }
    
    // Find the size of the largest connected component
    int maxSize = 0;
    for (int i = 0; i < n; i++) {
        maxSize = fmax(maxSize, size[find(i)]);
    }
    
    free(parent);
    free(size);
    return maxSize;
    
}