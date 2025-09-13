/**https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/ */
//Given a string s consisting only of characters a, b and c.
//Return the number of substrings containing at least one occurrence of all these characters a, b and c.
// 
//Example 1:
//Input: s = "abcabc"
//Output: 10
//Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
//Example 2:
//Input: s = "aaacb"
//Output: 3
//Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
//Example 3:
//Input: s = "abc"
//Output: 1
// 
//Constraints:
//	3 <= s.length <= 5 x 10^4
//	s only consists of a, b or c characters.
int numberOfSubstrings(char* s) {
    int len = strlen(s);
    int count[3] = {0};
    int res = 0;
    int left = 0;
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
        while (count[0] && count[1] && count[2]) {
            count[s[left] - 'a']--;
            left++;
        }
        res += left;
    }
    return res;    
}