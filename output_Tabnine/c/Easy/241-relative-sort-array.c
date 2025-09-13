/**https://leetcode.com/problems/relative-sort-array/ */
//Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
//Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
// 
//Example 1:
//Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
//Output: [2,2,2,1,4,3,3,9,6,7,19]
//Example 2:
//Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
//Output: [22,28,8,6,17,44]
// 
//Constraints:
//	1 <= arr1.length, arr2.length <= 1000
//	0 <= arr1[i], arr2[i] <= 1000
//	All the elements of arr2 are distinct.
//	Each arr2[i] is in arr1.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int* result = malloc(arr1Size * sizeof(int));
    int* counts = calloc(1001, sizeof(int));
    int* sorted = malloc(arr1Size * sizeof(int));
    int* index = malloc(arr2Size * sizeof(int));
    int i, j, k;
    
    // Count the occurrences of each element in arr1
    for (i = 0; i < arr1Size; i++) {
        counts[arr1[i]]++;
    }
    
    // Sort the elements in arr2 based on their counts in arr1
    for (i = 0; i < arr2Size; i++) {
        index[i] = i;
        for (j = i + 1; j < arr2Size; j++) {
            if (counts[arr2[j]] > counts[arr2[i]]) {
                int temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
                temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }
    
    // Fill the result array with elements from arr1 based on their counts in arr2
    j = 0;
    for (i = 0; i < arr1Size; i++) {
        while (counts[arr1[i]] > 0) {
            result[j++] = arr1[i];
            counts[arr1[i]]--;
        }
    }
    
    // Fill the remaining elements of the result array with elements from arr2
    for (i = 0; i < arr2Size; i++) {
        result[j++] = arr2[index[i]];
    }
    
    *returnSize = arr1Size;
    return result;
}