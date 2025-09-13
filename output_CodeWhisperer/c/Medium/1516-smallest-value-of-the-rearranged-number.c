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
long long smallestNumber(long long num) {
    if (num == 0) {
        return 0;
    }
    int sign = 1;
    if (num < 0) {
        sign = -1;
        num = -num;
    }
    int digits[10] = {0};
    while (num > 0) {
        digits[num % 10]++;
        num /= 10;
    }
    long long result = 0;
    if (sign == 1) {
        for (int i = 1; i < 10; i++) {
            while (digits[i] > 0) {
                result = result * 10 + i;
                digits[i]--;
            }
        }
        if (result == 0) {
            while (digits[0] > 0) {
                result = result * 10;
                digits[0]--;
            }
        }
    } else {
        for (int i = 9; i >= 0; i--) {
            while (digits[i] > 0) {
                result = result * 10 + i;
                digits[i]--;
            }
        }
    }
    return sign * result;
}