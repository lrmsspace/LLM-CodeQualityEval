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
        int maxCount = 0;
        for (int i = 0; i < n - 3; i++) {
            int count = 1;
            char start = word.charAt(i);
            char end = word.charAt(i + 3);
            if (start == end) {
                for (int j = i + 1; j < n - 3; j++) {
                    if (word.charAt(j) == start && word.charAt(j + 3) == end) {
                        count++;
                        i = j;
                    } else {
                        break;
                    }
                }
            }
            maxCount = Math.max(maxCount, count);
        }
        return maxCount;    
        
    }
}