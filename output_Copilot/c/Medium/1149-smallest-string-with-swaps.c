/**https://leetcode.com/problems/smallest-string-with-swaps/ */
//You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
//You can swap the characters at any pair of indices in the given pairs any number of times.
//Return the lexicographically smallest string that s can be changed to after using the swaps.
// 
//Example 1:
//Input: s = "dcab", pairs = [[0,3],[1,2]]
//Output: "bacd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[1] and s[2], s = "bacd"
//Example 2:
//Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
//Output: "abcd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[0] and s[2], s = "acbd"
//Swap s[1] and s[2], s = "abcd"
//Example 3:
//Input: s = "cba", pairs = [[0,1],[1,2]]
//Output: "abc"
//Explaination: 
//Swap s[0] and s[1], s = "bca"
//Swap s[1] and s[2], s = "bac"
//Swap s[0] and s[1], s = "abc"
// 
//Constraints:
//	1 <= s.length <= 10^5
//	0 <= pairs.length <= 10^5
//	0 <= pairs[i][0], pairs[i][1] < s.length
//	s only contains lower case English letters.
char* smallestStringWithSwaps(char* s, int** pairs, int pairsSize, int* pairsColSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100001] = {0};
    int b[100001] = {0};
    int c[100001] = {0};
    int d[100001] = {0};
    int e[100001] = {0};
    int f[100001] = {0};
    int g[100001] = {0};
    int h[100001] = {0};
    int *head = (int *)malloc(sizeof(int) * 100001);
    int *next = (int *)malloc(sizeof(int) * 100001);
    int *parent = (int *)malloc(sizeof(int) * 100001);
    int *rank = (int *)malloc(sizeof(int) * 100001);
    char *ret = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    for(i = 0; i < strlen(s); i++) {
        a[i] = i;
        head[i] = i;
        next[i] = -1;
        parent[i] = i;
        rank[i] = 0;
    }
    for(i = 0; i < pairsSize; i++) {
        j = pairs[i][0];
        k = pairs[i][1];
        l = find(parent, j);
        m = find(parent, k);
        if(l != m) {
            unionSet(parent, rank, l, m);
        }
    }
    for(i = 0; i < strlen(s); i++) {
        j = find(parent, i);
        next[i] = head[j];
        head[j] = i;
    }
    for(i = 0; i < strlen(s); i++) {
        b[i] = s[i];
    }
    for(i = 0; i < strlen(s); i++) {
        j = head[i];
        while(j != -1) {
            c[j] = b[i];
            j = next[j];
        }
    }
    for(i = 0; i < strlen(s); i++) {
        ret[i] = c[i];
    }
    ret[strlen(s)] = '\0';
    return ret;    
}