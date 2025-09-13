/*
 You are given an array of positive integers nums.
 Return the number of subarrays of nums, where the first and the last elements of the subarray are equal to the largest element in the subarray.
 Example 1:
 Input: nums = [1,4,3,3,2]
 Output: 6
 Explanation:
 There are 6 subarrays which have the first and the last elements equal to the largest element of the subarray:
 subarray [1,4,3,3,2], with its largest element 1. The first element is 1 and the last element is also 1.
 subarray [1,4,3,3,2], with its largest element 4. The first element is 4 and the last element is also 4.
 subarray [1,4,3,3,2], with its largest element 3. The first element is 3 and the last element is also 3.
 subarray [1,4,3,3,2], with its largest element 3. The first element is 3 and the last element is also 3.
 subarray [1,4,3,3,2], with its largest element 2. The first element is 2 and the last element is also 2.
 subarray [1,4,3,3,2], with its largest element 3. The first element is 3 and the last element is also 3.
 Hence, we return 6.
 Example 2:
 Input: nums = [3,3,3]
 Output: 6
 Explanation:
 There are 6 subarrays which have the first and the last elements equal to the largest element of the subarray:
 subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
 subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
 subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
 subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
 subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
 subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
 Hence, we return 6.
 Example 3:
 Input: nums = [1]
 Output: 1
 Explanation:
 There is a single subarray of nums which is [1], with its largest element 1. The first element is 1 and the last element is also 1.
 Hence, we return 1.
 Constraints:
 1 <= nums.length <= 105
 1 <= nums[i] <= 109
*/

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        int maxElement = 0;
        vector<int> positions;

        // Iterate through the array to find the maximum element and its positions
        for (int i = 0; i < n; ++i) {
            if (nums[i] > maxElement) {
                maxElement = nums[i];
                positions.clear();
                positions.push_back(i);
            } else if (nums[i] == maxElement) {
                positions.push_back(i);
            }
        }

        // Calculate the number of valid subarrays using the positions of the maximum elements
        for (int i = 0; i < positions.size(); ++i) {
            int left = (i == 0) ? positions[i] + 1 : positions[i] - positions[i - 1];
            int right = (i == positions.size() - 1) ? n - positions[i] : positions[i + 1] - positions[i];
            result += static_cast<long long>(left) * right;
        }

        return result;

    }
};