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
    int maxNum = 0;
    for (int i = 0; i < numsSize; i++) {
        maxNum = fmax(maxNum, nums[i]);
    }
    int* parent = (int*)malloc((maxNum + 1) * sizeof(int));
    int* size = (int*)malloc((maxNum + 1) * sizeof(int));
    for (int i = 0; i <= maxNum; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    for (int i = 0; i < numsSize; i++) {
        for (int j = 2; j <= sqrt(nums[i]); j++) {
            if (nums[i] % j == 0) {
                unionSet(parent, size, nums[i], j);
                unionSet(parent, size, nums[i], nums[i] / j);
            }
        }
    }
    int* count = (int*)malloc((maxNum + 1) * sizeof(int));
    int result = 1;
    for (int i = 0; i < numsSize; i++) {
        int root = findRoot(parent, nums[i]);
        count[root]++;
        result = fmax(result, count[root]);
    }
    return result;    
}