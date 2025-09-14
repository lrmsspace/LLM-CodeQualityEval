/**https://leetcode.com/problems/check-if-the-number-is-fascinating/ */
//You are given an integer n that consists of exactly 3 digits.
//We call the number n fascinating if, after the following modification, the resulting number contains all the digits from 1 to 9 exactly once and does not contain any 0's:
//	Concatenate n with the numbers 2 * n and 3 * n.
//Return true if n is fascinating, or false otherwise.
//Concatenating two numbers means joining them together. For example, the concatenation of 121 and 371 is 121371.
// 
//Example 1:
//Input: n = 192
//Output: true
//Explanation: We concatenate the numbers n = 192 and 2 * n = 384 and 3 * n = 576. The resulting number is 192384576. This number contains all the digits from 1 to 9 exactly once.
//Example 2:
//Input: n = 100
//Output: false
//Explanation: We concatenate the numbers n = 100 and 2 * n = 200 and 3 * n = 300. The resulting number is 100200300. This number does not satisfy any of the conditions.
// 
//Constraints:
//	100 <= n <= 999
bool isFascinating(int n) {
    int i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z;
    i = n * 2;
    j = n * 3;
    k = n * 1000000 + i * 1000 + j;
    l = k;
    m = 0;
    o = 0;
    p = 0;
    q = 0;
    r = 0;
    s = 0;
    t = 0;
    u = 0;
    v = 0;
    w = 0;
    x = 0;
    y = 0;
    z = 0;
    while (l > 0) {
        m = l % 10;
        l = l / 10;
        if (m == 1) {
            o = 1;
        }
        if (m == 2) {
            p = 1;
        }
        if (m == 3) {
            q = 1;
        }
        if (m == 4) {
            r = 1;
        }
        if (m == 5) {
            s = 1;
        }
        if (m == 6) {
            t = 1;
        }
        if (m == 7) {
            u = 1;
        }
        if (m == 8) {
            v = 1;
        }
        if (m == 9) {
            w = 1;
        }
        if (m == 0) {
            x = 1;
        }
    }
    if (o == 1 && p == 1 && q == 1 && r == 1 && s == 1 && t == 1 && u == 1 && v == 1 && w == 1 && x == 0) {
        y = 1;
    }
    if (y == 1) {
        z = 1;
    }
    return z;    
}