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
        int mid = n / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        int median = nums[mid];
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (nums[j] > median) {
                swap(nums[i++], nums[j++]);
            }
        } 
        else if (nums[j] < median) {
            swap(nums[j], nums[k--]);
        }
        else {
            j++;
        }
        for (int i = 0, j = 1; j < n; i += 2, j += 2) {
            swap(nums[i], nums[j]);
        }
        return; 
    }
};