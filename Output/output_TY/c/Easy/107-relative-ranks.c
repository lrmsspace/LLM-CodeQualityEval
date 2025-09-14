/**https://leetcode.com/problems/relative-ranks/ */
//You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.
//The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:
//	The 1st place athlete's rank is "Gold Medal".
//	The 2nd place athlete's rank is "Silver Medal".
//	The 3rd place athlete's rank is "Bronze Medal".
//	For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
//Return an array answer of size n where answer[i] is the rank of the ith athlete.
// 
//Example 1:
//Input: score = [5,4,3,2,1]
//Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
//Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
//Example 2:
//Input: score = [10,3,8,9,4]
//Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
//Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].
// 
//Constraints:
//	n == score.length
//	1 <= n <= 104
//	0 <= score[i] <= 106
//	All the values in score are unique.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findRelativeRanks(int* score, int scoreSize, int* returnSize){
        // 创建一个副本数组，用于排序
    int *sortedScore = (int *)malloc(scoreSize * sizeof(int));
    memcpy(sortedScore, score, scoreSize * sizeof(int));

    // 对副本数组进行降序排序
    qsort(sortedScore, scoreSize, sizeof(int), compare);

    // 创建结果数组
    char **result = (char **)malloc(scoreSize * sizeof(char *));
    *returnSize = scoreSize;

    // 填充结果数组
    for (int i = 0; i < scoreSize; i++) {
        int index = findIndex(score, scoreSize, sortedScore[i]);
        if (i == 0) {
            result[index] = strdup("Gold Medal");
        } else if (i == 1) {
            result[index] = strdup("Silver Medal");
        } else if (i == 2) {
            result[index] = strdup("Bronze Medal");
        } else {
            char rank[10];
            sprintf(rank, "%d", i + 1);
            result[index] = strdup(rank);
        }
    }

    // 释放副本数组
    free(sortedScore);

    return result;
}