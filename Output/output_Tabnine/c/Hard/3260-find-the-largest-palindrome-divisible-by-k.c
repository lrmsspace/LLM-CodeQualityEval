/*
 You are given two positive integers n and k.
 An integer x is called k-palindromic if:
 x is a palindrome.
 x is divisible by k.
 Return the largest integer having n digits (as a string) that is k-palindromic.
 Note that the integer must not have leading zeros.
 Example 1:
 Input: n = 3, k = 5
 Output: "595"
 Explanation:
 595 is the largest k-palindromic integer with 3 digits.
 Example 2:
 Input: n = 1, k = 4
 Output: "8"
 Explanation:
 4 and 8 are the only k-palindromic integers with 1 digit.
 Example 3:
 Input: n = 5, k = 6
 Output: "89898"
 Constraints:
 1 <= n <= 105
 1 <= k <= 9
*/

char* largestPalindrome(int n, int k) {

    char* res = (char*)malloc((n + 1) * sizeof(char));
    res[n] = '\0';
    
    int left = (int)pow(10, n - 1) - 1;
    int right = (int)pow(10, n) - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isKPalindrome(mid, k)) {
            left = mid + 1;
            strncpy(res, to_string(mid).c_str(), n);
        } else {
            right = mid - 1;
        }
    }
    
    return res;
    
}