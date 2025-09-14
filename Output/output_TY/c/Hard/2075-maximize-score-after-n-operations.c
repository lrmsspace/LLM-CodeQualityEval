/**https://leetcode.com/problems/maximize-score-after-n-operations/ */
//You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.
//In the ith operation (1-indexed), you will:
//	Choose two elements, x and y.
//	Receive a score of i * gcd(x, y).
//	Remove x and y from nums.
//Return the maximum score you can receive after performing n operations.
//The function gcd(x, y) is the greatest common divisor of x and y.
// 
//Example 1:
//Input: nums = [1,2]
//Output: 1
//Explanation: The optimal choice of operations is:
//(1 * gcd(1, 2)) = 1
//Example 2:
//Input: nums = [3,4,6,8]
//Output: 11
//Explanation: The optimal choice of operations is:
//(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
//Example 3:
//Input: nums = [1,2,3,4,5,6]
//Output: 14
//Explanation: The optimal choice of operations is:
//(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
// 
//Constraints:
//	1 <= n <= 7
//	nums.length == 2 * n
//	1 <= nums[i] <= 106
int maxScore(int* nums, int numsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[16] = {0};
    int b[16] = {0};
    int c[16] = {0};
    int d[16] = {0};
    int e[16] = {0};
    int f[16]= {0};
    for(i = 0; i < numsSize; i += 2){
        a[i / 2] = nums[i];
        b[i / 2] = nums[i + 1];
    }
    for(i = 0; i < numsSize / 2; i++){
        for(j = 0; j < numsSize / 2; j++){
            if(i == j){
                continue;
            }
            c[i * numsSize / 2 + j] = a[i] * a[j];
            d[i * numsSize / 2 + j] = a[i] * b[j];
        }
    }
    for(i = 0; i < numsSize / 2; i++){
        for(j = 0; j < numsSize / 2; j++){
            if(i == j){
                continue;
            }
            e[i * numsSize / 2 + j] = b[i] * a[j];
            f[i * numsSize / 2 + j] = b[i] * b[j];
        }
    }
    for(i = 0; i < numsSize / 2; i++){
        for(j = 0; j < numsSize / 2; j++){
            for(k = 0; k < numsSize / 2; k++){
                if(i == j || i == k || j == k){
                    continue;
                }
                x = c[i * numsSize / 2 + j] + d[i * numsSize / 2 + k];
                y = c[i * numsSize / 2 + j] + e[j * numsSize /2 + k];
            }
        }
    }
    return x > y ? x : y;
}