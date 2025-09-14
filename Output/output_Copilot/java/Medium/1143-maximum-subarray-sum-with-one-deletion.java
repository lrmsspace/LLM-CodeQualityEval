/**https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/ */
//Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.
//Note that the subarray needs to be non-empty after deleting one element.
// 
//Example 1:
//Input: arr = [1,-2,0,3]
//Output: 4
//Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
//Example 2:
//Input: arr = [1,-2,-2,3]
//Output: 3
//Explanation: We just choose [3] and it's the maximum sum.
//Example 3:
//Input: arr = [-1,-1,-1,-1]
//Output: -1
//Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.
// 
//Constraints:
//	1 <= arr.length <= 105
//	-104 <= arr[i] <= 104
class Solution {
    public int maximumSum(int[] arr) {
        int n = arr.length;
        int[] f = new int[n];
        int[] g = new int[n];
        f[0] = arr[0];
        g[0] = 0;
        int res = arr[0];
        for (int i = 1; i < n; i++) {
            f[i] = Math.max(f[i - 1] + arr[i], arr[i]);
            g[i] = Math.max(g[i - 1] + arr[i], f[i - 1]);
            res = Math.max(res, Math.max(f[i], g[i]));
        }
        return res; // Return the maximum sum found in either f or g arrays        
    }
}