/**https://leetcode.com/problems/smallest-value-of-the-rearranged-number/ */
//You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.
//Return the rearranged number with minimal value.
//Note that the sign of the number does not change after rearranging the digits.
// 
//Example 1:
//Input: num = 310
//Output: 103
//Explanation: The possible arrangements for the digits of 310 are 013, 031, 103, 130, 301, 310. 
//The arrangement with the smallest value that does not contain any leading zeros is 103.
//Example 2:
//Input: num = -7605
//Output: -7650
//Explanation: Some possible arrangements for the digits of -7605 are -7650, -6705, -5076, -0567.
//The arrangement with the smallest value that does not contain any leading zeros is -7650.
// 
//Constraints:
//	-1015 <= num <= 1015
class Solution {
    public long smallestNumber(long num) {
        long ans = 0;
        int[] digits = new int[10];
        int n = 0;
        while(num != 0){
            int digit = (int)(num % 10);
            if(digit != 0){
                digits[digit]++;
            }
            num = num / 10;
            n++;
        }
        if(n == 1){
            return num;
        }
        int i = 1;
        while(i <= 9){
            while(digits[i] > 0){
                ans = ans * 10 + i;
                digits[i]--;
            }
            i++;
       }
       return ans;
    }
}