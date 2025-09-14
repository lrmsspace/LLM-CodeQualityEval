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
    int fact[n];
    fact[0] = 1;
    for (int i = 1; i < n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    k -= 1;
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int nums[n];
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        int index = k / fact[i];
        result[n - i - 1] = nums[index] + '0';
        k %= fact[i];
        for (int j = index; j < n - 1; j++) {
            nums[j] = nums[j + 1];
        }
    }
    result[n] = '\0';
    return result;
}