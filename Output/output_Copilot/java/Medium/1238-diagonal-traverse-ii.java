/**https://leetcode.com/problems/diagonal-traverse-ii/ */
//Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.
// 
//Example 1:
//Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,4,2,7,5,3,8,6,9]
//Example 2:
//Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
//Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i].length <= 105
//	1 <= sum(nums[i].length) <= 105
//	1 <= nums[i][j] <= 105
class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        List<List<Integer>> list = new ArrayList<>();
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.get(i).size(); j++) {
                if (i + j >= list.size()) {
                    list.add(new ArrayList<>());
                }
                list.get(i + j).add(nums.get(i).get(j));
            }
        }
        int[] res = new int[nums.size() * nums.get(0).size()];
        int index = 0;
        for (List<Integer> l : list) {
            for (int i = l.size() - 1; i >= 0; i--) {
                res[index++] = l.get(i);
            }
        } 
        return res; // Return the diagonal order of elements       
    }
}