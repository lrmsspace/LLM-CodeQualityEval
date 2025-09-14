/**https://leetcode.com/problems/number-of-beautiful-partitions/ */
//You are given a string s that consists of the digits '1' to '9' and two integers k and minLength.
//A partition of s is called beautiful if:
//	s is partitioned into k non-intersecting substrings.
//	Each substring has a length of at least minLength.
//	Each substring starts with a prime digit and ends with a non-prime digit. Prime digits are '2', '3', '5', and '7', and the rest of the digits are non-prime.
//Return the number of beautiful partitions of s. Since the answer may be very large, return it modulo 109 + 7.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "23542185131", k = 3, minLength = 2
//Output: 3
//Explanation: There exists three ways to create a beautiful partition:
//"2354 | 218 | 5131"
//"2354 | 21851 | 31"
//"2354218 | 51 | 31"
//Example 2:
//Input: s = "23542185131", k = 3, minLength = 3
//Output: 1
//Explanation: There exists one way to create a beautiful partition: "2354 | 218 | 5131".
//Example 3:
//Input: s = "3312958", k = 3, minLength = 1
//Output: 1
//Explanation: There exists one way to create a beautiful partition: "331 | 29 | 58".
// 
//Constraints:
//	1 <= k, minLength <= s.length <= 1000
//	s consists of the digits '1' to '9'.
int beautifulPartitions(char* s, int k, int minLength) {
    int n = strlen(s);
    int i, j, l, p, q, r, t, x, y, z, ans = 0;
    int cnt[10][10] = {0};
    int dp[1001][1001] = {0};
    int prime[10] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 0};
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            cnt[i][j] = prime[s[i] - '0'] && !prime[s[j] - '0'];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            dp[i][j] = cnt[i][j];
            if (j > i) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (dp[i][j] == 0) {
                continue;
            }
            for (l = 1; l <= k; l++) {
                if (i == 0) {
                    if (l == 1) {
                        if (j - i + 1 >= minLength) {
                            ans++;
                        }
                    }
                    continue;
                }
                for (p = 0; p < i; p++) {
                    if (dp[p][i - 1] >= l - 1) {
                        for (q = j + 1; q < n; q++) {
                            if (dp[j + 1][q] >= k - l) {
                                x = dp[p][i - 1] - l + 1;
                                y = dp[i][j];
                                z = dp[j + 1][q] - (k - l);
                                if (x >= minLength && y >= minLength && z >= minLength) {
                                    ans++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ans;    
}