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
    public String complexNumberMultiply(String num1, String num2) {
        String[] num1Parts = num1.split("\\+|i");
        String[] num2Parts = num2.split("\\+|i");

        int real1 = Integer.parseInt(num1Parts[0]);
        int imaginary1 = Integer.parseInt(num1Parts[1]);
        int real2 = Integer.parseInt(num2Parts[0]);
        int imaginary2 = Integer.parseInt(num2Parts[1]);

        int realResult = real1 * real2 - imaginary1 * imaginary2;
        int imaginaryResult = real1 * imaginary2 + imaginary1 * real2;

        return realResult + "+" + imaginaryResult + "i";        
    }
}