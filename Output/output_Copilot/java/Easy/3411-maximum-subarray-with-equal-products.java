/*
 You are given an array of positive integers nums.
 An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:
 prod(arr) is the product of all elements of arr.
 gcd(arr) is the GCD of all elements of arr.
 lcm(arr) is the LCM of all elements of arr.
 Return the length of the longest product equivalent subarray of nums.
 Example 1:
 Input: nums = [1,2,1,2,1,1,1]
 Output: 5
 Explanation: 
 The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.
 Example 2:
 Input: nums = [2,3,4,5,6]
 Output: 3
 Explanation: 
 The longest product equivalent subarray is [3, 4, 5].
 Example 3:
 Input: nums = [1,2,3,1,4,5,1]
 Output: 5
 Constraints:
 2 <= nums.length <= 100
 1 <= nums[i] <= 10
*/

class Solution {
    public int maxLength(int[] nums) {
        int n = nums.length;
        int maxLength = 0;

        // Iterate through all possible subarrays
        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) {
                int product = 1;
                int gcd = nums[start];
                int lcm = nums[start];

                // Calculate product, gcd, and lcm for the current subarray
                for (int i = start; i <= end; i++) {
                    product *= nums[i];
                    gcd = gcd(gcd, nums[i]);
                    lcm = lcm(lcm, nums[i]);
                }

                // Check if the subarray is product equivalent
                if (product == lcm * gcd) {
                    maxLength = Math.max(maxLength, end - start + 1);
                }
            }
        }

        return maxLength;
        
    }
}