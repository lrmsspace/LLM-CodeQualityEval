/**https://leetcode.com/problems/numbers-with-repeated-digits/ */
//Given an integer n, return the number of positive integers in the range [1, n] that have at least one repeated digit.
// 
//Example 1:
//Input: n = 20
//Output: 1
//Explanation: The only positive number (<= 20) with at least 1 repeated digit is 11.
//Example 2:
//Input: n = 100
//Output: 10
//Explanation: The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.
//Example 3:
//Input: n = 1000
//Output: 262
// 
//Constraints:
//	1 <= n <= 109
int numDupDigitsAtMostN(int n) {
    int count = 0;
    int i = 1;
    while (i <= n) {
        int temp = i;
        int flag = 0;
        int digits[10] = {0};
        while (temp > 0) {
            int digit = temp % 10;
            if (digits[digit] == 1) {
                flag = 1;
                break;
            }
            digits[digit] = 1;
            temp /= 10;
        }
        if (flag == 0) {
            count++;
        }
        i++;
    }
    return n - count;
    
}