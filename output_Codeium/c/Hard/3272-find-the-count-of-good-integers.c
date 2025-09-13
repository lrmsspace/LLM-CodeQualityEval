/*
 You are given two positive integers n and k.
 An integer x is called k-palindromic if:
 x is a palindrome.
 x is divisible by k.
 An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.
 Return the count of good integers containing n digits.
 Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.
 Example 1:
 Input: n = 3, k = 5
 Output: 27
 Explanation:
 Some of the good integers are:
 551 because it can be rearranged to form 515.
 525 because it is already k-palindromic.
 Example 2:
 Input: n = 1, k = 4
 Output: 2
 Explanation:
 The two good integers are 4 and 8.
 Example 3:
 Input: n = 5, k = 6
 Output: 2468
 Constraints:
 1 <= n <= 10
 1 <= k <= 9
*/

// Function to check if a number is a palindrome
bool isPalindrome(long long num) {
    long long reversed = 0, original = num, remainder;
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    return original == reversed;
}

long long countGoodIntegers(int n, int k) {
    long long count = 0;
    long long start = 1;
    for (int i = 1; i < n; i++) {
        start *= 10;
    }
    long long end = start * 10 - 1;
    
    // Iterate over all n-digit numbers
    for (long long i = start; i <= end; i++) {
        if (i % k == 0 && isPalindrome(i)) {
            count++;
        }
    }
    
    return count;
}

