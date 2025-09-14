/*
 Given an array of integers nums and an integer k, return the number of subarrays of nums where the bitwise AND of the elements of the subarray equals k.
 Example 1:
 Input: nums = [1,1,1], k = 1
 Output: 6
 Explanation:
 All subarrays contain only 1's.
 Example 2:
 Input: nums = [1,1,2], k = 1
 Output: 3
 Explanation:
 Subarrays having an AND value of 1 are: [1,1,2], [1,1,2], [1,1,2].
 Example 3:
 Input: nums = [1,2,3], k = 2
 Output: 2
 Explanation:
 Subarrays having an AND value of 2 are: [1,2,3], [1,2,3].
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i], k <= 109
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        vector<int> prefix(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] & nums[i - 1];
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                if (prefix[j] == k) {
                    ans += j - i + 1;
                }
            }
        }
        
        return ans;
        
    }
};