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

    // Union-Find data structure
    int* parent = (int*)malloc(n * sizeof(int));

    // Initialize parent array
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Union function
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by rank
    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            parent[x] = y;
        }
    }

    // Perform union for each pair
    for (int i = 0; i < pairsSize; i++) {
        unionSet(pairs[i][0], pairs[i][1]);
    }

    // Group characters by their parent
    char** groups = (char**)malloc(n * sizeof(char*));
    int* groupSizes = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        int parentIndex = find(i);
        if (groupSizes[parentIndex] == 0) {
            groups[parentIndex] = (char*)malloc(n * sizeof(char));
        }
        groups[parentIndex][groupSizes[parentIndex]++] = s[i];
    }

    // Sort each group
    for (int i = 0; i < n; i++) {
        if (groupSizes[i] > 0) {
            qsort(groups[i], groupSizes[i], sizeof(char), cmpfunc);
        }
    }
    
}