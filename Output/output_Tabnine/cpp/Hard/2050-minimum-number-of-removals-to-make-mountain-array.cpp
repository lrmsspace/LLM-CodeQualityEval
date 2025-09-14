/**https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/ */
//You may recall that an array arr is a mountain array if and only if:
//	arr.length >= 3
//	There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
//	
//		arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//		arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
//	
//	
//Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.
// 
//Example 1:
//Input: nums = [1,3,1]
//Output: 0
//Explanation: The array itself is a mountain array so we do not need to remove any elements.
//Example 2:
//Input: nums = [2,1,1,5,6,2,3,1]
//Output: 3
//Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
// 
//Constraints:
//	3 <= nums.length <= 1000
//	1 <= nums[i] <= 109
//	It is guaranteed that you can make a mountain array out of nums.
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        
        int peak = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                peak = i;
                break;
            }
        }
        
        for (int i = peak; i > 0; --i) {
            left[i] = max(left[i - 1], nums[i - 1]);
        }
        
        for (int i = peak + 1; i < n; ++i) {
            right[i] = max(right[i + 1], nums[i + 1]);
        }
        
        int ans = 0;
        for (int i = 1; i < peak; ++i) {
            ans += max(0, left[i] - nums[i]);
        }
        
        for (int i = peak + 1; i < n - 1; ++i) {
            ans += max(0, right[i] - nums[i]);
        }
        
        return ans;
        
    }
};