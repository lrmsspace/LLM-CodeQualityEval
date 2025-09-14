/**https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/ */
//Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
// 
//Example 1:
//Input: n = 13, k = 2
//Output: 10
//Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
//Example 2:
//Input: n = 1, k = 1
//Output: 1
// 
//Constraints:
//	1 <= k <= n <= 109
class Solution {
public:
    int findKthNumber(int n, int k) {
        int res = 1;
        k--;
        while (k > 0) {
            int step = 0;
            int first = res;
            int last = res + 1;
            while (first <= n) {
                step += min(n + 1, last) - first;
                first *= 10;
                last *= 10;
            }
            if (k >= step) {
                k -= step;
                res += 1;
            } else {
                res *= 10;
                k -= 1;
            }
        }
        return res;
    }
};