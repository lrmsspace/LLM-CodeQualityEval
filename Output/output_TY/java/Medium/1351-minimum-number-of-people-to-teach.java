/**https://leetcode.com/problems/minimum-number-of-people-to-teach/ */
//On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.
//You are given an integer n, an array languages, and an array friendships where:
//	There are n languages numbered 1 through n,
//	languages[i] is the set of languages the i​​​​​​th​​​​ user knows, and
//	friendships[i] = [u​​​​​​i​​​, v​​​​​​i] denotes a friendship between the users u​​​​​​​​​​​i​​​​​ and vi.
//You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.
//Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.
// 
//Example 1:
//Input: n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
//Output: 1
//Explanation: You can either teach user 1 the second language or user 2 the first language.
//Example 2:
//Input: n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
//Output: 2
//Explanation: Teach the third language to users 1 and 3, yielding two users to teach.
// 
//Constraints:
//	2 <= n <= 500
//	languages.length == m
//	1 <= m <= 500
//	1 <= languages[i].length <= n
//	1 <= languages[i][j] <= n
//	1 <= u​​​​​​i < v​​​​​​i <= languages.length
//	1 <= friendships.length <= 500
//	All tuples (u​​​​​i, v​​​​​​i) are unique
//	languages[i] contains only unique values
class Solution {
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        int[] lang = new int[n + 1];
        for (int[] f : friendships) {
            int u = f[0], v = f[1];
            if (lang[u] == 0 && lang[v] == 0) {
                int l = languages[u - 1][0];
                for (int i = 1; i < languages[u - 1].length; i++) {
                    l |= languages[u - 1][i];
                }
                for (int i = 0; i < languages[v - 1].length; i++) {
                    if ((l & languages[v - 1][i]) != 0) {
                       lang[u] = 1;
                    }
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (lang[j + 1] == 0) {
                    continue;
                }
                int l = languages[j][0];
                for (int k = 1; k < languages[j].length; k++) {
                    l |= languages[j][k];
                }
                if ((l & i) == 0) {
                    cnt++;
                }
            }
            ans = Math.min(ans, cnt);
        }
        return ans;
    }
}