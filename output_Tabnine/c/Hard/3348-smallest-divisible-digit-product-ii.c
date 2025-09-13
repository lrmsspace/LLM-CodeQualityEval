/*
 You are given a string num which represents a positive integer, and an integer t.
 A number is called zero-free if none of its digits are 0.
 Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".
 Example 1:
 Input: num = "1234", t = 256
 Output: "1488"
 Explanation:
 The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.
 Example 2:
 Input: num = "12355", t = 50
 Output: "12355"
 Explanation:
 12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.
 Example 3:
 Input: num = "11111", t = 26
 Output: "-1"
 Explanation:
 No number greater than 11111 has the product of its digits divisible by 26.
 Constraints:
 2 <= num.length <= 2 * 105
 num consists only of digits in the range ['0', '9'].
 num does not contain leading zeros.
 1 <= t <= 1014
*/

char* smallestNumber(char* num, long long t) {


    // Convert the string to an array of integers
    int n = strlen(num);
    int* digits = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        digits[i] = num[i] - '0';
    }
    
    // Sort the digits in descending order
    qsort(digits, n, sizeof(int), compare);
    
    // Find the smallest zero-free number
    int i = 0;
    while (i < n && digits[i] == 0) {
        i++;
    }
    if (i == n) {
        return "-1"; // No zero-free number exists
    }
    
    // Calculate the product of the digits
    long long product = 1;
    for (int j = i; j < n; j++) {
        product *= digits[j];
    }
    if (product % t!= 0) {
        return "-1"; // The product of the digits is not divisible by t
    }
    else {
        // Find the smallest number greater than or equal to num with the same product
        long long smallest = 0;
        for (int k = i; k < n; k++) {
            smallest = smallest * 10 + digits[k];
        }
        
        // Convert the smallest number back to a string
        char* result = (char*)malloc((n + 1) * sizeof(char));
        sprintf(result, "%lld", smallest);
        
        return result;
    
        free(digits);
    }
    free(result);
    free(digits);
    return NULL;
    
}