/**https://leetcode.com/problems/number-of-atoms/ */
//Given a string formula representing a chemical formula, return the count of each atom.
//The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.
//One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.
//	For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
//Two formulas are concatenated together to produce another formula.
//	For example, "H2O2He3Mg4" is also a formula.
//A formula placed in parentheses, and a count (optionally added) is also a formula.
//	For example, "(H2O2)" and "(H2O2)3" are formulas.
//Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.
//The test cases are generated so that all the values in the output fit in a 32-bit integer.
// 
//Example 1:
//Input: formula = "H2O"
//Output: "H2O"
//Explanation: The count of elements are {'H': 2, 'O': 1}.
//Example 2:
//Input: formula = "Mg(OH)2"
//Output: "H2MgO2"
//Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
//Example 3:
//Input: formula = "K4(ON(SO3)2)2"
//Output: "K4N2O14S4"
//Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
// 
//Constraints:
//	1 <= formula.length <= 1000
//	formula consists of English letters, digits, '(', and ')'.
//	formula is always valid.
/**
 * @param {string} formula
 * @return {string}
 */
var countOfAtoms = function(formula) {
    let map = new Map();
    let stack = [];
    let i = 0;
    let num = 0;
    let numStack = [];
    while (i < formula.length) {
        let c = formula[i];
        if (c === '(') {
            stack.push(map);
            map = new Map();
            i++;
            numStack.push(num);
            num = 0;
        } else if (c === ')') {
            let count = numStack.pop();
            let temp = map;
            map = stack.pop();
            i++;
            num = 0;
            for (let [key, value] of temp) {
                if (map.has(key)) {
                    map.set(key, map.get(key) + value * count);
                } else {
                    map.set(key, value * count);
                }
            }
        } else if (c >= '0' && c <= '9') {
            num = num * 10 + parseInt(c);
            i++;
        } else if (c >= 'A' && c <= 'Z') {
            let start = i;
            i++;
            while (i < formula.length && formula[i] >= 'a' && formula[i] <= 'z') {
                i++;
            }
            let name = formula.substring(start, i);
            if (map.has(name)) {
                map.set(name, map.get(name) + Math.max(num, 1));
            } else {
                map.set(name, Math.max(num, 1));
            }
            num = 0;
        }
    }
    let result = '';
    let keys = Array.from(map.keys());
    keys.sort();
    for (let key of keys) {
        result += key;
        if (map.get(key) > 1) {
            result += map.get(key);
        }
    }
    return result;
};