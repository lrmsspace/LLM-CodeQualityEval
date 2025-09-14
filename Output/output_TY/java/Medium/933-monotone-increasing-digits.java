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
        String num = String.valueOf(n);
        int[] nums = new int[num.length()];
        for (int i = 0; i < num.length(); i++) {
            nums[i] = num.charAt(i) - '0';
        }
        int index = nums.length - 1;
        while (index > 0 && nums[index] < nums[index - 1]) {
            nums[index - 1]--;
            index--;
        }
        for (int i = index; i < nums.length; i++) {
            nums[i] = 9;
        }
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            result += nums[i] * Math.pow(10, nums.length - i - 1);
        }
        return result;
    }
}