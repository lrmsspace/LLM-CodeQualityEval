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
    // Sort the folders array in lexicographical order
    qsort(folder, folderSize, sizeof(char*), compareFolders);
    
    // Create a boolean array to keep track of visited folders
    bool* visited = (bool*)calloc(folderSize, sizeof(bool));
    
    // Create a result array to store the remaining folders
    char** result = (char**)calloc(folderSize, sizeof(char*));
    *returnSize = 0;
    
    // Iterate through each folder and check if it is a subfolder of any other folder
    for (int i = 0; i < folderSize; i++) {
        if (!visited[i]) {
            // Check if the current folder is a subfolder of any other folder
            bool isSubfolder = false;
            for (int j = 0; j < folderSize; j++) {
                if (i!= j &&!visited[j] && strstr(folder[j], folder[i])) {
                    isSubfolder = true;
                    break;
                }
            }
            
            // If the current folder is not a subfolder, add it to the result array
            if (!isSubfolder) {
                result[(*returnSize)++] = folder[i];
                visited[i] = true;
            }
        }
    }
    
    // Free the visited array and return the result array
    free(visited);
    return result;
    
}