/**https://leetcode.com/problems/palindromic-substrings/ */
//Given a string s, return the number of palindromic substrings in it.
//A string is a palindrome when it reads the same backward as forward.
//A substring is a contiguous sequence of characters within the string.
// 
//Example 1:
//Input: s = "abc"
//Output: 3
//Explanation: Three palindromic strings: "a", "b", "c".
//Example 2:
//Input: s = "aaa"
//Output: 6
//Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
// 
//Constraints:
//	1 <= s.length <= 1000
//	s consists of lowercase English letters.
bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int countSubstrings(char* s) {
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        for (int j = i + 1; j <= strlen(s); j++) {
            char* substr = (char*)malloc((j - i + 1) * sizeof(char));
            strncpy(substr, s + i, j - i);
            substr[j - i] = '\0';
            if (isPalindrome(substr)) {
                count++;
            }
            free(substr);
        }
    }
    return count;
}   