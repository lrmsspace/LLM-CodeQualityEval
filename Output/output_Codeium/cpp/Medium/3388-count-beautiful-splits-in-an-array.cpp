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
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                vector<int> first(nums.begin(), nums.begin() + i + 1);
                vector<int> second(nums.begin() + i + 1, nums.begin() + j + 1);
                vector<int> third(nums.begin() + j + 1, nums.end());
                if (isPrefix(first, second) || isPrefix(second, third)) count++;
            }
        }
        return count;
    }
    
    bool isPrefix(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) return false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};