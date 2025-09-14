/**https://leetcode.com/problems/largest-number/ */
//Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
//Since the result may be very large, so you need to return a string instead of an integer.
// 
//Example 1:
//Input: nums = [10,2]
//Output: "210"
//Example 2:
//Input: nums = [3,30,34,5,9]
//Output: "9534330"
// 
//Constraints:
//	1 <= nums.length <= 100
//	0 <= nums[i] <= 109
class Solution {
    public String largestNumber(int[] nums) {
        String[] strs = new String[nums.length];
        for(int i=0;i<nums.length;i++)
            strs[i] = String.valueOf(nums[i]);
        Arrays.sort(strs,new Comparator<String>(){
            public int compare(String a,String b){
                return (b+a).compareTo(a+b);
            }
        });
        StringBuilder sb = new StringBuilder();
        for(String s:strs)
            sb.append(s);
        while(sb.length()>1&&sb.charAt(0)=='0')
            sb.deleteCharAt(0);
        return sb.toString();
    }
}