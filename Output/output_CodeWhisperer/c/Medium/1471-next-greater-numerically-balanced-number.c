/**https://leetcode.com/problems/next-greater-numerically-balanced-number/ */
//An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
//Given an integer n, return the smallest numerically balanced number strictly greater than n.
// 
//Example 1:
//Input: n = 1
//Output: 22
//Explanation: 
//22 is numerically balanced since:
//- The digit 2 occurs 2 times. 
//It is also the smallest numerically balanced number strictly greater than 1.
//Example 2:
//Input: n = 1000
//Output: 1333
//Explanation: 
//1333 is numerically balanced since:
//- The digit 1 occurs 1 time.
//- The digit 3 occurs 3 times. 
//It is also the smallest numerically balanced number strictly greater than 1000.
//Note that 1022 cannot be the answer because 0 appeared more than 0 times.
//Example 3:
//Input: n = 3000
//Output: 3133
//Explanation: 
//3133 is numerically balanced since:
//- The digit 1 occurs 1 time.
//- The digit 3 occurs 3 times.
//It is also the smallest numerically balanced number strictly greater than 3000.
// 
//Constraints:
//	0 <= n <= 106
int nextBeautifulNumber(int n) {
    int i, j, k, l, m, count, temp, sum, rem, num;
    int *a = (int *)malloc(sizeof(int) * 10);
    for (i = 0; i < 10; i++) {
        a[i] = 0;
    }
    num = n + 1;
    while (1) {
        temp = num;
        count = 0;
        while (temp > 0) {
            rem = temp % 10;
            a[rem]++;
            temp /= 10;
            count++;
        }
        for (i = 0; i < 10; i++) {
            if (a[i] > 0 && a[i] != i) {
                break;
            }
        }
        if (i == 10) {
            return num;
        }
        for (i = 0; i < 10; i++) {
            a[i] = 0;
        }
        num++;
    }
    return -1;
}