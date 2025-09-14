/**https://leetcode.com/problems/custom-sort-string/ */
//You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
//Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
//Return any permutation of s that satisfies this property.
// 
//Example 1:
//Input: order = "cba", s = "abcd"
//Output: "cbad"
//Explanation: 
//"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
//Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
//Example 2:
//Input: order = "cbafg", s = "abcd"
//Output: "cbad"
// 
//Constraints:
//	1 <= order.length <= 26
//	1 <= s.length <= 200
//	order and s consist of lowercase English letters.
//	All the characters of order are unique.
char * customSortString(char * order, char * s){
    int i, j, k, l, m, n, o, p, q, r, t, u, v, w, x, y, z;
    int a[26] = {0};
    char *p = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    for (i = 0; i < strlen(s); i++) a[s[i] - 'a']++;    
    p[0] = '\0';
    for (i = 0; i < strlen(order); i++) {
        for (j = 0; j < strlen(s); j++) {
            if (order[i] == s[j]) {
                for (k = 0; k < a[s[j] - 'a']; k++) {
                    strcat(p, &s[j]);
                }
                a[s[j] - 'a'] = 0;
            }
        }
    }   
    return p;

}