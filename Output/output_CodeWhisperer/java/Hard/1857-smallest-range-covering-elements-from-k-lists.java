/**https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/ */
//You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
// 
//Example 1:
//Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//Output: [20,24]
//Explanation: 
//List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
//List 2: [0, 9, 12, 20], 20 is in range [20,24].
//List 3: [5, 18, 22, 30], 22 is in range [20,24].
//Example 2:
//Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//Output: [1,1]
// 
//Constraints:
//	nums.length == k
//	1 <= k <= 3500
//	1 <= nums[i].length <= 50
//	-105 <= nums[i][j] <= 105
//	nums[i] is sorted in non-decreasing order.
class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int k = nums.size();
        int[] indices = new int[k];
        int[] res = new int[2];
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        int minRange = Integer.MAX_VALUE;
        while (true) {
            for (int i = 0; i < k; i++) {
                List<Integer> list = nums.get(i);
                if (indices[i] == list.size()) {
                    return res;
                }
                if (list.get(indices[i]) < min) {
                    min = list.get(indices[i]);
                }
                if (list.get(indices[i]) > max) {
                    max = list.get(indices[i]);
                }
            }
            if (max - min < minRange) {
                minRange = max - min;
                res[0] = min;
                res[1] = max;
            }
            int minIndex = 0;
            for (int i = 1; i < k; i++) {
                if (nums.get(i).get(indices[i]) < nums.get(minIndex).get(indices[minIndex])) {
                    minIndex = i;
                }
            }
            indices[minIndex]++;
            min = Integer.MAX_VALUE;
            max = Integer.MIN_VALUE;
        }
              
    }
}