/**https://leetcode.com/problems/subarrays-with-k-different-integers/ */
//Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A good array is an array where the number of different integers in that array is exactly k.
//	For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
//A subarray is a contiguous part of an array.
// 
//Example 1:
//Input: nums = [1,2,1,2,3], k = 2
//Output: 7
//Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
//Example 2:
//Input: nums = [1,2,1,3,4], k = 3
//Output: 3
//Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i], k <= nums.length
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m1, m2;
        int ans = 0, l1 = 0, l2 = 0;
        for (int r = 0; r < n; r++){
            m1[nums[r]]++;
            m2[nums[r]]++;
            while (m1.size() > k){
                m1[nums[l1]]--;
                if (m1[nums[l1]] == 0){
                    m1.erase(nums[l1]);
                }
                l1++;
            }
            while (m2.size() >= k){
                m2[nums[l2]]--;
                if (m2[nums[l2]] == 0){
                    m2.erase(nums[l2]);
                }
            }
        }
        for (int r = 0; r < n; r++){
            while (m2.size() > k - 1){
                m2[nums[l2]]--;
                if (m2[nums[l2]] == 0){
                    m2.erase(nums[l2]);
                }
                l2++;
            }
            ans += l2 - l1;
            m2[nums[r]]++;
        }
        return ans;
    }
};