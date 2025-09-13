/**https://leetcode.com/problems/buddy-strings/ */
//Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.
//Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].
//	For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
// 
//Example 1:
//Input: s = "ab", goal = "ba"
//Output: true
//Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
//Example 2:
//Input: s = "ab", goal = "ab"
//Output: false
//Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
//Example 3:
//Input: s = "aa", goal = "aa"
//Output: true
//Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
// 
//Constraints:
//	1 <= s.length, goal.length <= 2 * 104
//	s and goal consist of lowercase letters.
bool buddyStrings(char* s, char* goal) {
    int len = strlen(s);
    if (len != strlen(goal)) {
        return false;
    }
    int diffCount = 0;
    int diffIndex1 = -1;
    int diffIndex2 = -1;
    int charCount[26] = {0};
    for (int i = 0; i < len; i++) {
        if (s[i] != goal[i]) {
            diffCount++;
            if (diffIndex1 == -1) {
                diffIndex1 = i;
            } else {
                diffIndex2 = i;
            }
        }
        charCount[s[i] - 'a']++;
    }
    if (diffCount == 0) {
        for (int i = 0; i < 26; i++) {
            if (charCount[i] >= 2) {
                return true;
            }
        }
        return false;
    } else if (diffCount == 2) {
        return s[diffIndex1] == goal[diffIndex2] && s[diffIndex2] == goal[diffIndex1];
    } else {
        return false;
    }
    
}