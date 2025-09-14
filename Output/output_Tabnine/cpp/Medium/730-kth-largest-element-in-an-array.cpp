/**https://leetcode.com/problems/kth-largest-element-in-an-array/ */
//Given an integer array nums and an integer k, return the kth largest element in the array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//Can you solve it without sorting?
// 
//Example 1:
//Input: nums = [3,2,1,5,6,4], k = 2
//Output: 5
//Example 2:
//Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//Output: 4
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	-104 <= nums[i] <= 104
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == k - 1) {
                return nums[pivotIndex];
            } else if (pivotIndex > k - 1) {
                right = pivotIndex - 1;
            } else {
                left = pivotIndex + 1;
            }
        }

        int partition(vector<int>& nums, int left, int right) {
            int pivot = nums[right];
            int i = left - 1;
            for (int j = left; j < right; ++j) {
                if (nums[j] > pivot) {
                    swap(nums[++i], nums[j]);
                }
            }
            swap(nums[++i], nums[right]);
            return i;
        }
        return 0; // Not reachable
    }
};