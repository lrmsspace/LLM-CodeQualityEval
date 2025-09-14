/**https://leetcode.com/problems/super-palindromes/ */
//Let's say a positive integer is a super-palindrome if it is a palindrome, and it is also the square of a palindrome.
//Given two positive integers left and right represented as strings, return the number of super-palindromes integers in the inclusive range [left, right].
// 
//Example 1:
//Input: left = "4", right = "1000"
//Output: 4
//Explanation: 4, 9, 121, and 484 are superpalindromes.
//Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
//Example 2:
//Input: left = "1", right = "2"
//Output: 1
// 
//Constraints:
//	1 <= left.length, right.length <= 18
//	left and right consist of only digits.
//	left and right cannot have leading zeros.
//	left and right represent integers in the range [1, 1018 - 1].
//	left is less than or equal to right.
int superpalindromesInRange(char* left, char* right) {
    int l = strlen(left);
    int r = strlen(right);
    int count = 0;
    
    // Iterate from the longest possible length to the shortest possible length
    for (int len = max(l, r); len >= 1; len--) {
        // Generate all possible substrings of the current length
        for (int i = 0; i <= l - len; i++) {
            for (int j = 0; j <= r - len; j++) {
                // Check if the substring is a palindrome
                bool isPalindrome = true;
                for (int k = i, lk = j + len - 1; k < lk; k++, lk--) {
                    if (left[k]!= left[lk]) {
                        isPalindrome = false;
                        break;
                    }
                }
                
                // Check if the square of the palindrome is a super-palindrome
                if (isPalindrome && isSuperPalindrome(left + i, len)) {
                    count++;
                }
            }
        }
    }
    
    return count;
    
}