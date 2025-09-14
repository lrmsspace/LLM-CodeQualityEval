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
    //Split num1 and num2 into real and imaginary parts
    char* real1 = strtok(num1, "+");
    char* imaginary1 = strtok(NULL, "i");
    char* real2 = strtok(num2, "+");
    char* imaginary2 = strtok(NULL, "i");
    
    //Parse real and imaginary parts into integers
    int r1 = atoi(real1);
    int i1 = atoi(imaginary1);
    int r2 = atoi(real2);
    int i2 = atoi(imaginary2);
    
    //Calculate the real and imaginary parts of the multiplication
    int real = r1 * r2 - i1 * i2;
    int imaginary = r1 * i2 + r2 * i1;
    
    //Convert the result back into a complex number string
    char* result = malloc(sizeof(char) * 30);
    sprintf(result, "%d+%di", real, imaginary);
    
    return result;
    
}