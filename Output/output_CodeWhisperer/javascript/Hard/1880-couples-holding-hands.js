/**https://leetcode.com/problems/couples-holding-hands/ */
//There are n couples sitting in 2n seats arranged in a row and want to hold hands.
//The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).
//Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.
// 
//Example 1:
//Input: row = [0,2,1,3]
//Output: 1
//Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
//Example 2:
//Input: row = [3,2,0,1]
//Output: 0
//Explanation: All couples are already seated side by side.
// 
//Constraints:
//	2n == row.length
//	2 <= n <= 30
//	n is even.
//	0 <= row[i] < 2n
//	All the elements of row are unique.
/**
 * @param {number[]} row
 * @return {number}
 */
var minSwapsCouples = function(row) {
    let n = row.length;
    let pos = new Array(n);
    for (let i = 0; i < n; i++) {
        pos[row[i]] = i;
    }
    
    let res = 0;
    for (let i = 0; i < n; i += 2) {
        let x = row[i];
        let y = x ^ 1;
        if (row[i + 1] != y) {
            let j = pos[y];
            [row[i + 1], row[j]] = [row[j], row[i + 1]];
            [pos[row[i + 1]], pos[row[j]]] = [pos[row[j]], pos[row[i + 1]]];
            res++;
        }
    }
    
    return res;
};