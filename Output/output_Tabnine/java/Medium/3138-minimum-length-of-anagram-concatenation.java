/*
 You are given a string s, which is known to be a concatenation of anagrams of some string t.
 Return the minimum possible length of the string t.
 An anagram is formed by rearranging the letters of a string. For example, "aab", "aba", and, "baa" are anagrams of "aab".
 Example 1:
 Input: s = "abba"
 Output: 2
 Explanation:
 One possible string t could be "ba".
 Example 2:
 Input: s = "cdef"
 Output: 4
 Explanation:
 One possible string t could be "cdef", notice that t can be equal to s.
 Example 2:
 Input: s = "abcbcacabbaccba"
 Output: 3
 Constraints:
 1 <= s.length <= 105
 s consist only of lowercase English letters.
*/

class Solution {
    public int minAnagramLength(String s) {
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }
        
        int minLength = Integer.MAX_VALUE;
        int uniqueCount = 0;
        
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (count[s.charAt(i) - 'a']-- > 0) {
                uniqueCount++;
            }
            
            while (uniqueCount == 26) {
                if (i - j + 1 < minLength) {
                    minLength = i - j + 1;
                }
                
                if (++count[s.charAt(j) - 'a'] > 0) {
                    uniqueCount--;
                }
                
                j++;
            }
        }
        
        return minLength == Integer.MAX_VALUE? 0 : minLength;
        
    }
}