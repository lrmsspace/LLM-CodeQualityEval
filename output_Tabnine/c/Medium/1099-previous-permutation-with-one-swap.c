/**https://leetcode.com/problems/previous-permutation-with-one-swap/ */
//Given an array of positive integers arr (not necessarily distinct), return the lexicographically largest permutation that is smaller than arr, that can be made with exactly one swap. If it cannot be done, then return the same array.
//Note that a swap exchanges the positions of two numbers arr[i] and arr[j]
// 
//Example 1:
//Input: arr = [3,2,1]
//Output: [3,1,2]
//Explanation: Swapping 2 and 1.
//Example 2:
//Input: arr = [1,1,5]
//Output: [1,1,5]
//Explanation: This is already the smallest permutation.
//Example 3:
//Input: arr = [1,9,4,6,7]
//Output: [1,7,4,6,9]
//Explanation: Swapping 9 and 7.
// 
//Constraints:
//	1 <= arr.length <= 104
//	1 <= arr[i] <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prevPermOpt1(int* arr, int arrSize, int* returnSize) {
    int* result = malloc(arrSize * sizeof(int));
    *returnSize = arrSize;
    
    for (int i = arrSize - 1; i > 0; i--) {
        if (arr[i] <= arr[i - 1]) {
            for (int j = arrSize - 1; j >= i; j--) {
                if (arr[j] > arr[i - 1]) {
                    int temp = arr[i - 1];
                    arr[i - 1] = arr[j];
                    arr[j] = temp;
                    break;
                }
            }
        } else {
            break;
        }
    }
    
    return result;
    
}