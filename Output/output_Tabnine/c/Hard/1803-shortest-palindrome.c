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
    
    // Build the suffix array
    int n = strlen(s);
    int* suffix = malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) {
        suffix[i] = n - i;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] < s[suffix[i]]) {
            suffix[i - 1] = i;
        } else {
            int j = suffix[i - 1];
            while (j >= 0 && s[i]!= s[j]) {
                j = suffix[j - 1];
            }
            suffix[i - 1] = j + 1;
        }
    }
    
    // Find the longest common prefix of s and its reverse
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 0; i < n; i++) {
        if (suffix[i] > maxLen) {
            maxLen = suffix[i];
            centerIndex = i;
        }
    }
    
    // Construct the shortest palindrome by adding characters in front of s
    char* shortestPalindrome = malloc((n + maxLen + 1) * sizeof(char));
    int j = 0;
    for (int i = centerIndex; i >= 0; i--) {
        shortestPalindrome[j++] = s[i];
    }
    for (int i = n - 1; i >= centerIndex + 1; i--) {
        shortestPalindrome[j++] = s[i];
    }
    shortestPalindrome[j] = '\0';
    
    return shortestPalindrome;
}