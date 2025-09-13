/**https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/ */
//You are given a string s and a positive integer k.
//Select a set of non-overlapping substrings from the string s that satisfy the following conditions:
//	The length of each substring is at least k.
//	Each substring is a palindrome.
//Return the maximum number of substrings in an optimal selection.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "abaccdbbd", k = 3
//Output: 2
//Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
//It can be shown that we cannot find a selection with more than two valid substrings.
//Example 2:
//Input: s = "adbcda", k = 2
//Output: 0
//Explanation: There is no palindrome substring of length at least 2 in the string.
// 
//Constraints:
//	1 <= k <= s.length <= 2000
//	s consists of lowercase English letters.
int maxPalindromes(char* s, int k) {
        int isPalindrome(char* s, int start, int end) {
            while (start < end) {
                if (s[start] != s[end]) return 0;
                start++;
                end--;
            }
            return 1;
        }

        int n = strlen(s);
        int count = 0;
        int i = 0;

        while (i <= n - k) {
            int found = 0;
            for (int j = i + k - 1; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    count++;
                    i = j + 1;
                    found = 1;
                    break;
                }
            }
            if (!found) i++;
        }

        return count;
}   