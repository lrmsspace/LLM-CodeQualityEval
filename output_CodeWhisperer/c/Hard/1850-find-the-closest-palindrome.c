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
    int i = 0;

    if (len == 1) {
        n[0] = '0';
        return n;
    }

    if (len % 2 == 0) {
        i = len / 2 - 1;
    } else {
        i = len / 2;
    }

    while (i >= 0) {
        if (n[i] != '0') {
            n[i] = n[i] - 1;
            break;
        } else {
            n[i] = '9';
            i--;
        }
    }

    if (i < 0) {
        char* result = (char*)malloc(sizeof(char) * (len + 2));
        result[0] = '1';
        for (int j = 1; j < len; j++) {
            result[j] = '0';
        }
        result[len + 1] = '\0';
        return result;
    } else {
        for (int j = 0; j < i; j++) {
            n[len - 1 - j] = n[j];
        }
        return n;
    }

    return n;
    
}