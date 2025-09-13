/**https://leetcode.com/problems/maximum-gap/ */
//Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
//You must write an algorithm that runs in linear time and uses linear extra space.
// 
//Example 1:
//Input: nums = [3,6,9,1]
//Output: 3
//Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
//Example 2:
//Input: nums = [10]
//Output: 0
//Explanation: The array contains less than 2 elements, therefore return 0.
// 
//Constraints:
//	1 <= nums.length <= 105
//	0 <= nums[i] <= 109
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return 0;
        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());
        int gap = (max_val - min_val) / (n - 1);
        if((max_val - min_val) % (n - 1) != 0)
            gap++;
        vector<int> bucket_min(n - 1, INT_MAX);
        vector<int> bucket_max(n - 1, INT_MIN);
        for(int i = 0;i < n; i++){
            if(nums[i] == min_val || nums[i] == max_val)
                continue;
            int index = (nums[i] - min_val) / gap;
            bucket_min[index] = min(bucket_min[index], nums[i]);
            bucket_max[index] = max(bucket_max[index], nums[i]);
        }
        int max_gap = INT_MIN;
        int pre_max = min_val;
        for(int i = 0;i < n - 1; i++){
            if(bucket_min[i] == INT_MAX && bucket_max[i] == INT_MIN)
                continue;
            max_gap = max(max_gap, bucket_min[i] - pre_max);
            pre_max = bucket_max[i];
        }
        max_gap = max(max_gap, max_val - pre_max);
        return max_gap;
    }
};