/*
 You are given an integer array nums.
 Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.
 Example 1:
 Input: nums = [4,2,9,5,3]
 Output: 3
 Explanation: nums[1], nums[3], and nums[4] are prime. So the answer is |4 - 1| = 3.
 Example 2:
 Input: nums = [4,8,2,8]
 Output: 0
 Explanation: nums[2] is prime. Because there is just one prime number, the answer is |2 - 2| = 0.
 Constraints:
 1 <= nums.length <= 3 * 105
 1 <= nums[i] <= 100
 The input is generated such that the number of prime numbers in the nums is at least one.
*/

class Solution {
    public int maximumPrimeDifference(int[] nums) {
        int max = 0;
        for(int i = 0; i < nums.length; i++) {
            for(int j = i + 1; j < nums.length; j++) {
                int a = nums[i];
                int b = nums[j];
                boolean flag = true;
                for(int k = 2; k < a; k++) {
                    if(a % k == 0) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    for(int k = 2; k < b; k++) {
                        if(b % k == 0) {
                            flag = false;
                        }
                    }
                }
            }
        }
        return flag ? "YES" : "NO";
        
    }
}