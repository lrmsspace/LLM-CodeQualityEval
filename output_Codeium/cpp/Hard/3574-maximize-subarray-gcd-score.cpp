/*
 You are given an array of positive integers nums and an integer k.
 You may perform at most k operations. In each operation, you can choose one element in the array and double its value. Each element can be doubled at most once.
 The score of a contiguous subarray is defined as the product of its length and the greatest common divisor (GCD) of all its elements.
 Your task is to return the maximum score that can be achieved by selecting a contiguous subarray from the modified array.
 Note:
 The greatest common divisor (GCD) of an array is the largest integer that evenly divides all the array elements.
 Example 1:
 Input: nums = [2,4], k = 1
 Output: 8
 Explanation:
 Double nums[0] to 4 using one operation. The modified array becomes [4, 4].
 The GCD of the subarray [4, 4] is 4, and the length is 2.
 Thus, the maximum possible score is 2 × 4 = 8.
 Example 2:
 Input: nums = [3,5,7], k = 2
 Output: 14
 Explanation:
 Double nums[2] to 14 using one operation. The modified array becomes [3, 5, 14].
 The GCD of the subarray [14] is 14, and the length is 1.
 Thus, the maximum possible score is 1 × 14 = 14.
 Example 3:
 Input: nums = [5,5,5], k = 1
 Output: 15
 Explanation:
 The subarray [5, 5, 5] has a GCD of 5, and its length is 3.
 Since doubling any element doesn't improve the score, the maximum score is 3 × 5 = 15.
 Constraints:
 1 <= n == nums.length <= 1500
 1 <= nums[i] <= 109
 1 <= k <= n
*/

class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        long long res = 0;
        int n = nums.size();
        
        // Try each element as the start of a subarray
        for (int i = 0; i < n; ++i) {
            int curGCD = nums[i];
            int count = 1;
            res = max(res, static_cast<long long>(curGCD * count));
            
            // Extend the subarray and calculate the GCD
            for (int j = i + 1; j < n; ++j) {
                curGCD = gcd(curGCD, nums[j]);
                ++count;
                res = max(res, static_cast<long long>(curGCD * count));
            }
        }
        
        // Try doubling each element at most once to maximize score
        for (int i = 0; i < n; ++i) {
            nums[i] *= 2;
            int curGCD = nums[i];
            int count = 1;
            res = max(res, static_cast<long long>(curGCD * count));
            
            for (int j = i + 1; j < n; ++j) {
                curGCD = gcd(curGCD, nums[j]);
                ++count;
                res = max(res, static_cast<long long>(curGCD * count));
            }
            nums[i] /= 2; // Revert the change
        }
        
        return res;

    }
};