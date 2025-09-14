/**https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/ */
//You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.
//Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
//Return the minimum possible difference.
// 
//Example 1:
//Input: nums = [90], k = 1
//Output: 0
//Explanation: There is one way to pick score(s) of one student:
//- [90]. The difference between the highest and lowest score is 90 - 90 = 0.
//The minimum possible difference is 0.
//Example 2:
//Input: nums = [9,4,1,7], k = 2
//Output: 2
//Explanation: There are six ways to pick score(s) of two students:
//- [9,4,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
//- [9,4,1,7]. The difference between the highest and lowest score is 9 - 1 = 8.
//- [9,4,1,7]. The difference between the highest and lowest score is 9 - 7 = 2.
//- [9,4,1,7]. The difference between the highest and lowest score is 4 - 1 = 3.
//- [9,4,1,7]. The difference between the highest and lowest score is 7 - 4 = 3.
//- [9,4,1,7]. The difference between the highest and lowest score is 7 - 1 = 6.
//The minimum possible difference is 2.
// 
//Constraints:
//	1 <= k <= nums.length <= 1000
//	0 <= nums[i] <= 105
int minimumDifference(int* nums, int numsSize, int k) {
    if (k == 1) {
        return 0;
    }
    if (k == numsSize) {
        int min = nums[0];
        int max = nums[0];
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] < min) {
                min = nums[i];
            }
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        return max - min;
    }
    int min = 100000;
    for (int i = 0; i <= numsSize - k; i++) {
        int max = nums[i];
        int min = nums[i];
        for (int j = i + 1; j < i + k; j++) {
            if (nums[j] < min) {
                min = nums[j];
            }
            if (nums[j] > max) {
                max = nums[j];
            }
        }
        if (max - min < min) {
            min = max - min;
        }
    }
    return min;
    
}