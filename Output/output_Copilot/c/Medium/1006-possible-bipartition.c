/**https://leetcode.com/problems/possible-bipartition/ */
//We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
//Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.
// 
//Example 1:
//Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
//Output: true
//Explanation: The first group has [1,4], and the second group has [2,3].
//Example 2:
//Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
//Output: false
//Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
// 
//Constraints:
//	1 <= n <= 2000
//	0 <= dislikes.length <= 104
//	dislikes[i].length == 2
//	1 <= ai < bi <= n
//	All the pairs of dislikes are unique.
bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize) {
    int *group = (int *)malloc(sizeof(int) * (n + 1));
    memset(group, 0, sizeof(int) * (n + 1));
    int **dislike = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++) {
        dislike[i] = (int *)malloc(sizeof(int) * (n + 1));
        memset(dislike[i], 0, sizeof(int) * (n + 1));
    }
    for (int i = 0; i < dislikesSize; i++) {
        dislike[dislikes[i][0]][dislikes[i][1]] = 1;
        dislike[dislikes[i][1]][dislikes[i][0]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (group[i] == 0 && !dfs(dislike, group, i, 1)) {
            return false;
        }
    }
    return true;    
}