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
    int* freq = calloc(10001, sizeof(int));
    for (int i = 0; i < barcodesSize; i++) {
        freq[barcodes[i]]++;
    }
    
    int* result = malloc(barcodesSize * sizeof(int));
    int index = 0;
    for (int i = 10000; i >= 1; i--) {
        while (freq[i] > 0) {
            result[index++] = i;
            freq[i]--;
            if (index < barcodesSize && i - 1 > 0 && freq[i - 1] > 0) {
                result[index++] = i - 1;
                freq[i - 1]--;
            }
        }
    }
    
    *returnSize = barcodesSize;
    return result;
    
}