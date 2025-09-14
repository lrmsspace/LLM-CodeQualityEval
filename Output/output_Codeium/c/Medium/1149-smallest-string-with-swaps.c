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
    int len = strlen(s);
    int* parent = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < pairsSize; i++) {
        int a = find(parent, pairs[i][0]);
        int b = find(parent, pairs[i][1]);
        if (a != b) {
            parent[a] = b;
        }
    }

    int* group = (int*)malloc(len * sizeof(int));
    memset(group, 0, len * sizeof(int));
    for (int i = 0; i < len; i++) {
        group[find(parent, i)]++;
    }

    char* res = (char*)malloc((len + 1) * sizeof(char));
    int idx = 0;
    for (int i = 0; i < len; i++) {
        if (group[i] > 0) {
            int j = i;
            while (group[j] > 0) {
                group[j]--;
                res[idx++] = s[j];
                j = find(parent, j + 1);
            }
            qsort(res + (idx - group[i]), group[i], sizeof(char), compare);
        }
    }
    res[idx] = '\0';
    free(parent);
    free(group);
    return res;

    int find(int* parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }

    int compare(const void* a, const void* b) {
        return *(char*)a - *(char*)b;
    }
}   