/**https://leetcode.com/problems/combination-sum-iii/ */
//Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
//	Only numbers 1 through 9 are used.
//	Each number is used at most once.
//Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
// 
//Example 1:
//Input: k = 3, n = 7
//Output: [[1,2,4]]
//Explanation:
//1 + 2 + 4 = 7
//There are no other valid combinations.
//Example 2:
//Input: k = 3, n = 9
//Output: [[1,2,6],[1,3,5],[2,3,4]]
//Explanation:
//1 + 2 + 6 = 9
//1 + 3 + 5 = 9
//2 + 3 + 4 = 9
//There are no other valid combinations.
//Example 3:
//Input: k = 4, n = 1
//Output: []
//Explanation: There are no valid combinations.
//Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
// 
//Constraints:
//	2 <= k <= 9
//	1 <= n <= 60
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    int** ans = (int**)malloc(sizeof(int*) * 10000);
    int ans_size = 0;
    int* ans_col = (int*)malloc(sizeof(int) * 10000);
    int ans_col_size = 0;
    int i, j;
    for (i = 1; i <= 9; i++) {
        for (j = i + 1; j <= 9;j++) {
            if (i + j <= n) {
                ans[ans_size] = (int*)malloc(sizeof(int) * 3);
                ans[ans_size][0] = i;
                ans[ans_size][1] = j;
                ans[ans_size][2] = n - i - j;
                ans_col[ans_col_size] = 3;
                ans_size++;
                ans_col_size++;
            }
        }
    }
    *returnSize = ans_size;
    *returnColumnSizes = ans_col;
    return ans;
}