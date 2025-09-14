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
        if (n == 1) return 2;
        if (n <= 3) return n;
        if (n <= 5) return 5;
        if (n <= 7) return 7;
        if (n <= 11) return 11;
        for (int i = 1; i < 100000; i++) {
            string s = to_string(i);
            string t = s;
            reverse(t.begin(), t.end());
            s += t.substr(1);
            int x = stoi(s);
            if (x >= n && isPrime(x)) return x;
        }
        return -1;        
    }
};