/*
 You are given an integer array nums of length n and a positive integer k.
 The power of an array of integers is defined as the number of subsequences with their sum equal to k.
 Return the sum of power of all subsequences of nums.
 Since the answer may be very large, return it modulo 109 + 7.
 Example 1:
 Input:   nums = [1,2,3], k = 3 
 Output:   6 
 Explanation:
 There are 5 subsequences of nums with non-zero power:
 The subsequence [1,2,3] has 2 subsequences with sum == 3: [1,2,3] and [1,2,3].
 The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
 The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
 The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
 The subsequence [1,2,3] has 1 subsequence with sum == 3: [1,2,3].
 Hence the answer is 2 + 1 + 1 + 1 + 1 = 6.
 Example 2:
 Input:   nums = [2,3,3], k = 5 
 Output:   4 
 Explanation:
 There are 3 subsequences of nums with non-zero power:
 The subsequence [2,3,3] has 2 subsequences with sum == 5: [2,3,3] and [2,3,3].
 The subsequence [2,3,3] has 1 subsequence with sum == 5: [2,3,3].
 The subsequence [2,3,3] has 1 subsequence with sum == 5: [2,3,3].
 Hence the answer is 2 + 1 + 1 = 4.
 Example 3:
 Input:   nums = [1,2,3], k = 7 
 Output:   0 
 Explanation: There exists no subsequence with sum 7. Hence all subsequences of nums have power = 0.
 Constraints:
 1 <= n <= 100
 1 <= nums[i] <= 104
 1 <= k <= 100
*/

int sumOfPower(int* nums, int numsSize, int k) {
    const int MOD = 1000000007;
    // dp[i][j] represents number of subsequences ending at index i with sum j
    int dp[101][101] = {0};
    
    // Initialize base case
    dp[0][0] = 1;
    if(nums[0] <= k) {
        dp[0][nums[0]] = 1;
    }
    
    // For each index
    for(int i = 1; i < numsSize; i++) {
        // Copy previous state
        for(int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
        }
        
        // Add current number to previous sums
        for(int j = 0; j <= k - nums[i]; j++) {
            dp[i][j + nums[i]] = (dp[i][j + nums[i]] + dp[i-1][j]) % MOD;
        }
    }
    
    long long result = 0;
    
    // For each subsequence ending at index i
    for(int i = 0; i < numsSize; i++) {
        // Add number of subsequences with sum k
        result = (result + dp[i][k]) % MOD;
    }
    
    return (int)result;
}            
