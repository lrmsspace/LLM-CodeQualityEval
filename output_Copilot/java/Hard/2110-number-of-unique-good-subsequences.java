/**https://leetcode.com/problems/number-of-unique-good-subsequences/ */
//You are given a binary string binary. A subsequence of binary is considered good if it is not empty and has no leading zeros (with the exception of "0").
//Find the number of unique good subsequences of binary.
//	For example, if binary = "001", then all the good subsequences are ["0", "0", "1"], so the unique good subsequences are "0" and "1". Note that subsequences "00", "01", and "001" are not good because they have leading zeros.
//Return the number of unique good subsequences of binary. Since the answer may be very large, return it modulo 109 + 7.
//A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
// 
//Example 1:
//Input: binary = "001"
//Output: 2
//Explanation: The good subsequences of binary are ["0", "0", "1"].
//The unique good subsequences are "0" and "1".
//Example 2:
//Input: binary = "11"
//Output: 2
//Explanation: The good subsequences of binary are ["1", "1", "11"].
//The unique good subsequences are "1" and "11".
//Example 3:
//Input: binary = "101"
//Output: 5
//Explanation: The good subsequences of binary are ["1", "0", "1", "10", "11", "101"]. 
//The unique good subsequences are "0", "1", "10", "11", and "101".
// 
//Constraints:
//	1 <= binary.length <= 105
//	binary consists of only '0's and '1's.
class Solution {
    public int numberOfUniqueGoodSubsequences(String binary) {
        int n = binary.length(), mod = 1000000007;
        long[] dp = new long[n + 1], last = new long[2];
        dp[0] = 1; // empty string is a good subsequence

        for (int i = 1; i <= n; i++) {
            char c = binary.charAt(i - 1);
            if (c == '0') {
                dp[i] = dp[i - 1] * 2 % mod; // double the count of good subsequences
                last[0] = (last[0] + dp[i - 1]) % mod; // update last occurrence of '0'
            } else {
                dp[i] = (dp[i - 1] * 2 + last[0]) % mod; // add last occurrence of '0' to count
                last[1] = (last[1] + dp[i - 1]) % mod; // update last occurrence of '1'
            }
        }

        return (int) ((dp[n] + mod - last[0]) % mod); // subtract empty subsequence and last occurrence of '0'        
    }
}