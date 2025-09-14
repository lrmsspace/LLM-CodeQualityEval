/**https://leetcode.com/problems/second-largest-digit-in-a-string/ */
//Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.
//An alphanumeric string is a string consisting of lowercase English letters and digits.
// 
//Example 1:
//Input: s = "dfa12321afd"
//Output: 2
//Explanation: The digits that appear in s are [1, 2, 3]. The second largest digit is 2.
//Example 2:
//Input: s = "abc1111"
//Output: -1
//Explanation: The digits that appear in s are [1]. There is no second largest digit. 
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters and digits.
class Solution {
    public int secondHighest(String s) {
        int[] nums = new int[10];
        for (char c : s.toCharArray()) {
            if (c >= '0' && c <= '9') {
                nums[c - '0']++;
            }
        }
        int max = -1, secondMax = -1;
        for (int i = 9; i >= 0; i--) {
            if (nums[i] > 0) {
                if (i > max) {
                    secondMax = max;
                    max = i;
                } else if (i > secondMax) {
                    secondMax = i;
                }
            }
        }
        return secondMax;
    }
}