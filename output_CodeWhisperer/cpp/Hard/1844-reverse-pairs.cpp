/**https://leetcode.com/problems/reverse-pairs/ */
//Given an integer array nums, return the number of reverse pairs in the array.
//A reverse pair is a pair (i, j) where:
//	0 <= i < j < nums.length and
//	nums[i] > 2 * nums[j].
// 
//Example 1:
//Input: nums = [1,3,2,3,1]
//Output: 2
//Explanation: The reverse pairs are:
//(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
//(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
//Example 2:
//Input: nums = [2,4,3,5,1]
//Output: 3
//Explanation: The reverse pairs are:
//(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
//(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
//(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
// 
//Constraints:
//	1 <= nums.length <= 5 * 104
//	-231 <= nums[i] <= 231 - 1  
class Solution {
    public:
        int reversePairs(vector<int>& nums) {
            return mergeSort(nums, 0, nums.size() - 1);
        }
        
    private:
        int mergeSort(vector<int>& nums, int start, int end) {
            // Base case: single element or empty array
            if (start >= end) return 0;
            
            // Divide the array into two halves
            int mid = start + (end - start) / 2;
            
            // Count reverse pairs in left and right halves
            int count = mergeSort(nums, start, mid) + mergeSort(nums, mid + 1, end);
            
            // Count reverse pairs where elements are from different halves
            count += countCrossPairs(nums, start, mid, end);
            
            // Merge the two sorted halves
            merge(nums, start, mid, end);
            
            return count;
        }
        
        int countCrossPairs(vector<int>& nums, int start, int mid, int end) {
            int count = 0;
            int j = mid + 1;
            
            // For each element in the left half, count elements in the right half that form reverse pairs
            for (int i = start; i <= mid; i++) {
                // Find the first element in the right half that doesn't form a reverse pair
                while (j <= end && (long long)nums[i] > 2LL * nums[j]) {
                    j++;
                }
                // Add the count of elements that form reverse pairs
                count += (j - (mid + 1));
            }
            
            return count;
        }
        
        void merge(vector<int>& nums, int start, int mid, int end) {
            vector<int> temp(end - start + 1);
            int i = start, j = mid + 1, k = 0;
            
            // Merge the two sorted halves
            while (i <= mid && j <= end) {
                if (nums[i] <= nums[j]) {
                    temp[k++] = nums[i++];
                } else {
                    temp[k++] = nums[j++];
                }
            }
            
            // Copy remaining elements
            while (i <= mid) {
                temp[k++] = nums[i++];
            }
            
            while (j <= end) {
                temp[k++] = nums[j++];
            }
            
            // Copy back to the original array
            for (int p = 0; p < temp.size(); p++) {
                nums[start + p] = temp[p];
            }
        }
    };
    