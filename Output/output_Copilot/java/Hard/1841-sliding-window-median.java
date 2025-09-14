/**https://leetcode.com/problems/sliding-window-median/ */
//The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.
//	For examples, if arr = [2,3,4], the median is 3.
//	For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
//You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.
// 
//Example 1:
//Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
//Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
//Explanation: 
//Window position                Median
//---------------                -----
//[1  3  -1] -3  5  3  6  7        1
// 1 [3  -1  -3] 5  3  6  7       -1
// 1  3 [-1  -3  5] 3  6  7       -1
// 1  3  -1 [-3  5  3] 6  7        3
// 1  3  -1  -3 [5  3  6] 7        5
// 1  3  -1  -3  5 [3  6  7]       6
//Example 2:
//Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
//Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
// 
//Constraints:
//	1 <= k <= nums.length <= 105
//	-231 <= nums[i] <= 231 - 1
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        double[] result = new double[n - k + 1];
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < k; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }
        for (int i = 0; i <= n - k; i++) {
            if (i > 0) {
                map.put(nums[i + k - 1], map.getOrDefault(nums[i + k - 1], 0) + 1);
                map.put(nums[i - 1], map.get(nums[i - 1]) - 1);
                if (map.get(nums[i - 1]) == 0) {
                    map.remove(nums[i - 1]);
                }
            }
            int mid = k / 2;
            if (k % 2 == 0) {
                int left = getKth(map, mid);
                int right = getKth(map, mid + 1);
                result[i] = (left + right) / 2.0;
            } else {
                result[i] = getKth(map, mid + 1);
            }
        }
        return result;        
    }
}