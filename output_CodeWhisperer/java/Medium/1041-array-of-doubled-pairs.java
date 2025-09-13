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

        Map<Integer, Integer> count = new HashMap<>();
        for (int num : arr) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        
        Integer[] sortedArr = new Integer[arr.length];
        for (int i = 0; i < arr.length; i++) {
            sortedArr[i] = arr[i];
        }
        Arrays.sort(sortedArr, Comparator.comparingInt(Math::abs));
        
        for (int num : sortedArr) {
            if (count.get(num) == 0) {
                continue;
            }
            if (count.getOrDefault(2 * num, 0) <= 0) {
                return false;
            }
            
            count.put(num, count.get(num) - 1);
            count.put(2 * num, count.get(2 * num) - 1);
        }
        
        return true;
    }
}