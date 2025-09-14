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
        int a = 0, b = 0;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    return nums1[i];
                }
                if(nums1[i] < nums2[j]){
                    if(a < nums1[i]){
                        a = nums1[i];
                    }
                    if(b < nums2[j]){
                        b = nums2[j];
                    }
                }
                else{
                    if(a < nums2[j]){
                        a = nums2[j];
                    }
                    if(b < nums1[i]){
                        b = nums1[i];
                    }
                }
            }
        }
        return a * 10 + b;
    }
};