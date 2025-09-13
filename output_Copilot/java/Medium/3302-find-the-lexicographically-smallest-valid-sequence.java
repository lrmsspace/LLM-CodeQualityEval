/*
 You are given two strings word1 and word2.
 A string x is called almost equal to y if you can change at most one character in x to make it identical to y.
 A sequence of indices seq is called valid if:
 The indices are sorted in ascending order.
 Concatenating the characters at these indices in word1 in the same order results in a string that is almost equal to word2.
 Return an array of size word2.length representing the lexicographically smallest valid sequence of indices. If no such sequence of indices exists, return an empty array.
 Note that the answer must represent the lexicographically smallest array, not the corresponding string formed by those indices.
 Example 1:
 Input: word1 = "vbcca", word2 = "abc"
 Output: [0,1,2]
 Explanation:
 The lexicographically smallest valid sequence of indices is [0, 1, 2]:
 Change word1[0] to 'a'.
 word1[1] is already 'b'.
 word1[2] is already 'c'.
 Example 2:
 Input: word1 = "bacdc", word2 = "abc"
 Output: [1,2,4]
 Explanation:
 The lexicographically smallest valid sequence of indices is [1, 2, 4]:
 word1[1] is already 'a'.
 Change word1[2] to 'b'.
 word1[4] is already 'c'.
 Example 3:
 Input: word1 = "aaaaaa", word2 = "aaabc"
 Output: []
 Explanation:
 There is no valid sequence of indices.
 Example 4:
 Input: word1 = "abc", word2 = "ab"
 Output: [0,1]
 Constraints:
 1 <= word2.length < word1.length <= 3 * 105
 word1 and word2 consist only of lowercase English letters.
*/

class Solution {
    public int[] validSequence(String word1, String word2) {
        int n = word1.length(), m = word2.length();
        int[] result = new int[m];
        int j = 0, k = 0;
        boolean changed = false;

        for (int i = 0; i < n && j < m; i++) {
            if (word1.charAt(i) == word2.charAt(j)) {
                result[j++] = i;
            } else if (!changed && k < m && word1.charAt(i) == word2.charAt(k)) {
                result[k++] = i;
                changed = true;
            } else if (!changed && j > 0 && word1.charAt(i) == word2.charAt(j - 1)) {
                result[--j] = i;
                changed = true;
            }
        }

        return j == m ? result : new int[0];        
    }
}