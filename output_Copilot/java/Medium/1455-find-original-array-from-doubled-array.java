/**https://leetcode.com/problems/find-original-array-from-doubled-array/ */
//An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.
//Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.
// 
//Example 1:
//Input: changed = [1,3,4,2,6,8]
//Output: [1,3,4]
//Explanation: One possible original array could be [1,3,4]:
//- Twice the value of 1 is 1 * 2 = 2.
//- Twice the value of 3 is 3 * 2 = 6.
//- Twice the value of 4 is 4 * 2 = 8.
//Other original arrays could be [4,3,1] or [3,1,4].
//Example 2:
//Input: changed = [6,3,0,1]
//Output: []
//Explanation: changed is not a doubled array.
//Example 3:
//Input: changed = [1]
//Output: []
//Explanation: changed is not a doubled array.
// 
//Constraints:
//	1 <= changed.length <= 105
//	0 <= changed[i] <= 105
class Solution {
    public int[] findOriginalArray(int[] changed) {
        if (changed.length % 2 != 0) {
            return new int[0];
        }
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : changed) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        Arrays.sort(changed);
        int[] res = new int[changed.length / 2];
        int index = 0;
        for (int num : changed) {
            if (map.get(num) == 0) {
                continue;
            }
            if (map.getOrDefault(num * 2, 0) == 0) {
                return new int[0];
            }
            res[index++] = num;
            map.put(num, map.get(num) - 1);
            map.put(num * 2, map.get(num * 2) - 1);
        }
        return res;        
    }
}