/**https://leetcode.com/problems/minimum-cost-to-merge-stones/ */
//There are n piles of stones arranged in a row. The ith pile has stones[i] stones.
//A move consists of merging exactly k consecutive piles into one pile, and the cost of this move is equal to the total number of stones in these k piles.
//Return the minimum cost to merge all piles of stones into one pile. If it is impossible, return -1.
// 
//Example 1:
//Input: stones = [3,2,4,1], k = 2
//Output: 20
//Explanation: We start with [3, 2, 4, 1].
//We merge [3, 2] for a cost of 5, and we are left with [5, 4, 1].
//We merge [4, 1] for a cost of 5, and we are left with [5, 5].
//We merge [5, 5] for a cost of 10, and we are left with [10].
//The total cost was 20, and this is the minimum possible.
//Example 2:
//Input: stones = [3,2,4,1], k = 3
//Output: -1
//Explanation: After any merge operation, there are 2 piles left, and we can't merge anymore.  So the task is impossible.
//Example 3:
//Input: stones = [3,5,1,2,6], k = 3
//Output: 25
//Explanation: We start with [3, 5, 1, 2, 6].
//We merge [5, 1, 2] for a cost of 8, and we are left with [3, 8, 6].
//We merge [3, 8, 6] for a cost of 17, and we are left with [17].
//The total cost was 25, and this is the minimum possible.
// 
//Constraints:
//	n == stones.length
//	1 <= n <= 30
//	1 <= stones[i] <= 100
//	2 <= k <= 30
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)!= 0) return -1;
        int total = accumulate(stones.begin(), stones.end(), 0);
        vector<int> dp(1 << n, total);
        vector<vector<int>> pre(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                pre[i][j] = accumulate(stones.begin() + i, stones.begin() + j + 1, 0);
                
        for (int mask = (1 << n) - 1; mask >= 0; --mask) {
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) continue;
                for (int j = i + 1; j < n; ++j) {
                    if (!(mask & (1 << j))) continue;
                    int left = i, right = j;
                    while (right < n && (mask & (1 << (right + 1)))) ++right;
                    dp[mask] = min(dp[mask], dp[mask ^ (1 << i) ^ (1 << j)] + pre[left][right]);
                }
            }
        }
        return dp[0];
        
    }
};