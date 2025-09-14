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
        int maxCount = 0;
        for (int i = 0; i < 26; i++) {
            maxCount = Math.max(maxCount, count[i]);
        }
        int[] freq = new int[26];
        int[] freq2 = new int[26];
        int[] pos = new int[26];
        int ans = 0;
        for (int i = 0; i < text.length(); i++) {
            int c = text.charAt(i) - 'a';
            freq[c]++;
            if (i == 0) {
                pos[c] = i;
                freq2[c] = 1;
            } else {
                if (text.charAt(i) == text.charAt(i - 1)) {
                    freq2[c]++;
                } else {
                    pos[c] = i;
                    freq2[c] = 1;
                }
            }
            int start = pos[c];
            int end = i;
        }
        for (int i = 0; i < 26; i++) {
            ans = Math.max(ans, Math.min(freq[i], freq2[i] + 1));
        }
        return ans;
    }
}