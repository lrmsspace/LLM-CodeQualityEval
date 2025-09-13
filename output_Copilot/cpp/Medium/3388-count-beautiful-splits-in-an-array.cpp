/*
 You are given an array nums.
 A split of an array nums is beautiful if:
 The array nums is split into three subarrays: nums1, nums2, and nums3, such that nums can be formed by concatenating nums1, nums2, and nums3 in that order.
 The subarray nums1 is a prefix of nums2 OR nums2 is a prefix of nums3.
 Return the number of ways you can make this split.
 Example 1:
 Input: nums = [1,1,2,1]
 Output: 2
 Explanation:
 The beautiful splits are:
 A split with nums1 = [1], nums2 = [1,2], nums3 = [1].
 A split with nums1 = [1], nums2 = [1], nums3 = [2,1].
 Example 2:
 Input: nums = [1,2,3,4]
 Output: 0
 Explanation:
 There are 0 beautiful splits.
 Constraints:
 1 <= nums.length <= 5000
 0 <= nums[i] <= 50
*/

class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<int> nums1(nums.begin(), nums.begin() + i);
                vector<int> nums2(nums.begin() + i, nums.begin() + j);
                vector<int> nums3(nums.begin() + j, nums.end());

                if ((nums1 == nums2 || nums2 == nums3) && !nums1.empty() && !nums2.empty() && !nums3.empty()) {
                    count++;
                }
            }
        }

        return count;
    }
};