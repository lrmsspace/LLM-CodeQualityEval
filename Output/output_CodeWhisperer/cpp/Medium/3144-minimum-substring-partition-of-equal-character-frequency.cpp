/*
 Given a string s, you need to partition it into one or more balanced substrings. For example, if s == "ababcc" then ("abab", "c", "c"), ("ab", "abc", "c"), and ("ababcc") are all valid partitions, but ("a", "bab", "cc"), ("aba", "bc", "c"), and ("ab", "abcc") are not. The unbalanced substrings are bolded.
 Return the minimum number of substrings that you can partition s into.
 Note: A balanced string is a string where each character in the string occurs the same number of times.
 Example 1:
 Input: s = "fabccddg"
 Output: 3
 Explanation:
 We can partition the string s into 3 substrings in one of the following ways: ("fab, "ccdd", "g"), or ("fabc", "cd", "dg").
 Example 2:
 Input: s = "abababaccddb"
 Output: 2
 Explanation:
 We can partition the string s into 2 substrings like so: ("abab", "abaccddb").
 Constraints:
 1 <= s.length <= 1000
 s consists only of English lowercase letters.
*/

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int freq[26] = {0};
            int maxFreq = 0;
            for(int j=i-1;j>=0;j--){
                freq[s[j]-'a']++;
                maxFreq = max(maxFreq, freq[s[j]-'a']);
                if(maxFreq <= i-j){
                    dp[i] = (j==0) ? 1 : min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n];        
    }
};