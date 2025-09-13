/**https://leetcode.com/problems/beautiful-array/ */
//An array nums of length n is beautiful if:
//	nums is a permutation of the integers in the range [1, n].
//	For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
//Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.
// 
//Example 1:
//Input: n = 4
//Output: [2,1,4,3]
//Example 2:
//Input: n = 5
//Output: [3,1,2,5,4]
// 
//Constraints:
//	1 <= n <= 1000
class Solution {
    public int[] beautifulArray(int n) {
        List<Integer> res = new ArrayList<>();
        for (int i = 1; i <= n; i += 2) res.add(i);
        while (res.size() < n) {
            List<Integer> temp = new ArrayList<>();
            for (int num : res) {
                temp.add(2 * num - 1);
                temp.add(2 * num);
            }
            res = temp;
        }
        return res.stream().mapToInt(Integer::intValue).toArray();
        
    }
}