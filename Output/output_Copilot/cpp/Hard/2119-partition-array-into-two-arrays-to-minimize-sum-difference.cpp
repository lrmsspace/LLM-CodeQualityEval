/**https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/ */
//You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.
//Return the minimum possible absolute difference.
// 
//Example 1:
//Input: nums = [3,9,7,3]
//Output: 2
//Explanation: One optimal partition is: [3,9] and [7,3].
//The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
//Example 2:
//Input: nums = [-36,36]
//Output: 72
//Explanation: One optimal partition is: [-36] and [36].
//The absolute difference between the sums of the arrays is abs((-36) - (36)) = 72.
//Example 3:
//Input: nums = [2,-1,0,4,-2,-9]
//Output: 0
//Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
//The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.
// 
//Constraints:
//	1 <= n <= 15
//	nums.length == 2 * n
//	-107 <= nums[i] <= 107
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;
        vector<vector<int>> sum(2, vector<int>(1 << m, 0));
        vector<vector<int>> sum2(2, vector<int>(1 << m, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 1 << m; j++) {
                for (int k = 0; k < m; k++) {
                    if (j >> k & 1) {
                        sum[i][j] += nums[k + i * m];
                    }
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 1 << m; j++) {
                for (int k = 0; k < m; k++) {
                    if (j >> k & 1) {
                        sum2[i][j] += nums[k + i * m + m];
                    }
                }
            }
        }
        vector<int> sum2_min(1 << m, INT_MAX);
        for (int i = 0; i < 1 << m; i++) {
            for (int j = 0; j < 1 << m; j++) {
                if ((i & j) == 0) {
                    sum2_min[i] = min(sum2_min[i], sum2[1][j]);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < 1 << m; i++) {
            ans = min(ans, abs(sum[0][i] - sum2_min[i]));
        }
        return ans; 
    }
};