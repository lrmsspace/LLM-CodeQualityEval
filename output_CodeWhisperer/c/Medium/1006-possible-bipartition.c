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
    int* group = (int*)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        group[i] = i;
    }
    for (int i = 0; i < dislikesSize; i++) {
        int a = dislikes[i][0], b = dislikes[i][1];
        if (group[a] == a) {
            group[a] = b;
        } else if (group[a] == b) {
            group[b] = a;
        } else {
            int group_a = group[a], group_b = group[b];
            for (int j = 0; j < dislikesSize; j++) {
                if (dislikes[j][0] == a && dislikes[j][1] != group_a) {
                    return false;
                }
                if (dislikes[j][0] == b && dislikes[j][1] != group_b) {
                    return false;
                }
                if (dislikes[j][1] == a && dislikes[j][0] != group_a) {
                    return false;
                }
                if (dislikes[j][1] == b && dislikes[j][0] != group_b) {
                    return false;
                }
            }
            for (int j = 1; j <= n; j++) {
                if (group[j] == group_a) {
                    group[j] = group_b;
                }
            }
        }
    }
    return true;
}