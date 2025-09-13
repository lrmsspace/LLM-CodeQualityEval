/**https://leetcode.com/problems/smallest-good-base/ */
//Given an integer n represented as a string, return the smallest good base of n.
//We call k >= 2 a good base of n, if all digits of n base k are 1's.
// 
//Example 1:
//Input: n = "13"
//Output: "3"
//Explanation: 13 base 3 is 111.
//Example 2:
//Input: n = "4681"
//Output: "8"
//Explanation: 4681 base 8 is 11111.
//Example 3:
//Input: n = "1000000000000000000"
//Output: "999999999999999999"
//Explanation: 1000000000000000000 base 999999999999999999 is 11.
// 
//Constraints:
//	n is an integer in the range [3, 1018].
//	n does not contain any leading zeros.
char* smallestGoodBase(char* n) {
    long long num = atoll(n); // Convert the input string to a long long integer

    // Iterate through possible base values from 2 to num - 1
    for (long long base = 2; base < num; base++) {
        long long sum = 1, product = 1;

        // Check if the current base value satisfies the good base condition
        while (product < num) {
            product *= base;
            sum += product;
        }

        // If the sum of the series is equal to the input number, we have found the smallest good base
        if (sum == num) {
            char* result = (char*)malloc(20 * sizeof(char)); // Allocate memory for the result string
            sprintf(result, "%lld", base); // Convert the base value to a string and store it in the result
            return result;
        }
    }
    return NULL;
    
}