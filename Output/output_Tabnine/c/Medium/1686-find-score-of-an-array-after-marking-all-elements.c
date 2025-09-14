/**https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/ */
//You are given an array nums consisting of positive integers.
//Starting with score = 0, apply the following algorithm:
//	Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
//	Add the value of the chosen integer to score.
//	Mark the chosen element and its two adjacent elements if they exist.
//	Repeat until all the array elements are marked.
//Return the score you get after applying the above algorithm.
// 
//Example 1:
//Input: nums = [2,1,3,4,5,2]
//Output: 7
//Explanation: We mark the elements as follows:
//- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
//- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
//- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
//Our score is 1 + 2 + 4 = 7.
//Example 2:
//Input: nums = [2,3,5,1,3,2]
//Output: 5
//Explanation: We mark the elements as follows:
//- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
//- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
//- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
//Our score is 1 + 2 + 2 = 5.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 106
long long findScore(int* nums, int numsSize) {
    int* mark = (int*)calloc(numsSize, sizeof(int));
    int* left = (int*)calloc(numsSize, sizeof(int));
    int* right = (int*)calloc(numsSize, sizeof(int));
    int minIndex = -1;
    long long score = 0;
    
    for (int i = 0; i < numsSize; i++) {
        mark[i] = 0;
        left[i] = i > 0? nums[i - 1] : INT_MAX;
        right[i] = i < numsSize - 1? nums[i + 1] : INT_MAX;
    }

    for (int i = 0; i < numsSize; i++) {
        if (mark[i] == 0) {
            if (minIndex == -1 || (left[i] == left[minIndex] && nums[i] < nums[minIndex])) {
                minIndex = i;
            }
            score += nums[i];
            mark[i] = 1;
            if (i > 0) {
                mark[i - 1] = 1;
            }
            if (i < numsSize - 1) {
                mark[i + 1] = 1;
            }
        }
    }
    
    free(mark);
    free(left);
    free(right);
    
    return score;
    
}