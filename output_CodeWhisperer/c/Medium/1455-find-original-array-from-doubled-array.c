/**https://leetcode.com/problems/find-original-array-from-doubled-array/ */
//An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.
//Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.
// 
//Example 1:
//Input: changed = [1,3,4,2,6,8]
//Output: [1,3,4]
//Explanation: One possible original array could be [1,3,4]:
//- Twice the value of 1 is 1 * 2 = 2.
//- Twice the value of 3 is 3 * 2 = 6.
//- Twice the value of 4 is 4 * 2 = 8.
//Other original arrays could be [4,3,1] or [3,1,4].
//Example 2:
//Input: changed = [6,3,0,1]
//Output: []
//Explanation: changed is not a doubled array.
//Example 3:
//Input: changed = [1]
//Output: []
//Explanation: changed is not a doubled array.
// 
//Constraints:
//	1 <= changed.length <= 105
//	0 <= changed[i] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOriginalArray(int* changed, int changedSize, int* returnSize) {
    int* original = (int*)malloc(sizeof(int) * changedSize / 2);
    *returnSize = 0;
    if (changedSize % 2 != 0) {
        return original;
    }
    int* count = (int*)calloc(200001, sizeof(int));
    for (int i = 0; i < changedSize; i++) {
        count[changed[i]]++;
    }
    for (int i = 0; i < 200001; i++) {
        if (count[i] > 0) {
            if (i * 2 > 200000 || count[i * 2] < count[i]) {
                free(original);
                return (int*)calloc(0, sizeof(int));
            }
            count[i * 2] -= count[i];
            for (int j = 0; j < count[i]; j++) {
                original[*returnSize] = i;
                (*returnSize)++;
            }
        }
    }
    free(count);
    return original;
}