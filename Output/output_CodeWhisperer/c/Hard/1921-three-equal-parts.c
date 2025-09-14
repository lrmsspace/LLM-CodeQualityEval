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
int* threeEqualParts(int* arr, int arrSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 1) {
            count++;
        }
    }
    if (count % 3 != 0) {
        result[0] = -1;
        result[1] = -1;
        return result;
    }
    if (count == 0) {
        result[0] = 0;
        result[1] = arrSize - 1;
        return result;
    }
    int num = count / 3;
    int* index = (int*)malloc(sizeof(int) * 3);
    int j = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 1) {
            index[j++] = i;
        }
    }
    int i = 0;
    while (i < arrSize - num) {
        if (arr[i] != arr[index[0] + i] || arr[i] != arr[index[1] + i]) {
            result[0] = -1;
            result[1] = -1;
            return result;
        }
        i++;
    }
    result[0] = index[0] + num - 1;
    result[1] = index[1] + num;
    return result;
    
}