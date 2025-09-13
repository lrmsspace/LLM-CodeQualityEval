/*
 You are given a string word.
 Return the maximum number of non-intersecting substrings of word that are at least four characters long and start and end with the same letter.
 Example 1:
 Input: word = "abcdeafdef"
 Output: 2
 Explanation:
 The two substrings are "abcdea" and "fdef".
 Example 2:
 Input: word = "bcdaaaab"
 Output: 1
 Explanation:
 The only substring is "aaaa". Note that we cannot also choose "bcdaaaab" since it intersects with the other substring.
 Constraints:
 1 <= word.length <= 2 * 105
 word consists only of lowercase English letters.
*/

class Solution {
    public int maxSubstrings(String word) {
        int n = word.length();
        int[] last = new int[26];
        for (int i = 0; i < 26; i++) {
            last[i] = -1;
        }
        boolean[] used = new boolean[n];
        int count = 0;

        for (int i = 0; i < n; i++) {
            char c = word.charAt(i);
            int index = c - 'a';
            if (last[index] != -1 && i - last[index] >= 3) {
                count++;
                for (int j = last[index]; j <= i; j++) {
                    used[j] = true;
                }
            }
            last[index] = i;
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                continue;
            }
            while (i < n && used[i]) {
                i++;
            }
        }

        return count;        
    }
}