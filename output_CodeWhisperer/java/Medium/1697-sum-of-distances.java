/**https://leetcode.com/problems/sum-of-distances/ */
//You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.
//Return the array arr.
// 
//Example 1:
//Input: nums = [1,3,1,1,2]
//Output: [5,0,3,4,0]
//Explanation: 
//When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
//When i = 1, arr[1] = 0 because there is no other index with value 3.
//When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
//When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
//When i = 4, arr[4] = 0 because there is no other index with value 2. 
//Example 2:
//Input: nums = [0,5,3]
//Output: [0,0,0]
//Explanation: Since each element in nums is distinct, arr[i] = 0 for all i.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 109
// 
//Note: This question is the same as  2121: Intervals Between Identical Elements.
class Solution {
    public long[] distance(int[] nums) {
        int n = nums.length;
        long[] ans = new long[n];
        HashMap<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.computeIfAbsent(nums[i], x -> new ArrayList<>()).add(i);
        }
        for (List<Integer> group : map.values()) {
            long sum = 0;
            for (int i = 1; i < group.size(); i++) {
                sum += group.get(i) - group.get(0);
            }
            ans[group.get(0)] = sum;
            for (int i = 1; i < group.size(); i++) {
                sum += (i - 1) * (group.get(i) - group.get(i - 1));
                sum -= (group.size() - i - 1) * (group.get(i) - group.get(i - 1));
                ans[group.get(i)] = sum;
            }
        }
        return ans;       
    }
}