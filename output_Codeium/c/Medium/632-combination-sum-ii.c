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

void backtracking(int *candidates, int candidatesSize, int target, int start, int *index, int **ans, int *ansCols, int used[]) {
    if (target == 0) {
        ans[*index] = (int *)malloc(sizeof(int) * (candidatesSize - start));
        int j = 0;
        for (int i = start; i < candidatesSize; i++) {
            if (used[i]) {
                ans[*index][j++] = candidates[i];
            }
        }
        ansCols[(*index)++] = j;
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue;
        }
        if (target - candidates[i] < 0) {
            break;
        }
        used[i] = 1;
        backtracking(candidates, candidatesSize, target - candidates[i], i + 1, index, ans, ansCols, used);
        used[i] = 0;
    }
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {

    int **ans = (int **)malloc(sizeof(int *) * (candidatesSize + 1));
    int *ansCols = (int *)malloc(sizeof(int) * (candidatesSize + 1));
    int index = 0;
    int used[candidatesSize];
    memset(used, 0, sizeof(used));
    backtracking(candidates, candidatesSize, target, 0, &index, ans, ansCols, used);
    *returnSize = index;
    *returnColumnSizes = ansCols;
    return ans;
}   