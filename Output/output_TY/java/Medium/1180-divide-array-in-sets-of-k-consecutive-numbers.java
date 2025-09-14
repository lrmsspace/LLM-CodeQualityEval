/**https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/ */
//Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
//Return true if it is possible. Otherwise, return false.
// 
//Example 1:
//Input: nums = [1,2,3,3,4,4,5,6], k = 4
//Output: true
//Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
//Example 2:
//Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
//Output: true
//Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
//Example 3:
//Input: nums = [1,2,3,4], k = 3
//Output: false
//Explanation: Each array should be divided in subarrays of size 3.
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	1 <= nums[i] <= 109
// 
//Note: This question is the same as 846: https://leetcode.com/problems/hand-of-straights/
class Solution {
    public boolean isPossibleDivide(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) map.put(num, map.getOrDefault(num, 0) + 1);
        for (int num : nums) {
            if (map.get(num) == 0) continue;
            for (int i = 1; i < k; i++) {
                if (map.getOrDefault(num + i, 0) < map.get(num)) return false;
                map.put(num + i, map.get(num + i) - map.get(num));
            }
        }
        return true;
    }
}