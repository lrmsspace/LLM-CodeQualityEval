/**https://leetcode.com/problems/count-unhappy-friends/ */
//You are given a list of preferences for n friends, where n is always even.
//For each person i, preferences[i] contains a list of friends sorted in the order of preference. In other words, a friend earlier in the list is more preferred than a friend later in the list. Friends in each list are denoted by integers from 0 to n-1.
//All the friends are divided into pairs. The pairings are given in a list pairs, where pairs[i] = [xi, yi] denotes xi is paired with yi and yi is paired with xi.
//However, this pairing may cause some of the friends to be unhappy. A friend x is unhappy if x is paired with y and there exists a friend u who is paired with v but:
//	x prefers u over y, and
//	u prefers x over v.
//Return the number of unhappy friends.
// 
//Example 1:
//Input: n = 4, preferences = [[1, 2, 3], [3, 2, 0], [3, 1, 0], [1, 2, 0]], pairs = [[0, 1], [2, 3]]
//Output: 2
//Explanation:
//Friend 1 is unhappy because:
//- 1 is paired with 0 but prefers 3 over 0, and
//- 3 prefers 1 over 2.
//Friend 3 is unhappy because:
//- 3 is paired with 2 but prefers 1 over 2, and
//- 1 prefers 3 over 0.
//Friends 0 and 2 are happy.
//Example 2:
//Input: n = 2, preferences = [[1], [0]], pairs = [[1, 0]]
//Output: 0
//Explanation: Both friends 0 and 1 are happy.
//Example 3:
//Input: n = 4, preferences = [[1, 3, 2], [2, 3, 0], [1, 3, 0], [0, 2, 1]], pairs = [[1, 3], [0, 2]]
//Output: 4
// 
//Constraints:
//	2 <= n <= 500
//	n is even.
//	preferences.length == n
//	preferences[i].length == n - 1
//	0 <= preferences[i][j] <= n - 1
//	preferences[i] does not contain i.
//	All values in preferences[i] are unique.
//	pairs.length == n/2
//	pairs[i].length == 2
//	xi != yi
//	0 <= xi, yi <= n - 1
//	Each person is contained in exactly one pair.
int unhappyFriends(int n, int** preferences, int preferencesSize, int* preferencesColSize, int** pairs, int pairsSize, int* pairsColSize){
    int i, j, k, l, m, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17, n18, n19, n20, n21, n22, n23, n24, n25, n26, n27, n28, n29, n30, n31,n32, n33, n34, n35, n36, n    = 0;
    int* p = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        p[i] = -1;
    }
    for (i = 0; i < pairsSize; i++) {
        n1 = pairs[i][0];
        n2 = pairs[i][1];
        p[n1] = n2;
        p[n2] = n1;
    }
    for (i = 0; i < n; i++) {

            n1 = i;
            n2 = p[i];
            for (j = 0; j < n; j++) {
                n3 = j;
                n4 = p[j];
                for (k = 0; k < n; k++) {
                    n5 = k;
                    n6 = p[k];
                    for (l = 0; l < n; l++) {
                        n7 = l;
                        n8 = p[l];
                        n9 = preferences[n1][n7];
                        n10 = preferences[n2][n8];
                        n11 = preferences[n3][n9];
                        n12 = preferences[n4][n10];
                        n13 = preferences[n5][n11];
                       n14 = preferences[n6][n12]; 
                    }
                }
            }
    }
    return n;
}
