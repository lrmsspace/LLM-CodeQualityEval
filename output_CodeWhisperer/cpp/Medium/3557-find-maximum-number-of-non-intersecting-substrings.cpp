/*
 You are given a string word.
 Return the maximum number of non-intersecting substrings of word that are at least four characters long and start and end with the same letter.
 Example 1:
 Input: word = "abcdeafdef"
 Output: 2
 Explanation:
 The two substrings are "abcdea" and "fdef".
 Example 2:
 Input: word = "bcdaaaab"
 Output: 1
 Explanation:
 The only substring is "aaaa". Note that we cannot also choose "bcdaaaab" since it intersects with the other substring.
 Constraints:
 1 <= word.length <= 2 * 105
 word consists only of lowercase English letters.
*/

class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(word[i] == word[j]) {
                    if(j - i == 1) {
                        dp[i][j] = 1;
                    }
                    else if(dp[i + 1][j - 1] == 1) {
                        dp[i][j] = 1;
                    }
                }
            }
        }
        vector<int> dp2(n, 0);
        for(int i = 0; i < n; i++) {
            if(dp[0][i] == 1) {
                dp2[i] = 1;
            }
            for(int j = 0; j < i; j++) {
                if(dp[j + 1][i] == 1 && word[j] == word[i]) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        return *max_element(dp2.begin(), dp2.end());      
    }
};