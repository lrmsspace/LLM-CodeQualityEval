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
    int n = strlen(s);
    int* index = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        index[i] = i;
    }
    
    // Sort pairs by first index
    qsort(pairs, pairsSize, sizeof(int*), compare);
    
    // Create a disjoint set
    int* parent = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    // Union by rank
    for (int i = 0; i < pairsSize; i++) {
        int u = find(parent, pairs[i][0]);
        int v = find(parent, pairs[i][1]);
        if (u!= v) {
            parent[u] = v;
        }
    }
    
    // Assign each character to its group
    int* group = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        group[i] = find(parent, i);
    }
    
    // Sort characters in each group
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0 && group[j - 1] > group[j]) {
            swap(index, j - 1, j);
            swap(group, j - 1, j);
            j--;
        }
    }
    
    // Build the result string
    char* result = malloc((n + 1) * sizeof(char));
    strcpy(result, s);
    
    for (int i = 0; i < n; i++) {
        int j = index[i];
        result[i] = s[j];
    }
    
    free(index);
    free(parent);
    free(group);
    
    return result;
    
}