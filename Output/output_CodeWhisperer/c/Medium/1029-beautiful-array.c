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
    int* result = (int*)malloc(sizeof(int) * n);
    *returnSize = n;
    if (n == 1) {
        result[0] = 1;
        return result;
    }
    int* left = beautifulArray((n + 1) / 2, returnSize);
    int* right = beautifulArray(n / 2, returnSize);
    for (int i = 0; i < n / 2; i++) {
        result[i] = left[i] * 2 - 1;
        result[i + n / 2] = right[i] * 2;
    }
    free(left);
    free(right);
    return result;
}