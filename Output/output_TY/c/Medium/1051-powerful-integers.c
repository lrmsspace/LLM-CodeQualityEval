/**https://leetcode.com/problems/powerful-integers/ */
//Given three integers x, y, and bound, return a list of all the powerful integers that have a value less than or equal to bound.
//An integer is powerful if it can be represented as xi + yj for some integers i >= 0 and j >= 0.
//You may return the answer in any order. In your answer, each value should occur at most once.
// 
//Example 1:
//Input: x = 2, y = 3, bound = 10
//Output: [2,3,4,5,7,9,10]
//Explanation:
//2 = 20 + 30
//3 = 21 + 30
//4 = 20 + 31
//5 = 21 + 31
//7 = 22 + 31
//9 = 23 + 30
//10 = 20 + 32
//Example 2:
//Input: x = 3, y = 5, bound = 15
//Output: [2,4,6,8,10,14]
// 
//Constraints:
//	1 <= x, y <= 100
//	0 <= bound <= 106
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* powerfulIntegers(int x, int y, int bound, int* returnSize){
    int i, j, k, l, m, n, p, q, r, s, t, u, v, w, xx, yy, zz;
    int* a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t, *u,*v, *w, *x, *y, *z;
    a = (int*)malloc(sizeof(int)*(bound+1));
    b = (int*)malloc(sizeof(int)*(bound+1));
    c = (int*)malloc(sizeof(int)*(bound+1));
    d = (int*)malloc(sizeof(int)*(bound+1));
    e = (int*)malloc(sizeof(int)*(bound+1));
    f = (int*)malloc(sizeof(int)*(bound+1));
    g = (int*)malloc(sizeof(int)*(bound+1));
    h = (int*)malloc(sizeof(int)*(bound+1));
    i = (int*)malloc(sizeof(int)*(bound+1));
    j = (int*)malloc(sizeof(int)*(bound+1));
    k = (int*)malloc(sizeof(int)*(bound+1));
    l = (int*)malloc(sizeof(int)*(bound+1));
    m = (int*)malloc(sizeof(int)*(bound+1));
    n = (int*)malloc(sizeof(int)*(bound+1));
    o = (int*)malloc(sizeof(int)*(bound+1));
    p = (int*)malloc(sizeof(int)*(bound+1));
    q = (int*)malloc(sizeof(int)*(bound+1));
    for (int i_i = 0; i_i < bound+1; i_i++) {
        h[i_i] = 0;
    }
    for (int i_i = 0; i_i < bound+1; i_i++) {
        i[i_i] = 0;
    }
    for (int i_i = 0; i_i < bound+1; i_i++) {
        j[i_i] = 0;
    }
    for (int i_i = 0; i_i < bound+1; i_i++) {
        k[i_i] = 0;
    }
    for (int i_i = 0; i_i < bound+1; i_i++) {
        p[i_i] = 0;
    }
    for (int i_i = 0; i_i < bound+1; i_i++) {
        q[i_i] = 0;
    }
    for (int i_i = 0; i_i < bound+1; i_i++) {
        r[i_i] = 0;
    }
    for (int i_i = 0; i_i < bound+1; i_i++) {
        s[i_i] = 0;
    }    
    for (int i = 1; i <= bound; i++) {
        for (int j = 1; j <= bound; j++) {
            int p = i + j;
            if (p <= bound) {
                p[p] = 1;
            }
        }
    }
    for (int i = 1; i <= bound; i++) {
        for (int j = 1; j <= bound; j++) {
            int p = i * j;
            if (p <= bound) {
                q[p] = 1;
            }
        }
    }
    for (int i = 1; i <= bound; i++) {
        if (p[i] && q[i]) {
            res[k++] = i;
        }
    }
    return res;
}