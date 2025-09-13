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
        int n = s.length();
        int[] freq = new int[26];
        int maxFreq = 0;
        int minFreq = Integer.MAX_VALUE;
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            freq[s.charAt(i) - 'a']++;
            maxFreq = Math.max(maxFreq, freq[s.charAt(i) - 'a']);
            minFreq = Math.min(minFreq, freq[s.charAt(i) - 'a']);
            sum += maxFreq - minFreq;
        }
        
        return sum;
        
    }
}