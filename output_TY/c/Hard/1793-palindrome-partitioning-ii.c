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
int minCut(char * s){
    int len = strlen(s);
    if (len == 0) return 0;
    int i, j, k, cut[len];
    bool palindrome[len][len];
    memset(palindrome, 0, sizeof(palindrome));
    for (i = 0; i < len; i++) {
        cut[i] = i;
        palindrome[i][i] = true;
    }
    for (i = 0; i < len - 1; i++) {
        palindrome[i][i + 1] = (s[i] == s[i + 1]);
    }
    for (k = 3; k <= len; k++) {
        for (i = 0; i <= len - k; i++) {
            j = i + k - 1;
            palindrome[i][j] = (s[i] == s[j]) && palindrome[i + 1][j - 1];
        }
    }
    for (i = 1; i < len; i++) {
        for (j = 0; j < i; j++) {
            if (palindrome[j][i]) {
                cut[i] = fmin(cut[i], cut[j] + 1);
            }
        }
    }
    return cut[len - 1];
}