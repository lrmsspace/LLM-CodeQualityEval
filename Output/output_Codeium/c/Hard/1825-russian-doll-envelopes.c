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

static int compare(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    if (p1[0] != p2[0]) {
        return p1[0] - p2[0];
    }
    return p1[1] - p2[1];
}
int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    int dp[envelopesSize];
    memset(dp, 0, sizeof(dp));
    qsort(envelopes, envelopesSize, sizeof(int*), compare);
    int max = 0;
    for (int i = 0; i < envelopesSize; i++) {
        int j = 0;
        for (; j < i; j++) {
            if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                dp[i] = fmax(dp[i], dp[j] + 1);
            }
        }
        max = fmax(max, dp[i]);
    }
    return max + 1;
}   