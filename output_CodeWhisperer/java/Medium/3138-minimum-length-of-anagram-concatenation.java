/*
import java.util.Arrays;
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
        int n = s.length();
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                String sub = s.substring(0, i);
                int[] count = new int[26];
                for (char c : sub.toCharArray()) {
                    count[c - 'a']++;
                }
                boolean isAnagram = true;
                for (int j = i; j < n; j += i) {
                    int[] count2 = new int[26];
                    for (char c : s.substring(j, j + i).toCharArray()) {
                        count2[c - 'a']++;
                    }
                    if (!Arrays.equals(count, count2)) {
                        isAnagram = false;
                        break;
                    }
                }
                if (isAnagram) {
                    return i;
                }
            }
        }
        return n;        
    }
}