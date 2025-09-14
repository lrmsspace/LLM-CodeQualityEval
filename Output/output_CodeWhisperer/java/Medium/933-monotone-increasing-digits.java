/**https://leetcode.com/problems/monotone-increasing-digits/ */
//An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
//Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
// 
//Example 1:
//Input: n = 10
//Output: 9
//Example 2:
//Input: n = 1234
//Output: 1234
//Example 3:
//Input: n = 332
//Output: 299
// 
//Constraints:
//	0 <= n <= 109
class Solution {
    public int monotoneIncreasingDigits(int n) {
        if (n == 0) return 0;
        char[] chars = String.valueOf(n).toCharArray();
        int mark = chars.length;
        for (int i = chars.length - 1; i > 0; i--) {
            if (chars[i] < chars[i - 1]) {
                mark = i;
                chars[i - 1]--;
            }
        }
        for (int i = mark; i < chars.length; i++) {
            chars[i] = '9';
        }
        return Integer.parseInt(String.valueOf(chars));    
    }
}