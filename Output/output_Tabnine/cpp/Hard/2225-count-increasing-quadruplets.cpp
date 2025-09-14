/**https://leetcode.com/problems/count-increasing-quadruplets/ */
//Given a 0-indexed integer array nums of size n containing all numbers from 1 to n, return the number of increasing quadruplets.
//A quadruplet (i, j, k, l) is increasing if:
//	0 <= i < j < k < l < n, and
//	nums[i] < nums[k] < nums[j] < nums[l].
// 
//Example 1:
//Input: nums = [1,3,2,4,5]
//Output: 2
//Explanation: 
//- When i = 0, j = 1, k = 2, and l = 3, nums[i] < nums[k] < nums[j] < nums[l].
//- When i = 0, j = 1, k = 2, and l = 4, nums[i] < nums[k] < nums[j] < nums[l]. 
//There are no other quadruplets, so we return 2.
//Example 2:
//Input: nums = [1,2,3,4]
//Output: 0
//Explanation: There exists only one quadruplet with i = 0, j = 1, k = 2, l = 3, but since nums[j] < nums[k], we return 0.
// 
//Constraints:
//	4 <= nums.length <= 4000
//	1 <= nums[i] <= nums.length
//	All the integers of nums are unique. nums is a permutation.
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; ++i) {
            cnt[nums[i]]++;
        }
        for (int i = 1; i <= n; ++i) {
            ans += 1LL * cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) * (cnt[i] - 3) / 2;
            for (int j = i + 1; j <= n; ++j) {
                ans += 1LL * cnt[i] * cnt[j] * (cnt[j] - 1) * (cnt[j] - 2) / 2;
            }
        }
        return ans;       
    }
};