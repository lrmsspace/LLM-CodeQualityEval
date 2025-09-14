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
 * @param {number[]} barcodes
 * @return {number[]}
 */
var rearrangeBarcodes = function(barcodes) {
    const count = new Map();
    for (const barcode of barcodes) {
        count.set(barcode, (count.get(barcode) || 0) + 1);
    }
    const sortedBarcodes = [...count.entries()].sort((a, b) => b[1] - a[1]);
    const result = new Array(barcodes.length);
    let index = 0;
    for (const [barcode, freq] of sortedBarcodes) {
        for (let i = 0; i < freq; i++) {
            result[index] = barcode;
            index += 2;
            if (index >= barcodes.length) {
                index = 1;
            }
        }
    }
    return result;    
};