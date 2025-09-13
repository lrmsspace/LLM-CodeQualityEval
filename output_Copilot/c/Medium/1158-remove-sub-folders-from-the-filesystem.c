/**https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/ */
//Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.
//If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".
//The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.
//	For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.
// 
//Example 1:
//Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
//Output: ["/a","/c/d","/c/f"]
//Explanation: Folders "/a/b" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
//Example 2:
//Input: folder = ["/a","/a/b/c","/a/b/d"]
//Output: ["/a"]
//Explanation: Folders "/a/b/c" and "/a/b/d" will be removed because they are subfolders of "/a".
//Example 3:
//Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
//Output: ["/a/b/c","/a/b/ca","/a/b/d"]
// 
//Constraints:
//	1 <= folder.length <= 4 * 104
//	2 <= folder[i].length <= 100
//	folder[i] contains only lowercase letters and '/'.
//	folder[i] always starts with the character '/'.
//	Each folder name is unique.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** removeSubfolders(char** folder, int folderSize, int* returnSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[40000] = {0};
    int b[40000] = {0};
    int c[40000] = {0};
    int d[40000] = {0};
    int e[40000] = {0};
    int f[40000] = {0};
    int g[40000] = {0};
    int h[40000] = {0};
    char **ret = (char **)malloc(sizeof(char *) * folderSize);
    for(i = 0; i < folderSize; i++) {
        ret[i] = (char *)malloc(sizeof(char) * 100);
    }
    for(i = 0; i < folderSize; i++) {
        a[i] = strlen(folder[i]);
    }
    for(i = 0; i < folderSize; i++) {
        for(j = 0; j < a[i]; j++) {
            if(folder[i][j] == '/') {
                b[i]++;
            }
        }
    }
    for(i = 0; i < folderSize; i++) {
        for(j = 0; j < folderSize; j++) {
            if(i == j) {
                continue;
            }
            if(b[i] >= b[j]) {
                continue;
            }
            if(strncmp(folder[j], folder[i], b[i]) == 0 && folder[j][b[i]] == '/') {
                c[j] = 1;
            }
        }
    }
    *returnSize = 0;
    for(i = 0; i < folderSize; i++) {
        if(c[i] == 0) {
            strcpy(ret[*returnSize], folder[i]);
            (*returnSize)++;
        }
    }
    return ret;   
}