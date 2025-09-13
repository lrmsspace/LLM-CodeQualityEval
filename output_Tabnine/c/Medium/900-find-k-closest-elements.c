/**https://leetcode.com/problems/find-k-closest-elements/ */
//Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
//An integer a is closer to x than an integer b if:
//	|a - x| < |b - x|, or
//	|a - x| == |b - x| and a < b
// 
//Example 1:
//Input: arr = [1,2,3,4,5], k = 4, x = 3
//Output: [1,2,3,4]
//Example 2:
//Input: arr = [1,1,2,3,4,5], k = 4, x = -1
//Output: [1,1,2,3]
// 
//Constraints:
//	1 <= k <= arr.length
//	1 <= arr.length <= 104
//	arr is sorted in ascending order.
//	-104 <= arr[i], x <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    *returnSize = k;
    int* result = (int*)malloc(k * sizeof(int));
    
    int left = 0;
    int right = arrSize - 1;
    
    while (right - left + 1 > k) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == x) {
            left = mid;
            break;
        }
        
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    int start = left;
    int end = start + k - 1;
    
    while (start >= 0 && end < arrSize) {
        if (x - arr[start] <= arr[end] - x) {
            result[--k] = arr[start--];
        } else {
            result[--k] = arr[end++];
        }
    }
    
    while (k-- > 0) {
        result[k] = arr[start--];
    }
    
    return result;
    
}