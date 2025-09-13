/*
 You are given integers n, m, and k.
 There are two logs of lengths n and m units, which need to be transported in three trucks where each truck can carry one log with length at most k units.
 You may cut the logs into smaller pieces, where the cost of cutting a log of length x into logs of length len1 and len2 is cost = len1 * len2 such that len1 + len2 = x.
 Return the minimum total cost to distribute the logs onto the trucks. If the logs don't need to be cut, the total cost is 0.
 Example 1:
 Input: n = 6, m = 5, k = 5
 Output: 5
 Explanation:
 Cut the log with length 6 into logs with length 1 and 5, at a cost equal to 1 * 5 == 5. Now the three logs of length 1, 5, and 5 can fit in one truck each.
 Example 2:
 Input: n = 4, m = 4, k = 6
 Output: 0
 Explanation:
 The two logs can fit in the trucks already, hence we don't need to cut the logs.
 Constraints:
 2 <= k <= 105
 1 <= n, m <= 2 * k
 The input is generated such that it is always possible to transport the logs.
*/

class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k) {
            return 0;
        } else if (n <= k) {
            return m;
        } else if (m <= k) {
            return n;
        } else {
            long long minCost = LLONG_MAX;
            for (int i = 1; i <= k; i++) {
                long long cost = (n / i) * (m / i) * i;
                if (n % i != 0) {
                    cost += (m / i) * (n % i);
                }
                if (m % i != 0) {
                    cost += (n / i) * (m % i);
                }
                minCost = min(minCost, cost);
            }
            return minCost;
        }
    }
};