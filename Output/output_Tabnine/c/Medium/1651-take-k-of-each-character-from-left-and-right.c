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
    int count[3] = {0}, min_moves = 0, left = 0, right = strlen(s) - 1;
    while (left <= right) {
        count[s[left] - 'a']++;
        count[s[right] - 'a']--;
        left++;
        right--;
        min_moves++;
        while (count[0] < k && count[1] < k && count[2] < k) {
            if (count[0] < k) min_moves += k - count[0];
            if (count[1] < k) min_moves += k - count[1];
            if (count[2] < k) min_moves += k - count[2];
        }
    }
    return min_moves == 0? -1 : min_moves;
    
}