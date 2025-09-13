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
public:
    vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
            97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
        for (const auto& query : queries) {
            int idx = query[0];
            int val = query[1];
            nums[idx] = val;
            int count = 0;
            for (int num : nums) {
                if (primes.count(num)) {
                    count++;
                }
            }
            int prefixCount = 0;
            int suffixCount = count;
            for (int num : nums) {
                if (num == nums[idx]) {
                    prefixCount++;
                }
                if (num == val) {
                    suffixCount--;
                }
                if (prefixCount == 0 || suffixCount == 0) {
                    break;
                }
            }
            result.push_back(prefixCount + suffixCount);
        }
        return result;
        
    }
};