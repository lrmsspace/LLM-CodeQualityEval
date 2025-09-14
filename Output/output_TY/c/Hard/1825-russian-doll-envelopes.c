/**https://leetcode.com/problems/russian-doll-envelopes/ */
//You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
//One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
//Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
//Note: You cannot rotate an envelope.
// 
//Example 1:
//Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
//Output: 3
//Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
//Example 2:
//Input: envelopes = [[1,1],[1,1],[1,1]]
//Output: 1
// 
//Constraints:
//	1 <= envelopes.length <= 105
//	envelopes[i].length == 2
//	1 <= wi, hi <= 105
int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[envelopesSize], b[envelopesSize];
    for (i = 0; i < envelopesSize; i++) {
        a[i] = envelopes[i][0];
        b[i] = envelopes[i][1];
    }
   qsort(a, envelopesSize, sizeof(int), (int (*)(const void *, const void *)));
   qsort(b, envelopesSize, sizeof(int), (int (*)(const void *, const void *)));
    for (i = 0; i < envelopesSize; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (i = 0; i < envelopesSize; i++) {
        printf("%d ", b[i]);
    }   
    return 0;
}