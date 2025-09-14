/**https://leetcode.com/problems/ways-to-make-a-fair-array/ */
//You are given an integer array nums. You can choose exactly one index (0-indexed) and remove the element. Notice that the index of the elements may change after the removal.
//For example, if nums = [6,1,7,4,1]:
//	Choosing to remove index 1 results in nums = [6,7,4,1].
//	Choosing to remove index 2 results in nums = [6,1,4,1].
//	Choosing to remove index 4 results in nums = [6,1,7,4].
//An array is fair if the sum of the odd-indexed values equals the sum of the even-indexed values.
//Return the number of indices that you could choose such that after the removal, nums is fair. 
// 
//Example 1:
//Input: nums = [2,1,6,4]
//Output: 1
//Explanation:
//Remove index 0: [1,6,4] -> Even sum: 1 + 4 = 5. Odd sum: 6. Not fair.
//Remove index 1: [2,6,4] -> Even sum: 2 + 4 = 6. Odd sum: 6. Fair.
//Remove index 2: [2,1,4] -> Even sum: 2 + 4 = 6. Odd sum: 1. Not fair.
//Remove index 3: [2,1,6] -> Even sum: 2 + 6 = 8. Odd sum: 1. Not fair.
//There is 1 index that you can remove to make nums fair.
//Example 2:
//Input: nums = [1,1,1]
//Output: 3
//Explanation: You can remove any index and the remaining array is fair.
//Example 3:
//Input: nums = [1,2,3]
//Output: 0
//Explanation: You cannot make a fair array after removing any index.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 104
class Solution {
    public int waysToMakeFair(int[] nums) {
        int n = nums.length;
        int[] even = new int[n + 1];
        int[] odd = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            even[i] = even[i - 1];
            odd[i] = odd[i - 1];
            if (i % 2 == 0) {
                even[i] += nums[i - 1];
            } else {
                odd[i] += nums[i - 1];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int evenSum = even[i - 1] + odd[n] - odd[i];
            int oddSum = odd[i - 1] + even[n] - even[i];
            if (evenSum == oddSum) {
                res++;
            }
        }   
        return res; // Return the number of indices that can be removed to make the array fair     
    }
}