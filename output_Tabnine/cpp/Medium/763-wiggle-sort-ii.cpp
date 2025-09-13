/**https://leetcode.com/problems/wiggle-sort-ii/ */
//Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//You may assume the input array always has a valid answer.
// 
//Example 1:
//Input: nums = [1,5,1,1,6,4]
//Output: [1,6,1,5,1,4]
//Explanation: [1,4,1,5,1,6] is also accepted.
//Example 2:
//Input: nums = [1,3,2,2,3,1]
//Output: [2,3,1,3,1,2]
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	0 <= nums[i] <= 5000
//	It is guaranteed that there will be an answer for the given input nums.
// 
//Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        // Find the median
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = nums[n / 2];
        
        // Partition the array into three parts
        int left = 0, right = n - 1;
        for (int i = 0; i <= right; ++i) {
            if (nums[i] < mid) {
                swap(nums[i], nums[left++]);
            } else if (nums[i] > mid) {
                swap(nums[i], nums[right--]);
            }
        }   
        
        // Reorder the array
        int n2 = left, n3 = right;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                nums[i] = nums[n2++];
            } else {
                nums[i] = nums[n3--];
            }
        }
        return;
    }
};