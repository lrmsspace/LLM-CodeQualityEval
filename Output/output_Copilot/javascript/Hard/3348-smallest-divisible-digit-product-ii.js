/*
 You are given a string num which represents a positive integer, and an integer t.
 A number is called zero-free if none of its digits are 0.
 Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".
 Example 1:
 Input: num = "1234", t = 256
 Output: "1488"
 Explanation:
 The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.
 Example 2:
 Input: num = "12355", t = 50
 Output: "12355"
 Explanation:
 12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.
 Example 3:
 Input: num = "11111", t = 26
 Output: "-1"
 Explanation:
 No number greater than 11111 has the product of its digits divisible by 26.
 Constraints:
 2 <= num.length <= 2 * 105
 num consists only of digits in the range ['0', '9'].
 num does not contain leading zeros.
 1 <= t <= 1014
*/

/**
 * @param {string} num
 * @param {number} t
 * @return {string}
 */
var smallestNumber = function(num, t) {
    const n = num.length;
    let product = 1;

    // Calculate the product of digits in num
    for (let i = 0; i < n; i++) {
        product *= parseInt(num[i]);
    }

    // If the product is already divisible by t, return num
    if (product % t === 0) {
        return num;
    }

    // Try to find the smallest zero-free number greater than num
    for (let i = 0; i < n; i++) {
        for (let j = 1; j <= 9; j++) {
            const newNum = num.slice(0, i) + j + num.slice(i + 1);
            if (isZeroFree(newNum) && productOfDigits(newNum) % t === 0) {
                return newNum;
            }
        }
    }

    return "-1";
};

// Helper function to check if a number is zero-free
const isZeroFree = (num) => {
    for (let i = 0; i < num.length; i++) {
        if (num[i] === '0') {
            return false;
        }
    }
    return true;
};

// Helper function to calculate the product of digits in a number
const productOfDigits = (num) => {
    let product = 1;
    for (let i = 0; i < num.length; i++) {
        product *= parseInt(num[i]);
    }
    return product;
};