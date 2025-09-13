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
int monotoneIncreasingDigits(int n) {
    char digits[10];
    int len = 0;
    while (n) {
        digits[len++] = n % 10;
        n /= 10;
    }
    
    int i = 0;
    while (i < len - 1 && digits[i] <= digits[i + 1]) {
        i++;
    }
    
    if (i == len - 1) return n;
    
    digits[i]++;
    for (int j = i + 1; j < len; j++) digits[j] = 0;
    
    long result = 0;
    for (int j = len - 1; j >= 0; j--) {
        result = result * 10 + digits[j];
    }
    
    return result <= INT_MAX? result : 0;
    
}