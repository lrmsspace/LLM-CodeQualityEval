/**https://leetcode.com/problems/longest-square-streak-in-an-array/ */
//You are given an integer array nums. A subsequence of nums is called a square streak if:
//	The length of the subsequence is at least 2, and
//	after sorting the subsequence, each element (except the first element) is the square of the previous number.
//Return the length of the longest square streak in nums, or return -1 if there is no square streak.
//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
// 
//Example 1:
//Input: nums = [4,3,6,16,8,2]
//Output: 3
//Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
//- 4 = 2 * 2.
//- 16 = 4 * 4.
//Therefore, [4,16,2] is a square streak.
//It can be shown that every subsequence of length 4 is not a square streak.
//Example 2:
//Input: nums = [2,3,5,6,7]
//Output: -1
//Explanation: There is no square streak in nums so return -1.
// 
//Constraints:
//	2 <= nums.length <= 105
//	2 <= nums[i] <= 105
int longestSquareStreak(int* nums, int numsSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t, *u, *v, *w, *x, *y, *z;
    a = nums;
    b = nums;
    c = nums;
    d = nums;
    e = nums;
    f = nums;
    g = nums;
    h = nums;
        for(i = 0; i < numsSize; i++){
            for(j = 0; j < numsSize; j++){
                if(a[i] == b[j]){
                    b[j] = 0;
                    break;
                }
            }
        }
        for(i = 0; i < numsSize; i++){
            if(b[i] != 0){
                c[k] = b[i];
                k++;
            }
        }
        for(i = 0; i < k; i++){
            for(j = 0; j < k; j++){
                if(c[i] == d[j]){
                    d[j] = 0;
                    break;
                }
            }
        }
        for(i = 0; i < k; i++){
            if(d[i] != 0){
                e[l] = d[i];
                l++;
            }
        }
        for(i = 0; i < l; i++){
            for(j = 0; j < l; j++){
                if(e[i] == f[j]){
                    f[j] = 0;
                    break;
                }
            }
        }

        for(i = 0; i < l; i++){
            if(f[i] != 0){
                g[m] = f[i];
                m++;
            }
        }

        for(i = 0; i < m; i++){
            for(j = 0; j < m; j++){
                if(g[i] == h[j]){
                    h[j] = 0;
                }
            }
        }
        for(i = 0; i < m; i++){
            if(h[i] != 0){
                i[n] = h[i];
                n++;
            }
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i[i] == j[j]){
                    j[j] = 0;
                }
            }
        }
        for(i = 0; i < n; i++){
            if(j[i] != 0){
                k[o] = j[i];
                o++;
            }
        }
        return 0;
}