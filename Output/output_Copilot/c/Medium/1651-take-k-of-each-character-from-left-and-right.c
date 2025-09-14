/**https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/ */
//You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
//Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.
// 
//Example 1:
//Input: s = "aabaaaacaabc", k = 2
//Output: 8
//Explanation: 
//Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
//Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
//A total of 3 + 5 = 8 minutes is needed.
//It can be proven that 8 is the minimum number of minutes needed.
//Example 2:
//Input: s = "a", k = 1
//Output: -1
//Explanation: It is not possible to take one 'b' or 'c' so return -1.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only the letters 'a', 'b', and 'c'.
//	0 <= k <= s.length
int takeCharacters(char* s, int k) {
    int count[3] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }
    int min = 0;
    int left = 0;
    int right = len - 1;
    while (left <= right) {
        if (count[s[left] - 'a'] >= k && count[s[right] - 'a'] >= k) {
            break;
        }
        if (count[s[left] - 'a'] < k) {
            count[s[left] - 'a']++;
            left++;
        }
        if (count[s[right] - 'a'] < k) {
            count[s[right] - 'a']++;
            right--;
        }
        min++;
    }
    if (left > right) {
        return -1;
    }
    return min;    
}