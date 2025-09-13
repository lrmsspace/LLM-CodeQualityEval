/**https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/ */
//There are n people and 40 types of hats labeled from 1 to 40.
//Given a 2D integer array hats, where hats[i] is a list of all hats preferred by the ith person.
//Return the number of ways that the n people wear different hats to each other.
//Since the answer may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: hats = [[3,4],[4,5],[5]]
//Output: 1
//Explanation: There is only one way to choose hats given the conditions. 
//First person choose hat 3, Second person choose hat 4 and last one hat 5.
//Example 2:
//Input: hats = [[3,5,1],[3,5]]
//Output: 4
//Explanation: There are 4 ways to choose hats:
//(3,5), (5,3), (1,3) and (1,5)
//Example 3:
//Input: hats = [[1,2,3,4],[1,2,3,4],[1,2,3,4],[1,2,3,4]]
//Output: 24
//Explanation: Each person can choose hats labeled from 1 to 4.
//Number of Permutations of (1,2,3,4) = 24.
// 
//Constraints:
//	n == hats.length
//	1 <= n <= 10
//	1 <= hats[i].length <= 40
//	1 <= hats[i][j] <= 40
//	hats[i] contains a list of unique integers.
import java.util.ArrayList;
class Solution {
    public int numberWays(List<List<Integer>> hats) {
        final int MOD = 1000000007;
        int n = hats.size();
        List<Integer>[] h2p = new List[41];
        for (int i = 1; i <= 40; ++i) {
            h2p[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; ++i) {
            for (int hat : hats.get(i)) {
                h2p[hat].add(i);
            }
        }
        int[] dp = new int[1 << n];
        dp[0] = 1;
        for (int hat = 1; hat <= 40; ++hat) {
            for (int mask = (1 << n) - 1; mask >= 0; --mask) {
                for (int p : h2p[hat]) {
                    if ((mask & (1 << p)) > 0) {
                        dp[mask] = (dp[mask] + dp[mask ^ (1 << p)]) % MOD;
                    }
                }
            }
        }
        return dp[(1 << n) - 1];       
    }
}