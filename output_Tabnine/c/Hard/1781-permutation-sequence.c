/**https://leetcode.com/problems/permutation-sequence/ */
//The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
//By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//	"123"
//	"132"
//	"213"
//	"231"
//	"312"
//	"321"
//Given n and k, return the kth permutation sequence.
// 
//Example 1:
//Input: n = 3, k = 3
//Output: "213"
//Example 2:
//Input: n = 4, k = 9
//Output: "2314"
//Example 3:
//Input: n = 3, k = 1
//Output: "123"
// 
//Constraints:
//	1 <= n <= 9
//	1 <= k <= n!
char* getPermutation(int n, int k) {
    // Create a factorial array to store factorials of numbers from 1 to n
    int* fact = (int*)malloc((n + 1) * sizeof(int));
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = i * fact[i - 1];
    }
    
    // Create a string to store the permutation sequence
    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0';
    
    // Iterate from left to right in the permutation sequence
    for (int i = 1; i <= n; i++) {
        // Calculate the index of the current digit in the permutation sequence
        int index = (k - 1) / fact[n - i];
        k = k % fact[n - i];
        
        // Remove the current digit from the remaining numbers
        int* remaining = (int*)malloc((n - i) * sizeof(int));
        int j = 0;
        for (int num = 1; num <= n; num++) {
            if (num!= result[index] + 1) {
                remaining[j++] = num;
            }
        }
        
        // Replace the current digit in the result string
        result[i - 1] = remaining[index] + '0';
        
        // Free the remaining array
        free(remaining);
    }
    
    // Return the permutation sequence
    return result;
    
}