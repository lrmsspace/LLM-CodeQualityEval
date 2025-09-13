/**https://leetcode.com/problems/find-duplicate-file-in-system/ */
//Given a list paths of directory info, including the directory path, and all the files with contents in this directory, return all the duplicate files in the file system in terms of their paths. You may return the answer in any order.
//A group of duplicate files consists of at least two files that have the same content.
//A single directory info string in the input list has the following format:
//	"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
//It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content) respectively in the directory "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.
//The output is a list of groups of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:
//	"directory_path/file_name.txt"
// 
//Example 1:
//Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
//Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
//Example 2:
//Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"]
//Output: [["root/a/2.txt","root/c/d/4.txt"],["root/a/1.txt","root/c/3.txt"]]
// 
//Constraints:
//	1 <= paths.length <= 2 * 104
//	1 <= paths[i].length <= 3000
//	1 <= sum(paths[i].length) <= 5 * 105
//	paths[i] consist of English letters, digits, '/', '.', '(', ')', and ' '.
//	You may assume no files or directories share the same name in the same directory.
//	You may assume each given directory info represents a unique directory. A single blank space separates the directory path and file info.
// 
//Follow up:
//	Imagine you are given a real file system, how will you search files? DFS or BFS?
//	If the file content is very large (GB level), how will you modify your solution?
//	If you can only read the file by 1kb each time, how will you modify your solution?
//	What is the time complexity of your modified solution? What is the most time-consuming part and memory-consuming part of it? How to optimize?
//	How to make sure the duplicated files you find are not false positive?
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** findDuplicate(char** paths, int pathsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * pathsSize);
    
    // Create a map to store the file content and its corresponding paths
    // Key: file content, Value: array of file paths with the same content
    char*** fileContentMap = malloc(sizeof(char**) * pathsSize);
    for (int i = 0; i < pathsSize; i++) {
        (*returnColumnSizes)[i] = 0;
        fileContentMap[i] = NULL;
    }
    
    // Parse the input paths and store the file content and its corresponding paths
    for (int i = 0; i < pathsSize; i++) {
        char* path = paths[i];
        char* dirPath = strtok(path, " ");
        char* contentStart = strtok(NULL, "");
    
        char* contentEnd = strchr(contentStart, '(');
        int contentLength = contentEnd - contentStart;
        char* content = malloc((contentLength + 1) * sizeof(char));
        strncpy(content, contentStart, contentLength);
        content[contentLength] = '\0';
        
        char* fileNames = strtok(contentEnd + 1, ")");
        while (fileNames!= NULL) {
            int fileNameLength = strlen(fileNames);
            char* fileName = malloc((fileNameLength + 1) * sizeof(char));
            strncpy(fileName, fileNames, fileNameLength);
            fileName[fileNameLength] = '\0';
            
            char* filePath = malloc((strlen(dirPath) + strlen(fileName) + 2) * sizeof(char));
            sprintf(filePath, "%s/%s", dirPath, fileName);
            
            // Check if the file content exists in the map
            int exists = 0;
            for (int j = 0; j < (*returnSize); j++) {
                if (strcmp(fileContentMap[j][0], content) == 0) {
                    fileContentMap[j][(*returnColumnSizes)[j]] = filePath;
                    (*returnColumnSizes)[j]++;
                    exists = 1;
                    break;
                }
            }
            
            // If the file content does not exist in the map, create a new entry
            if (!exists) {
                fileContentMap[*returnSize] = malloc(sizeof(char*) * 2);
                fileContentMap[*returnSize][0] = content;
                fileContentMap[*returnSize][1] = filePath;
                (*returnColumnSizes)[*returnSize] = 2;
                (*returnSize)++;
            }
            
            free(fileName);
            fileNames = strtok(NULL, ")");
        }
    
        free(content);
        free(dirPath);
        free(path);
        free(contentStart);
        free(contentEnd);

        // Sort the file paths in each group to ensure the correct output
        for (int j = 0; j < (*returnSize) - 1; j++) {
            for (int k = 0; k < (*returnColumnSizes)[j] - 1; k++) {
                if (strcmp(fileContentMap[j][k], fileContentMap[j][k + 1]) > 0) {
                    char* temp = fileContentMap[j][k];
                    fileContentMap[j][k] = fileContentMap[j][k + 1];
                    fileContentMap[j][k + 1] = temp;
                }
            }
        }
    }
    
    return fileContentMap;
    
}