/**https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/ */
//Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
//Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.
// 
//Example 1:
//Input: nums = [1,2,1,2,6,7,5,1], k = 2
//Output: [0,3,5]
//Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
//We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
//Example 2:
//Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
//Output: [0,2,4]
// 
//Constraints:
//	1 <= nums.length <= 2 * 104
//	1 <= nums[i] < 216
//	1 <= k <= floor(nums.length / 3)
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n-k+1, 0);
        int sum = 0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        sums[0] = sum;
        for(int i=k; i<n; i++){
            sum = sum - nums[i-k] + nums[i];
            sums[i-k+1] = sum;
        }
        vector<int> left(n-k+1, 0);
        vector<int> right(n-k+1, n-k);
        left[0] = 0;
        for(int i=1; i<n-k+1; i++){
            if(sums[left[i-1]] <= sums[i]){
                left[i] = i;
            }else{
                left[i] = left[i-1];
            }
        }
        right[n-k] = n-k;
        for(int i=n-k-1; i>=0; i--){
            if(sums[right[i+1]] <= sums[i]){
                right[i] = i;
            }else{
                right[i] = right[i+1];
            }
        }
        vector<int> res(3, 0);
        for(int i=k; i<n-2*k+1; i++){
            int l = left[i-k], r = right[i+k];
            if(res[0]==-1 || (sums[l]+sums[i]+sums[r] > sums[res[0]]+sums[res[1]]+sums[res[2]])){
                res[0] = l;
                res[1] = i;
                res[2] = r;
            }
        }
        return res;
        
    }
};