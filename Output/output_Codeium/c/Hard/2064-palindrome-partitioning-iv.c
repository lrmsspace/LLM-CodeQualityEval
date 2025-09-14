/**https://leetcode.com/problems/palindrome-partitioning-iv/ */
//Given a string s, return true if it is possible to split the string s into three non-empty palindromic substrings. Otherwise, return false.​​​​​
//A string is said to be palindrome if it the same string when reversed.
// 
//Example 1:
//Input: s = "abcbdd"
//Output: true
//Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
//Example 2:
//Input: s = "bcbddxy"
//Output: false
//Explanation: s cannot be split into 3 palindromes.
// 
//Constraints:
//	3 <= s.length <= 2000
//	s​​​​​​ consists only of lowercase English letters.

bool isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) return false;
    }
    return true;
}
bool checkPartitioning(char* s) {
    int n = strlen(s);
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (isPalindrome(s, 0, i) && isPalindrome(s, i + 1, j) && isPalindrome(s, j + 1, n - 1)) return true;
        }
    }
    return false;
}
    