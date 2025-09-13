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
int numberOfSubstrings(char * s){
    int a = 0, b = 0, c = 0;
    int ans = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'a') a++;
        else if (s[i] == 'b') b++;
        else c++;
        while (a && b && c) {
            ans += s[i - 2] == 'a' ? a - 1 : a;
            ans += s[i - 2] == 'b' ? b -1 : b;
        }
    }
    return ans;
}