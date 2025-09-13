/**https://leetcode.com/problems/maximum-score-of-a-node-sequence/ */
//There is an undirected graph with n nodes, numbered from 0 to n - 1.
//You are given a 0-indexed integer array scores of length n where scores[i] denotes the score of node i. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
//A node sequence is valid if it meets the following conditions:
//	There is an edge connecting every pair of adjacent nodes in the sequence.
//	No node appears more than once in the sequence.
//The score of a node sequence is defined as the sum of the scores of the nodes in the sequence.
//Return the maximum score of a valid node sequence with a length of 4. If no such sequence exists, return -1.
// 
//Example 1:
//Input: scores = [5,2,9,8,4], edges = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
//Output: 24
//Explanation: The figure above shows the graph and the chosen node sequence [0,1,2,3].
//The score of the node sequence is 5 + 2 + 9 + 8 = 24.
//It can be shown that no other node sequence has a score of more than 24.
//Note that the sequences [3,1,2,0] and [1,0,2,3] are also valid and have a score of 24.
//The sequence [0,3,2,4] is not valid since no edge connects nodes 0 and 3.
//Example 2:
//Input: scores = [9,20,6,4,11,12], edges = [[0,3],[5,3],[2,4],[1,3]]
//Output: -1
//Explanation: The figure above shows the graph.
//There are no valid node sequences of length 4, so we return -1.
// 
//Constraints:
//	n == scores.length
//	4 <= n <= 5 * 104
//	1 <= scores[i] <= 108
//	0 <= edges.length <= 5 * 104
//	edges[i].length == 2
//	0 <= ai, bi <= n - 1
//	ai != bi
//	There are no duplicate edges.
int maximumScore(int* scores, int scoresSize, int** edges, int edgesSize, int* edgesColSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[scoresSize][scoresSize];
    int b[scoresSize][scoresSize];
    int c[scoresSize][scoresSize];
    int d[scoresSize][scoresSize];
    int e[scoresSize][scoresSize];
    int f[scoresSize][scoresSize];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    memset(e, 0, sizeof(e));
    memset(f, 0, sizeof(f));
    for (i = 0; i < edgesSize; i++) {
        a[edges[i][0]][edges[i][1]] = 1;
    }
    for (i = 0; i < scoresSize; i++) {
        for (j = 0; j < scoresSize; j++) {
            if (i == j) {
                continue;
            }
            for (k = 0; k < scoresSize; k++) {
                if (k == i || k == j) {
                    continue;
                }
                if (a[i][k] && a[k][j]) {
                    b[i][j] = scores[k];
                }
            }
        }
    }
    for (i = 0; i < scoresSize; i++) {
        for (j = 0; j < scoresSize; j++) {
            if (i == j) {
                continue;
            }
            for (k = 0; k < scoresSize; k++) {
                if (k == i || k == j) {
                    continue;
                }
                for (l = 0; l < scoresSize;l++) {
                    if (l == i || l == j || l == k) {
                        continue;
                    }
                }
            }
        }
    }
    for (i = 0; i < scoresSize; i++) {
        for (j = 0; j < scoresSize; j++) {
            if (i == j) {
                continue;
            }
            for (k = 0; k < scoresSize; k++) {
                if (k == i || k == j) {
                    continue;
                }
                for (l = 0; l < scoresSize;l++) {
                    if (l == i || l == j || l == k) {
                        continue;
                    }
                }
            }
        }
    }
    for (i = 0; i < scoresSize; i++) {
        for (j = 0; j < scoresSize; j++) {
            if (i == j) {
                continue;
            }
            for (k = 0; k < scoresSize; k++) {
                if (k == i || k == j) {
                    continue;
                }
                for (l = 0; l < scoresSize;l++) {
                    if (l == i || l == j || l== k) {
                        continue;
                    }
                }
            }
        }
    }
    for (i = 0; i < scoresSize; i++) {
        for (j = 0; j < scoresSize; j++) {
            if (i == j) {
                continue;
            }
            for (k = 0; k < scoresSize; k++) {
                if (k == i || k == j) {
                    continue;
                }
                for (l = 0; l < scoresSize;l++) {
                    if (l == i || l == j || l == k) {
                        continue;
                    }
                }
            }
        }
    }
    for (i = 0; i < scoresSize; i++) {
        for (j = 0; j < scoresSize; j++) {
            if (i == j) {
                continue;
            }
            for (k = 0; k < scoresSize; k++) {
                if (k == i || k == j) {
                    continue;
                }
                for (l = 0; l < scoresSize;l++) {
                    if (l == i || l == j || l == k) {
                        continue;
                    }
                    for (m = 0; m < scoresSize; m++) {
                        if (m == i || m == j || m == k || m == l) {
                            continue;
                        }
                    }
                    for (n = 0; n < scoresSize; n++) {
                        if (n == i || n == j || n == k || n == l) {
                            continue;
                        }
                    }
                    for (o = 0; o < scoresSize; o++) {
                        if (o == i || o == j || o == k || o == l) {
                            continue;
                        }
                    }
                    for (p = 0; p < scoresSize; p++) {
                        if (p == i || p == j || p == k || p == l) {
                            continue;
                        }
                    }
                    for (q = 0; q < scoresSize; q++) {
                        if (q == i || q == j || q == k || q == l) {
                            continue;
                        }
                    }
                    for (r = 0; r < scoresSize; r++) {
                        if (r == i || r == j || r == k || r == l) {
                            continue;
                        }
                    }
                    for (s = 0; s < scoresSize; s++) {
                        if (s == i || s == j || s == k || s == l) {
                            continue;
                        }
                    }
                    for (t = 0; t < scoresSize; t++) {
                        if (t == i || t == j || t == k || t == l) {
                            continue;
                        }
                    }
                    for (u = 0; u < scoresSize; u++) {
                        if (u == i || u == j || u == k || u == l) {
                            continue;
                        }
                    }
                    for (v = 0; v < scoresSize; v++) {
                        if (v == i || v == j || v == k || v == l) {
                            continue;
                        }
                    }
                    for (w = 0; w < scoresSize; w++) {
                        if (w == i || w == j || w == k || w == l) {
                            continue;
                        }
                    }
                    for (x = 0; x < scoresSize; x++) {
                        if (x == i || x == j || x == k || x == l) {
                            continue;
                        }
                    }
                    for (y = 0; y < scoresSize; y++) {
                        if (y == i || y == j || y == k || y == l) {
                            continue;
                        }
                    }
                    for (z = 0; z < scoresSize; z++) {
                        if (z == i || z == j || z == k || z == l) {
                            continue;
                        }
                    }
                }
            }
        }
    }
    return 0;
}