/**https://leetcode.com/problems/minimum-incompatibility/ */
//You are given an integer array nums​​​ and an integer k. You are asked to distribute this array into k subsets of equal size such that there are no two equal elements in the same subset.
//A subset's incompatibility is the difference between the maximum and minimum elements in that array.
//Return the minimum possible sum of incompatibilities of the k subsets after distributing the array optimally, or return -1 if it is not possible.
//A subset is a group integers that appear in the array with no particular order.
// 
//Example 1:
//Input: nums = [1,2,1,4], k = 2
//Output: 4
//Explanation: The optimal distribution of subsets is [1,2] and [1,4].
//The incompatibility is (2-1) + (4-1) = 4.
//Note that [1,1] and [2,4] would result in a smaller sum, but the first subset contains 2 equal elements.
//Example 2:
//Input: nums = [6,3,8,1,3,1,2,2], k = 4
//Output: 6
//Explanation: The optimal distribution of subsets is [1,2], [2,3], [6,8], and [1,3].
//The incompatibility is (2-1) + (3-2) + (8-6) + (3-1) = 6.
//Example 3:
//Input: nums = [5,3,3,6,3,3], k = 3
//Output: -1
//Explanation: It is impossible to distribute nums into 3 subsets where no two elements are equal in the same subset.
// 
//Constraints:
//	1 <= k <= nums.length <= 16
//	nums.length is divisible by k
//	1 <= nums[i] <= nums.length
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n / k;
        vector<int> dp(1 << n, -1);
        vector<int> cnt(1 << n, 0);
        vector<int> min_val(1 << n, INT_MAX);
        for (int i = 0; i < (1 << n); i++) {
            if (__builtin_popcount(i) == m) {
                bool is_valid = true;
                vector<int> num_set;
                for (int j = 0; j < n; j++) {
                    if (i & (1 << j)) {
                        num_set.push_back(nums[j]);
                        cnt[i] |= (1 << nums[j]);
                    }
                }
                sort(num_set.begin(), num_set.end());
                for (int j = 0; j < m - 1; j++) {
                    if (num_set[j] == num_set[j + 1]) {
                        is_valid = false;
                        break;
                    }
                }
                if (is_valid) {
                    for (int j = 0; j < n; j++) {
                        if (i & (1 << j)) {
                            int pre = i ^ (1 << j);
                            if (dp[pre] != -1) {
                                min_val[i] = min(min_val[i], min_val[pre]);
                            }
                        }
                    }
                    if (min_val[i] == INT_MAX) {
                        min_val[i] = 0;
                    }
                    for (int j = 0; j < n; j++) {
                        if (i & (1 << j)) {
                            int pre = i ^ (1 << j);
                            if (dp[pre] != -1) {
                                dp[i] = max(dp[i], max(dp[pre], num_set[m - 1] - num_set[0]));
                            }
                        }
                    }
                }
            }
        }
        if (dp[(1 << n) - 1] == -1) {
            return -1;
        }
        return dp[(1 << n) - 1];        
    }
};