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
//Input: arr = [1,2,3,4,5], k = 4, x = -1
//Output: [1,2,3,4]
// 
//Constraints:
//	1 <= k <= arr.length
//	1 <= arr.length <= 104
//	arr is sorted in ascending order.
//	-104 <= arr[i], x <= 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize){
    int i, j, left, right, mid;
    for (i = 0; i < arrSize; i++) {
        if (arr[i] >= x) {
            break;
        }
    }
    left = i - 1;
    right = i;
    for (i = 0; i < k; i++) {
        if (left < 0) {
            right++;
        } else if (right >= arrSize) {
            left--;
        } else {
            if (x - arr[left] <= arr[right] - x) {
                left--;
            } else {
                right++;
            }
        }
    }
    for (i = left + 1; i < right; i++) {
        res[i - left - 1] = arr[i];
    }
    return res;
}