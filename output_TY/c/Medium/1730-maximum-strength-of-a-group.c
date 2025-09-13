/**https://leetcode.com/problems/maximum-strength-of-a-group/ */
//You are given a 0-indexed integer array nums representing the score of students in an exam. The teacher would like to form one non-empty group of students with maximal strength, where the strength of a group of students of indices i0, i1, i2, ... , ik is defined as nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​].
//Return the maximum strength of a group the teacher can create.
// 
//Example 1:
//Input: nums = [3,-1,-5,2,5,-9]
//Output: 1350
//Explanation: One way to form a group of maximal strength is to group the students at indices [0,2,3,4,5]. Their strength is 3 * (-5) * 2 * 5 * (-9) = 1350, which we can show is optimal.
//Example 2:
//Input: nums = [-4,-5,-4]
//Output: 20
//Explanation: Group the students at indices [0, 1] . Then, we’ll have a resulting strength of 20. We cannot achieve greater strength.
// 
//Constraints:
//	1 <= nums.length <= 13
//	-9 <= nums[i] <= 9
long long maxStrength(int* nums, int numsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a, b, c, d, e, f, g, h,

        max = 0;
    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            for (k = j + 1; k < numsSize; k++) {
                for (l = k + 1; l < numsSize; l++) {
                    for (m = l + 1; m < numsSize; m++) {
                        for (n= m + 1; n < numsSize; n++) {
                            for (o = n + 1; o < numsSize; o++) {
                                for (p = o + 1; p < numsSize; p++) {
                                    for (q = p + 1; q < numsSize; q++) {
                                        for (r = q + 1; r < numsSize; r++) {
                                            for (s = r + 1; s < numsSize; s++) {
                                                for (t = s + 1; t < numsSize; t++) {
                                                    for (u = t + 1; u < numsSize; u++) {
                                                        for (v = u + 1; v < numsSize; v++) {
                                                            for (w = v + 1; w < numsSize; w++) {
                                                                for (x = w + 1; x < numsSize; x++) {
                                                                    for (y = x + 1; y < numsSize; y++) {
                                                                        for (z = y + 1; z < numsSize; z++) {
                                                                            a = nums[i] * nums[j] * nums[k] * nums[l] * nums[m] * nums[n] * nums[o] * nums[p] * nums[q] * nums[r] * nums[s] * nums[t] * nums[u] * nums[v] * nums[w] * nums[x] * nums[y] * nums[z];
                                                                            if (a > max) {
                                                                                max = a;
                                                                            }
                                                                            if (a < 0) {
                                                                                a = -a;
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
    return max;
}