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
        int n = word1.length(), m = word2.length();
        long result = 0;
        int[] word2Count = new int[26];
        int[] windowCount = new int[26];
        
        for (char c : word2.toCharArray()) {
            word2Count[c - 'a']++;
        }
        
        for (int i = 0; i < n; i++) {
            windowCount[word1.charAt(i) - 'a']++;
            
            if (i >= m) {
                windowCount[word1.charAt(i - m) - 'a']--;
            }
            
            boolean isValid = true;
            for (int j = 0; j < 26; j++) {
                if (windowCount[j] < word2Count[j]) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                result++;
            }
        }
        
        return result;

    }
}