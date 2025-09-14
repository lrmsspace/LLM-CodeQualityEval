/**https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/ */
//You are given a list of strings of the same length words and a string target.
//Your task is to form target using the given words under the following rules:
//	target should be formed from left to right.
//	To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
//	Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
//	Repeat the process until you form the string target.
//Notice that you can use multiple characters from the same string in words provided the conditions above are met.
//Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: words = ["acca","bbbb","caca"], target = "aba"
//Output: 6
//Explanation: There are 6 ways to form target.
//"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
//"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
//"aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
//"aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
//"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
//"aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
//Example 2:
//Input: words = ["abba","baab"], target = "bab"
//Output: 4
//Explanation: There are 4 ways to form target.
//"bab" -> index 0 ("baab"), index 1 ("baab"), index 2 ("abba")
//"bab" -> index 0 ("baab"), index 1 ("baab"), index 3 ("baab")
//"bab" -> index 0 ("baab"), index 2 ("baab"), index 3 ("baab")
//"bab" -> index 1 ("abba"), index 2 ("baab"), index 3 ("baab")
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length <= 1000
//	All strings in words have the same length.
//	1 <= target.length <= 1000
//	words[i] and target contain only lowercase English letters. 
class Solution {
    public:
        int numWays(vector<string>& words, string target) {
            const int MOD = 1e9 + 7;
            int m = target.length();
            int n = words[0].length();
            int wordCount = words.size();
            
            // Count the occurrences of each character at each position across all words
            vector<vector<int>> charCount(n, vector<int>(26, 0));
            for (int j = 0; j < wordCount; j++) {
                for (int i = 0; i < n; i++) {
                    charCount[i][words[j][i] - 'a']++;
                }
            }
            
            // dp[i][j] = number of ways to form target[0...i] using characters up to position j
            vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
            
            // Base case: empty target can be formed in 1 way
            for (int j = 0; j <= n; j++) {
                dp[0][j] = 1;
            }
            
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    // Option 1: Don't use the current position j-1
                    dp[i][j] = dp[i][j-1];
                    
                    // Option 2: Use the current position j-1 if the character matches
                    int targetChar = target[i-1] - 'a';
                    int count = charCount[j-1][targetChar];
                    if (count > 0) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-1] * count % MOD) % MOD;
                    }
                }
            }
            
            return dp[m][n];
        }
    };
    