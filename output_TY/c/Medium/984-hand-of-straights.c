/**https://leetcode.com/problems/hand-of-straights/ */
//Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
//Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
// 
//Example 1:
//Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
//Output: true
//Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
//Example 2:
//Input: hand = [1,2,3,4,5], groupSize = 4
//Output: false
//Explanation: Alice's hand can not be rearranged into groups of 4.
// 
//Constraints:
//	1 <= hand.length <= 104
//	0 <= hand[i] <= 109
//	1 <= groupSize <= hand.length
// 
//Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
bool isNStraightHand(int* hand, int handSize, int groupSize){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[10000], b[10000], c[10000], d[10000], e[10000], f[10000], g[10000], h[10000], jj, kk, ll, mm, nn, oo, pp, qq, rr, ss, tt, uu, vv, ww, xx, yy, zz;
    for (i = 0; i < 10000; i++) a[i] = 0;
    for (i = 0; i < handSize; i++) a[hand[i]]++;
    for (i = 0; i < 10000; i++) {
        if (a[i] > 0) {
            for (j = i + 1; j < 10000; j++) {
                if (a[j] > 0) {
                    for (k = j + 1; k < 10000; k++) {
                        if (a[k] > 0) {
                            if (a[i] >= a[j] + a[k]) {
                                a[i] -= a[j] + a[k];
                                a[j] = a[k] = 0;
                            }
                        }
                    }
                }
            }
        }
    }   
    return a[0] == 0;
}