/**https://leetcode.com/problems/duplicate-zeros/ */
//Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
//Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
// 
//Example 1:
//Input: arr = [1,0,2,3,0,4,5,0]
//Output: [1,0,0,2,3,0,0,4]
//Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
//Example 2:
//Input: arr = [1,2,3]
//Output: [1,2,3]
//Explanation: After calling your function, the input array is modified to: [1,2,3]
// 
//Constraints:
//	1 <= arr.length <= 104
//	0 <= arr[i] <= 9
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;
        
        // Count the number of zeros in the array
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) zeros++;
        }
        
        // Shift the zeros to the right and duplicate the zeros
        for (int i = n - 1; i >= zeros; i--) {
            if (arr[i] == 0) {
                arr[i + zeros] = 0;
                zeros--;
            } else {
                arr[i + zeros] = arr[i];
            }
        }
        
        // Fill the remaining zeros with the previous elements
        for (int i = zeros; i < n; i++) {
            arr[i] = arr[i - zeros];
        }
        
        // Return the modified array
        return;
        
    }
};