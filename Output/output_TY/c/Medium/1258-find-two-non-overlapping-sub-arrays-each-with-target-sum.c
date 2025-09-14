/**https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/ */
//You are given an array of integers arr and an integer target.
//You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.
//Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.
// 
//Example 1:
//Input: arr = [3,2,2,4,3], target = 3
//Output: 2
//Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.
//Example 2:
//Input: arr = [7,3,4,7], target = 7
//Output: 2
//Explanation: Although we have three non-overlapping sub-arrays of sum = 7 ([7], [3,4] and [7]), but we will choose the first and third sub-arrays as the sum of their lengths is 2.
//Example 3:
//Input: arr = [4,3,2,6,2,3,4], target = 6
//Output: -1
//Explanation: We have only one sub-array of sum = 6.
// 
//Constraints:
//	1 <= arr.length <= 105
//	1 <= arr[i] <= 1000
//	1 <= target <= 108
int minSumOfLengths(int* arr, int arrSize, int target){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[arrSize], b[arrSize], c[arrSize], d[arrSize], e[arrSize], f[arrSize], g[arrSize], h[arrSize], i1, i2, i3, i4, i5, i6, i7, i8,i9, i10, i11, i12, i13, i14;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    for (i = 0; i < arrSize; i++) {
        for (j = i; j < arrSize; j++) {
            for (k = j; k < arrSize; k++) {
                for (l = k; l < arrSize; l++) {
                    for (m = l; m < arrSize; m++) {
                        for (n = m; n < arrSize; n++) {
                            for(o = n; o < arrSize; o++) {
                                for (p = o; p < arrSize; p++) {
                                    for (q = p; q < arrSize; q++) {
                                        for (r = q; r < arrSize; r++) {
                                            for (s = r; s < arrSize; s++) {
                                                for (t = s; t < arrSize; t++) {
                                                    for (u = t; u < arrSize; u++) {
                                                        for (v = u; v < arrSize; v++) {
                                                            for (w = v; w < arrSize; w++) {
                                                                for (x = w; x < arrSize; x++) {
                                                                    for (y = x; y < arrSize; y++) {
                                                                        for (z = y; z < arrSize; z++) {
                                                                           if (arr[i] + arr[j] + arr[
                                                                            k] + arr[l] + arr[m] + arr[n] + arr[o] + arr[p] + arr[q] + arr[r] + arr[s] + arr[t] + arr[u] + arr[v] + arr[w] + arr[x] + arr[y] + arr[z] == target) {
                                                                   a[i] = 1;
                                                                            }
                                                                           ])
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
    for (i = 0; i < arrSize; i++) {
        if (a[i] == 1) {
            for (j = i; j < arrSize; j++) {
                if (a[j] == 1) {
                    for (k = j; k < arrSize; k++) {
                        if (a[k] == 1) {
                            for (l = k; l < arrSize;l++) {
                                if (a[l] == 1) {
                                    for (m = l; m < arrSize; m++) {
                                        if (a[m] == 1) {
                                            for (n = m; n < arrSize; n++) {
                                                if (a[n] == 1) {
                                                    for (o = n; o < arrSize; o++) {
                                                       if (a[o] == 1) {
                                                          for (p = o; p < arrSize; p++) {
                                                               if (a[p] == 1) {
                                                                   for (q = p; q < arrSize; q++) {
                                                                       if (a[q] == 1) {
                                                                           for (r = q; r < arrSize; r++) {
                                                                              if (a[r] == 1) {
                                                                                for (s = r; s < arrSize; s++) {
                                                                                    if (a[s] == 1) {
                                                                                        for (t = s; t < arrSize; t++) {
                                                                                            if (a[t] == 1) {
                                                                                                for (u = t; u < arrSize; u++) {
                                                                                                    if (a[u] == 1) {
                                                                                                       for (v = u; v < arrSize; v++) {
                                                                                                          if (a[v] == 1) {
                                                                                                       for (w = v; w < arrSize; w++) {
                                                                                                           if (a[w] == 1) {
                                                                                                               for (x = w; x < arrSize; x++) {
                                                                                                                   if (a[x] == 1) {
                                                                                                                    for (y = x; y < arrSize; y++) {
                                                                                                                        if (a[y] == 1) {
                                                                                                                   for (z = y; z < arrSize; z++) {
                                                                                                                       if (a[z] == 1) {
                                                                                                                           return 1;
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
    }
    return 0;
}