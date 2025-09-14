/*
 You are given an integer array nums of length n.
 Your goal is to start at index 0 and reach index n - 1. You can only jump to indices greater than your current index.
 The score for a jump from index i to index j is calculated as (j - i) * nums[i].
 Return the maximum possible total score by the time you reach the last index.
 Example 1:
 Input: nums = [1,3,1,5]
 Output: 7
 Explanation:
 First, jump to index 1 and then jump to the last index. The final score is 1 * 1 + 2 * 3 = 7.
 Example 2:
 Input: nums = [4,3,1,3,2]
 Output: 16
 Explanation:
 Jump directly to the last index. The final score is 4 * 4 = 16.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 105
*/

long long findMaximumScore(int* nums, int numsSize) {

    // Create an array dp of size n to store the maximum score at each index
    long long* dp = (long long*)malloc(sizeof(long long) * numsSize);
    
    // Initialize the first index with the score of jumping to it
    dp[0] = nums[0];    
    
    // Iterate through the array from index 1 to n - 1  
    for (int i = 1; i < numsSize; i++) {
        
        // Initialize the maximum score at the current index as the score of the current index
        dp[i] = nums[i];
        
        // Iterate through the previous indices to find the maximum score that can be obtained by jumping to the current index
        for (int j = i - 1; j >= 0; j--) {
            
            // Update the maximum score at the current index if it is greater than the sum of the maximum score at the previous index and the score of the current index
            if (dp[i] < dp[j] + nums[i]) {
                dp[i] = dp[j] + nums[i];
            }
        }
    }
    
    // Return the maximum possible total score
    long long result = dp[numsSize - 1];
    free(dp);
    return result;  
    
}