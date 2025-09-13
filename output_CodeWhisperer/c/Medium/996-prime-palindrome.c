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

// Check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Check for factors of the form 6k ± 1
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Check if a number is a palindrome
bool isPalindrome(int n) {
    // Convert to string for easy comparison
    char str[12]; // Max int is 10 digits + null terminator
    sprintf(str, "%d", n);
    
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    
    return true;
}

// Generate the next palindrome greater than or equal to n
int nextPalindrome(int n) {
    char str[12];
    sprintf(str, "%d", n);
    int len = strlen(str);
    
    // Special case for single digit
    if (len == 1) {
        return n;
    }
    
    // Create a palindrome by mirroring the left half
    char palindrome[12];
    strncpy(palindrome, str, len);
    
    for (int i = 0; i < len / 2; i++) {
        palindrome[len - 1 - i] = palindrome[i];
    }
    
    // Check if the created palindrome is >= n
    if (atoi(palindrome) >= n) {
        return atoi(palindrome);
    }
    
    // Increment the middle digit(s) and propagate carry
    int mid = len / 2;
    bool carry = true;
    
    if (len % 2 == 1) { // Odd length
        palindrome[mid]++;
        if (palindrome[mid] <= '9') {
            carry = false;
        } else {
            palindrome[mid] = '0';
        }
        mid--;
    }
    
    // Propagate carry if needed
    while (carry && mid >= 0) {
        palindrome[mid]++;
        if (palindrome[mid] <= '9') {
            carry = false;
        } else {
            palindrome[mid] = '0';
        }
        palindrome[len - 1 - mid] = palindrome[mid];
        mid--;
    }
    
    // If we still have a carry, we need to add a digit
    if (carry) {
        palindrome[0] = '1';
        palindrome[len] = '1';
        palindrome[len + 1] = '\0';
        return atoi(palindrome);
    }
    
    return atoi(palindrome);
}

int primePalindrome(int n) {
    // Handle special cases
    if (n <= 2) return 2;
    if (n <= 3) return 3;
    if (n <= 5) return 5;
    if (n <= 7) return 7;
    if (n <= 11) return 11;
    
    // All even-length palindromes > 11 are divisible by 11
    // So we can skip checking even-length palindromes
    
    // Start with the next palindrome >= n
    int candidate = nextPalindrome(n);
    
    while (true) {
        // Check if the candidate is prime
        if (isPrime(candidate)) {
            return candidate;
        }
        
        // Generate the next palindrome
        candidate = nextPalindrome(candidate + 1);
        
        // Optimization: Skip even-length palindromes > 11
        int digits = (int)log10(candidate) + 1;
        if (digits % 2 == 0 && candidate > 11) {
            // Jump to the smallest palindrome with one more digit
            int power = (int)pow(10, digits);
            candidate = power + 1; // This will be 10...01
        }
    }
}
