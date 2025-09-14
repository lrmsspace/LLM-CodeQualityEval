/**https://leetcode.com/problems/delete-duplicate-folders-in-system/ */
//Due to a bug, there are many duplicate folders in a file system. You are given a 2D array paths, where paths[i] is an array representing an absolute path to the ith folder in the file system.
//	For example, ["one", "two", "three"] represents the path "/one/two/three".
//Two folders (not necessarily on the same level) are identical if they contain the same non-empty set of identical subfolders and underlying subfolder structure. The folders do not need to be at the root level to be identical. If two or more folders are identical, then mark the folders as well as all their subfolders.
//	For example, folders "/a" and "/b" in the file structure below are identical. They (as well as their subfolders) should all be marked:
//	
//		/a
//		/a/x
//		/a/x/y
//		/a/z
//		/b
//		/b/x
//		/b/x/y
//		/b/z
//	
//	
//	However, if the file structure also included the path "/b/w", then the folders "/a" and "/b" would not be identical. Note that "/a/x" and "/b/x" would still be considered identical even with the added folder.
//Once all the identical folders and their subfolders have been marked, the file system will delete all of them. The file system only runs the deletion once, so any folders that become identical after the initial deletion are not deleted.
//Return the 2D array ans containing the paths of the remaining folders after deleting all the marked folders. The paths may be returned in any order.
// 
//Example 1:
//Input: paths = [["a"],["c"],["d"],["a","b"],["c","b"],["d","a"]]
//Output: [["d"],["d","a"]]
//Explanation: The file structure is as shown.
//Folders "/a" and "/c" (and their subfolders) are marked for deletion because they both contain an empty
//folder named "b".
//Example 2:
//Input: paths = [["a"],["c"],["a","b"],["c","b"],["a","b","x"],["a","b","x","y"],["w"],["w","y"]]
//Output: [["c"],["c","b"],["a"],["a","b"]]
//Explanation: The file structure is as shown. 
//Folders "/a/b/x" and "/w" (and their subfolders) are marked for deletion because they both contain an empty folder named "y".
//Note that folders "/a" and "/c" are identical after the deletion, but they are not deleted because they were not marked beforehand.
//Example 3:
//Input: paths = [["a","b"],["c","d"],["c"],["a"]]
//Output: [["c"],["c","d"],["a"],["a","b"]]
//Explanation: All folders are unique in the file system.
//Note that the returned array can be in a different order as the order does not matter.
// 
//Constraints:
//	1 <= paths.length <= 2 * 104
//	1 <= paths[i].length <= 500
//	1 <= paths[i][j].length <= 10
//	1 <= sum(paths[i][j].length) <= 2 * 105
//	path[i][j] consists of lowercase English letters.
//	No two paths lead to the same folder.
//	For any folder not at the root level, its parent folder will also be in the input.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** deleteDuplicateFolder(char*** paths, int pathsSize, int* pathsColSize, int* returnSize, int** returnColumnSizes) {
    
    // Create a map to store the paths and their counts

    int maxLen = 0;
    for (int i = 0; i < pathsSize; i++) {
        maxLen = fmax(maxLen, pathsColSize[i]);
    }
    int* pathCount = calloc(maxLen, sizeof(int));
    
    for (int i = 0; i < pathsSize; i++) {
        for (int j = 0; j < pathsColSize[i]; j++) {
            pathCount[j]++;
        }

    }
    
    // Create a map to store the unique paths and their counts
    char*** uniquePaths = calloc(pathsSize, sizeof(char**));
    int* uniquePathCounts = calloc(pathsSize, sizeof(int));
    int uniquePathsSize = 0;
    
    for (int i = 0; i < pathsSize; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < uniquePathsSize; j++) {
            if (pathsColSize[i] == uniquePathCounts[j]) {
                int match = 1;
                for (int k = 0; k < pathsColSize[i]; k++) {
                    if (strcmp(paths[i][k], uniquePaths[j][k])!= 0) {
                        match = 0;
                        break;
                    }
                }
                if (match) {
                    isDuplicate = 1;
                    pathCount[k]--;
                    break;
                }
            }
        }
        
        if (!isDuplicate) {
            uniquePaths[uniquePathsSize] = malloc(pathsColSize[i] * sizeof(char*));
            uniquePathCounts[uniquePathsSize] = pathsColSize[i];
            for (int j = 0; j < pathsColSize[i]; j++) {
                uniquePaths[uniquePathsSize][j] = strdup(paths[i][j]);
            }
            uniquePathsSize++;
        }


    }
    
    // Sort the unique paths based on their counts in descending order
    qsort(uniquePaths, uniquePathsSize, sizeof(char**), comparePaths);
    
    // Create the return array
    *returnSize = uniquePathsSize;
    *returnColumnSizes = uniquePathCounts;
    char*** returnPaths = malloc(uniquePathsSize * sizeof(char**));
    for (int i = 0; i < uniquePathsSize; i++) {
        returnPaths[i] = uniquePaths[i];
    }
    
    // Free the temporary arrays
    free(pathCount);
    free(uniquePathCounts);
    for (int i = 0; i < pathsSize; i++) {
        free(paths[i]);
    }
    free(paths);
    
    return returnPaths;
}