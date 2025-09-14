/*
 You are given a binary array nums.
 We call a subarray alternating if no two adjacent elements in the subarray have the same value.
 Return the number of alternating subarrays in nums.
 Example 1:
 Input: nums = [0,1,1,1]
 Output: 5
 Explanation:
 The following subarrays are alternating: [0], [1], [1], [1], and [0,1].
 Example 2:
 Input: nums = [1,0,1,0]
 Output: 10
 Explanation:
 Every subarray of the array is alternating. There are 10 possible subarrays that we can choose.
 Constraints:
 1 <= nums.length <= 105
 nums[i] is either 0 or 1.
*/

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
    long long result = nums.size(); // Single elements are always alternating
    
    for(int i = 0; i < nums.size() - 1; i++) {
        int j = i + 1;
        bool isAlternating = true;
        
        // Check if current subarray is alternating
        while(j < nums.size() && isAlternating) {
            if(nums[j] == nums[j-1]) {
                isAlternating = false;
            }
            if(isAlternating) {
                result++;
                j++;
            }
        }
    }
    
    return result;
}                
};