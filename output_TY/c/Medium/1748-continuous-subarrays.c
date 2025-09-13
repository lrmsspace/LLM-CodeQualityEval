/**https://leetcode.com/problems/continuous-subarrays/ */
//You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:
//	Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
//Return the total number of continuous subarrays.
//A subarray is a contiguous non-empty sequence of elements within an array.
// 
//Example 1:
//Input: nums = [5,4,2,4]
//Output: 8
//Explanation: 
//Continuous subarray of size 1: [5], [4], [2], [4].
//Continuous subarray of size 2: [5,4], [4,2], [2,4].
//Continuous subarray of size 3: [4,2,4].
//Thereare no subarrys of size 4.
//Total continuous subarrays = 4 + 3 + 1 = 8.
//It can be shown that there are no more continuous subarrays.
// 
//Example 2:
//Input: nums = [1,2,3]
//Output: 6
//Explanation: 
//Continuous subarray of size 1: [1], [2], [3].
//Continuous subarray of size 2: [1,2], [2,3].
//Continuous subarray of size 3: [1,2,3].
//Total continuous subarrays = 3 + 2 + 1 = 6.
// 
//Constraints:
//	1 <= nums.length <= 105
//	1 <= nums[i] <= 109
long long continuousSubarrays(int* nums, int numsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    long long ans = 0;
    for (i = 0; i < numsSize; i++) {
        for (j = i; j < numsSize; j++) {
            for (k = i; k <= j; k++) {
                for (l = k; l <= j; l++) {
                    for (m = i; m <= j; m++) {
                        for (n = m; n <= j; n++) {
                            for (o = i; o <= j; o++) {
                                for (p = o; p <= j; p++) {
                                    for (q = i; q <= j; q++) {
                                        for (r = q; r <= j; r++) {
                                            for(s = i; s <= j; s++) {
                                                for (t = s; t <= j; t++) {
                                                    for (u = i; u <= j; u++) {
                                                        for (v = u; v <= j; v++) {
                                                            for (w = i; w <= j; w++) {
                                                                for (x = w; x <= j; x++) {
                                                                    for (y = i; y<= j; y++) {
                                                                        for (z = y; z <= j; z++) {
                                                                            if (abs(nums[k] - nums[l]) <= 2 && abs(nums[m] - nums[n]) <= 2 && abs(nums[o] - nums[p]) <= 2 && abs(nums[q] - nums[r]) <= 2 && abs(nums[s] - nums[t])<= 2 && abs(nums[u] - nums[v]))   ans++;
                                                                            return ans;
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
    return ans;
}