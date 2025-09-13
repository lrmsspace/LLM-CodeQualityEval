/**https://leetcode.com/problems/combinations/ */
//Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
//You may return the answer in any order.
// 
//Example 1:
//Input: n = 4, k = 2
//Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
//Explanation: There are 4 choose 2 = 6 total combinations.
//Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
//Example 2:
//Input: n = 1, k = 1
//Output: [[1]]
//Explanation: There is 1 choose 1 = 1 total combination.
// 
//Constraints:
//	1 <= n <= 20
//	1 <= k <= n
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    if(k == 0) {
        *returnSize = 0;
        *returnColumnSizes = malloc(sizeof(int));
        (*returnColumnSizes)[0] = 0;
        return malloc(sizeof(int*));
    }
    
    if(n == k) {
        *returnSize = 1;
        *returnColumnSizes = malloc(sizeof(int));
        (*returnColumnSizes)[0] = k;
        int** result = malloc(sizeof(int*));
        result[0] = malloc(sizeof(int) * k);
        for(int i = 0; i < k; i++) {
            result[0][i] = i + 1;
        }
        return result;
    }
    
    int** result = malloc(sizeof(int*) * (n - k + 1));
    *returnSize = n - k + 1;
    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = k;
        result[i] = malloc(sizeof(int) * k);
        combineHelper(n, k, i + 1, result[i]);
    }
    
    return result;
    
}