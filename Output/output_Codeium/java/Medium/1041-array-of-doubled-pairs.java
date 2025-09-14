/**https://leetcode.com/problems/array-of-doubled-pairs/ */
//Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.
// 
//Example 1:
//Input: arr = [3,1,3,6]
//Output: false
//Example 2:
//Input: arr = [2,1,2,6]
//Output: false
//Example 3:
//Input: arr = [4,-2,2,-4]
//Output: true
//Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
// 
//Constraints:
//	2 <= arr.length <= 3 * 104
//	arr.length is even.
//	-105 <= arr[i] <= 105
class Solution {
    public boolean canReorderDoubled(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int x : arr) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }
        Arrays.sort(arr);
        for (int x : arr) {
            if (map.getOrDefault(2 * x, 0) > 0) {
                map.put(2 * x, map.get(2 * x) - 1);
                map.put(x, map.get(x) - 1);
            }
        }
        for (int count : map.values()) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
}