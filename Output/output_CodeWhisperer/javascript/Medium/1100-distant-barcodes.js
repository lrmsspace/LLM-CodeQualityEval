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
    let map = new Map();
    for (let i = 0; i < barcodes.length; i++) {
        if (!map.has(barcodes[i])) {
            map.set(barcodes[i], 1);
        } else {
            map.set(barcodes[i], map.get(barcodes[i]) + 1);
        }
    }
    let arr = Array.from(map);
    arr.sort((a, b) => b[1] - a[1]);
    let res = [];
    let index = 0;
    while (arr[0][1] > 0) {
        res[index] = arr[0][0];
        arr[0][1]--;
        index += 2;
        if (index >= barcodes.length) index = 1;
        arr.sort((a, b) => b[1] - a[1]);
    }
    return res;
};