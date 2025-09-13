/**https://leetcode.com/problems/shopping-offers/ */
//In LeetCode Store, there are n items to sell. Each item has a price. However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.
//You are given an integer array price where price[i] is the price of the ith item, and an integer array needs where needs[i] is the number of pieces of the ith item you want to buy.
//You are also given an array special where special[i] is of size n + 1 where special[i][j] is the number of pieces of the jth item in the ith offer and special[i][n] (i.e., the last integer in the array) is the price of the ith offer.
//Return the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers. You are not allowed to buy more items than you want, even if that would lower the overall price. You could use any of the special offers as many times as you want.
// 
//Example 1:
//Input: price = [2,5], special = [[3,0,5],[1,2,10]], needs = [3,2]
//Output: 14
//Explanation: There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
//In special offer 1, you can pay $5 for 3A and 0B
//In special offer 2, you can pay $10 for 1A and 2B. 
//You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
//Example 2:
//Input: price = [2,3,4], special = [[1,1,0,4],[2,2,1,9]], needs = [1,2,1]
//Output: 11
//Explanation: The price of A is $2, and $3 for B, $4 for C. 
//You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
//You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
//You cannot add more items, though only $9 for 2A ,2B and 1C.
// 
//Constraints:
//	n == price.length == needs.length
//	1 <= n <= 6
//	0 <= price[i], needs[i] <= 10
//	1 <= special.length <= 100
//	special[i].length == n + 1
//	0 <= special[i][j] <= 50
//	The input is generated that at least one of special[i][j] is non-zero for 0 <= j <= n - 1.
int shoppingOffers(int* price, int priceSize, int** special, int specialSize, int* specialColSize, int* needs, int needsSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int dp[7][7][7][7][7][7];
    int *a, *b, *c, *d, *e, *f;
    a = (int*)malloc(sizeof(int) * 6 * 6 * 6 * 6 * 6 * 6);
    b = (int*)malloc(sizeof(int) * 6 * 6 * 6 * 6 * 6 * 6);
    c = (int*)malloc(sizeof(int) * 6 * 6 * 6 * 6 * 6);
    d = (int*)malloc(sizeof(int) * 6 * 6 * 6 * 6);
    e = (int*)malloc(sizeof(int) * 6 * 6 * 6);
    f = (int*)malloc(sizeof(int) * 6 * 6);
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            for (k = 0; k < 6; k++) {
                for (l = 0; l < 6; l++) {
                    for (m = 0; m < 6; m++) {
                        for (n = 0; n < 6; n++) {
                            dp[i][j][k][l][m][n] = 0;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < 6; i++) {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
        d[i] = 0;
        e[i] = 0;
        f[i] = 0;
    }
    for (i = 0; i < priceSize; i++) {
        a[i] = price[i];
    }
    for (i = 0; i < specialSize; i++) {
        for (j = 0; j < needsSize; j++) {
            b[j] = special[i][j];
        }
        b[j] = special[i][j];
        c[0] = special[i][ needsSize];
        for (j = 0; j < needsSize; j++) {
            if (b[j] > needs[j]) {
                break;
            }
        }
        if (j == needsSize) {
            for (j = 0; j < needsSize; j++) {
                d[j] = needs[j] - b[j];
            }
            dp[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]] = shoppingOffers(price, priceSize, special, specialSize, specialColSize, d, needsSize);
            if (c[0] + dp[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]] < c[0]) {
                c[0] = c[0] + dp[d[0]][d[1]][d[2]][d[3]][d[4]][d[5]];
            }
        }
        if (c[0] < f[0]) {
            f[0] = c[0];
        }
        }
    return f[0];  
}