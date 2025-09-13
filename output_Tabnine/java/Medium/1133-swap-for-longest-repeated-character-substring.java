/**https://leetcode.com/problems/swap-for-longest-repeated-character-substring/ */
//You are given a string text. You can swap two of the characters in the text.
//Return the length of the longest substring with repeated characters.
// 
//Example 1:
//Input: text = "ababa"
//Output: 3
//Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa" with length 3.
//Example 2:
//Input: text = "aaabaaa"
//Output: 6
//Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.
//Example 3:
//Input: text = "aaaaa"
//Output: 5
//Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.
// 
//Constraints:
//	1 <= text.length <= 2 * 104
//	text consist of lowercase English characters only.
class Solution {
    public int maxRepOpt1(String text) {
        int n = text.length();
        int[] count = new int[26];
        int[] start = new int[26];
        int maxLen = 0;
        int maxStart = 0;
        
        for (int i = 0; i < n; i++) {
            count[text.charAt(i) - 'a']++;
            if (i > 0 && count[text.charAt(i) - 'a'] == 1) {
                maxLen = Math.max(maxLen, i - start[text.charAt(i) - 'a']);
                start[text.charAt(i) - 'a'] = i;
            }
        }
        
        maxLen = Math.max(maxLen, n - start[text.charAt(n - 1) - 'a']);
        
        return maxLen;
        
    }
}