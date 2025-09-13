/**https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/ */
//You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:
//	nums.length == n
//	nums[i] is a positive integer where 0 <= i < n.
//	abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
//	The sum of all the elements of nums does not exceed maxSum.
//	nums[index] is maximized.
//Return nums[index] of the constructed array.
//Note that abs(x) equals x if x >= 0, and -x otherwise.
// 
//Example 1:
//Input: n = 4, index = 2,  maxSum = 6
//Output: 2
//Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
//There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].
//Example 2:
//Input: n = 6, index = 1,  maxSum = 10
//Output: 3
// 
//Constraints:
//	1 <= n <= maxSum <= 109
//	0 <= index < n
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        // Initialize the first and last elements of the array.
        int left = 1, right = maxSum - n + 1;
        
        // Binary search to find the maximum value at the given index.
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int sum = mid * (n - 1) + maxSum - mid;
            
            // If the sum is equal to the target index, return mid.
            if (sum == index) {
                return mid;
            }
            
            // If the sum is less than the target index, update the left boundary.
            if (sum < index) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Return the maximum value at the given index.
        return left;
        
    }
};