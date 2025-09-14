/**https://leetcode.com/problems/number-of-ways-to-split-a-string/ */
//Given a binary string s, you can split s into 3 non-empty strings s1, s2, and s3 where s1 + s2 + s3 = s.
//Return the number of ways s can be split such that the number of ones is the same in s1, s2, and s3. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: s = "10101"
//Output: 4
//Explanation: There are four ways to split s in 3 parts where each part contain the same number of letters '1'.
//"1|010|1"
//"1|01|01"
//"10|10|1"
//"10|1|01"
//Example 2:
//Input: s = "1001"
//Output: 0
//Example 3:
//Input: s = "0000"
//Output: 3
//Explanation: There are three ways to split s in 3 parts.
//"0|0|00"
//"0|00|0"
//"00|0|0"
// 
//Constraints:
//	3 <= s.length <= 105
//	s[i] is either '0' or '1'.
int numWays(char* s) {
    const int MOD = 1e9 + 7;
    int onesCount = 0, n = strlen(s);

    // Count the total number of '1's in the string
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') onesCount++;
    }

    // If the number of ones is not divisible by 3, return 0
    if (onesCount % 3 != 0) return 0;

    // If there are no ones, then we can choose two split points in (n-1) ways
    if (onesCount == 0) return (long long)(n - 1) * (n - 2) / 2 % MOD;

    int onesPerPart = onesCount / 3;
    int count = 0, firstSplitWays = 0, secondSplitWays = 0;

    // Find the number of ways to split at both required positions
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') count++;

        if (count == onesPerPart) firstSplitWays++;
        else if (count == 2 * onesPerPart) secondSplitWays++;
    }

    return (long long)firstSplitWays * secondSplitWays % MOD;
}
    