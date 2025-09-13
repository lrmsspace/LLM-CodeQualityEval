/**https://leetcode.com/problems/smallest-range-ii/ */
//You are given an integer array nums and an integer k.
//For each index i where 0 <= i < nums.length, change nums[i] to be either nums[i] + k or nums[i] - k.
//The score of nums is the difference between the maximum and minimum elements in nums.
//Return the minimum score of nums after changing the values at each index.
// 
//Example 1:
//Input: nums = [1], k = 0
//Output: 0
//Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
//Example 2:
//Input: nums = [0,10], k = 2
//Output: 6
//Explanation: Change nums to be [2, 8]. The score is max(nums) - min(nums) = 8 - 2 = 6.
//Example 3:
//Input: nums = [1,3,6], k = 3
//Output: 3
//Explanation: Change nums to be [4, 6, 3]. The score is max(nums) - min(nums) = 6 - 3 = 3.
// 
//Constraints:
//	1 <= nums.length <= 104
//	0 <= nums[i] <= 104
//	0 <= k <= 104
int smallestRangeII(int* nums, int numsSize, int k) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Initialize the minimum score as the difference between the maximum and minimum elements
    int minScore = nums[numsSize - 1] - nums[0];
    
    // Iterate through the array and adjust the elements to minimize the score
    for (int i = 0; i < numsSize - 1; i++) {
        int left = nums[i] + k;
        int right = nums[i + 1] - k;
        
        // Update the minimum score if the current range is smaller
        minScore = fmin(minScore, fmax(left, right) - nums[i]);
    }
    
    return minScore;
    
}