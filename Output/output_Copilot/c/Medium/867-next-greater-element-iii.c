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
    char s[11];
    int i, j, len = 0, min = 0, minj = 0;
    long long res = 0;
    while (n) {
        s[len++] = n % 10;
        n /= 10;
    }
    for (i = 0; i < len - 1; i++) {
        if (s[i] > s[i + 1]) {
            for (j = 0; j <= i; j++) {
                if (s[j] > s[i + 1] && (min == 0 || s[j] < min)) {
                    min = s[j];
                    minj = j;
                }
            }
            s[i + 1] = s[minj];
            s[minj] = s[i + 1];
            break;
        }
    }
    if (i == len - 1) return -1;
    for (i = 0; i <= minj; i++) {
        res = res * 10 + s[i];
    }
    for (i = 0; i < len - minj - 1; i++) {
        res = res * 10 + s[minj + len - i];
    }
    if (res > INT_MAX) return -1;
    return res;    
}