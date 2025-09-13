/**https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/ */
//Given a string s, return the maximum number of unique substrings that the given string can be split into.
//You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "ababccc"
//Output: 5
//Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
//Example 2:
//Input: s = "aba"
//Output: 2
//Explanation: One way to split maximally is ['a', 'ba'].
//Example 3:
//Input: s = "aa"
//Output: 1
//Explanation: It is impossible to split the string any further.
// 
//Constraints:
//	
//	1 <= s.length <= 16
//	
//	
//	s contains only lower case English letters.
//	
int maxUniqueSplit(char* s) {
    int n = strlen(s);
    int dp[17] = {0};
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        for (int j = i - 1; j >= 0; j--) {
            char* sub = malloc((i - j + 1) * sizeof(char));
            strncpy(sub, s + j, i - j);
            sub[i - j] = '\0';
            int k;
            for (k = 0; k < j; k++) {
                if (strcmp(sub, s + k) == 0) {
                    break;
                }
            }
            if (k == j) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
            free(sub);
        }
    }
    return dp[n];
}