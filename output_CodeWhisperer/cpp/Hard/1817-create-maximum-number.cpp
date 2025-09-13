/**https://leetcode.com/problems/create-maximum-number/ */
//You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2 represent the digits of two numbers. You are also given an integer k.
//Create the maximum number of length k <= m + n from digits of the two numbers. The relative order of the digits from the same array must be preserved.
//Return an array of the k digits representing the answer.
// 
//Example 1:
//Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
//Output: [9,8,6,5,3]
//Example 2:
//Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
//Output: [6,7,6,0,4]
//Example 3:
//Input: nums1 = [3,9], nums2 = [8,9], k = 3
//Output: [9,8,9]
// 
//Constraints:
//	m == nums1.length
//	n == nums2.length
//	1 <= m, n <= 500
//	0 <= nums1[i], nums2[i] <= 9
//	1 <= k <= m + n 
class Solution {
    public:
        vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
            int m = nums1.size();
            int n = nums2.size();
            vector<int> result(k, 0);
            
            // Try all possible combinations
            for (int i = max(0, k - n); i <= min(k, m); i++) {
                // Get maximum number of length i from nums1
                vector<int> candidate1 = maxSingleNumber(nums1, i);
                
                // Get maximum number of length k-i from nums2
                vector<int> candidate2 = maxSingleNumber(nums2, k - i);
                
                // Merge the two candidates
                vector<int> merged = merge(candidate1, candidate2);
                
                // Update result if the merged number is larger
                if (isGreater(merged, 0, result, 0)) {
                    result = merged;
                }
            }
            
            return result;
        }
        
    private:
        // Find the maximum number of length k from a single array
        vector<int> maxSingleNumber(const vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> result;
            
            // Number of digits to remove
            int drop = n - k;
            
            for (int i = 0; i < n; i++) {
                // Remove digits that are smaller than the current one
                while (!result.empty() && drop > 0 && result.back() < nums[i]) {
                    result.pop_back();
                    drop--;
                }
                
                // Add the current digit if there's room
                if (result.size() < k) {
                    result.push_back(nums[i]);
                } else {
                    // Otherwise, skip this digit (count it as dropped)
                    drop--;
                }
            }
            
            return result;
        }
        
        // Merge two arrays to create the maximum number
        vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
            vector<int> result;
            int i = 0, j = 0;
            
            while (i < nums1.size() || j < nums2.size()) {
                if (i < nums1.size() && j < nums2.size()) {
                    if (isGreater(nums1, i, nums2, j)) {
                        result.push_back(nums1[i++]);
                    } else {
                        result.push_back(nums2[j++]);
                    }
                } else if (i < nums1.size()) {
                    result.push_back(nums1[i++]);
                } else {
                    result.push_back(nums2[j++]);
                }
            }
            
            return result;
        }
        
        // Compare two arrays lexicographically starting from indices i and j
        bool isGreater(const vector<int>& nums1, int i, const vector<int>& nums2, int j) {
            while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
                i++;
                j++;
            }
            
            // If one array is exhausted or we found a difference
            return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
        }
    };
    