/**https://leetcode.com/problems/sell-diminishing-valued-colored-balls/ */
//You have an inventory of different colored balls, and there is a customer that wants orders balls of any color.
//The customer weirdly values the colored balls. Each colored ball's value is the number of balls of that color you currently have in your inventory. For example, if you own 6 yellow balls, the customer would pay 6 for the first yellow ball. After the transaction, there are only 5 yellow balls left, so the next yellow ball is then valued at 5 (i.e., the value of the balls decreases as you sell more to the customer).
//You are given an integer array, inventory, where inventory[i] represents the number of balls of the ith color that you initially own. You are also given an integer orders, which represents the total number of balls that the customer wants. You can sell the balls in any order.
//Return the maximum total value that you can attain after selling orders colored balls. As the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: inventory = [2,5], orders = 4
//Output: 14
//Explanation: Sell the 1st color 1 time (2) and the 2nd color 3 times (5 + 4 + 3).
//The maximum total value is 2 + 5 + 4 + 3 = 14.
//Example 2:
//Input: inventory = [3,5], orders = 6
//Output: 19
//Explanation: Sell the 1st color 2 times (3 + 2) and the 2nd color 4 times (5 + 4 + 3 + 2).
//The maximum total value is 3 + 2 + 5 + 4 + 3 + 2 = 19.
// 
//Constraints:
//	1 <= inventory.length <= 105
//	1 <= inventory[i] <= 109
//	1 <= orders <= min(sum(inventory[i]), 109)
int maxProfit(int* inventory, int inventorySize, int orders){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[1000000], b[1000000], c[1000000], d[1000000], e[1000000], f[1000000], g[1000000], h[1000000], i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    memset(e, 0, sizeof(e));
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    memset(h, 0, sizeof(h));
    for (i = 0; i < inventorySize; i++) {
        a[inventory[i]]++;
    }
    for (i = 0; i < 1000000; i++) {
        if (a[i] > 0) {
            b[i] = i;
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (a[i] > 0) {
            c[i] = a[i];
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (a[i] > 0) {
            d[i] = a[i] * i;
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (a[i] > 0) {
            e[i] = a[i] * (i + 1);
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (a[i] > 0) {
            f[i] = a[i] * (i + 2);
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (a[i] > 0) {
            g[i] = a[i] * (i + 3);
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (a[i] > 0) {
            h[i] = a[i] * (i + 4);
        }
    }
    for (i = 0; i < 1000000; i++) {
        if (a[i] > 0) {
            break;
        }
    }
    i1 = i;
    for (i = 0; i < 1000000; i++) {
        if (a[i] == 0) {
            break;
        }
    }
    i2 = i;
    for (i = 0; i < 1000000; i++) {
        if (a[i] == 0) {
            break;
        }
    }
    i3 = i;
    for (i = 0; i < 1000000; i++) {
        if (a[i] == 0) {
            break;
        }
    }
    i4 = i;
    for (i = 0; i < 1000000; i++) {
        if (a[i] == 0) {
            break;
        }
    }
    i5 = i;
    for (i = 0; i < 1000000; i++) {
        if (a[i] == 0) {
            break;
        }
    }
    i6 = i;
    for (i = 0; i < 1000000; i++) {
        if (a[i] == 0) {
            break;
        }
    }
    i7 = i;
    for (i = 0; i < 1000000; i++) {
        if (a[i] == 0) {
            break;
        }
    }
    i8 = i;
    for (i = 0; i < 1000000; i++) {
        if (a[i] == 0) {
            break;
        }
    }
    i9 = i;

        for (i = 0; i < 1000000; i++) {
            if (a[i] == 0) {
                break;
            }
        }
        i10 = i;
        return ((((orders / i10) * h[i9] + ((orders % i10) * g[i8])) % 1000000007 + (((orders / i9) * f[i7] + ((orders % i9) * e[i6])) % 1000000007 + (((orders / i8) * d[i5] + ((orders % i8) * c[i4])) % 1000000007 + (((orders/ i7) * b[i3] + ((orders % i7)))))))) % 1000000007;
}