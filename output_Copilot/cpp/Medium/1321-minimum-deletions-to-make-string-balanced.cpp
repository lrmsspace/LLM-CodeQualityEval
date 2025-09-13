/**https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/ */
//You are given a string s consisting only of characters 'a' and 'b'​​​​.
//You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
//Return the minimum number of deletions needed to make s balanced.
// 
//Example 1:
//Input: s = "aababbab"
//Output: 2
//Explanation: You can either:
//Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
//Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
//Example 2:
//Input: s = "bbaaaaabb"
//Output: 2
//Explanation: The only solution is to delete the first two characters.
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is 'a' or 'b'​​.
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') cnt++;
            dp[i] = cnt;
        }
        int ans = INT_MAX;
        cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'a') cnt++;
            ans = min(ans, cnt + dp[i]);
        }
        return ans;        
    }
};