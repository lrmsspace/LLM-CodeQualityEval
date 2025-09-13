/*
 You are given an integer array nums having length n and a 2D integer array queries where queries[i] = [idx, val].
 For each query:
 Update nums[idx] = val.
 Choose an integer k with 1 <= k < n to split the array into the non-empty prefix nums[0..k-1] and suffix nums[k..n-1] such that the sum of the counts of distinct prime values in each part is maximum.
 Note: The changes made to the array in one query persist into the next query.
 Return an array containing the result for each query, in the order they are given.
 Example 1:
 Input: nums = [2,1,3,1,2], queries = [[1,2],[3,3]]
 Output: [3,4]
 Explanation:
 Initially nums = [2, 1, 3, 1, 2].
 After 1st query, nums = [2, 2, 3, 1, 2]. Split nums into [2] and [2, 3, 1, 2]. [2] consists of 1 distinct prime and [2, 3, 1, 2] consists of 2 distinct primes. Hence, the answer for this query is 1 + 2 = 3.
 After 2nd query, nums = [2, 2, 3, 3, 2]. Split nums into [2, 2, 3] and [3, 2] with an answer of 2 + 2 = 4.
 The output is [3, 4].
 Example 2:
 Input: nums = [2,1,4], queries = [[0,1]]
 Output: [0]
 Explanation:
 Initially nums = [2, 1, 4].
 After 1st query, nums = [1, 1, 4]. There are no prime numbers in nums, hence the answer for this query is 0.
 The output is [0].
 Constraints:
 2 <= n == nums.length <= 5 * 104
 1 <= queries.length <= 5 * 104
 1 <= nums[i] <= 105
 0 <= queries[i][0] < nums.length
 1 <= queries[i][1] <= 105
*/

class Solution {
    public int[] maximumCount(int[] nums, int[][] queries) {
        int n = nums.length;
        int[] result = new int[queries.length];
        boolean[] isPrime = new boolean[100001];
        for (int i = 2; i < isPrime.length; i++) {
            isPrime[i] = true;
        }
        for (int i = 2; i * i < isPrime.length; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < isPrime.length; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int q = 0; q < queries.length; q++) {
            int idx = queries[q][0];
            int val = queries[q][1];
            nums[idx] = val;

            int leftCount = 0, rightCount = 0;
            boolean[] leftSeen = new boolean[100001];
            boolean[] rightSeen = new boolean[100001];

            for (int i = 0; i < n; i++) {
                if (isPrime[nums[i]]) {
                    if (i < idx) {
                        if (!leftSeen[nums[i]]) {
                            leftSeen[nums[i]] = true;
                            leftCount++;
                        }
                    } else if (i > idx) {
                        if (!rightSeen[nums[i]]) {
                            rightSeen[nums[i]] = true;
                            rightCount++;
                        }
                    }
                }
            }

            result[q] = leftCount + rightCount;
        }

        return result;
            
    }
}