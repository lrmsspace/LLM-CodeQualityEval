/**https://leetcode.com/problems/length-of-the-longest-valid-substring/ */
//You are given a string word and an array of strings forbidden.
//A string is called valid if none of its substrings are present in forbidden.
//Return the length of the longest valid substring of the string word.
//A substring is a contiguous sequence of characters in a string, possibly empty.
// 
//Example 1:
//Input: word = "cbaaaabc", forbidden = ["aaa","cb"]
//Output: 4
//Explanation: There are 11 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", "ab", "abc" and "aabc". The length of the longest valid substring is 4. 
//It can be shown that all other substrings contain either "aaa" or "cb" as a substring. 
//Example 2:
//Input: word = "leetcode", forbidden = ["de","le","e"]
//Output: 4
//Explanation: There are 11 valid substrings in word: "l", "t", "c", "o", "d", "tc", "co", "od", "tco", "cod", and "tcod". The length of the longest valid substring is 4.
//It can be shown that all other substrings contain either "de", "le", or "e" as a substring. 
// 
//Constraints:
//	1 <= word.length <= 105
//	word consists only of lowercase English letters.
//	1 <= forbidden.length <= 105
//	1 <= forbidden[i].length <= 10
//	forbidden[i] consists only of lowercase English letters.
int longestValidSubstring(char* word, char** forbidden, int forbiddenSize) {
    int len = strlen(word);
    int *dp = (int *)malloc(sizeof(int) * len);
    int *forbiddenLen = (int *)malloc(sizeof(int) * forbiddenSize);
    int *forbiddenHash = (int *)malloc(sizeof(int) * forbiddenSize);
    int *forbiddenHashLen = (int *)malloc(sizeof(int) * forbiddenSize);
    int i, j, k, max = 0, tmp;
    for (i = 0; i < forbiddenSize; i++) {
        forbiddenLen[i] = strlen(forbidden[i]);
        forbiddenHash[i] = 0;
        for (j = 0; j < forbiddenLen[i]; j++) {
            forbiddenHash[i] = forbiddenHash[i] * 26 + forbidden[i][j] - 'a';
        }
        forbiddenHashLen[i] = 1;
        for (j = 1; j < forbiddenLen[i]; j++) {
            forbiddenHashLen[i] *= 26;
        }
    }
    for (i = 0; i < len; i++) {
        dp[i] = 1;
        for (j = 0; j < forbiddenSize; j++) {
            if (i + 1 >= forbiddenLen[j]) {
                tmp = 0;
                for (k = 0; k < forbiddenLen[j]; k++) {
                    tmp = tmp * 26 + word[i - k] - 'a';
                }
                if (tmp == forbiddenHash[j]) {
                    dp[i] = 0;
                    break;
                }
            }
        }
        if (i > 0) {
            dp[i] += dp[i - 1];
        }
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    free(dp);
    free(forbiddenLen);
    free(forbiddenHash);
    free(forbiddenHashLen);
    return max;    
}