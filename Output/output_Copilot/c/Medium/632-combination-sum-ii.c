/**https://leetcode.com/problems/combination-sum-ii/ */
//Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
//Each number in candidates may only be used once in the combination.
//Note: The solution set must not contain duplicate combinations.
// 
//Example 1:
//Input: candidates = [10,1,2,7,6,1,5], target = 8
//Output: 
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//]
//Example 2:
//Input: candidates = [2,5,2,1,2], target = 5
//Output: 
//[
//[1,2,2],
//[5]
//]
// 
//Constraints:
//	1 <= candidates.length <= 100
//	1 <= candidates[i] <= 50
//	1 <= target <= 30
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int **res = (int **)malloc(sizeof(int *) * 1000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 1000);
    int *temp = (int *)malloc(sizeof(int) * 1000);
    int tempSize = 0;
    int resSize = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int sum = 0;
    int flag = 0;
    int *visited = (int *)malloc(sizeof(int) * candidatesSize);
    for (i = 0; i < candidatesSize; i++) {
        visited[i] = 0;
    }
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    dfs(candidates, candidatesSize, target, 0, temp, &tempSize, res, &resSize, returnColumnSizes, visited);
    *returnSize = resSize;
    return res;    
}