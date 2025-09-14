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
    int i, j, t;
    int* nums = (int*)malloc(sizeof(int) * n);
    int* used = (int*)malloc(sizeof(int) * n);
    char* ret = (char*)malloc(sizeof(char) * (n + 1));
    ret[n] = '\0';
    for (i = 0; i < n; i++) {
        nums[i] = i + 1;
        used[i] = 0;
    }
    for (i = 0; i < n; i++) {
        t = factorial(n - i - 1);
        for (j = 0; j < n; j++) {
            if (!used[j]) {
                if (k > t) {
                    k -= t;
                } else {
                    used[j] = 1;
                    ret[i] = nums[j] + '0';
                    break;
                }
            }
        }
    }
    return ret;
    
}