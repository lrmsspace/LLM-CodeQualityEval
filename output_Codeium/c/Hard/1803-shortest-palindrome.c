/**https://leetcode.com/problems/shortest-palindrome/ */
//You are given a string s. You can convert s to a palindrome by adding characters in front of it.
//Return the shortest palindrome you can find by performing this transformation.
// 
//Example 1:
//Input: s = "aacecaaa"
//Output: "aaacecaaa"
//Example 2:
//Input: s = "abcd"
//Output: "dcbabcd"
// 
//Constraints:
//	0 <= s.length <= 5 * 104
//	s consists of lowercase English letters only.
char* shortestPalindrome(char* s) {
    int n = strlen(s);
    int k = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == s[k]) {
            k++;
        }
    }
    char* ret = (char*)malloc((n + n - k + 1) * sizeof(char));
    int j = n - k;
    for (int i = n - 1; i >= k; i--) {
        ret[j++] = s[i];
    }
    strcpy(ret + j, s);
    return ret;
}