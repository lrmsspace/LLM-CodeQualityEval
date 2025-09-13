/**https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/ */
//Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
//if no such substring exists, return 0.
// 
//Example 1:
//Input: s = "aaabb", k = 3
//Output: 3
//Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
//Example 2:
//Input: s = "ababbc", k = 2
//Output: 5
//Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of only lowercase English letters.
//	1 <= k <= 105
class Solution {
    public int longestSubstring(String s, int k) {
        if (k == 0) return s.length();
        int[] count = new int[26];
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            Arrays.fill(count, 0);
            for (int j = i; j < s.length(); j++) {
                count[s.charAt(j) - 'a']++;
                int min = Integer.MAX_VALUE;
                for (int c : count) {
                    if (c > 0) min = Math.min(min, c);
                }
                if (min >= k) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
}