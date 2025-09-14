/**https://leetcode.com/problems/palindrome-partitioning-ii/ */
//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return the minimum cuts needed for a palindrome partitioning of s.
// 
//Example 1:
//Input: s = "aab"
//Output: 1
//Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//Example 2:
//Input: s = "a"
//Output: 0
//Example 3:
//Input: s = "ab"
//Output: 1
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase English letters only.
int minCut(char* s) {
    int n = strlen(s);

    int* cuts = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        cuts[i] = i;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) {
                if (j == 0) {
                    dp[j][i] = true;
                } else {
                    dp[j][i] = dp[j - 1][i - 1];
                }
                if (dp[j][i]) {
                    if (j == 0) {
                        cuts[i] = 0;
                    } else {
                        cuts[i] = min(cuts[i], cuts[j - 1] + 1);
                    }
                }
            }
        }
    }

    return cuts[n - 1];
    
}