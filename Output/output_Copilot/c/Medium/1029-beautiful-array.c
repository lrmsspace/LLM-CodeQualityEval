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
    int *res = (int *)malloc(sizeof(int) * n);
    *returnSize = n;
    int *tmp = (int *)malloc(sizeof(int) * n);
    int tmpSize = 0;
    res[0] = 1;
    int resSize = 1;
    while (resSize < n) {
        tmpSize = 0;
        for (int i = 0; i < resSize; i++) {
            if (res[i] * 2 - 1 <= n) {
                tmp[tmpSize++] = res[i] * 2 - 1;
            }
        }
        for (int i = 0; i < resSize; i++) {
            if (res[i] * 2 <= n) {
                tmp[tmpSize++] = res[i] * 2;
            }
        }
        for (int i = 0; i < tmpSize; i++) {
            res[i] = tmp[i];
        }
        resSize = tmpSize;
    }
    free(tmp);
    return res;    
}