/**https://leetcode.com/problems/beautiful-array/ */
//An array nums of length n is beautiful if:
//	nums is a permutation of the integers in the range [1, n].
//	For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
//Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.
// 
//Example 1:
//Input: n = 4
//Output: [2,1,4,3]
//Example 2:
//Input: n = 5
//Output: [3,1,2,5,4]
// 
//Constraints:
//	1 <= n <= 1000
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* beautifulArray(int n, int* returnSize) {
    int *res = (int *)malloc(n * sizeof(int));
    int idx = 0, size = 1;
    res[idx++] = 1;
    while (size < n) {
        int new_size = 0;
        for (int i = 0; i < size; ++i) {
            if (idx < n) {
                res[idx++] = res[i] * 2 - 1;
                ++new_size;
            }
            if (idx < n) {
                res[idx++] = res[i] * 2;
                ++new_size;
            }
        }
        size = new_size;
    }
    *returnSize = n;
    return res;
}