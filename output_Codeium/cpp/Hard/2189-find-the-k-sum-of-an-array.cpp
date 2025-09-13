/**https://leetcode.com/problems/find-the-k-sum-of-an-array/ */
//You are given an integer array nums and a positive integer k. You can choose any subsequence of the array and sum all of its elements together.
//We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).
//Return the K-Sum of the array.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
//Note that the empty subsequence is considered to have a sum of 0.
// 
//Example 1:
//Input: nums = [2,4,-2], k = 5
//Output: 2
//Explanation: All the possible subsequence sums that we can obtain are the following sorted in decreasing order:
//- 6, 4, 4, 2, 2, 0, 0, -2.
//The 5-Sum of the array is 2.
//Example 2:
//Input: nums = [1,-2,3,4,-10,12], k = 16
//Output: 10
//Explanation: The 16-Sum of the array is 10.
// 
//Constraints:
//	n == nums.length
//	1 <= n <= 105
//	-109 <= nums[i] <= 109
//	1 <= k <= min(2000, 2n)
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        // Compute prefix sums
        vector<long long> prefixSums(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }

        // Use a priority queue to store the k largest sums
        priority_queue<long long> queue;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j <= nums.size(); ++j) {
                long long sum = prefixSums[j] - prefixSums[i];
                if (queue.size() < k) {
                    queue.push(sum);
                } else if (sum > queue.top()) {
                    queue.pop();
                    queue.push(sum);
                }
            }
        }

        // Return the kth largest sum
        return queue.top();
    }
};