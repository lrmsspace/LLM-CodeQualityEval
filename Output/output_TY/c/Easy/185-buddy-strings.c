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
bool buddyStrings(char * s, char * goal){
    int n = strlen(s);
    int m = strlen(goal);
    if (n != m) return false;
    int i = 0;
    int j = n - 1;
    while (i < j && s[i] == goal[i]) i++;
    while (j >= 0 && s[j] == goal[j]) j--;
    if (i >= j) return false;
    char tmp= s[i];
    s[i] = s[j];
    s[j] = tmp;
    return !strcmp(s, goal);
}