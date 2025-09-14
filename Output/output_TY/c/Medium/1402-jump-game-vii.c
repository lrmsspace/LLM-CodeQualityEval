/**https://leetcode.com/problems/jump-game-vii/ */
//You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:
//	i + minJump <= j <= min(i + maxJump, s.length - 1), and
//	s[j] == '0'.
//Return true if you can reach index s.length - 1 in s, or false otherwise.
// 
//Example 1:
//Input: s = "011010", minJump = 2, maxJump = 3
//Output: true
//Explanation:
//In the first step, move from index 0 to index 3. 
//In the second step, move from index 3 to index 5.
//Example 2:
//Input: s = "01101110", minJump = 2, maxJump = 3
//Output: false
// 
//Constraints:
//	2 <= s.length <= 105
//	s[i] is either '0' or '1'.
//	s[0] == '0'
//	1 <= minJump <= maxJump < s.length
bool canReach(char * s, int minJump, int maxJump){
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s1 = 0, t = 0, u = 0, v = 0, w = 0, x = 0, y = 0, z = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i1 = 0, j1 = 0, k1 = 0, l1 = 0, m1 = 0, n1 = 0, o1 = 0, p1 = 0, q1 = 0, r1 = 0, s2 = 0, t1 = 0, u1 = 0, v1 = 0, w1 = 0, x1 = 0, y1 = 0, z1 = 0;
    int a1 = 0, b1 = 0, c1 = 0, d1 = 0, e1 = 0, f1 = 0, g1 = 0, h1 = 0, i2 = 0, j2 = 0, k2 = 0, l2 = 0, m2 = 0, n2 = 0, o2 = 0, p2 = 0, q2 = 0, r2 = 0, s3 = 0, t2 = 0  , u2 = 0, v2 = 0, w2 = 0, x2 = 0, y2 = 0, z2 = 0;
    while (s[i] != '\0') {
        if (s[i] == '0') {
            j = i + minJump;
            k = i + maxJump;
            if (j > k) {
                return false;
            }
            while (j <= k) {
                if (s[j] == '1') {
                    j++;
                    continue;
                }
                if(j == k) {
                    return true;
                }
            }
        }
    }
    return false;
}