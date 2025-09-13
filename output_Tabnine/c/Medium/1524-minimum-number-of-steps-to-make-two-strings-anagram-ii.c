/**https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/ */
//You are given two strings s and t. In one step, you can append any character to either s or t.
//Return the minimum number of steps to make s and t anagrams of each other.
//An anagram of a string is a string that contains the same characters with a different (or the same) ordering.
// 
//Example 1:
//Input: s = "leetcode", t = "coats"
//Output: 7
//Explanation: 
//- In 2 steps, we can append the letters in "as" onto s = "leetcode", forming s = "leetcodeas".
//- In 5 steps, we can append the letters in "leede" onto t = "coats", forming t = "coatsleede".
//"leetcodeas" and "coatsleede" are now anagrams of each other.
//We used a total of 2 + 5 = 7 steps.
//It can be shown that there is no way to make them anagrams of each other with less than 7 steps.
//Example 2:
//Input: s = "night", t = "thing"
//Output: 0
//Explanation: The given strings are already anagrams of each other. Thus, we do not need any further steps.
// 
//Constraints:
//	1 <= s.length, t.length <= 2 * 105
//	s and t consist of lowercase English letters.
int minSteps(char* s, char* t) {
    int n = strlen(s);
    int count[26] = {0};
    
    // Count the frequency of each character in s
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }
    
    int steps = 0;
    
    // For each character in t, find the minimum number of steps required to make it the same as the corresponding character in s
    for (int i = 0; i < n; i++) {
        int diff = count[t[i] - 'a'] - (s[i] == t[i]? 0 : 1);
        steps += abs(diff);
    }
    
    return steps;
    
}