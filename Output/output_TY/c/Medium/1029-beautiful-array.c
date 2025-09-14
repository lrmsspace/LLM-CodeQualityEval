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
int* beautifulArray(int n, int* returnSize){
    *returnSize = n;
    int *res = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) res[i] = i + 1;
    while (n > 1) {
        int *tmp = (int*)malloc(sizeof(int) * (n / 2));
        int k = 0;
        for (int i = 0; i < n; i += 2) {
            tmp[k++] = res[i];
        }
        for (int i = 1; i < n; i += 2) {
            tmp[k++] = res[i];
        }
        n /=2;
    }
    return res;
}