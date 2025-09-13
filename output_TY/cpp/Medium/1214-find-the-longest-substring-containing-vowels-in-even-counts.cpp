/**https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/ */
//Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.
// 
//Example 1:
//Input: s = "eleetminicoworoep"
//Output: 13
//Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
//Example 2:
//Input: s = "leetcodeisgreat"
//Output: 5
//Explanation: The longest substring is "leetc" which contains two e's.
//Example 3:
//Input: s = "bcbcbc"
//Output: 6
//Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
// 
//Constraints:
//	1 <= s.length <= 5 x 10^5
//	s contains only lowercase English letters.
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int mask = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') mask ^= 1;
            else if(s[i] == 'e') mask ^= 2;
            else if(s[i] == 'i') mask ^= 4;
            else if(s[i] == 'o') mask ^= 8;
            else if(s[i] == 'u') mask ^= 16;
            if(m.find(mask) != m.end()){
                ans = max(ans, i - m[mask]);
                m[mask] = i;
                continue;
            }
        }
        return ans;
    }
};