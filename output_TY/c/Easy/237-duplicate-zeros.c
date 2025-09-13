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
void duplicateZeros(int* arr, int arrSize){
    int i = 0;
    int j = 0;
    int temp = 0;
    int count = 0;
    while (j < arrSize) {
        if (arr[i] == 0) {
            count++;
        }
        i++;
        j++;
    }
    i--;
    j--;
    while (j >= 0) {
        if (count > 0 && arr[i] == 0) {
            count--;
            arr[j] = 0;
            j--;
        }
        arr[j] = arr[i];
        i--;
        j--;
        }
    return;
}