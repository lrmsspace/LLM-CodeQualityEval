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
int minNumber(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Sort the arrays in descending order
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    
    // Initialize the result string
    char* result = (char*)malloc((nums1Size + nums2Size + 1) * sizeof(char));
    result[nums1Size + nums2Size] = '\0';
    
    // Concatenate the arrays into the result string
    for (int i = nums1Size - 1; i >= 0; i--) {
        result[i + nums2Size] = '0' + nums1[i];
    }
    for (int i = nums2Size - 1; i >= 0; i--) {
        result[i] = '0' + nums2[i];
    }
    
    // Convert the result string to an integer and return it
    return atoi(result);
    
}