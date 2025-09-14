/**https://leetcode.com/problems/word-break/ */
//Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
//Note that the same word in the dictionary may be reused multiple times in the segmentation.
// 
//Example 1:
//Input: s = "leetcode", wordDict = ["leet","code"]
//Output: true
//Explanation: Return true because "leetcode" can be segmented as "leet code".
//Example 2:
//Input: s = "applepenapple", wordDict = ["apple","pen"]
//Output: true
//Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//Note that you are allowed to reuse a dictionary word.
//Example 3:
//Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
//Output: false
// 
//Constraints:
//	1 <= s.length <= 300
//	1 <= wordDict.length <= 1000
//	1 <= wordDict[i].length <= 20
//	s and wordDict[i] consist of only lowercase English letters.
//	All the strings of wordDict are unique.
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    
    int len = strlen(s);
    bool dp[len + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 0; i < len; ++i) {
        if (dp[i]) {
            for (int j = 0; j < wordDictSize; ++j) {
                int len_word = strlen(wordDict[j]);
                if (i + len_word <= len && memcmp(s + i, wordDict[j], len_word) == 0) {
                    dp[i + len_word] = true;
                }
            }
        }
    }
    return dp[len];
}
