/**https://leetcode.com/problems/split-array-with-same-average/ */
//You are given an integer array nums.
//You should move each element of nums into one of the two arrays A and B such that A and B are non-empty, and average(A) == average(B).
//Return true if it is possible to achieve that and false otherwise.
//Note that for an array arr, average(arr) is the sum of all the elements of arr over the length of arr.
// 
//Example 1:
//Input: nums = [1,2,3,4,5,6,7,8]
//Output: true
//Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have an average of 4.5.
//Example 2:
//Input: nums = [3,1]
//Output: false
// 
//Constraints:
//	1 <= nums.length <= 30
//	0 <= nums[i] <= 104
bool splitArraySameAverage(int* nums, int numsSize) {
    // Sum of all numbers
    long long sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    
    // If the sum is odd, it's impossible to split the array into two equal-sized subarrays with an average
    if (sum % 2!= 0) {
        return false;
    }
    
    // Find the target average
    long long target = sum / 2;
    
    // Initialize a 2D dp array dp[i][j] to store whether it is possible to split nums[0..i] into two subarrays with average j
    bool dp[numsSize + 1][target + 1];
    
    // Initialize the first row and column of the dp array
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= numsSize; i++) {
        dp[i][0] = true;
    }
    
    // Fill the dp array
    for (int i = 1; i <= numsSize; i++) {
        for (int j = 1; j <= target; j++) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    
    // Return the result
    return dp[numsSize][target];
    
}