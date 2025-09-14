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
int primePalindrome(int n) {
    // Find the largest prime palindrome less than or equal to n
    int left = n, right = n;
    while (true) {
        int num = left * 10 + right;
        if (isPrime(num)) {
            return num;
        }
        left = num / 10;
        right = num % 10;
    }
    
    // Helper function to check if a number is prime
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
    
    // Start from the next prime number and check if it's a palindrome
    int nextPrime = getNextPrime(n);
    while (true) {
        if (isPrime(nextPrime) && isPalindrome(nextPrime)) {
            return nextPrime;
        }
        nextPrime++;
    }
    
    // Helper function to get the next prime number
    int getNextPrime(int num) {
        while (true) {
            num++;
            if (isPrime(num)) {
                return num;
            }
        }
    }
    
    // Helper function to check if a number is palindrome
    bool isPalindrome(int num) {
        int reversedNum = 0;
        int temp = num;
        while (temp!= 0) {
            reversedNum = reversedNum * 10 + temp % 10;
            temp /= 10;
        }
        return reversedNum == num;
    }
    
    // Return -1 if no prime palindrome greater than or equal to n exists
    return -1;
    
}