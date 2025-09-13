/**https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/ */
//You are given an array nums consisting of positive integers.
//You are also given an integer array queries of size m. For the ith query, you want to make all of the elements of nums equal to queries[i]. You can perform the following operation on the array any number of times:
//	Increase or decrease an element of the array by 1.
//Return an array answer of size m where answer[i] is the minimum number of operations to make all elements of nums equal to queries[i].
//Note that after each query the array is reset to its original state.
// 
//Example 1:
//Input: nums = [3,1,6,8], queries = [1,5]
//Output: [14,10]
//Explanation: For the first query we can do the following operations:
//- Decrease nums[0] 2 times, so that nums = [1,1,6,8].
//- Decrease nums[2] 5 times, so that nums = [1,1,1,8].
//- Decrease nums[3] 7 times, so that nums = [1,1,1,1].
//So the total number of operations for the first query is 2 + 5 + 7 = 14.
//For the second query we can do the following operations:
//- Increase nums[0] 2 times, so that nums = [5,1,6,8].
//- Increase nums[1] 4 times, so that nums = [5,5,6,8].
//- Decrease nums[2] 1 time, so that nums = [5,5,5,8].
//- Decrease nums[3] 3 times, so that nums = [5,5,5,5].
//So the total number of operations for the second query is 2 + 4 + 1 + 3 = 10.
//Example 2:
//Input: nums = [2,9,6,3], queries = [10]
//Output: [20]
//Explanation: We can increase each value in the array to 10. The total number of operations will be 8 + 1 + 4 + 7 = 20.
// 
//Constraints:
//	n == nums.length
//	m == queries.length
//	1 <= n, m <= 105
//	1 <= nums[i], queries[i] <= 109
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<long long> ans(m,0);
        vector<long long> prefix(n,0);
        vector<long long> suffix(n,0);
        sort(nums.begin(),nums.end());
        prefix[0] = nums[0];
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        suffix[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            suffix[i] =suffix[i+1] + nums[i];
        }
        for(int i = 0;i<m;i++){
            int q = queries[i];
            int index = lower_bound(nums.begin(),nums.end(),q) - nums.begin();
            if(index == 0){
                ans[i] = (long long)q*n - prefix[n-1];
            }
            else if(index == n){
                ans[i] = suffix[0] - (long long)q*n;
            }
            else{
                ans[i] = min(prefix[index-1] + (long long)q*(n-index) - suffix[index],suffix[index-1] - (longlong)q*(index) + prefix[index-1]);
            }
        }
        return ans;
    }
};