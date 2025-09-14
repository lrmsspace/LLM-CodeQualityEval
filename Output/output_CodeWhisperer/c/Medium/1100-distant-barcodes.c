/**https://leetcode.com/problems/distant-barcodes/ */
//In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
//Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.
// 
//Example 1:
//Input: barcodes = [1,1,1,2,2,2]
//Output: [2,1,2,1,2,1]
//Example 2:
//Input: barcodes = [1,1,1,1,2,2,3,3]
//Output: [1,3,1,3,1,2,1,2]
// 
//Constraints:
//	1 <= barcodes.length <= 10000
//	1 <= barcodes[i] <= 10000
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * barcodesSize);
    *returnSize = barcodesSize;
    int count[10001] = {0};
    for (int i = 0; i < barcodesSize; i++) {
        count[barcodes[i]]++;
    }
    int max = 0;
    int maxIndex = 0;
    for (int i = 0; i <= 10000; i++) {
        if (count[i] > max) {
            max = count[i];
            maxIndex = i;
        }
    }
    int index = 0;
    for (int i = 0; i < max; i++) {
        result[index] = maxIndex;
        index += 2;
    }
    count[maxIndex] = 0;
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < count[i]; j++) {
            if (index >= barcodesSize) {
                index = 1;
            }
            result[index] = i;
            index += 2;
        }
    }
    return result;
}