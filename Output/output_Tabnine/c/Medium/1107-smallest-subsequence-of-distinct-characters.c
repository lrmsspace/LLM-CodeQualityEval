/**https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/ */
//Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.
// 
//Example 1:
//Input: s = "bcabc"
//Output: "abc"
//Example 2:
//Input: s = "cbacdcbc"
//Output: "acdb"
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
// 
//Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
char* smallestSubsequence(char* s) {
    int count[26] = {0}, seen[26] = {0}, start = 0, end = 0;
    char* res = (char*)malloc(sizeof(char) * (strlen(s) + 1));
    
    while (end < strlen(s)) {
        count[s[end] - 'a']++;
        while (start <= end && count[s[end] - 'a'] > 1) {
            count[s[start] - 'a']--;
            start++;
        }
        res[end - start + 1] = s[end];
        seen[s[end] - 'a'] = 1;
        end++;
    }
    
    res[end - start + 1] = '\0';
    return res;
    
}