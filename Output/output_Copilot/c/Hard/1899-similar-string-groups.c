/**https://leetcode.com/problems/similar-string-groups/ */
//Two strings, X and Y, are considered similar if either they are identical or we can make them equivalent by swapping at most two letters (in distinct positions) within the string X.
//For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".
//Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.
//We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?
// 
//Example 1:
//Input: strs = ["tars","rats","arts","star"]
//Output: 2
//Example 2:
//Input: strs = ["omv","ovm"]
//Output: 1
// 
//Constraints:
//	1 <= strs.length <= 300
//	1 <= strs[i].length <= 300
//	strs[i] consists of lowercase letters only.
//	All words in strs have the same length and are anagrams of each other.
int numSimilarGroups(char** strs, int strsSize) {
       int n = strsSize;
        int m = strlen(strs[0]);
        int* parent = (int*)malloc(n * sizeof(int));
        int* size = (int*)malloc(n * sizeof(int));
        int* top = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
            top[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (similar(strs[i], strs[j], m)) {
                    unionSet(parent, size, top, i, j);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                result++;
            }
        }
        free(parent);
        free(size);
        free(top);
        return result;     
}