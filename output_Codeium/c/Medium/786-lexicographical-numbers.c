/**https://leetcode.com/problems/lexicographical-numbers/ */
//Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
//You must write an algorithm that runs in O(n) time and uses O(1) extra space. 
// 
//Example 1:
//Input: n = 13
//Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
//Example 2:
//Input: n = 2
//Output: [1,2]
// 
//Constraints:
//	1 <= n <= 5 * 104
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* lexicalOrder(int n, int* returnSize) { 
    int* res = (int*)malloc(n * sizeof(int));
    int idx = 1, base = 1;
    *returnSize = n;
    while (idx <= n) {
        res[idx - 1] = base;
        if (base * 10 <= n) {
            base *= 10;
        } else {
            while (base % 10 == 9 || base + 1 > n) base /= 10;
            base++;
        }
        idx++;
    }
    return res;
}