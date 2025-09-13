/*
 You are given a binary string s representing a number n in its binary form.
 You are also given an integer k.
 An integer x is called k-reducible if performing the following operation at most k times reduces it to 1:
 Replace x with the count of set bits in its binary representation.
 For example, the binary representation of 6 is "110". Applying the operation once reduces it to 2 (since "110" has two set bits). Applying the operation again to 2 (binary "10") reduces it to 1 (since "10" has one set bit).
 Return an integer denoting the number of positive integers less than n that are k-reducible.
 Since the answer may be too large, return it modulo 109 + 7.
 Example 1:
 Input: s = "111", k = 1
 Output: 3
 Explanation: 
 n = 7. The 1-reducible integers less than 7 are 1, 2, and 4.
 Example 2:
 Input: s = "1000", k = 2
 Output: 6
 Explanation:
 n = 8. The 2-reducible integers less than 8 are 1, 2, 3, 4, 5, and 6.
 Example 3:
 Input: s = "1", k = 3
 Output: 0
 Explanation:
 There are no positive integers less than n = 1, so the answer is 0.
 Constraints:
 1 <= s.length <= 800
 s has no leading zeros.
 s consists only of the characters '0' and '1'.
 1 <= k <= 5
*/

/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var countKReducibleNumbers = function(s, k) {
    const n = parseInt(s, 2);
    let count = 0;

    for (let i = 1; i < n; i++) {
        let x = i;
        let steps = 0;

        while (x > 1 && steps < k) {
            x = countSetBits(x);
            steps++;
        }

        if (x === 1) {
            count++;
        }
    }

    return count;
};

// Helper function to count the number of set bits in a number
const countSetBits = (x) => {
    let count = 0;
    while (x > 0) {
        count += (x & 1);
        x >>= 1;
    }
    return count;
};