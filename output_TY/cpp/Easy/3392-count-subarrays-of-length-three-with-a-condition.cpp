/*
 Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.
 Example 1:
 Input: nums = [1,2,1,4,1]
 Output: 1
 Explanation:
 Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.
 Example 2:
 Input: nums = [1,1,1]
 Output: 0
 Explanation:
 [1,1,1] is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.
 Constraints:
 3 <= nums.length <= 100
 -100 <= nums[i] <= 100
*/

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = i; j < n; j++){
                if(nums[j] * 2 > nums[i] + nums[j]) count++;
                else break;
            }
            for(int j = i; j < n; j++){
                if(nums[j] * 2 < nums[i] + nums[j]) count++;
                else break;
            }
            ans += count;
        }
        return ans;
        
    }
};