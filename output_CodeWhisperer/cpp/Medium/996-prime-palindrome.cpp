/**https://leetcode.com/problems/prime-palindrome/ */
//Given an integer n, return the smallest prime palindrome greater than or equal to n.
//An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.
//	For example, 2, 3, 5, 7, 11, and 13 are all primes.
//An integer is a palindrome if it reads the same from left to right as it does from right to left.
//	For example, 101 and 12321 are palindromes.
//The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].
// 
//Example 1:
//Input: n = 6
//Output: 7
//Example 2:
//Input: n = 8
//Output: 11
//Example 3:
//Input: n = 13
//Output: 101
// 
//Constraints:
//	1 <= n <= 108
class Solution {
public:
    int primePalindrome(int n) {
        if (n <= 2) {
            return 2;
        }
        if (n == 3) {
            return 3;
        }
        if (n <= 5) {
            return 5;
        }
        if (n <= 7) {
            return 7;
        }
        if (n <= 11) {
            return 11;
        }
        int x = 1;
        while (true) {
            x++;
            if (x % 2 == 0) {
                continue;
            }
            int y = x;
            int r = 0;
            while (y > 0) {
                r = r * 10 + y % 10;
                y /= 10;
            }
            x = r;
            bool isPrime = true;
            for (int i = 3; i * i <= x; i += 2) {
                if (x % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                if (x >= n) {
                    return x;
                }
            }
        }
  
        return 0;
    }
};