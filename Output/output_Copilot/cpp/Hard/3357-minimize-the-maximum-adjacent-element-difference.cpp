/*
 You are given an array of integers nums. Some values in nums are missing and are denoted by -1.
 You must choose a pair of positive integers (x, y) exactly once and replace each missing element with either x or y.
 You need to minimize the maximum absolute difference between adjacent elements of nums after replacements.
 Return the minimum possible difference.
 Example 1:
 Input: nums = [1,2,-1,10,8]
 Output: 4
 Explanation:
 By choosing the pair as (6, 7), nums can be changed to [1, 2, 6, 10, 8].
 The absolute differences between adjacent elements are:
 |1 - 2| == 1
 |2 - 6| == 4
 |6 - 10| == 4
 |10 - 8| == 2
 Example 2:
 Input: nums = [-1,-1,-1]
 Output: 0
 Explanation:
 By choosing the pair as (4, 4), nums can be changed to [4, 4, 4].
 Example 3:
 Input: nums = [-1,10,-1,8]
 Output: 1
 Explanation:
 By choosing the pair as (11, 9), nums can be changed to [11, 10, 9, 8].
 Constraints:
 2 <= nums.length <= 105
 nums[i] is either -1 or in the range [1, 109].
*/

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> missingIndices;
        vector<int> knownValues;

        // Collect known values and indices of missing values
        for (int i = 0; i < n; ++i) {
            if (nums[i] == -1) {
                missingIndices.push_back(i);
            } else {
                knownValues.push_back(nums[i]);
            }
        }

        // If there are no missing values, return the maximum difference between adjacent known values
        if (missingIndices.empty()) {
            int maxDiff = 0;
            for (int i = 1; i < knownValues.size(); ++i) {
                maxDiff = max(maxDiff, abs(knownValues[i] - knownValues[i - 1]));
            }
            return maxDiff;
        }

        // Sort known values to find the minimum possible difference
        sort(knownValues.begin(), knownValues.end());

        // Calculate the minimum possible difference
        int minDiff = INT_MAX;
        for (int i = 1; i < knownValues.size(); ++i) {
            minDiff = min(minDiff, abs(knownValues[i] - knownValues[i - 1]));
        }

        // The minimum difference can be achieved by choosing x and y as the closest known values
        return minDiff;
        
    }
};