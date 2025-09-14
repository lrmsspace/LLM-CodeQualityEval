/**https://leetcode.com/problems/palindrome-partitioning/ */
//Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
// 
//Example 1:
//Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]
//Example 2:
//Input: s = "a"
//Output: [["a"]]
// 
//Constraints:
//	1 <= s.length <= 16
//	s contains only lowercase English letters.  
class Solution {
    public:
        vector<vector<string>> partition(string s) {
            int n = s.length();
            vector<vector<string>> result;
            vector<string> currentPartition;
            
            // Pre-compute palindrome information
            // dp[i][j] = true if substring s[i...j] is a palindrome
            vector<vector<bool>> dp(n, vector<bool>(n, false));
            
            // All single characters are palindromes
            for (int i = 0; i < n; i++) {
                dp[i][i] = true;
            }
            
            // Check for palindromes of length 2
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == s[i + 1]) {
                    dp[i][i + 1] = true;
                }
            }
            
            // Check for palindromes of length 3 or more
            for (int len = 3; len <= n; len++) {
                for (int i = 0; i <= n - len; i++) {
                    int j = i + len - 1;
                    if (s[i] == s[j] && dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
            
            // Start backtracking from the beginning of the string
            backtrack(s, 0, dp, currentPartition, result);
            
            return result;
        }
        
    private:
        void backtrack(const string& s, int start, const vector<vector<bool>>& dp, 
                      vector<string>& currentPartition, vector<vector<string>>& result) {
            // If we've reached the end of the string, we've found a valid partition
            if (start == s.length()) {
                result.push_back(currentPartition);
                return;
            }
            
            // Try all possible substrings starting from the current position
            for (int end = start; end < s.length(); end++) {
                // If the substring s[start...end] is a palindrome
                if (dp[start][end]) {
                    // Add this palindrome to our current partition
                    currentPartition.push_back(s.substr(start, end - start + 1));
                    
                    // Recursively find all palindrome partitions for the rest of the string
                    backtrack(s, end + 1, dp, currentPartition, result);
                    
                    // Backtrack: remove the current palindrome to try other partitions
                    currentPartition.pop_back();
                }
            }
        }
    };
    