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
int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize, int** friendships, int friendshipsSize, int* friendshipsColSize){
    int i, j, k, l, m, n1, n2, cnt, ans, *lang, *lang1, *lang2;
    ans = INT_MAX;
    for (i = 0; i < friendshipsSize; i++) {
        n1 = friendships[i][0];
        n2 = friendships[i][1];
        lang1 = languages[n1 - 1];
        lang2 = languages[n2 - 1];
        cnt = 0;
        for (j = 0; j < languagesColSize[n2 - 1]; j++) {
            for (k = 0; k < languagesColSize[n1 - 1]; k++) {
                if (lang1[k] == lang2[j]) {
                    cnt++;
                    break;
                }
            }
        }
    }

    for (i = 0; i < languagesSize; i++) {
        lang = languages[i];
        cnt = 0;
        for (j = 0; j < friendshipsSize; j++) {
            n1 = friendships[j][0];
            n2 = friendships[j][1];
            lang1 = languages[n1 - 1];
            lang2 = languages[n2 - 1];
            for (k = 0; k < languagesColSize[n2 - 1]; k++) {
                for (l = 0; l < languagesColSize[n1 - 1]; l++) {
                    if (lang1[l] == lang2[k]) {
                        goto next;
                    }
                }
            }
            cnt++;
next:;
            }
        }
 
    ans = fmin(ans, cnt);
    return ans;
}