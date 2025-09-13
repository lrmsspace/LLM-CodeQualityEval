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
    int* result = (int*)malloc(barcodesSize * sizeof(int));
    int max = 0;
    int maxIndex = 0;
    int secondMax = 0;
    int secondMaxIndex = 0;
    for (int i = 0; i < barcodesSize; i++) {
        if (barcodes[i] > max) {
            secondMax = max;
            secondMaxIndex = maxIndex;
            max = barcodes[i];
            maxIndex = i;
        } else if (barcodes[i] > secondMax && barcodes[i] != max) {
            secondMax = barcodes[i];
            secondMaxIndex = i;
        }
    }
    int index = 0;
    while (max != 0) {
        result[index] = max;
        index += 2;
        max = 0;
        if (secondMax != 0) {
            result[index-1] = secondMax;
            secondMax = 0;
        }
    }
    int j = 0;
    for (int i = 0; i < barcodesSize; i++) {
        if (barcodes[i] != result[j] && barcodes[i] != result[j-1]) {
            result[index] = barcodes[i];
            index++;
        }
    }
    *returnSize = barcodesSize;
    return result;
}