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
        int[] count = new int[26];
        for (char c : text.toCharArray()) {
            count[c - 'a']++;
        }
        int[] charCount = new int[26];
        int start = 0;
        int max = 0;
        for (int end = 0; end < text.length(); end++) {
            charCount[text.charAt(end) - 'a']++;
            while (end - start + 1 - Math.max(charCount[text.charAt(start) - 'a'], count[text.charAt(start) - 'a']) > 1) {
                charCount[text.charAt(start++) - 'a']--;
            }
            max = Math.max(max, Math.min(end - start + 1, count[text.charAt(start) - 'a']));
        }
        return max;       
    }
}