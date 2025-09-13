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
    int n = strlen(s);
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') a++;
        else if (s[i] == 'b') b++;
        else c++;
    }
    if (a < k || b < k || c < k) return -1;
    int left = 0, right = 0, res = n;
    while (right < n) {
        if (s[right] == 'a') a--;
        else if (s[right] == 'b') b--;
        else c--;
        while (a <= k && b <= k && c <= k) {
            res = fmin(res, n - (right - left + 1));
            if (s[left] == 'a') a++;
            else if (s[left] == 'b') b++;
            else c++;
            left++;
        }
        right++;
    }
    return res;
}