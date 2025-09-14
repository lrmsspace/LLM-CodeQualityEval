/*
 You are given two strings word1 and word2.
 A string x is called valid if x can be rearranged to have word2 as a prefix.
 Return the total number of valid substrings of word1.
 Example 1:
 Input: word1 = "bcca", word2 = "abc"
 Output: 1
 Explanation:
 The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.
 Example 2:
 Input: word1 = "abcabc", word2 = "abc"
 Output: 10
 Explanation:
 All the substrings except substrings of size 1 and size 2 are valid.
 Example 3:
 Input: word1 = "abcabc", word2 = "aaabc"
 Output: 0
 Constraints:
 1 <= word1.length <= 105
 1 <= word2.length <= 104
 word1 and word2 consist only of lowercase English letters.
*/

class Solution {
    public long validSubstringCount(String word1, String word2) {
        int[] count = new int[26];
        for (char c : word2.toCharArray()) {
            count[c - 'a']++;
        }

        int n = word1.length();
        int m = word2.length();
        long result = 0;
        int start = 0;
        int end = 0;

        while (end < n) {
            count[word1.charAt(end) - 'a']--;
            while (isValid(count, m)) {
                result += n - end;
                count[word1.charAt(start) - 'a']++;
                start++;
            }
            end++;
        }

        return result;        
    }
}