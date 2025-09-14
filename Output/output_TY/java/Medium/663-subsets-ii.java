/**https://leetcode.com/problems/subsets-ii/ */
//Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any order.
// 
//Example 1:
//Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
//Example 2:
//Input: nums = [0]
//Output: [[],[0]]
// 
//Constraints:
//	1 <= nums.length <= 10
//	-10 <= nums[i] <= 10
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result=new ArrayList<>();
        Arrays.sort(nums);
        result.add(new ArrayList<>());
        int start=0,end=0;
        for(int i=0;i<nums.length;i++){
            start=0;
            if(i>0&&nums[i]==nums[i-1])
                start=end+1;
            end=result.size()-1;
            for(int j=start;j<=end;j++){
                List<Integer> temp=new ArrayList<>(result.get(j));
                temp.add(nums[i]);
                result.add(temp);
            }
        }
        return result;
    }
}