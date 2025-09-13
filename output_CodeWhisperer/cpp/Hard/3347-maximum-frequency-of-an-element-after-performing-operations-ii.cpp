/*
 You are given an integer array nums and two integers k and numOperations.
 You must perform an operation numOperations times on nums, where in each operation you:
 Select an index i that was not selected in any previous operations.
 Add an integer in the range [-k, k] to nums[i].
 Return the maximum possible frequency of any element in nums after performing the operations.
 Example 1:
 Input: nums = [1,4,5], k = 1, numOperations = 2
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1], after which nums becomes [1, 4, 5].
 Adding -1 to nums[2], after which nums becomes [1, 4, 4].
 Example 2:
 Input: nums = [5,11,20,20], k = 5, numOperations = 1
 Output: 2
 Explanation:
 We can achieve a maximum frequency of two by:
 Adding 0 to nums[1].
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
 0 <= k <= 109
 0 <= numOperations <= nums.length
*/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r;
        long sum = 0;
        for (r = 0; r < n; r++) {
            sum += nums[r];
            if (r - l + 1 > numOperations + 1) {
                sum -= nums[l];
                l++;
            }
            if (sum + k >= (long)nums[r] * (r - l + 1)) {
                continue;
            }
            else {
                sum -= nums[r];
                r--;
                sum -= nums[r];
                break;
            }
        }
        return r - l + 1;   
    }
};