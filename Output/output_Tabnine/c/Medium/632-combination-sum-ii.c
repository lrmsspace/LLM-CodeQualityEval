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
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * candidatesSize);
    memset(*returnColumnSizes, 0, sizeof(int) * candidatesSize);
    
    qsort(candidates, candidatesSize, sizeof(int), compare);
    
    int** result = malloc(sizeof(int*) * 1000);
    for (int i = 0; i < 1000; i++) {
        result[i] = malloc(sizeof(int) * 100);
        memset(result[i], 0, sizeof(int) * 100);
    }
    
    combinationSum2Helper(candidates, candidatesSize, target, 0, 0, result, returnSize, returnColumnSizes);
    
    return result;
    
}