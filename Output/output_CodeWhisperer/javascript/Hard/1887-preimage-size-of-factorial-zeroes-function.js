/**https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/ */
//Let f(x) be the number of zeroes at the end of x!. Recall that x! = 1 * 2 * 3 * ... * x and by convention, 0! = 1.
//	For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) = 2 because 11! = 39916800 has two zeroes at the end.
//Given an integer k, return the number of non-negative integers x have the property that f(x) = k.
// 
//Example 1:
//Input: k = 0
//Output: 5
//Explanation: 0!, 1!, 2!, 3!, and 4! end with k = 0 zeroes.
//Example 2:
//Input: k = 5
//Output: 0
//Explanation: There is no x such that x! ends in k = 5 zeroes.
//Example 3:
//Input: k = 3
//Output: 5
// 
//Constraints:
//	0 <= k <= 109
/**
 * @param {number} k
 * @return {number}
 */
var preimageSizeFZF = function(k) {
    let left = 0, right = 5 * (k + 1);
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        let count = 0;
        let temp = mid;
        while (temp > 0) {
            count += Math.floor(temp / 5);
            temp = Math.floor(temp / 5);
        }
        if (count < k) left = mid + 1;
        else if (count > k) right = mid - 1;
        else return 5;
    }
    return 0;
};