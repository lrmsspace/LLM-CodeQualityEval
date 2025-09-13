/**https://leetcode.com/problems/permutations-ii/ */
//Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
// 
//Example 1:
//Input: nums = [1,1,2]
//Output:
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
//Example 2:
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//Constraints:
//	1 <= nums.length <= 8
//	-10 <= nums[i] <= 10
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int* a = (int*)malloc(sizeof(int) * numsSize);
    int* b = (int*)malloc(sizeof(int) * numsSize);
    int* c = (int*)malloc(sizeof(int) * numsSize);
    int*d = (int*)malloc(sizeof(int));
    *d = 1;
    for (i = 0; i < numsSize; i++) {
        a[i] = nums[i];
        b[i] = 0;
        c[i] = 0;
    }
    for (i = 0; i < numsSize; i++) {
        for (j = 0; j < numsSize; j++) {
            if (b[j] == 0) {
                for (k = 0; k < numsSize; k++) {
                    if (c[k] == 0) {
                        for (l = 0; l < numsSize; l++) {
                            if(b[l] == 0) {
                                for (m = 0; m < numsSize; m++) {
                                    if (c[m] == 0) {
                                        for (n = 0; n < numsSize; n++) {
                                            if (b[n] == 0) {
                                                for (o = 0; o < numsSize; o++) {
                                                    if (c[o] == 0) {
                                                        for (p = 0; p < numsSize; p++) {
                                                            if (b[p] == 0) {
                                                                for (q = 0; q < numsSize; q++) {
                                                                    if (c[q] == 0) {
                                                                        for (r = 0; r < numsSize; r++) {
                                                                           if (b[r] == 0) {
                                                                              for (s = 0; s < numsSize; s++) {
                                                                               if (c[s] == 0) {
                                                                                   for (t = 0; t < numsSize; t++) {
                                                                                       if (b[t] == 0) {
                                                                                           for (u = 0; u < numsSize; u++) {
                                                                                            if (c[u] == 0) {
                                                                                           for (v = 0; v < numsSize; v++) {
                                                                                               if (b[v] == 0) {
                                                                                                   for (w = 0; w < numsSize; w++) {
                                                                                                       if (c[w] == 0) {
                                                                                                        for (x = 0; x < numsSize; x++) {
                                                                                                            if (c[x] == 0) {
                                                                                                                for (y = 0; y < numsSize; y++) {
                                                                                                                    if (c[y] == 0) {
                                                                                                                        for (z = 0;z < numsSize; z++) {
                                                                                                                            if (c[z] == 0) {
                                                                                                                int* e = (int*)malloc(sizeof(int) * numsSize);
                                                                                                                int* f = (int*)malloc(sizeof(int) * numsSize);
                                                                                                                int* g = (int*)malloc(sizeof(int) * numsSize);
                                                                                                               int* h = (int*)m
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                       }
                                                                                                   }
                                                                                               }
                                                                                           }
                                                                                            }
                                                                                           }
                                                                                       }
                                                                                   }
                                                                               }
                                                                              }
                                                                           }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}