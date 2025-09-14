/**https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/ */
//You are given two strings, word1 and word2. You want to construct a string in the following manner:
//	Choose some non-empty subsequence subsequence1 from word1.
//	Choose some non-empty subsequence subsequence2 from word2.
//	Concatenate the subsequences: subsequence1 + subsequence2, to make the string.
//Return the length of the longest palindrome that can be constructed in the described manner. If no palindromes can be constructed, return 0.
//A subsequence of a string s is a string that can be made by deleting some (possibly none) characters from s without changing the order of the remaining characters.
//A palindrome is a string that reads the same forward as well as backward.
// 
//Example 1:
//Input: word1 = "cacb", word2 = "cbba"
//Output: 5
//Explanation: Choose "ab" from word1 and "cba" from word2 to make "abcba", which is a palindrome.
//Example 2:
//Input: word1 = "ab", word2 = "ab"
//Output: 3
//Explanation: Choose "ab" from word1 and "a" from word2 to make "aba", which is a palindrome.
//Example 3:
//Input: word1 = "aa", word2 = "bb"
//Output: 0
//Explanation: You cannot construct a palindrome from the described method, so return 0.
// 
//Constraints:
//	1 <= word1.length, word2.length <= 1000
//	word1 and word2 consist of lowercase English letters.
int longestPalindrome(char * word1, char * word2){
    int n = strlen(word1), m = strlen(word2), i, j, k, l, r, cnt[26] = {0}, ans = 0;
    for (i = 0; i < n; i++) cnt[word1[i] - 'a']++;
    for (i = 0; i < m; i++) cnt[word2[i] - 'a']++;
    for (i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        if (cnt[i] % 2 == 0) ans +=2;
    }
    for (i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        if (cnt[i] % 2 == 1) {
            for (j = 0; j < 26; j++) {
                if (cnt[j] == 0) continue;
                if (i == j) continue;
                for (k = 0; k < 26; k++) {
                    if (cnt[k] == 0) continue;
                    for (l = 0; l < 26; l++) {
                        if (cnt[l] == 0) continue;
                        if (i == l || j == l || k == l) continue;
                        for (r = 0; r < 26; r++) {
                            if (cnt[r] == 0) continue;
                            if (i == r || j == r || k == r || l == r) continue;
                        }
                    }
                }
            }
        }
    }
    return ans;
}
