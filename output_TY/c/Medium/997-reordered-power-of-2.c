/**https://leetcode.com/problems/reordered-power-of-2/ */
//You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
//Return true if and only if we can do this so that the resulting number is a power of two.
// 
//Example 1:
//Input: n = 1
//Output: true
//Example 2:
//Input: n = 10
//Output: false
// 
//Constraints:
//	1 <= n <= 109
bool reorderedPowerOf2(int n){
    int a[10] = {0};
    int b[10] = {0};
    int i, j, k, t, flag;
    int len = 0;
    int num = n;
    while (num) {
        a[len++] = num % 10;
        num /= 10;
    }
    for (i = 0; i < 32; i++) {
        t = 1<< i;
    }
    for (i = 0; i < 32; i++) {
        num = t;
        flag = 1;
        for (j = 0; j < len; j++) {
            b[j] = num % 10;
            num /= 10;
        }
        for (j = 0; j < len; j++) {
            for (k = 0; k < len; k++) {
                if (a[j] == b[k]) {
                    flag = 0;
                    break;
                }
            }
        }
    }
    return flag;
}