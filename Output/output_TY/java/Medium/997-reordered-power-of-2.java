/**https://leetcode.com/problems/reordered-power-of-2/ */
//You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
//Return true if and only if we can do this so that the resulting number is a power of two.
// 
//Example 1:
//Input: n = 1
//Output: true
//Example 2:
//Input: n = 10
//Output: false
// 
//Constraints:
//	1 <= n <= 109
class Solution {
    public boolean reorderedPowerOf2(int n) {
        int[] count = new int[10];
        while (n > 0) {
            count[n % 10]++;
            n = n / 10;
        }
        int powerOf2 = 1;
        while (powerOf2 <= n) {
            int[] count2 = new int[10];
            int temp = powerOf2;
            while (temp > 0) {
                count2[temp % 10]++;
                temp = temp / 10;
            }
            boolean match = true;
            for (int i = 0; i < 10; i++) {
                if (count[i] != count2[i]) {
                    match =false;
                }
            }
        }
        return match;
    }
}