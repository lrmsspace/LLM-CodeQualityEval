/*
import java.util.Arrays;
 You are given a string num which represents a positive integer, and an integer t.
 A number is called zero-free if none of its digits are 0.
 Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".
 Example 1:
 Input: num = "1234", t = 256
 Output: "1488"
 Explanation:
 The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.
 Example 2:
 Input: num = "12355", t = 50
 Output: "12355"
 Explanation:
 12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.
 Example 3:
 Input: num = "11111", t = 26
 Output: "-1"
 Explanation:
 No number greater than 11111 has the product of its digits divisible by 26.
 Constraints:
 2 <= num.length <= 2 * 105
 num consists only of digits in the range ['0', '9'].
 num does not contain leading zeros.
 1 <= t <= 1014
*/

class Solution {
    public String smallestNumber(String num, long t) {
        int[] nums = new int[num.length()];
        for (int i = 0; i < num.length(); i++) {
            nums[i] = num.charAt(i) - '0';
        }
        Arrays.sort(nums);
        if (nums[0] == 0) {
            return "0";
        }
        long product = 1;
        for (int i = 0; i < nums.length; i++) {
            product *= nums[i];
            if (product >= t) {
                StringBuilder sb = new StringBuilder();
                sb.append(nums[i]);
                for (int j = nums.length - 1; j >= 0; j--) {
                    if (j != i) {
                        sb.append(nums[j]);
                    }
                }
                return sb.toString();
            }
        }
        return "-1";        
    }
}