/**https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/ */
//Given two arrays of unique digits nums1 and nums2, return the smallest number that contains at least one digit from each array.
// 
//Example 1:
//Input: nums1 = [4,1,3], nums2 = [5,7]
//Output: 15
//Explanation: The number 15 contains the digit 1 from nums1 and the digit 5 from nums2. It can be proven that 15 is the smallest number we can have.
//Example 2:
//Input: nums1 = [3,5,2,6], nums2 = [3,1,7]
//Output: 3
//Explanation: The number 3 contains the digit 3 which exists in both arrays.
// 
//Constraints:
//	1 <= nums1.length, nums2.length <= 9
//	1 <= nums1[i], nums2[i] <= 9
//	All digits in each array are unique.
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        int res = 0;
        while(i < n1 && j < n2) {
            if(nums1[i] == nums2[j]) {
                return nums1[i];
            }
            res = res * 10 + (nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
        }
        while(i < n1) {
            res = res * 10 + nums1[i++];
        }
        while(j < n2) {
            res = res * 10 + nums2[j++];
        }
        return res;        
    }
};