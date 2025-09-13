/*
 You are given two strings word1 and word2.
 A string x is called valid if x can be rearranged to have word2 as a prefix.
 Return the total number of valid substrings of word1.
 Note that the memory limits in this problem are smaller than usual, so you must implement a solution with a linear runtime complexity.
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
 1 <= word1.length <= 106
 1 <= word2.length <= 104
 word1 and word2 consist only of lowercase English letters.
*/

class Solution {
    public long validSubstringCount(String word1, String word2) {

        int n = word1.length();
        int m = word2.length();
        
        if (n < m) {
            return 0;
        }
        
        int[] count = new int[26];
        
        for (int i = 0; i < m; i++) {
            count[word2.charAt(i) - 'a']++;
        }
        
        long result = 0;
        int left = 0;
        int right = 0;
        int validCount = 0;
        while (right < n) {
            count[word1.charAt(right) - 'a']--;
            if (count[word1.charAt(right) - 'a'] >= 0) {
                validCount++;
            }
            right++;
            
            while (validCount == m) {
                if (right - left == m) {
                    result++;
                }
                count[word1.charAt(left) - 'a']++;
                if (count[word1.charAt(left) - 'a'] > 0) {
                    validCount--;
                }
                left++;
            }
        }
        return result;
        
    }
}