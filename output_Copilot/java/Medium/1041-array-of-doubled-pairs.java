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
        Map<Integer, Integer> count = new TreeMap<>();
        for (int a : arr) {
            count.put(a, count.getOrDefault(a, 0) + 1);
        }
        for (int x : count.keySet()) {
            if (count.get(x) == 0) {
                continue;
            }
            int want = x < 0 ? x / 2 : x * 2;
            if (x < 0 && x % 2 != 0 || count.get(x) > count.getOrDefault(want, 0)) {
                return false;
            }
            count.put(want, count.get(want) - count.get(x));
        }
        return true;        
    }
}