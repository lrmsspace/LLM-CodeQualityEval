/*
 You are given an array of integers nums of length n and a positive integer k.
 The power of an array is defined as:
 Its maximum element if all of its elements are consecutive and sorted in ascending order.
 -1 otherwise.
 You need to find the power of all subarrays of nums of size k.
 Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].
 Example 1:
 Input: nums = [1,2,3,4,3,2,5], k = 3
 Output: [3,4,-1,-1,-1]
 Explanation:
 There are 5 subarrays of nums of size 3:
 [1, 2, 3] with the maximum element 3.
 [2, 3, 4] with the maximum element 4.
 [3, 4, 3] whose elements are not consecutive.
 [4, 3, 2] whose elements are not sorted.
 [3, 2, 5] whose elements are not consecutive.
 Example 2:
 Input: nums = [2,2,2,2,2], k = 4
 Output: [-1,-1]
 Example 3:
 Input: nums = [3,2,3,2,3,2], k = 2
 Output: [-1,3,-1,3,-1]
 Constraints:
 1 <= n == nums.length <= 105
 1 <= nums[i] <= 106
 1 <= k <= n
*/

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1);
        int max = -1;
        int maxIndex = -1;
        for (int i = 0; i < n - k + 1; i++) {
            if (maxIndex < i) {
                max = -1;
                maxIndex = -1;
                for (int j = i; j < i + k; j++) {
                    if (max < nums[j]) {
                        max = nums[j];
                        maxIndex = j;
                    }
                }
            }
            else {
                if (maxIndex < i + k) {
                    if (max < nums[i + k - 1]) {
                        max = nums[i + k - 1];
                        maxIndex = i + k - 1;
                    }
                }
                else {
                    max = -1;
                    maxIndex = -1;
                    for (int j = i + k - 1; j >= i; j--) {
                        if (max < nums[j]) {
                            max = nums[j];
                            maxIndex = j;
                        }
                    }
                }
            }
            if (maxIndex == i + k - 1) {
                res[i] = max;
            }
            else {
                res[i] = -1;
            }
        }
        return res;

            
    }
};