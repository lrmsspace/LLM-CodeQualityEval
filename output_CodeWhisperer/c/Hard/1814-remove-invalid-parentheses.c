/**https://leetcode.com/problems/remove-invalid-parentheses/ */
//Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
//Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
// 
//Example 1:
//Input: s = "()())()"
//Output: ["(())()","()()()"]
//Example 2:
//Input: s = "(a)())()"
//Output: ["(a())()","(a)()()"]
//Example 3:
//Input: s = ")("
//Output: [""]
// 
//Constraints:
//	1 <= s.length <= 25
//	s consists of lowercase English letters and parentheses '(' and ')'.
//	There will be at most 20 parentheses in s.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** removeInvalidParentheses(char* s, int* returnSize) {

    *returnSize = 0;
    
    // Edge case: empty string
    if (s == NULL || s[0] == '\0') {
        char** result = (char**)malloc(sizeof(char*));
        result[0] = (char*)malloc(sizeof(char));
        result[0][0] = '\0';
        *returnSize = 1;
        return result;
    }
    
    // Initialize queue for BFS
    QueueNode* queue = (QueueNode*)malloc(10000 * sizeof(QueueNode));
    int front = 0, rear = 0;
    
    // Initialize visited set
    char** visited = (char**)malloc(10000 * sizeof(char*));
    int visitedCount = 0;
    
    // Initialize result array
    char** result = (char**)malloc(1000 * sizeof(char*));
    
    // Add the initial string to queue
    queue[rear].str = strdup(s);
    queue[rear].level = 0;
    rear++;
    
    // Mark as visited
    visited[visitedCount++] = strdup(s);
    
    // Variable to track if we've found a valid string
    bool found = false;
    int minLevel = -1;
    
    // BFS
    while (front < rear) {
        QueueNode current = queue[front++];
        char* str = current.str;
        int level = current.level;
        
        // If we've already found valid strings at a lower level, skip higher levels
        if (found && level > minLevel) {
            free(str);
            continue;
        }
        
        // Check if current string is valid
        if (isValid(str)) {
            // First valid string found
            if (!found) {
                found = true;
                minLevel = level;
            }
            
            // Add to result if at the minimum level
            if (level == minLevel) {
                result[*returnSize] = strdup(str);
                (*returnSize)++;
            }
        }
        
        // If we haven't found valid strings yet or at the same level, continue BFS
        if (!found || level == minLevel) {
            int len = strlen(str);
            
            // Try removing each character
            for (int i = 0; i < len; i++) {
                // Only try removing parentheses
                if (str[i] != '(' && str[i] != ')') continue;
                
                // Skip consecutive same parentheses to avoid duplicates
                if (i > 0 && str[i] == str[i-1]) continue;
                
                // Create a new string with the i-th character removed
                char* newStr = (char*)malloc((len) * sizeof(char));
                int k = 0;
                for (int j = 0; j < len; j++) {
                    if (j != i) {
                        newStr[k++] = str[j];
                    }
                }
                newStr[k] = '\0';
                
                // Check if already visited
                bool isVisited = false;
                for (int j = 0; j < visitedCount; j++) {
                    if (strcmp(visited[j], newStr) == 0) {
                        isVisited = true;
                        break;
                    }
                }
                
                // If not visited, add to queue and mark as visited
                if (!isVisited) {
                    visited[visitedCount++] = strdup(newStr);
                    queue[rear].str = newStr;
                    queue[rear].level = level + 1;
                    rear++;
                } else {
                    free(newStr);
                }
            }
        }
        
        free(str);
    }
    
    // If no valid string found, return empty string
    if (*returnSize == 0) {
        result[0] = (char*)malloc(sizeof(char));
        result[0][0] = '\0';
        *returnSize = 1;
    }
    
    // Clean up
    for (int i = 0; i < visitedCount; i++) {
        free(visited[i]);
    }
    free(visited);
    free(queue);
    
    return result;  
    
}