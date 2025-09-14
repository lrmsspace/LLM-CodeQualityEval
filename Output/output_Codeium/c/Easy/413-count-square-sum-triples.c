/**https://leetcode.com/problems/count-square-sum-triples/ */
//A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
//Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.
// 
//Example 1:
//Input: n = 5
//Output: 2
//Explanation: The square triples are (3,4,5) and (4,3,5).
//Example 2:
//Input: n = 10
//Output: 4
//Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
// 
//Constraints:
//	1 <= n <= 250
int countTriples(int n) {
    int count = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            int c2 = a * a + b * b;
            int c = sqrt(c2);
            if (c <= n && c2 == c * c) {
                count++;
            }
        }
    }
    return count;
}