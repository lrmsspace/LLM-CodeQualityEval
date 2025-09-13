/**https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/ */
//Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.
// 
//Example 1:
//Input: s = "1001"
//Output: false
//Explanation: The ones do not form a contiguous segment.
//Example 2:
//Input: s = "110"
//Output: true
// 
//Constraints:
//	1 <= s.length <= 100
//	s[i]​​​​ is either '0' or '1'.
//	s[0] is '1'.
class Solution {
    public boolean checkOnesSegment(String s) {
        // Find the first occurrence of '0' in the string
        int firstZeroIndex = s.indexOf('0');
        // If there is no '0', it means all characters are '1'
        if (firstZeroIndex == -1) {
            return true;
        }
        // Find the last occurrence of '0' in the string
        int lastZeroIndex = s.lastIndexOf('0');
        // Check if there are any '1's after the first '0'
        return lastZeroIndex == firstZeroIndex;        
    }
}