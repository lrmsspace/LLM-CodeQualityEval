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
/**
 * @param {number} n
 * @param {number[][]} languages
 * @param {number[][]} friendships
 * @return {number}
 */
var minimumTeachings = function(n, languages, friendships) {
    // Build adjacency list for friendships
    let friends = Array.from({length: n}, () => new Set());
    for (let [u, v] of friendships) {
        friends[u - 1].add(v - 1);
        friends[v - 1].add(u - 1);
    }
    
    // Count languages spoken by each user
    let speaks = Array.from({length: n}, () => new Set());
    for (let i = 0; i < n; i++) {
        for (let lang of languages[i]) {
            speaks[i].add(lang - 1);
        }
    }
    
    // Count languages spoken by each friend
    let friendsSpeaks = Array.from({length: n}, () => new Set());
    for (let i = 0; i < n; i++) {
        for (let friend of friends[i]) {
            for (let lang of languages[i]) {
                friendsSpeaks[friend].add(lang - 1);
            }
        }
    }
    
    // Count languages that can be taught by a user
    let taughtBy = Array.from({length: n}, () => new Set());
    for (let i = 0; i < n; i++) {
        for (let friend of friends[i]) {
            for (let lang of friendsSpeaks[friend]) {
                if (!speaks[i].has(lang)) {
                    taughtBy[i].add(lang);
                }
            }
        }
    }
    
    // Count users that can be taught by a language
    let taughtTo = Array.from({length: n}, () => 0);
    for (let i = 0; i < n; i++) {
        for (let lang of taughtBy[i]) {
            taughtTo[lang]++;
        }
    }
    
    // Count users that can be taught by at least one language
    let taughtToAtLeastOne = 0;
    for (let i = 0; i < n; i++) {
        if (taughtTo[i] > 0) {
            taughtToAtLeastOne++;
        }
    }
    
    return n - taughtToAtLeastOne;
    
};