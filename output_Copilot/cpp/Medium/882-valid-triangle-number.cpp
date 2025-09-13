/**https://leetcode.com/problems/valid-triangle-number/ */
//Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
// 
//Example 1:
//Input: nums = [2,2,3,4]
//Output: 3
//Explanation: Valid combinations are: 
//2,3,4 (using the first 2)
//2,3,4 (using the second 2)
//2,2,3
//Example 2:
//Input: nums = [4,2,3,4]
//Output: 4
// 
//Constraints:
//	1 <= nums.length <= 1000
//	0 <= nums[i] <= 1000
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int left = j + 1, right = n - 1, k = j;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < nums[i] + nums[j]) {
                        k = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                ans += k - j;
            }
        } 
        return ans;       
    }
};