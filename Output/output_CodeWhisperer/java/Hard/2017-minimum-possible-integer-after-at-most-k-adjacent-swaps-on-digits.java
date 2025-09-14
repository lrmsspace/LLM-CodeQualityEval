/**https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/ */
//You are given a string num representing the digits of a very large integer and an integer k. You are allowed to swap any two adjacent digits of the integer at most k times.
//Return the minimum integer you can obtain also as a string.
// 
//Example 1:
//Input: num = "4321", k = 4
//Output: "1342"
//Explanation: The steps to obtain the minimum integer from 4321 with 4 adjacent swaps are shown.
//Example 2:
//Input: num = "100", k = 1
//Output: "010"
//Explanation: It's ok for the output to have leading zeros, but the input is guaranteed not to have any leading zeros.
//Example 3:
//Input: num = "36789", k = 1000
//Output: "36789"
//Explanation: We can keep the number without any swaps.
// 
//Constraints:
//	1 <= num.length <= 3 * 104
//	num consists of only digits and does not contain leading zeros.
//	1 <= k <= 109
import java.util.Arrays;
import java.util.Arrays;
class Solution {
    public String minInteger(String num, int k) {
        int n = num.length();
        if (k > n * (n - 1) / 2) {
            char[] arr = num.toCharArray();
            Arrays.sort(arr);
            return new String(arr);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            char min = '9';
            int minIndex = -1;
            for (int j = Math.max(0, i - k); j <= Math.min(n - 1, i + k); j++) {
                if (num.charAt(j) < min) {
                    min = num.charAt(j);
                    minIndex = j;
                }
            }
            sb.append(min);
            k -= Math.abs(i - minIndex);
            num = num.substring(0, minIndex) + num.substring(minIndex + 1);
        }
        return sb.toString();      
    }
}