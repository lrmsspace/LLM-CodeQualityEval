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
    public int findTheLongestSubstring(String s) {
        Map<Integer, Integer> seen = new HashMap<>();
        seen.put(0, -1);
        int state = 0, res = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (c == 'a') state ^= 1 << 0;
            else if (c == 'e') state ^= 1 << 1;
            else if (c == 'i') state ^= 1 << 2;
            else if (c == 'o') state ^= 1 << 3;
            else if (c == 'u') state ^= 1 << 4;
            if (seen.containsKey(state)) res = Math.max(res, i - seen.get(state));
            else seen.put(state, i);
        }
        return res;      
    }
}