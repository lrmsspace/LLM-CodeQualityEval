/**https://leetcode.com/problems/count-the-number-of-fair-pairs/ */
//Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
//A pair (i, j) is fair if:
//	0 <= i < j < n, and
//	lower <= nums[i] + nums[j] <= upper
// 
//Example 1:
//Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
//Output: 6
//Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
//Example 2:
//Input: nums = [1,7,9,2,5], lower = 11, upper = 11
//Output: 1
//Explanation: There is a single fair pair: (2,3).
// 
//Constraints:
//	1 <= nums.length <= 105
//	nums.length == n
//	-109 <= nums[i] <= 109
//	-109 <= lower <= upper <= 109
class Solution {
    public long countFairPairs(int[] nums, int lower, int upper) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Arrays.sort(nums);
        for (int i = 0; i < n; i++) {
            left[i] = lower - nums[i];
            right[i] = upper - nums[i];
        }
        int leftCount = 0;
        int rightCount = 0;
        int leftIndex = 0;
        int rightIndex = n - 1;
        long result = 0;
        for (int i = 0; i < n; i++) {
            while (leftIndex < n && left[leftIndex] <= nums[i]) {
                leftCount++;
                leftIndex++;
            }
            while (rightIndex >= 0 && right[rightIndex] >= nums[i]) {
                rightCount++;
                rightIndex--;
            }
            result += leftCount * rightCount;
        }
        return result;
    }
}