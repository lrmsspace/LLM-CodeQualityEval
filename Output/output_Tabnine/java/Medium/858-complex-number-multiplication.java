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
        String[] parts1 = num1.split("\\+|i");
        String[] parts2 = num2.split("\\+|i");
        
        int real1 = Integer.parseInt(parts1[0]);
        int imag1 = Integer.parseInt(parts1[1]);
        int real2 = Integer.parseInt(parts2[0]);
        int imag2 = Integer.parseInt(parts2[1]);
        
        int real = real1 * real2 - imag1 * imag2;
        int imag = real1 * imag2 + imag1 * real2;
        
        return real + "+" + imag + "i";
        
    }
}