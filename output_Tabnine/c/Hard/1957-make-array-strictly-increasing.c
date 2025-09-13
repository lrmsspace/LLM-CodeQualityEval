/**https://leetcode.com/problems/make-array-strictly-increasing/ */
//Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
//In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
//If there is no way to make arr1 strictly increasing, return -1.
// 
//Example 1:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
//Output: 1
//Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
//Example 2:
//Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
//Output: 2
//Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
//Example 3:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
//Output: -1
//Explanation: You can't make arr1 strictly increasing.
// 
//Constraints:
//	1 <= arr1.length, arr2.length <= 2000
//	0 <= arr1[i], arr2[i] <= 10^9
// 
int makeArrayIncreasing(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    // Sort both arrays
    qsort(arr1, arr1Size, sizeof(int), compare);
    qsort(arr2, arr2Size, sizeof(int), compare);
    
    // Initialize variables
    int i = 0, j = 0, operations = 0;
    
    // Iterate through both arrays simultaneously
    while (i < arr1Size && j < arr2Size) {
        // If arr1[i] is less than or equal to arr2[j], increment i
        if (arr1[i] <= arr2[j]) {
            i++;
        }
        // If arr1[i] is greater than arr2[j], increment j and increment operations
        else {
            j++;
            operations++;
        }
    }
    
    // If there are remaining elements in arr1, increment operations by the difference
    while (i < arr1Size) {
        operations += arr1Size - i;
        i++;
    }
    
    // Return the minimum number of operations or -1 if it's impossible to make arr1 strictly increasing
    return operations == 0? -1 : operations;
    
}