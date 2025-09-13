/**https://leetcode.com/problems/frog-jump-ii/ */
//You are given a 0-indexed integer array stones sorted in strictly increasing order representing the positions of stones in a river.
//A frog, initially on the first stone, wants to travel to the last stone and then return to the first stone. However, it can jump to any stone at most once.
//The length of a jump is the absolute difference between the position of the stone the frog is currently on and the position of the stone to which the frog jumps.
//	More formally, if the frog is at stones[i] and is jumping to stones[j], the length of the jump is |stones[i] - stones[j]|.
//The cost of a path is the maximum length of a jump among all jumps in the path.
//Return the minimum cost of a path for the frog.
// 
//Example 1:
//Input: stones = [0,2,5,6,7]
//Output: 5
//Explanation: The above figure represents one of the optimal paths the frog can take.
//The cost of this path is 5, which is the maximum length of a jump.
//Since it is not possible to achieve a cost of less than 5, we return it.
//Example 2:
//Input: stones = [0,3,9]
//Output: 9
//Explanation: 
//The frog can jump directly to the last stone and come back to the first stone. 
//In this case, the length of each jump will be 9. The cost for the path will be max(9, 9) = 9.
//It can be shown that this is the minimum achievable cost.
// 
//Constraints:
//	2 <= stones.length <= 105
//	0 <= stones[i] <= 109
//	stones[0] == 0
//	stones is sorted in a strictly increasing order.
int maxJump(int* stones, int stonesSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[stonesSize], b[stonesSize], c[stonesSize], d[stonesSize], e[stonesSize], f[stonesSize], g[stonesSize], h[stonesSize], i[stonesSize], j[stonesSize], k[stonesSize], l[stonesSize], m[stonesSize], n[stonesSize], o[stonesSize], p[stonesSize], q[stonesSize], r[stonesSize], s[stonesSize], t[stonesSize], u[stonesSize], v[stonesSize], w[stonesSize], x[stonesSize], y[stonesSize], z[stonesSize];
    for (i = 0; i < stonesSize; i++) {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
        d[i] = 0;
        e[i] = 0;
        f[i] = 0;
        g[i] = 0;
        h[i] = 0;
        i[i] = 0;
    }
    for (i = 0; i < stonesSize; i++) {
        for (j = 0; j < stonesSize; j++) {
            if (stones[i] + stones[j] == stones[i + 1]) {
                a[i + 1] = a[i] + 1;
            }
            if (stones[i] + stones[j] == stones[i + 2]) {
                b[i + 2] = b[i] + 1;
            }
        }
    }
    for (i = 0; i < stonesSize; i++) {
        for (j = 0; j < stonesSize; j++) {
            if (stones[i] + stones[j] == stones[i + 3]) {
                c[i + 3] = c[i] + 1;
            }
        }
    }
    for (i = 0; i < stonesSize; i++) {
        for (j = 0; j < stonesSize; j++) {
            if (stones[i] + stones[j] == stones[i + 4]) {
                d[i + 4] = d[i] + 1;
            }
        }
    }
    for (i = 0; i < stonesSize; i++) {
        for (j = 0; j < stonesSize; j++) {
            if (stones[i] + stones[j] == stones[i + 5]) {
                e[i + 5] = e[i] + 1;
            }
        }
    }
    for (i = 0; i < stonesSize; i++) {
        for (j = 0; j < stonesSize; j++) {
            if (stones[i] + stones[j] == stones[i + 6]) {
                f[i + 6] = f[i] + 1;
            }
        }
    }
    for (i = 0; i < stonesSize; i++) {
        for (j = 0; j < stonesSize; j++) {
            if (stones[i] + stones[j] == stones[i + 7]) {
                g[i + 7] = g[i] + 1;
            }
        }
    }
    for (i = 0; i < stonesSize; i++) {
        for (j = 0; j < stonesSize; j++) {
            if (stones[i] + stones[j] == stones[i + 8]) {
                h[i + 8] = h[i] + 1;
            }
        }
    }
    for (i = 0; i < stonesSize; i++) {
        for (j = 0; j < stonesSize; j++) {
            if (stones[i] + stones[j] == stones[i + 9]) {
                i[i + 9] = i[i] + 1;
            }
        }
    }
    return 0;
}