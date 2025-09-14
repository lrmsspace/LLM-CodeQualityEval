/**https://leetcode.com/problems/largest-multiple-of-three/ */
//Given an array of digits digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order. If there is no answer return an empty string.
//Since the answer may not fit in an integer data type, return the answer as a string. Note that the returning answer must not contain unnecessary leading zeros.
// 
//Example 1:
//Input: digits = [8,1,9]
//Output: "981"
//Example 2:
//Input: digits = [8,6,7,1,0]
//Output: "8760"
//Example 3:
//Input: digits = [1]
//Output: ""
// 
//Constraints:
//	1 <= digits.length <= 104
//	0 <= digits[i] <= 9 
char* largestMultipleOfThree(int* digits, int digitsSize) {
    // Sort digits in descending order
    int compare(const void* a, const void* b) {
        return *(int*)b - *(int*)a;
    }
    qsort(digits, digitsSize, sizeof(int), compare);
    
    // Calculate sum of all digits
    int sum = 0;
    for (int i = 0; i < digitsSize; i++) {
        sum += digits[i];
    }
    
    // Create arrays to store indices of digits with remainder 1 and 2
    int mod1[digitsSize];
    int mod2[digitsSize];
    int mod1Count = 0, mod2Count = 0;
    
    // Find digits with remainder 1 and 2
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] % 3 == 1) {
            mod1[mod1Count++] = i;
        } else if (digits[i] % 3 == 2) {
            mod2[mod2Count++] = i;
        }
    }
    
    // Create a boolean array to mark digits to remove
    bool* remove = (bool*)calloc(digitsSize, sizeof(bool));
    
    if (sum % 3 == 1) {
        // Remove one digit with remainder 1, or two digits with remainder 2
        if (mod1Count >= 1) {
            remove[mod1[0]] = true;
        } else if (mod2Count >= 2) {
            remove[mod2[0]] = true;
            remove[mod2[1]] = true;
        } else {
            // Cannot form a multiple of 3
            free(remove);
            char* result = (char*)malloc(1);
            result[0] = '\0';
            return result;
        }
    } else if (sum % 3 == 2) {
        // Remove one digit with remainder 2, or two digits with remainder 1
        if (mod2Count >= 1) {
            remove[mod2[0]] = true;
        } else if (mod1Count >= 2) {
            remove[mod1[0]] = true;
            remove[mod1[1]] = true;
        } else {
            // Cannot form a multiple of 3
            free(remove);
            char* result = (char*)malloc(1);
            result[0] = '\0';
            return result;
        }
    }
    
    // Create the result string
    char* result = (char*)malloc((digitsSize + 1) * sizeof(char));
    int resultIndex = 0;
    
    for (int i = 0; i < digitsSize; i++) {
        if (!remove[i]) {
            result[resultIndex++] = digits[i] + '0';
        }
    }
    
    result[resultIndex] = '\0';
    free(remove);
    
    // Handle special case: if the result starts with '0', it should be just "0"
    if (resultIndex > 0 && result[0] == '0') {
        result[1] = '\0';
        return result;
    }
    
    // Handle empty result
    if (resultIndex == 0) {
        result[0] = '\0';
    }
    
    return result;
}