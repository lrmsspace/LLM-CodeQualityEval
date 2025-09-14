/**https://leetcode.com/problems/complex-number-multiplication/ */
//A complex number can be represented as a string on the form "real+imaginaryi" where:
//	real is the real part and is an integer in the range [-100, 100].
//	imaginary is the imaginary part and is an integer in the range [-100, 100].
//	i2 == -1.
//Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.
// 
//Example 1:
//Input: num1 = "1+1i", num2 = "1+1i"
//Output: "0+2i"
//Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
//Example 2:
//Input: num1 = "1+-1i", num2 = "1+-1i"
//Output: "0+-2i"
//Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
// 
//Constraints:
//	num1 and num2 are valid complex numbers.
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1, b1, a2, b2;
        int sign = 1;
        sscanf(num1.c_str(), "%d+%di", &a1, &b1);
        if (num1[0] == '-') sign = -1;
        sscanf(num2.c_str(), "%d+%di", &a2, &b2);
        if (num2[0] == '-') sign = -sign;
        int real = sign * (a1 * a2 - b1 * b2);
        int imaginary = sign * (a1 * b2 + a2 * b1);
        return to_string(real) + (imaginary >= 0? "+" : "") + to_string(imaginary) + "i";
        
    }
};