/*
import java.util.TreeSet;
import java.util.Arrays;
 You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].
 Each queries[i] represents the following action on nums:
 Decrement the value at each index in the range [li, ri] in nums by at most 1.
 The amount by which the value is decremented can be chosen independently for each index.
 A Zero Array is an array with all its elements equal to 0.
 Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.
 Example 1:
 Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]
 Output: 1
 Explanation:
 After removing queries[2], nums can still be converted to a zero array.
 Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
 Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
 Example 2:
 Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]
 Output: 2
 Explanation:
 We can remove queries[2] and queries[3].
 Example 3:
 Input: nums = [1,2,3,4], queries = [[0,3]]
 Output: -1
 Explanation:
 nums cannot be converted to a zero array even after using all the queries.
 Constraints:
 1 <= nums.length <= 105
 0 <= nums[i] <= 105
 1 <= queries.length <= 105
 queries[i].length == 2
 0 <= li <= ri < nums.length
*/

class Solution {
    public int maxRemoval(int[] nums, int[][] queries) {
        int n = nums.length;
        int m = queries.length;
        int[] index = new int[m];
        for(int i = 0; i < m; i++) {
            index[i] = i;
        }
        Arrays.sort(index, (a, b) -> queries[a][1] - queries[b][1]);
        TreeSet<Integer> set = new TreeSet<>();
        set.add(-1);
        set.add(n);
        for(int i = m - 1; i >= 0; i--) {
            int j = index[i];
            int left = queries[j][0];
            int right = queries[j][1];
            int val = nums[j];
            Integer lower = set.lower(left);
            Integer higher = set.higher(right);
            if((lower == -1 || nums[lower] <= val) && (higher == n || nums[higher] <= val)) {
                return i;
            }
            set.add(queries[j][0]);
        }
        return 0;
            
    }
}