/**https://leetcode.com/problems/find-the-closest-palindrome/ */
//Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
//The closest is defined as the absolute difference minimized between two integers.
// 
//Example 1:
//Input: n = "123"
//Output: "121"
//Example 2:
//Input: n = "1"
//Output: "0"
//Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
// 
//Constraints:
//	1 <= n.length <= 18
//	n consists of only digits.
//	n does not have leading zeros.
//	n is representing an integer in the range [1, 1018 - 1].
char* nearestPalindromic(char* n) {
    int len = strlen(n);
    if (len == 1) {
        if (n[0] == '0') return "1";
        return n[0] - 1;
    }
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    long long num = atoll(n);   
    long long lower = num - 1, higher = num + 1;

    // Helper function to check if a number is a palindrome
    int isPalindrome(long long x) {
        char str[20];
        sprintf(str, "%lld", x);
        int i = 0, j = strlen(str) - 1;
        while (i < j) {
            if (str[i++] != str[j--]) return 0;
        }
        return 1;
    }

    // Find the closest lower palindrome
    while (!isPalindrome(lower)) {
        lower--;
    }

    // Find the closest higher palindrome
    while (!isPalindrome(higher)) {
        higher++;
    }

    // Compare distances and return the closest palindrome
    if ((num - lower) <= (higher - num)) {
        sprintf(res, "%lld", lower);
    } else {
        sprintf(res, "%lld", higher);
    }

    return res;
}