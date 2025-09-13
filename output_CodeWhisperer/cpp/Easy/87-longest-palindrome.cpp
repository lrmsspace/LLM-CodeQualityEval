/**https://leetcode.com/problems/longest-palindrome/ */
//Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
//Letters are case sensitive, for example, "Aa" is not considered a palindrome.
// 
//Example 1:
//Input: s = "abccccdd"
//Output: 7
//Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
//Example 2:
//Input: s = "a"
//Output: 1
//Explanation: The longest palindrome that can be built is "a", whose length is 1.
// 
//Constraints:
//	1 <= s.length <= 2000
//	s consists of lowercase and/or uppercase English letters only.
class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {0};
        for(char c : s){
            count[c]++;
        }
        int ans = 0;
        for(int v : count){
            ans += v / 2 * 2;
            if(ans % 2 == 0 && v % 2 == 1){
                ans++;
            }
        }
        return ans;     
    }
};