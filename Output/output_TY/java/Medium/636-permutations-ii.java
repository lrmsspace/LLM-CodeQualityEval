/**https://leetcode.com/problems/permutations-ii/ */
//Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
// 
//Example 1:
//Input: nums = [1,1,2]
//Output:
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
//Example 2:
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//Constraints:
//	1 <= nums.length <= 8
//	-10 <= nums[i] <= 10
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> res=new ArrayList<>();
        List<Integer> list=new ArrayList<>();
        Arrays.sort(nums);
        boolean[] visited=new boolean[nums.length];
        helper(nums,res,list,visited);
        return res;
    }
    public void helper(int[] nums,List<List<Integer>> res,List<Integer> list,boolean[] visited){
        if(list.size()==nums.length){
            res.add(new ArrayList<>(list));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(visited[i]||(i>0&&nums[i]==nums[i-1]&&!visited[i-1])) continue;
        }
        visited[i]=true;
        list.add(nums[i]);
        helper(nums,res,list,visited);
        list.remove(list.size()-1);
        visited[i]=false;
        return;
    }
}