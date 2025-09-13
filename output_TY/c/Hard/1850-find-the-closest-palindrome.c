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
char * nearestPalindromic(char * n){    
    int len = strlen(n);
    if (len == 1) {
        n[0]--;
        return n;
    }
    char * res = malloc(len + 1);
    memcpy(res, n, len);
    res[len] = '\0';
    if (len % 2 == 0) {
        n[len / 2]--;
        n[len / 2 - 1]--;
    } else {
        n[len / 2]--;
    }
    return n;
}
