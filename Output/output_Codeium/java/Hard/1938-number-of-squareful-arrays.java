/**https://leetcode.com/problems/number-of-squareful-arrays/ */
//An array is squareful if the sum of every pair of adjacent elements is a perfect square.
//Given an integer array nums, return the number of permutations of nums that are squareful.
//Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
// 
//Example 1:
//Input: nums = [1,17,8]
//Output: 2
//Explanation: [1,8,17] and [17,8,1] are the valid permutations.
//Example 2:
//Input: nums = [2,2,2]
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 12
//	0 <= nums[i] <= 109
class Solution {
    public int numSquarefulPerms(int[] nums) {
        Arrays.sort(nums);
        int res = 0;
        dfs(nums, 0, new int[nums.length], res);
        return res;
    }

    private void dfs(int[] nums, int pos, int[] cur, int res) {
        if (pos == nums.length) {
            res++;
            return;
        }
        Set<Integer> used = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (used.contains(i)) continue;
            if (pos == 0 || isSquare(cur[pos - 1] + nums[i])) {
                cur[pos] = nums[i];
                used.add(i);
                dfs(nums, pos + 1, cur, res);
                used.remove(i);
            }
        }
     }
}