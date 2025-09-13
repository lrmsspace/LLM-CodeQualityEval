/**https://leetcode.com/problems/solve-the-equation/ */
//Solve a given equation and return the value of 'x' in the form of a string "x=#value". The equation contains only '+', '-' operation, the variable 'x' and its coefficient. You should return "No solution" if there is no solution for the equation, or "Infinite solutions" if there are infinite solutions for the equation.
//If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.
// 
//Example 1:
//Input: equation = "x+5-3+x=6+x-2"
//Output: "x=2"
//Example 2:
//Input: equation = "x=x"
//Output: "Infinite solutions"
//Example 3:
//Input: equation = "2x=x"
//Output: "x=0"
// 
//Constraints:
//	3 <= equation.length <= 1000
//	equation has exactly one '='.
//	equation consists of integers with an absolute value in the range [0, 100] without any leading zeros, and the variable 'x'.
//	The input is generated that if there is a single solution, it will be an integer.
/**
 * @param {string} equation
 * @return {string}
 */
var solveEquation = function(equation) {
    let [left, right] = equation.split('=');
    let leftX = 0, leftNum = 0, rightX = 0, rightNum = 0;
    
    const parseSide = (side, isLeft) => {
        let sign = 1;
        let num = '';
        for (let i = 0; i < side.length; i++) {
            if (side[i] === '+' || side[i] === '-') {
                if (num) {
                    if (num.includes('x')) {
                        let coeff = num.replace('x', '');
                        if (coeff === '' || coeff === '+') coeff = '1';
                        else if (coeff === '-') coeff = '-1';
                        isLeft ? leftX += sign * parseInt(coeff) : rightX += sign * parseInt(coeff);
                    } else {
                        isLeft ? leftNum += sign * parseInt(num) : rightNum += sign * parseInt(num);
                    }
                    num = '';
                }
                sign = side[i] === '+' ? 1 : -1;
            } else {
                num += side[i];
            }
        }
        if (num) {
            if (num.includes('x')) {
                let coeff = num.replace('x', '');
                if (coeff === '' || coeff === '+') coeff = '1';
                else if (coeff === '-') coeff = '-1';
                isLeft ? leftX += sign * parseInt(coeff) : rightX += sign * parseInt(coeff);
            } else {
                isLeft ? leftNum += sign * parseInt(num) : rightNum += sign * parseInt(num);
            }
        }
    };
    
    parseSide(left, true);
    parseSide(right, false);
    
    leftNum -= rightNum;
    rightX -= leftX;
    
    if (rightX === 0 && leftNum === 0) return "Infinite solutions";
    if (rightX === 0) return "No solution";
    
    return `x=${leftNum / rightX}`;    
};