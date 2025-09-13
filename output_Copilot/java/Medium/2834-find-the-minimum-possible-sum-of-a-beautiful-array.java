/*
 You are given positive integers n and target.
 An array nums is beautiful if it meets the following conditions:
 nums.length == n.
 nums consists of pairwise distinct positive integers.
 There doesn't exist two distinct indices, i and j, in the range [0, n - 1], such that nums[i] + nums[j] == target.
 Return the minimum possible sum that a beautiful array could have modulo 109 + 7.
 Example 1:
 Input: n = 2, target = 3
 Output: 4
 Explanation: We can see that nums = [1,3] is beautiful.
 - The array nums has length n = 2.
 - The array nums consists of pairwise distinct positive integers.
 - There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
 It can be proven that 4 is the minimum possible sum that a beautiful array could have.
 Example 2:
 Input: n = 3, target = 3
 Output: 8
 Explanation: We can see that nums = [1,3,4] is beautiful.
 - The array nums has length n = 3.
 - The array nums consists of pairwise distinct positive integers.
 - There doesn't exist two distinct indices, i and j, with nums[i] + nums[j] == 3.
 It can be proven that 8 is the minimum possible sum that a beautiful array could have.
 Example 3:
 Input: n = 1, target = 1
 Output: 1
 Explanation: We can see, that nums = [1] is beautiful.
 Constraints:
 1 <= n <= 109
 1 <= target <= 109
*/

class Solution {
    public int minimumPossibleSum(int n, int target) {
        int sum = 0;
        int current = 1;
        int count = 0;

        while (count < n) {
            if (current < target - current) {
                sum += current;
                count++;
            } else if (current != target - current) {
                sum += target - current;
                count++;
            }
            current++;
        }

        return sum % 1000000007;        
    }
}