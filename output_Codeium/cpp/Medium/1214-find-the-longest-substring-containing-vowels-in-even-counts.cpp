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
        int res = 0, count[5] = {0};
        unordered_map<int, int> map;
        map[0] = -1;
        for (int i = 0; i < s.length(); ++i) {
            switch (s[i]) {
                case 'a': ++count[0]; break;
                case 'e': ++count[1]; break;
                case 'i': ++count[2]; break;
                case 'o': ++count[3]; break;
                case 'u': ++count[4]; break;
            }
            int cur = count[0] + count[1]*2 + count[2]*4 + count[3]*8 + count[4]*16;
            if (map.find(cur) != map.end()) {
                res = max(res, i - map[cur]);
            } else {
                map[cur] = i;
            }
        }
        return res;
    }
};