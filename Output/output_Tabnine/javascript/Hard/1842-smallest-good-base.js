/**https://leetcode.com/problems/smallest-good-base/ */
//Given an integer n represented as a string, return the smallest good base of n.
//We call k >= 2 a good base of n, if all digits of n base k are 1's.
// 
//Example 1:
//Input: n = "13"
//Output: "3"
//Explanation: 13 base 3 is 111.
//Example 2:
//Input: n = "4681"
//Output: "8"
//Explanation: 4681 base 8 is 11111.
//Example 3:
//Input: n = "1000000000000000000"
//Output: "999999999999999999"
//Explanation: 1000000000000000000 base 999999999999999999 is 11.
// 
//Constraints:
//	n is an integer in the range [3, 1018].
//	n does not contain any leading zeros.
/**
 * @param {string} n
 * @return {string}
 */
var smallestGoodBase = function(n) {
    let m = BigInt(n);
    let ans = BigInt(n).toString(2).length;
    
    for (let i = BigInt(ans) - BigInt(1); i >= BigInt(2); i--) {
        let l = BigInt(1), r = m;
        
        while (l < r) {
            let mid = l + (r - l) / BigInt(2);
            let power = BigInt(i);
            
            if (mid.pow(power).toString(10) > m.toString(10)) {
                r = mid - BigInt(1);
            } else {
                l = mid + BigInt(1);
            }
        }
        
        if (l.pow(i).toString(10) === m.toString(10)) {
            return l.toString(10);
        }
    }
    
    return ans.toString(10);
    
};