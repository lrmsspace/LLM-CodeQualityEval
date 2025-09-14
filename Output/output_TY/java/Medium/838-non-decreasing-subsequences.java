/**https://leetcode.com/problems/non-decreasing-subsequences/ */
//Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.
// 
//Example 1:
//Input: nums = [4,6,7,7]
//Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
//Example 2:
//Input: nums = [4,4,3,2,1]
//Output: [[4,4]]
// 
//Constraints:
//	1 <= nums.length <= 15
//	-100 <= nums[i] <= 100
class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        helper(res, cur, nums, 0);
        return res;
    }
    public void helper(List<List<Integer>> res, List<Integer> cur, int[] nums, int start) {
        if (cur.size() >= 2) {
            res.add(new ArrayList<>(cur));
        }
        Set<Integer> set = new HashSet<>();
        for (int i = start; i < nums.length; i++) {
            if (!cur.isEmpty() && nums[i] < cur.get(cur.size() - 1) ||set.contains(nums[i])) {
                continue;
            } else {
                set.add(nums[i]);
                cur.add(nums[i]);
                helper(res, cur, nums, i + 1);
                cur.remove(cur.size() - 1);
            }
        }
        return;
    }
}