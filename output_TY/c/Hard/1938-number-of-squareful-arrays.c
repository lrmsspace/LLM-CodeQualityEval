/**https://leetcode.com/problems/number-of-squareful-arrays/ */
//An array is squareful if the sum of every pair of adjacent elements is a perfect square.
//Given an integer array nums, return the number of permutations of nums that are squareful.
//Two permutations perm1 and perm2 are different if there is some index i such that perm1[i] != perm2[i].
// 
//Example 1:
//Input: nums = [1,17,8]
//Output: 2
//Explanation: [1,8,17] and [17,8,1] are the valid permutations.
//Example 2:
//Input: nums = [2,2,2]
//Output: 1
// 
//Constraints:
//	1 <= nums.length <= 12
//	0 <= nums[i] <= 109
int numSquarefulPerms(int* nums, int numsSize){    
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int cnt[10] = {0}, cnt2[10][10] = {0}, cnt3[10][10][10] = {0}, cnt4[10][10][10][10] = {0}, cnt5[10][10][10][10][10] = {0};
    for (i = 0; i < numsSize; i++) {
        cnt[nums[i] % 10]++;
        cnt2[nums[i] / 10][nums[i] % 10]++;
        cnt3[nums[i] / 10][nums[i] % 10][nums[i] / 10]++;
        cnt4[nums[i] / 10][nums[i] % 10][nums[i] / 10][nums[i] % 10]++;
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 10; k++) {
                for (l = 0; l < 10; l++) {
                    for (m = 0; m < 10; m++) {
                        for (n = 0; n < 10; n++) {
                           for (o = 0; o < 10; o++) {
                            for (p = 0; p < 10; p++) {
                                for (q = 0; q < 10; q++) {
                                    for (r = 0; r < 10; r++) {
                                        for (s = 0; s < 10; s++) {
                                            for (t = 0; t < 10; t++) {
                                                for (u = 0; u < 10; u++) {
                                                    for (v = 0; v < 10; v++) {
                                                        for (w = 0; w < 10; w++) {
                                                            for (x = 0; x < 10; x++) {
                                                                for (y = 0; y < 10; y++) {
                                                                    for (z = 0; z < 10; z++) {
                                                                       if (((i + j) * (i + j))) == ((k + l) * (k + l)) &&
                                                                        ((j + k) * (j + k)) == ((m + n) * (m + n)) &&
                                                                        ((l + m) * (l + m)) == ((o + p) * (o + p)) &&
                                                                        ((n + o) * (n + o)) == ((q + r) *(q + r)) &&
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
    return 0;
}