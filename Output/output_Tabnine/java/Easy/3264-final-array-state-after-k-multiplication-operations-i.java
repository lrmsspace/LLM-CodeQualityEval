/*
 You are given an integer array nums, an integer k, and an integer multiplier.
 You need to perform k operations on nums. In each operation:
 Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
 Replace the selected minimum value x with x * multiplier.
 Return an integer array denoting the final state of nums after performing all k operations.
 Example 1:
 Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
 Output: [8,4,6,5,6]
 Explanation:
 Operation
 Result
 After operation 1
 [2, 2, 3, 5, 6]
 After operation 2
 [4, 2, 3, 5, 6]
 After operation 3
 [4, 4, 3, 5, 6]
 After operation 4
 [4, 4, 6, 5, 6]
 After operation 5
 [8, 4, 6, 5, 6]
 Example 2:
 Input: nums = [1,2], k = 3, multiplier = 4
 Output: [16,8]
 Explanation:
 Operation
 Result
 After operation 1
 [4, 2]
 After operation 2
 [4, 8]
 After operation 3
 [16, 8]
 Constraints:
 1 <= nums.length <= 100
 1 <= nums[i] <= 100
 1 <= k <= 10
 1 <= multiplier <= 5
*/

class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {

        // Perform k operations on nums
        for (int i = 0; i < k; i++) {
            int minValue = Integer.MAX_VALUE;
            int minIndex = -1;
            // Find the minimum value and its index
            for (int j = 0; j < nums.length; j++) {
                if (nums[j] < minValue) {
                    minValue = nums[j];
                    minIndex = j;
                }
            }
            // Replace the selected minimum value with x * multiplier
            nums[minIndex] = minValue * multiplier;
    
            // Sort the array in ascending order
            Arrays.sort(nums);
            
            // Remove duplicate elements
            int[] uniqueNums = new int[nums.length];
            int uniqueIndex = 0;
            for (int j = 0; j < nums.length - 1; j++) {
                if (nums[j]!= nums[j + 1]) {
                    uniqueNums[uniqueIndex++] = nums[j];
                }
            }
            uniqueNums[uniqueIndex++] = nums[nums.length - 1];
            nums = Arrays.copyOf(uniqueNums, uniqueIndex);
        }   
        return nums;
        
    }
}