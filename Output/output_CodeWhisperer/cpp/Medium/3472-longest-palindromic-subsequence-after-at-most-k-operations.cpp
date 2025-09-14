/*
 You are given a string s and an integer k.
 In one operation, you can replace the character at any position with the next or previous letter in the alphabet (wrapping around so that 'a' is after 'z'). For example, replacing 'a' with the next letter results in 'b', and replacing 'a' with the previous letter results in 'z'. Similarly, replacing 'z' with the next letter results in 'a', and replacing 'z' with the previous letter results in 'y'.
 Return the length of the longest palindromic subsequence of s that can be obtained after performing at most k operations.
 Example 1:
 Input: s = "abced", k = 2
 Output: 3
 Explanation:
 Replace s[1] with the next letter, and s becomes "acced".
 Replace s[4] with the previous letter, and s becomes "accec".
 The subsequence "ccc" forms a palindrome of length 3, which is the maximum.
 Example 2:
 Input: s = "aaazzz", k = 4
 Output: 6
 Explanation:
 Replace s[0] with the previous letter, and s becomes "zaazzz".
 Replace s[4] with the next letter, and s becomes "zaazaz".
 Replace s[3] with the next letter, and s becomes "zaaaaz".
 The entire string forms a palindrome of length 6.
 Constraints:
 1 <= s.length <= 200
 1 <= k <= 200
 s consists of only lowercase English letters.
*/

class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = n-1; i >= 0; i--) {
            dp[i][i] = 1;
            for(int j = i+1; j < n; j++) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        int ans = dp[0][n-1];
        for(int i = 0; i < n; i++) {
            for(char c = 'a'; c <= 'z'; c++) {
                int cnt = 0;
                for(int j = 0; j < n; j++) {
                    if(s[j] != c) {
                        cnt++;
                    }
                }
                if(cnt <= k) {
                    int l = 0, r = n-1;
                    while(l <= r) {
                        if(s[l] != s[r]) {
                            if(s[l] == c) {
                                l++;
                                continue;
                            }
                            if(s[r] == c) {
                                r--;
                                continue;
                            }
                            ans = max(ans, dp[l+1][r-1] + k - cnt + 1);
                            break;
                        }
                        else {
                            l++;
                            r--;
                        }
                    }
                    if(l > r) {
                        ans = max(ans, k - cnt + dp[0][n-1]);
                    }
                }
            }
        }
        return ans;
            
    }
};