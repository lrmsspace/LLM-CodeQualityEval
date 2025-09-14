/**https://leetcode.com/problems/longest-repeating-character-replacement/ */
//You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
//Return the length of the longest substring containing the same letter you can get after performing the above operations.
// 
//Example 1:
//Input: s = "ABAB", k = 2
//Output: 4
//Explanation: Replace the two 'A's with two 'B's or vice versa.
//Example 2:
//Input: s = "AABABBA", k = 1
//Output: 4
//Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
//The substring "BBBB" has the longest repeating letters, which is 4.
//There may exists other ways to achieve this answer too.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists of only uppercase English letters.
//	0 <= k <= s.length
class Solution {
    public int characterReplacement(String s, int k) {
        int start = 0, max_len = 0, max_count = 0;
        int[] count = new int[26];
        for (int end = 0; end < s.length(); end++) {
            count[s.charAt(end) - 'A']++;
            max_count = Math.max(max_count, count[s.charAt(end) - 'A']);
            if (end - start + 1 - max_count > k) {
                count[s.charAt(start) - 'A']--;
                start++;
            }
            max_len = Math.max(max_len, end - start + 1);
        }
        return max_len;
    }
}