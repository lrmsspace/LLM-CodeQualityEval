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
    var map = {};
    for(var i=0;i<barcodes.length;i++){
        if(map[barcodes[i]]){
            map[barcodes[i]]++
        }else{
            map[barcodes[i]] = 1
        }
    }
    var max = 0;
    var maxKey = 0;
    for(var key in map){
        if(map[key]>max){
            max = map[key];
            maxKey = key;
        }
    }
    var result = [];
    var index = 0;
    while(map[maxKey]>0){
        result[index] = maxKey;
    }
    delete map[maxKey];
    for(var key in map){
        for(var i=0;i<map[key];i++){
            if(index>=result.length){
                index = 1;
            }
            result[index] = key;
            index+=2;
        }
    }
    return result;
};