/**https://leetcode.com/problems/make-array-strictly-increasing/ */
//Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
//In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
//If there is no way to make arr1 strictly increasing, return -1.
// 
//Example 1:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
//Output: 1
//Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].
//Example 2:
//Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
//Output: 2
//Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].
//Example 3:
//Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
//Output: -1
//Explanation: You can't make arr1 strictly increasing.
// 
//Constraints:
//	1 <= arr1.length, arr2.length <= 2000
//	0 <= arr1[i], arr2[i] <= 10^9
// 
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
var makeArrayIncreasing = function(arr1, arr2) {
    arr2.sort((a, b) => a - b);
    const memo = new Map();
    const dfs = (i, prev) => {
        if (i === arr1.length) return 0;
        const key = `${i},${prev}`;
        if (memo.has(key)) return memo.get(key);
        let cost = Infinity;
        if (arr1[i] > prev) {
            cost = dfs(i + 1, arr1[i]);
        }
        let j = arr2.findIndex((num) => num > prev);
        while (j < arr2.length) {
            cost = Math.min(cost, 1 + dfs(i + 1, arr2[j]));
            prev = arr2[j];
            do {
                j++;
            } while (j < arr2.length && arr2[j] === prev);
        }
        memo.set(key, cost);
        return cost;
    };
    const res = dfs(0, -Infinity);
    return res === Infinity ? -1 : res;
};