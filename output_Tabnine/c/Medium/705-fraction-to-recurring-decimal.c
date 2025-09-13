/**https://leetcode.com/problems/fraction-to-recurring-decimal/ */
//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//If the fractional part is repeating, enclose the repeating part in parentheses.
//If multiple answers are possible, return any of them.
//It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
// 
//Example 1:
//Input: numerator = 1, denominator = 2
//Output: "0.5"
//Example 2:
//Input: numerator = 2, denominator = 1
//Output: "2"
//Example 3:
//Input: numerator = 4, denominator = 333
//Output: "0.(012)"
// 
//Constraints:
//	-231 <= numerator, denominator <= 231 - 1
//	denominator != 0
char* fractionToDecimal(int numerator, int denominator) {
    // Initialize result
    char *result = (char *)malloc(sizeof(char) * 104);
    
    // Handle negative numbers
    bool isNegative = (numerator < 0) ^ (denominator < 0);
    numerator = abs(numerator);
    denominator = abs(denominator);
    
    // Get integer part
    sprintf(result, "%s", isNegative? "-" : "");
    sprintf(result + strlen(result), "%d", numerator / denominator);
    
    // If denominator is 1, return result
    if (denominator == 1) {
        return result;
    }
    
    // Check for fractional part
    sprintf(result + strlen(result), ".");
    numerator %= denominator;
    
    // Initialize hash map to store recurring decimal digits
    int *hashMap = (int *)calloc(1000, sizeof(int));
    int hashMapIndex = 0;
    
    // Store recurring decimal digits in result
    while (numerator!= 0) {
        // If recurring decimal found, enclose it in parentheses
        if (hashMap[numerator]) {
            sprintf(result + strlen(result), "(%s)", result + hashMap[numerator]);
            break;
        }
        
        // Store current digit in hash map
        hashMap[numerator] = hashMapIndex;
        hashMapIndex++;
        
        // Calculate next digit
        numerator *= 10;
        sprintf(result + strlen(result), "%d", numerator / denominator);
        numerator %= denominator;
    }
    
    // Free hash map memory
    free(hashMap);
    
    return result;
    
}