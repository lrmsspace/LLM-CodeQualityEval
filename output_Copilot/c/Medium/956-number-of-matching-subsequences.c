/**https://leetcode.com/problems/number-of-matching-subsequences/ */
//Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
//A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
//	For example, "ace" is a subsequence of "abcde".
// 
//Example 1:
//Input: s = "abcde", words = ["a","bb","acd","ace"]
//Output: 3
//Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".
//Example 2:
//Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
//Output: 2
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	1 <= words.length <= 5000
//	1 <= words[i].length <= 50
//	s and words[i] consist of only lowercase English letters.
int numMatchingSubseq(char* s, char** words, int wordsSize) {
    int i, j, k, count = 0, len = strlen(s), len2;
    char *p;
    for (i = 0; i < wordsSize; i++) {
        p = words[i];
        len2 = strlen(p);
        if (len2 > len) {
            continue;
        }
        j = 0;
        k = 0;
        while (j < len2 && k < len) {
            if (p[j] == s[k]) {
                j++;
            }
            k++;
        }
        if (j == len2) {
            count++;
        }
    }
    return count;    
}