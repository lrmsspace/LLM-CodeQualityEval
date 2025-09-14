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
        String[] num1Arr = num1.split("\\+");
        String[] num2Arr = num2.split("\\+");
        int real1 = Integer.parseInt(num1Arr[0]);
        int imaginary1 = Integer.parseInt(num1Arr[1].substring(0, num1Arr[1].length() - 1));
        int real2 = Integer.parseInt(num2Arr[0]);
        int imaginary2 = Integer.parseInt(num2Arr[1].substring(0, num2Arr[1].length() - 1));
        int real = real1 * real2 - imaginary1 * imaginary2;
        int imaginary = real1 * imaginary2 + real2 * imaginary1;
        return real + "+" + imaginary + "i";
    }
}