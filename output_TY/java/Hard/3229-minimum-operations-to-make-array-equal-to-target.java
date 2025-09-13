/*
 You are given two positive integer arrays nums and target, of the same length.
 In a single operation, you can select any subarray of nums and increment each element within that subarray by 1 or decrement each element within that subarray by 1.
 Return the minimum number of operations required to make nums equal to the array target.
 Example 1:
 Input: nums = [3,5,1,2], target = [4,6,2,4]
 Output: 2
 Explanation:
 We will perform the following operations to make nums equal to target:
 - Increment nums[0..3] by 1, nums = [4,6,2,3].
 - Increment nums[3..3] by 1, nums = [4,6,2,4].
 Example 2:
 Input: nums = [1,3,2], target = [2,1,4]
 Output: 5
 Explanation:
 We will perform the following operations to make nums equal to target:
 - Increment nums[0..0] by 1, nums = [2,3,2].
 - Decrement nums[1..1] by 1, nums = [2,2,2].
 - Decrement nums[1..1] by 1, nums = [2,1,2].
 - Increment nums[2..2] by 1, nums = [2,1,3].
 - Increment nums[2..2] by 1, nums = [2,1,4].
 Constraints:
 1 <= nums.length == target.length <= 105
 1 <= nums[i], target[i] <= 108
*/

class Solution {
    public long minimumOperations(int[] nums, int[] target) {
        long ans = 0;
        int sum = 0;
        for(int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        
        if(sum < target[0]) {
            return -1;
        }
        
        int targetSum = 0;
        for(int i = 0; i < target.length; i++) {
            targetSum += target[i];
        }
        
        if(targetSum < sum) {
            return -1;
        }
        
        int targetSum1 = 0;
        int targetSum2 = 0;
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < target.length; i++) { 
            if(i < target.length / 2) {
                targetSum1 += target[i];
                sum1 += sum - target[i];
            } else {
                targetSum2 += target[i];
                sum2 += sum - target[i];
            }
        }
        return Math.min(sum1 - targetSum1, sum2 - targetSum2);

        
    }
}