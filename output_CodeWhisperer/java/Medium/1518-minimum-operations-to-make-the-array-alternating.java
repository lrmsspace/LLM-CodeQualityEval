/**https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/ */
//You are given a 0-indexed array nums consisting of n positive integers.
//The array nums is called alternating if:
//	nums[i - 2] == nums[i], where 2 <= i <= n - 1.
//	nums[i - 1] != nums[i], where 1 <= i <= n - 1.
//In one operation, you can choose an index i and change nums[i] into any positive integer.
//Return the minimum number of operations required to make the array alternating.
// 
//Example 1:
//Input: nums = [3,1,3,2,4,3]
//Output: 3
//Explanation:
//One way to make the array alternating is by converting it to [3,1,3,1,3,1].
//The number of operations required in this case is 3.
//It can be proven that it is not possible to make the array alternating in less than 3 operations. 
//Example 2:
//Input: nums = [1,2,2,2,2]
//Output: 2
//Explanation:
//One way to make the array alternating is by converting it to [1,2,1,2,1].
//The number of operations required in this case is 2.
//Note that the array cannot be converted to [2,2,2,2,2] because in this case nums[0] == nums[1] which violates the conditions of an alternating array.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 105
class Solution {
    public int minimumOperations(int[] nums) {
        int n = nums.length;
        if (n == 1) return 0;
        int[] even = new int[100001], odd = new int[100001];
        int maxEven = 0, maxOdd = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even[nums[i]]++;
                if (even[nums[i]] > even[maxEven]) maxEven = nums[i];
            } else {
                odd[nums[i]]++;
                if (odd[nums[i]] > odd[maxOdd]) maxOdd = nums[i];
            }
        }
        if (maxEven != maxOdd) return n - even[maxEven] - odd[maxOdd];
        int secondEven = 0, secondOdd = 0;
        for (int i = 0; i < 100001; i++) {
            if (i != maxEven && even[i] > even[secondEven]) secondEven = i;
            if (i != maxOdd && odd[i] > odd[secondOdd]) secondOdd = i;
        }
        return Math.min(n - even[maxEven] - odd[secondOdd], n - even[secondEven] - odd[maxOdd]);      
    }
}