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
        int n = nums.size();
        vector<int> result(queries.size());
        unordered_set<int> prefixPrimes, suffixPrimes;
        vector<int> prefixCount(n + 1, 0), suffixCount(n + 1, 0);
        
        // Function to check if a number is prime
        auto isPrime = [](int num) {
            if (num < 2) return false;
            for (int i = 2; i * i <= num; ++i) {
                if (num % i == 0) return false;
            }
            return true;
        };
        
        // Precompute distinct primes in the initial array
        for (int i = 0; i < n; ++i) {
            if (isPrime(nums[i])) {
                prefixPrimes.insert(nums[i]);
            }
            prefixCount[i + 1] = prefixPrimes.size();
        }
        
        // Precompute distinct primes in the reversed array
        for (int i = n - 1; i >= 0; --i) {
            if (isPrime(nums[i])) {
                suffixPrimes.insert(nums[i]);
            }
            suffixCount[n - i] = suffixPrimes.size();
        }
        
        // Process each query
        for (int i = 0; i < queries.size(); ++i) {
            int idx = queries[i][0], val = queries[i][1];
            
            // Update the value at idx
            if (isPrime(nums[idx])) {
                prefixPrimes.erase(nums[idx]);
                suffixPrimes.erase(nums[idx]);
            }
            nums[idx] = val;
            if (isPrime(val)) {
                prefixPrimes.insert(val);
                suffixPrimes.insert(val);
            }
            
            // Calculate the maximum count of distinct primes after the update
            int maxCount = 0;
            for (int k = 1; k < n; ++k) {
                maxCount = max(maxCount, prefixCount[k] + suffixCount[n - k]);
            }
            
            result[i] = maxCount;
        }
        
        return result;
        
    }
};