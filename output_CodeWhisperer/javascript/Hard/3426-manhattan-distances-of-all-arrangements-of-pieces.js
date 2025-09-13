/*
 You are given three integers m, n, and k.
 There is a rectangular grid of size m × n containing k identical pieces. Return the sum of Manhattan distances between every pair of pieces over all valid arrangements of pieces.
 A valid arrangement is a placement of all k pieces on the grid with at most one piece per cell.
 Since the answer may be very large, return it modulo 109 + 7.
 The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.
 Example 1:
 Input: m = 2, n = 2, k = 2
 Output: 8
 Explanation:
 The valid arrangements of pieces on the board are:
 In the first 4 arrangements, the Manhattan distance between the two pieces is 1.
 In the last 2 arrangements, the Manhattan distance between the two pieces is 2.
 Thus, the total Manhattan distance across all valid arrangements is 1 + 1 + 1 + 1 + 2 + 2 = 8.
 Example 2:
 Input: m = 1, n = 4, k = 3
 Output: 20
 Explanation:
 The valid arrangements of pieces on the board are:
 The first and last arrangements have a total Manhattan distance of 1 + 1 + 2 = 4.
 The middle two arrangements have a total Manhattan distance of 1 + 2 + 3 = 6.
 The total Manhattan distance between all pairs of pieces across all arrangements is 4 + 6 + 6 + 4 = 20.
 Constraints:
 1 <= m, n <= 105
 2 <= m * n <= 105
 2 <= k <= m * n
*/

/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var distanceSum = function(m, n, k) {
    const MOD = 1e9 + 7;
    const fact = (n) => {
        let res = 1;
        for (let i = 1; i <= n; i++) {
            res = (res * i) % MOD;
        }
        return res;
    };
    
    const nCr = (n, r) => {
        if (n < r) return 0;
        let res = 1;
        for (let i = 0; i < r; i++) {
            res = (res * (n - i)) % MOD;
            res = (res * pow((i + 1), MOD - 2, MOD)) % MOD;
        }
        return res;
    };
    
    const pow = (a, b, m) => {
        a %= m;
        let res = 1n;
        while (b > 0) {
            if (b & 1) res = (res * BigInt(a)) % BigInt(m);
            a = (BigInt(a) * BigInt(a)) % BigInt(m);
            b >>= 1;
        }
        return res;
    };
    
    let res = 0;
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= m; j++) {
            let temp = (nCr(k - 1, i - 1) * fact(i - 1)) % MOD;
            temp = (temp * nCr(k - i, j - 1) * fact(j - 1)) % MOD;
            temp = (temp * nCr((k - i - j + 1) * (n - i) + (k - i - j + 1), 2)) % MOD;
            res = (res + temp) % MOD;
        }
    }
    
    return (res * 2) % MOD;        
};