/**https://leetcode.com/problems/valid-palindrome-ii/ */
//Given a string s, return true if the s can be palindrome after deleting at most one character from it.
// 
//Example 1:
//Input: s = "aba"
//Output: true
//Example 2:
//Input: s = "abca"
//Output: true
//Explanation: You could delete the character 'c'.
//Example 3:
//Input: s = "abc"
//Output: false
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of lowercase English letters.

bool isPalindrome(char *s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
bool validPalindrome(char* s) {
    int l = 0, r = strlen(s) - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
        }
        l++;
        r--;
    }
    return true;
}
    