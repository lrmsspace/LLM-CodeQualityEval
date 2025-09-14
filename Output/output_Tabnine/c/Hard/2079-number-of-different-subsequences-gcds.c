/**https://leetcode.com/problems/number-of-different-subsequences-gcds/ */
//You are given an array nums that consists of positive integers.
//The GCD of a sequence of numbers is defined as the greatest integer that divides all the numbers in the sequence evenly.
//	For example, the GCD of the sequence [4,6,16] is 2.
//A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.
//	For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
//Return the number of different GCDs among all non-empty subsequences of nums.
// 
//Example 1:
//Input: nums = [6,10,3]
//Output: 5
//Explanation: The figure shows all the non-empty subsequences and their GCDs.
//The different GCDs are 6, 10, 3, 2, and 1.
//Example 2:
//Input: nums = [5,15,40,5,6]
//Output: 7
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 2 * 105
int countDifferentSubsequenceGCDs(int* nums, int numsSize) {
    // Initialize a 2D dp array dp[i][j] to store the count of different GCDs for the first i numbers and ending with j.
    int dp[100005][21] = {0};
    
    // Initialize the dp array with base cases.
    for (int i = 0; i < 21; i++) {
        dp[0][i] = 1;
    }
    
    // Calculate the dp array.
    for (int i = 1; i <= numsSize; i++) {
        for (int j = 0; j < 21; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 1000000007;
            }
        }
    }
    
    // Calculate the count of different GCDs for the given nums array.
    int result = 0;
    for (int i = 0; i < 21; i++) {
        result = (result + dp[numsSize][i]) % 1000000007;
    }
    
    return result;
    
}