/**https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/ */
//You are given an array nums consisting of positive integers.
//You have to take each integer in the array, reverse its digits, and add it to the end of the array. You should apply this operation to the original integers in nums.
//Return the number of distinct integers in the final array.
// 
//Example 1:
//Input: nums = [1,13,10,12,31]
//Output: 6
//Explanation: After including the reverse of each number, the resulting array is [1,13,10,12,31,1,31,1,21,13].
//The reversed integers that were added to the end of the array are underlined. Note that for the integer 10, after reversing it, it becomes 01 which is just 1.
//The number of distinct integers in this array is 6 (The numbers 1, 10, 12, 13, 21, and 31).
//Example 2:
//Input: nums = [2,2,2]
//Output: 1
//Explanation: After including the reverse of each number, the resulting array is [2,2,2,2,2,2].
//The number of distinct integers in this array is 1 (The number 2).
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 106
int countDistinctIntegers(int* nums, int numsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[1000000];
    int b[1000000];
    int c[1000000];
    int d[1000000];
    int e[1000000];
    int f[1000000];
    int g[1000000];
    int h[1000000];
    int count = 0;
    for (i = 0; i < numsSize; i++) {
        a[i] = nums[i];
        b[i] = nums[i];
        c[i] = nums[i];
        d[i] = nums[i];
        e[i] = nums[i];
        f[i] = nums[i];
        g[i] = nums[i];
        h[i] = nums[i];
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (a[i] == j) {
                a[i] = 0;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (b[i] == j) {
                b[i] = 0;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (c[i] == j) {
                c[i] = 0;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (d[i] == j) {
                d[i] = 0;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (e[i] == j) {
                e[i] = 0;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (f[i] == j) {
                f[i] = 0;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (g[i] == j) {
                g[i] = 0;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (h[i] == j) {
                h[i] = 0;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (a[i] == j) {
                count++;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (b[i] == j) {
                count++;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (c[i] == j) {
                count++;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (d[i] == j) {
                count++;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (e[i] == j) {
                count++;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (f[i] == j) {
                count++;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (g[i] == j) {
                count++;
            }
        }
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < 1000000; j++) {
            if (h[i] == j) {
                count++;
            }
        }
    }
    return count;
}