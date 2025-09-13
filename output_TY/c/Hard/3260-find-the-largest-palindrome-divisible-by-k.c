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
    char *res = malloc(sizeof(char) * 100000);  
    if (n == 1) {
        res[0] = '9';
        res[1] = '\0';
        return res;
    }

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            int a = i;
            int b = j;
            int c = i;
            int d = j;
            int e = i;
            int f = j;
            int g = i;
            int h = j;
            int k = i;
            int l = j;
            int m = i;
            int n = j;
            int o = i;
            int p = j;
            int q = i;
            int r = j;
            int s = i;
            int t = j;
            int u = i;
        }
    }
    return ans;
    
}