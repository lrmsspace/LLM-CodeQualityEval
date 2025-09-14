/**https://leetcode.com/problems/find-players-with-zero-or-one-losses/ */
//You are given an integer array matches where matches[i] = [winneri, loseri] indicates that the player winneri defeated player loseri in a match.
//Return a list answer of size 2 where:
//	answer[0] is a list of all players that have not lost any matches.
//	answer[1] is a list of all players that have lost exactly one match.
//The values in the two lists should be returned in increasing order.
//Note:
//	You should only consider the players that have played at least one match.
//	The testcases will be generated such that no two matches will have the same outcome.
// 
//Example 1:
//Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
//Output: [[1,2,10],[4,5,7,8]]
//Explanation:
//Players 1, 2, and 10 have not lost any matches.
//Players 4, 5, 7, and 8 each have lost one match.
//Players 3, 6, and 9 each have lost two matches.
//Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
//Example 2:
//Input: matches = [[2,3],[1,3],[5,4],[6,4]]
//Output: [[1,2,5,6],[]]
//Explanation:
//Players 1, 2, 5, and 6 have not lost any matches.
//Players 3 and 4 each have lost two matches.
//Thus, answer[0] = [1,2,5,6] and answer[1] = [].
// 
//Constraints:
//	1 <= matches.length <= 105
//	matches[i].length == 2
//	1 <= winneri, loseri <= 105
//	winneri != loseri
//	All matches[i] are unique.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findWinners(int** matches, int matchesSize, int* matchesColSize, int* returnSize, int** returnColumnSizes) {
    int* win = (int*)calloc(100001, sizeof(int));
    int* lose = (int*)calloc(100001, sizeof(int));
    for (int i = 0; i < matchesSize; i++) {
        win[matches[i][0]]++;
        lose[matches[i][1]]++;
    }
    int* ans0 = (int*)malloc(100001 * sizeof(int));
    int* ans1 = (int*)malloc(100001 * sizeof(int));
    int count0 = 0, count1 = 0;
    for (int i = 1; i <= 100000; i++) {
        if (win[i] > 0 && lose[i] == 0) {
            ans0[count0++] = i;
        }
        if (lose[i] == 1) {
            ans1[count1++] = i;
        }
    }
    int** ans = (int**)malloc(2 * sizeof(int*));
    ans[0] = ans0;
    ans[1] = ans1;
    *returnSize = 2;
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = count0;
    (*returnColumnSizes)[1] = count1;
    return ans;
}