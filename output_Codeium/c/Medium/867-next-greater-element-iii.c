/**https://leetcode.com/problems/next-greater-element-iii/ */
//Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
//Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
// 
//Example 1:
//Input: n = 12
//Output: 21
//Example 2:
//Input: n = 21
//Output: -1
// 
//Constraints:
//	1 <= n <= 231 - 1
int nextGreaterElement(int n) {
    int num = n;
    int digit[32] = {0};
    int len = 0;
    while (num > 0) {
        digit[len++] = num % 10;
        num /= 10;
    }

    int i = len - 1;
    while (i > 0 && digit[i] <= digit[i - 1]) {
        i--;
    }
    if (i == 0) {
        return -1;
    }
    int j = i - 1;
    while (j >= 0 && digit[i] > digit[j]) {
        j--;
    }
    swap(digit[i], digit[j]);

    for (int k = i + 1; k < len; k++) {
        digit[k] = 0;
    }

    num = 0;
    for (int k = 0; k < len; k++) {
        num = num * 10 + digit[k];
    }
    return num > INT_MAX ? -1 : num;
}