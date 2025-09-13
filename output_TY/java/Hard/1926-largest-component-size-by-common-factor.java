/**https://leetcode.com/problems/largest-component-size-by-common-factor/ */
//You are given an integer array of unique positive integers nums. Consider the following graph:
//	There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
//	There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
//Return the size of the largest connected component in the graph.
// 
//Example 1:
//Input: nums = [4,6,15,35]
//Output: 4
//Example 2:
//Input: nums = [20,50,9,63]
//Output: 2
//Example 3:
//Input: nums = [2,3,6,7,4,12,21,39]
//Output: 8
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i] <= 105
//	All the values of nums are unique.
class Solution {
    public int largestComponentSize(int[] nums) {
        int res = 0;
        int max = 0;
        for (int num : nums) {
            max = Math.max(max, num);
        }
        int[] parent = new int[max + 1];
        for (int i = 0; i <= max; i++) {
            parent[i] = i;
        }
        for (int num : nums) {
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    union(parent, num, i);
                    union(parent, num, num / i);
                }
            }
        }
        int[] count =new int[max + 1];
        for (int num : nums) {
            int root = find(parent, num);
            count[root]++;
            res = Math.max(res, count[root]);
        }
        return res;    
    }
}