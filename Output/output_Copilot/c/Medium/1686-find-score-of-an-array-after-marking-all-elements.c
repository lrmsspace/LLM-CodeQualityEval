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
    int *mark = (int *)malloc(sizeof(int) * numsSize);
    memset(mark, 0, sizeof(int) * numsSize);
    long long score = 0;
    for (int i = 0; i < numsSize; i++) {
        if (mark[i] == 1) {
            continue;
        }
        int left = i, right = i;
        while (left >= 0 && mark[left] == 0) {
            left--;
        }
        while (right < numsSize && mark[right] == 0) {
            right++;
        }
        int minIndex = i;
        for (int j = left + 1; j < right; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        score += nums[minIndex];
        mark[minIndex] = 1;
        if (minIndex - 1 >= 0) {
            mark[minIndex - 1] = 1;
        }
        if (minIndex + 1 < numsSize) {
            mark[minIndex + 1] = 1;
        }
    }
    free(mark);
    return score;    
}