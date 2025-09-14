/**https://leetcode.com/problems/sum-of-beauty-of-all-substrings/ */
//The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
//	For example, the beauty of "abaacc" is 3 - 1 = 2.
//Given a string s, return the sum of beauty of all of its substrings.
// 
//Example 1:
//Input: s = "aabcb"
//Output: 5
//Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
//Example 2:
//Input: s = "aabcbaa"
//Output: 17
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters.
class Solution {
    public int beautySum(String s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            int[] count = new int[26];
            for (int j = i; j < s.length(); j++) {
                count[s.charAt(j) - 'a']++;
                int max = 0, min = Integer.MAX_VALUE;
                for (int k = 0; k < 26; k++) {
                    if (count[k] > 0) {
                        max = Math.max(max, count[k]);
                        min = Math.min(min, count[k]);
                    }
                }
                sum += max - min;
            }
        }
        return sum;
    }
}