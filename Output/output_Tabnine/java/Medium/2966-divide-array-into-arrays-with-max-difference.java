/*
 You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.
 Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:
 The difference between any two elements in one array is less than or equal to k.
 Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.
 Example 1:
 Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
 Output: [[1,1,3],[3,4,5],[7,8,9]]
 Explanation:
 The difference between any two elements in each array is less than or equal to 2.
 Example 2:
 Input: nums = [2,4,2,2,5,2], k = 2
 Output: []
 Explanation:
 Different ways to divide nums into 2 arrays of size 3 are:
 [[2,2,2],[2,4,5]] (and its permutations)
 [[2,2,4],[2,2,5]] (and its permutations)
 Because there are four 2s there will be an array with the elements 2 and 5 no matter how we divide it. since 5 - 2 = 3 > k, the condition is not satisfied and so there is no valid division.
 Example 3:
 Input: nums = [4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11], k = 14
 Output: [[2,2,2],[4,5,5],[5,5,7],[7,8,8],[9,9,10],[11,12,12]]
 Explanation:
 The difference between any two elements in each array is less than or equal to 14.
 Constraints:
 n == nums.length
 1 <= n <= 105
 n is a multiple of 3
 1 <= nums[i] <= 105
 1 <= k <= 105
*/

class Solution {
    public int[][] divideArray(int[] nums, int k) {
        // Sort the array
        Arrays.sort(nums);
        
        int n = nums.length;
        int[][] result = new int[n / 3][3];
        
        // Initialize the first array
        result[0][0] = nums[0];
        result[0][1] = nums[1];
        result[0][2] = nums[2];
        
        // Initialize the remaining arrays
        int[] remaining = Arrays.copyOfRange(nums, 3, n);
        int index = 0;
        for (int i = 3; i < n; i += 3) {
            result[index][0] = remaining[i - 3];
            result[index][1] = remaining[i - 2];
            result[index][2] = remaining[i - 1];
            index++;
    
            // Sort the remaining array
            Arrays.sort(remaining);
            
            // Check if the condition is satisfied
            if (Math.abs(remaining[1] - remaining[0]) > k || Math.abs(remaining[2] - remaining[1]) > k) {
                return new int[0][0];
            }
        }
        return result;
        
    }
}