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
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        while(j < n){
            if(s[j] == 'a') a++;
            else if(s[j] == 'b') b++;
            else c++;
            while(a > 0 && b > 0 && c > 0){
                ans += n - j;
                if(s[i] == 'a') a--;
                else if(s[i] == 'b') b--;
                else c--;
            }
        }
        return ans;
    }
};