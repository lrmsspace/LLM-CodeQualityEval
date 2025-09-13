/**https://leetcode.com/problems/combination-sum/ */
//Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
//The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
//The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
// 
//Example 1:
//Input: candidates = [2,3,6,7], target = 7
//Output: [[2,2,3],[7]]
//Explanation:
//2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
//7 is a candidate, and 7 = 7.
//These are the only two combinations.
//Example 2:
//Input: candidates = [2,3,5], target = 8
//Output: [[2,2,2,2],[2,3,3],[3,5]]
//Example 3:
//Input: candidates = [2], target = 1
//Output: []
// 
//Constraints:
//	1 <= candidates.length <= 30
//	2 <= candidates[i] <= 40
//	All elements of candidates are distinct.
//	1 <= target <= 40
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 150);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 150);
    *returnSize = 0;
    int* combination = (int*)malloc(sizeof(int) * 30);
    int combinationSize = 0;
    int i = 0;
    while (i < candidatesSize) {
        if (candidates[i] <= target) {
            combination[combinationSize++] = candidates[i];
            if (candidates[i] == target) {
                result[*returnSize] = (int*)malloc(sizeof(int) * combinationSize);
                memcpy(result[*returnSize], combination, sizeof(int) * combinationSize);
                (*returnColumnSizes)[*returnSize] = combinationSize;
                (*returnSize)++;
            }
            else {
                int** subResult;
                int subReturnSize;
                int* subReturnColumnSizes;
                subResult = combinationSum(candidates, candidatesSize, target - candidates[i], &subReturnSize, &subReturnColumnSizes);
                for (int j = 0; j < subReturnSize; j++) {
                    result[*returnSize] = (int*)malloc(sizeof(int) * (combinationSize + subReturnColumnSizes[j]));
                    memcpy(result[*returnSize], combination, sizeof(int) * combinationSize);
                    memcpy(result[*returnSize] + combinationSize, subResult[j], sizeof(int) * subReturnColumnSizes[j]);
                    (*returnColumnSizes)[*returnSize] = combinationSize + subReturnColumnSizes[j];
                    (*returnSize)++;
                }
            }
            combinationSize--;
        }
        i++;
    }
    
}