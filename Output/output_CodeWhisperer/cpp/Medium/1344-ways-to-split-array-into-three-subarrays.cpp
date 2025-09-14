/**https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/ */
//A split of an integer array is good if:
//	The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
//	The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
//Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
// 
//Example 1:
//Input: nums = [1,1,1]
//Output: 1
//Explanation: The only good way to split nums is [1] [1] [1].
//Example 2:
//Input: nums = [1,2,2,2,5,0]
//Output: 3
//Explanation: There are three good ways of splitting nums:
//[1] [2] [2,2,5,0]
//[1] [2,2] [2,5,0]
//[1,2] [2,2] [5,0]
//Example 3:
//Input: nums = [3,2,1]
//Output: 0
//Explanation: There is no good way to split nums.
// 
//Constraints:
//	3 <= nums.length <= 105
//	0 <= nums[i] <= 104
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        int ans = 0;
        for (int i = 1; i <= n - 2; i++) {
            int left = prefix[i];
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (prefix[mid] - left <= prefix[n] - prefix[mid]) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            int right = prefix[lo];
            if (right - left > prefix[n] - right) {
                break;
            }
            ans = (ans + lo - i) % 1000000007;
            lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (prefix[mid] - left < left) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
            right = prefix[lo];
            if (left <= right - left) {
                ans = (ans + lo - i) % 1000000007;
            }
        }
        return ans;      
    }
};