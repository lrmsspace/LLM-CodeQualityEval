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
char* complexNumberMultiply(char* num1, char* num2) {
    int r1, i1, r2, i2;
    sscanf(num1, "%d+%di", &r1, &i1);
    sscanf(num2, "%d+%di", &r2, &i2);
    int r = r1 * r2 - i1 * i2;
    int i = r1 * i2 + i1 * r2;
    char *res = (char *)malloc(30 * sizeof(char));
    sprintf(res, "%d+%di", r, i);   
    return res;
}