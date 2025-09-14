/**https://leetcode.com/problems/find-array-given-subset-sums/ */
//You are given an integer n representing the length of an unknown array that you are trying to recover. You are also given an array sums containing the values of all 2n subset sums of the unknown array (in no particular order).
//Return the array ans of length n representing the unknown array. If multiple answers exist, return any of them.
//An array sub is a subset of an array arr if sub can be obtained from arr by deleting some (possibly zero or all) elements of arr. The sum of the elements in sub is one possible subset sum of arr. The sum of an empty array is considered to be 0.
//Note: Test cases are generated such that there will always be at least one correct answer.
// 
//Example 1:
//Input: n = 3, sums = [-3,-2,-1,0,0,1,2,3]
//Output: [1,2,-3]
//Explanation: [1,2,-3] is able to achieve the given subset sums:
//- []: sum is 0
//- [1]: sum is 1
//- [2]: sum is 2
//- [1,2]: sum is 3
//- [-3]: sum is -3
//- [1,-3]: sum is -2
//- [2,-3]: sum is -1
//- [1,2,-3]: sum is 0
//Note that any permutation of [1,2,-3] and also any permutation of [-1,-2,3] will also be accepted.
//Example 2:
//Input: n = 2, sums = [0,0,0,0]
//Output: [0,0]
//Explanation: The only correct answer is [0,0].
//Example 3:
//Input: n = 4, sums = [0,0,5,5,4,-1,4,9,9,-1,4,3,4,8,3,8]
//Output: [0,-1,4,5]
//Explanation: [0,-1,4,5] is able to achieve the given subset sums.
// 
//Constraints:
//	1 <= n <= 15
//	sums.length == 2n
//	-104 <= sums[i] <= 104
class Solution {
    public int[] recoverArray(int n, int[] sums) {
        int[] ans = new int[n];
        int[] prefixSums = new int[sums.length];
        
        // Calculate prefix sums
        prefixSums[0] = sums[0];
        for (int i = 1; i < sums.length; i++) {
            prefixSums[i] = prefixSums[i - 1] + sums[i];
        }
        
        // Check if prefix sums are unique
        Set<Integer> set = new HashSet<>();
        for (int sum : prefixSums) {
            if (!set.add(sum)) {
                return null;
            }
        }
        
        // Sort prefix sums
        Arrays.sort(prefixSums);
        
        // Find the largest prefix sum and its index
        int largestPrefixSum = prefixSums[prefixSums.length - 1];
        int largestIndex = prefixSums.length - 1;
        
        // Find the smallest prefix sum and its index
        int smallestPrefixSum = prefixSums[0];
        int smallestIndex = 0;
        
        // Find the possible values for ans[n - 1]
        for (int i = largestIndex; i >= smallestIndex; i--) {
            if (largestPrefixSum - prefixSums[i] == prefixSums[i] - smallestPrefixSum) {
                ans[n - 1] = prefixSums[i];
                break;
            }
        }
        
        // Find the possible values for ans[n - 2]
        for (int i = largestIndex; i >= smallestIndex; i--) {
            if (largestPrefixSum - ans[n - 1] == prefixSums[i] - ans[n - 1]) {
                ans[n - 2] = prefixSums[i];
                break;
            }
        }
        
        // Find the possible values for ans[n - 3]
        for (int i = largestIndex; i >= smallestIndex; i--) {
            if (largestPrefixSum - ans[n - 2] == prefixSums[i] - ans[n - 2]) {
                ans[n - 3] = prefixSums[i];
                break;
            }
        }
        
        return ans;
        
    }
}