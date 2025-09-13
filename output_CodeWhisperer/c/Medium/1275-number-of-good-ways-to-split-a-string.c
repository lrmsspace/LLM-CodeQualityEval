/**https://leetcode.com/problems/number-of-good-ways-to-split-a-string/ */
//You are given a string s.
//A split is called good if you can split s into two non-empty strings sleft and sright where their concatenation is equal to s (i.e., sleft + sright = s) and the number of distinct letters in sleft and sright is the same.
//Return the number of good splits you can make in s.
// 
//Example 1:
//Input: s = "aacaba"
//Output: 2
//Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
//("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
//("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
//("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
//("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
//("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
//Example 2:
//Input: s = "abcd"
//Output: 1
//Explanation: Split the string as follows ("ab", "cd").
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only lowercase English letters.
int numSplits(char* s) {
    int len = strlen(s);
    int left[26] = {0}, right[26] = {0};
    int left_count = 0, right_count = 0;
    for (int i = 0; i < len; i++) {
        if (right[s[i] - 'a'] == 0) {
            right_count++;
        }
        right[s[i] - 'a']++;
    }
    int result = 0;
    for (int i = 0; i < len; i++) {
        if (left[s[i] - 'a'] == 0) {
            left_count++;
        }
        left[s[i] - 'a']++;
        right[s[i] - 'a']--;
        if (right[s[i] - 'a'] == 0) {
            right_count--;
        }
        if (left_count == right_count) {
            result++;
        }
    }
    return result;
}