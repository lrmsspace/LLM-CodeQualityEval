/**https://leetcode.com/problems/substring-with-largest-variance/ */
//The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.
//Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "aababbb"
//Output: 3
//Explanation:
//All possible variances along with their respective substrings are listed below:
//- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
//- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
//- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
//- Variance 3 for substring "babbb".
//Since the largest possible variance is 3, we return it.
//Example 2:
//Input: s = "abcde"
//Output: 0
//Explanation:
//No letter occurs more than once in s, so the variance of every substring is 0.
// 
//Constraints:
//	1 <= s.length <= 104
//	s consists of lowercase English letters.
class Solution {
    public int largestVariance(String s) {
        int max = 0;
        for (char c1 = 'a'; c1 <= 'z'; c1++) {
            for (char c2 = 'a'; c2 <= 'z'; c2++) {
                if (c1 == c2) continue;
                int variance = 0;
                boolean hasC2 = false;
                for (char c : s.toCharArray()) {
                    if (c == c1) variance++;
                    else if (c == c2) {
                        variance--;
                        hasC2 = true;
                    }
                    if (variance < 0) {
                        variance = hasC2 ? 1 : 0;
                        hasC2= false;
                    }
                }
            }
        } 
        return ans; 
    }
}