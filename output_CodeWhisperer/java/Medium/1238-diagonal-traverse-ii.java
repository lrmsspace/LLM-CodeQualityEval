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
    public int[] findDiagonalOrder(List<List<Integer>> nums) 
    {
        int n = 0, i = 0, maxKey = 0;
        HashMap<Integer, List<Integer>> map = new HashMap<>();
        for (List<Integer> row : nums) {
            for (int j = 0; j < row.size(); j++) {
                if (!map.containsKey(i + j))
                    map.put(i + j, new ArrayList<>());
                map.get(i + j).add(row.get(j));
                maxKey = Math.max(maxKey, i + j);
                n++;
            }
            i++;
        }
        int[] res = new int[n];
        n = 0;
        for (i = 0; i <= maxKey; i++) {
            List<Integer> row = map.get(i);
            for (int j = row.size() - 1; j >= 0; j--) {
                res[n++] = row.get(j);
            }
        }
        return res;
    }
}