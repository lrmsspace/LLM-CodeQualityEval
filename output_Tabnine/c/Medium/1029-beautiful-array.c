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
    int* result = malloc(sizeof(int) * n);
    int* temp = malloc(sizeof(int) * n);
    int index = 0;
    
    for (int i = 1; i <= n; i += 2) {
        temp[index++] = i;
    }
    
    for (int i = 0; i < n / 2; i++) {
        result[i] = temp[i];
        result[n - 1 - i] = temp[n - 1 - i];
    }
    
    *returnSize = n;
    return result;
    
}