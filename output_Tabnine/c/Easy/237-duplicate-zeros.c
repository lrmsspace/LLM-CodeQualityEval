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
void duplicateZeros(int* arr, int arrSize) {
    int n = arrSize;
    int zerosCount = 0;
    
    // Count the number of zeros in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            zerosCount++;
        }
    }
    
    // Shift the zeros to the right
    int j = n - 1;
    for (int i = n - 1; i >= zerosCount; i--) {
        if (arr[i] == 0) {
            arr[j] = 0;
            j--;
        } else {
            arr[j] = arr[i];
        }
        j--;
    }
    
    // Fill the remaining elements with zeros
    for (int i = zerosCount; i < n; i++) {
        arr[i] = 0;
    }
    
    return;
}