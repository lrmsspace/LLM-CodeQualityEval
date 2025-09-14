/**https://leetcode.com/problems/three-equal-parts/ */
//You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.
//If it is possible, return any [i, j] with i + 1 < j, such that:
//	arr[0], arr[1], ..., arr[i] is the first part,
//	arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
//	arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
//	All three parts have equal binary values.
//If it is not possible, return [-1, -1].
//Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.
// 
//Example 1:
//Input: arr = [1,0,1,0,1]
//Output: [0,3]
//Example 2:
//Input: arr = [1,1,0,1,1]
//Output: [-1,-1]
//Example 3:
//Input: arr = [1,1,0,0,1]
//Output: [0,2]
// 
//Constraints:
//	3 <= arr.length <= 3 * 104
//	arr[i] is 0 or 1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* threeEqualParts(int* arr, int arrSize, int* returnSize){
    int i, j, k, l, r, s, t, u, v;
    for (i = 0; i < arrSize; i++) {
        if (arr[i]) {
            break;
        }
    }
    if (i == arrSize) {
        *returnSize = 3;
        return (int*)malloc(sizeof(int) * 3);
    }
    for (j = arrSize - 1; j >= 0; j--) {
        if (arr[j]) {
            break;
        }
    }
    if (j == -1) {
        *returnSize = 3;
        return (int*)malloc(sizeof(int) * 3);
    }
    if (j - i + 1 == 1) {
        *returnSize = 3;
        return (int*)malloc(sizeof(int) * 3);
    }
    for (k = i + 1; k <= j; k++) {
        if (arr[k] != arr[i]) {
            break;
        }
    }
    if (k > j) {
        *returnSize = 3;
        return (int*)malloc(sizeof(int) * 3);
    }
    for (l = k + 1; l <= j; l++) {
        if (arr[l] != arr[i]) {
            break;
        }
    }
    if (l > j) {
        *returnSize = 3;
        return (int*)malloc(sizeof(int) * 3);
    }
    for (r = l + 1; r <= j; r++) {
        if (arr[r] != arr[i]) {
            break;
        }
    }
        
    if (r > j) {
        *returnSize = 3;
        return (int*)malloc(sizeof(int) * 3);
    }
    s = r - i;
    t = k - i;
    u = l - i;
    v = j - i;
    if (s != t || s != u || s != v) {
        *returnSize = 3;
        return (int*)malloc(sizeof(int) * 3);
    }          
    for (i = 0; i + s <= arrSize; i += s) {
        for (j = i + s; j + s <= arrSize; j += s) {
            for (k = j + s; k + s <= arrSize; k += s) {
                if (i + s > j && j + s > k && i + s + s > k) {
                    if (memcmp(arr + i, arr + j, s * sizeof(int)) == 0 && memcmp(arr + j, arr + k, s * sizeof(int))) {
                        *returnSize = 3;
                        return (int*)malloc(sizeof(int) * 3);
                    }
                }
            }
        }
    }     
    *returnSize = 3;
    return (int*)malloc(sizeof(int) * 3);                                     
}