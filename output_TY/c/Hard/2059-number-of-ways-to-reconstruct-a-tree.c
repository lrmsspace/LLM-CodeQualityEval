/**https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/ */
//You are given an array pairs, where pairs[i] = [xi, yi], and:
//	There are no duplicates.
//	xi < yi
//Let ways be the number of rooted trees that satisfy the following conditions:
//	The tree consists of nodes whose values appeared in pairs.
//	A pair [xi, yi] exists in pairs if and only if xi is an ancestor of yi or yi is an ancestor of xi.
//	Note: the tree does not have to be a binary tree.
//Two ways are considered to be different if there is at least one node that has different parents in both ways.
//Return:
//	0 if ways == 0
//	1 if ways == 1
//	2 if ways > 1
//A rooted tree is a tree that has a single root node, and all edges are oriented to be outgoing from the root.
//An ancestor of a node is any node on the path from the root to that node (excluding the node itself). The root has no ancestors.
// 
//Example 1:
//Input: pairs = [[1,2],[2,3]]
//Output: 1
//Explanation: There is exactly one valid rooted tree, which is shown in the above figure.
//Example 2:
//Input: pairs = [[1,2],[2,3],[1,3]]
//Output: 2
//Explanation: There are multiple valid rooted trees. Three of them are shown in the above figures.
//Example 3:
//Input: pairs = [[1,2],[2,3],[2,4],[1,5]]
//Output: 0
//Explanation: There are no valid rooted trees.
// 
//Constraints:
//	1 <= pairs.length <= 105
//	1 <= xi < yi <= 500
//	The elements in pairs are unique.
int checkWays(int** pairs, int pairsSize, int* pairsColSize){
    int n = pairsSize;
    int m = 501;
    int i, j, k, l, x, y, cnt, ans, flag;
    int* p = (int*)malloc(sizeof(int) * m);
    int* q = (int*)malloc(sizeof(int) * m);
    int* r = (int*)malloc(sizeof(int) * m);
    int* s = (int*)malloc(sizeof(int) * m);
    for (i = 0; i < m; i++) {
        p[i] = 0;
        q[i] = 0;
        r[i] = 0;
        s[i] = 0;
    }
    for (i = 0; i < n; i++) {
        x = pairs[i][0];
        y = pairs[i][1];
        p[x]++;
        q[y]++;
        r[x] |= (1 << y);
        s[y] |= (1 << x);
    }
    for (i = 1; i < m; i++) {
        if (p[i] == 0) continue;
        for (j = 1; j < m; j++) {
            if (q[j] == 0) continue;
            if ((r[i] & (1 << j)) == 0) continue;
            if ((s[j] & (1 << i)) == 0) continue;
            cnt = 0;
            flag = 0;
            for (k = 1; k < m; k++) {
                if (p[k] == 0) continue;
            }
        }
    }
    return ans;
}