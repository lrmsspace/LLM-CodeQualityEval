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
    char* left = (char*)malloc((len + 1) * sizeof(char));
    char* right = (char*)malloc((len + 1) * sizeof(char));
    strcpy(left, n);
    strcpy(right, n);
    int diff = INT_MAX;
    int i = 0;
    while (i < len / 2) {
        left[len - i - 1] = left[i];
        right[i] = right[len - i - 1];
        i++;
    }
    int leftNum = atoi(left);
    int rightNum = atoi(right);
    if (abs(leftNum - atoi(n)) < diff) {
        diff = abs(leftNum - atoi(n));
        strcpy(right, left);
    }
    if (abs(rightNum - atoi(n)) < diff) {
        diff = abs(rightNum - atoi(n));
        strcpy(right, right);
    }
    free(left);
    free(right);
    return right;
}