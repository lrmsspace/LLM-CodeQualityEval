/**https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/ */
//You are given a 0-indexed string text and another 0-indexed string pattern of length 2, both of which consist of only lowercase English letters.
//You can add either pattern[0] or pattern[1] anywhere in text exactly once. Note that the character can be added even at the beginning or at the end of text.
//Return the maximum number of times pattern can occur as a subsequence of the modified text.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
// 
//Example 1:
//Input: text = "abdcdbc", pattern = "ac"
//Output: 4
//Explanation:
//If we add pattern[0] = 'a' in between text[1] and text[2], we get "abadcdbc". Now, the number of times "ac" occurs as a subsequence is 4.
//Some other strings which have 4 subsequences "ac" after adding a character to text are "aabdcdbc" and "abdacdbc".
//However, strings such as "abdcadbc", "abdccdbc", and "abdcdbcc", although obtainable, have only 3 subsequences "ac" and are thus suboptimal.
//It can be shown that it is not possible to get more than 4 subsequences "ac" by adding only one character.
//Example 2:
//Input: text = "aabb", pattern = "ab"
//Output: 6
//Explanation:
//Some of the strings which can be obtained from text and have 6 subsequences "ab" are "aaabb", "aaabb", and "aabbb".
// 
//Constraints:
//	1 <= text.length <= 105
//	pattern.length == 2
//	text and pattern consist only of lowercase English letters.
class Solution {
    public long maximumSubsequenceCount(String text, String pattern) {
        int n = text.length();
        int[] left = new int[n];
        int[] right = new int[n];
        int[] count = new int[26];
        int[] first = new int[26];
        Arrays.fill(first, -1);
        for (int i = 0; i < n; i++) {
            left[i] = i == 0 ? 0 : left[i - 1];
            if (i > 0) {
                left[i] = Math.max(left[i], left[i - 1]);
            }
            if (first[text.charAt(i) - 'a'] != -1) {
                left[i] = Math.max(left[i], count[first[text.charAt(i) - 'a']] + 1);
            }
            count[text.charAt(i) - 'a']++;
            first[text.charAt(i) - 'a'] = i;
        }
        Arrays.fill(count, 0);
        Arrays.fill(first, -1);
        for (int i = n - 1; i >= 0; i--) {
            right[i] = i == n - 1 ? 0 : right[i + 1];
            if (i < n - 1) {
                right[i] = Math.max(right[i], right[i + 1]);
            }
            if (first[text.charAt(i) - 'a'] != -1) {
                right[i] = Math.max(right[i], count[first[text.charAt(i) - 'a']] + 1);
            }
            count[text.charAt(i) - 'a']++;
            first[text.charAt(i) - 'a'] = i;
        }
        long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans = Math.max(ans, (long) left[i] + right[i + 1]);
        }
        return ans;        
    }
}