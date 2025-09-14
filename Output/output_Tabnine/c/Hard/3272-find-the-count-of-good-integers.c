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

long long countGoodIntegers(int n, int k) {

    // Calculate the maximum possible value for the first digit of the good integer
    int maxFirstDigit = k;
    
    // Calculate the maximum possible value for the remaining digits
    int maxRemainingDigits = k;
    for (int i = 1; i < n - 1; i++) {
        maxRemainingDigits *= k;
    }
    
    // Initialize the count of good integers
    long long count = 0;
    // Iterate through all possible values for the first digit
    for (int firstDigit = 0; firstDigit <= maxFirstDigit; firstDigit++) {
        // Iterate through all possible values for the remaining digits
        for (int remainingDigits = 0; remainingDigits <= maxRemainingDigits; remainingDigits++) {
            // Calculate the current good integer
            long long currentInteger = firstDigit * maxRemainingDigits + remainingDigits;
            // Check if the current integer is k-palindromic
            if (isPalindrome(currentInteger) && currentInteger % k == 0) {
                count++;
            }
        }
    }   
    return count;
    
}