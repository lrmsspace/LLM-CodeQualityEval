/**https://leetcode.com/problems/remove-comments/ */
//Given a C++ program, remove comments from it. The program source is an array of strings source where source[i] is the ith line of the source code. This represents the result of splitting the original source code string by the newline character '\n'.
//In C++, there are two types of comments, line comments, and block comments.
//	The string "//" denotes a line comment, which represents that it and the rest of the characters to the right of it in the same line should be ignored.
//	The string "/*" denotes a block comment, which represents that all characters until the next (non-overlapping) occurrence of "*/" should be ignored. (Here, occurrences happen in reading order: line by line from left to right.) To be clear, the string "/*/" does not yet end the block comment, as the ending would be overlapping the beginning.
//The first effective comment takes precedence over others.
//	For example, if the string "//" occurs in a block comment, it is ignored.
//	Similarly, if the string "/*" occurs in a line or block comment, it is also ignored.
//If a certain line of code is empty after removing comments, you must not output that line: each string in the answer list will be non-empty.
//There will be no control characters, single quote, or double quote characters.
//	For example, source = "string s = "/* Not a comment. */";" will not be a test case.
//Also, nothing else such as defines or macros will interfere with the comments.
//It is guaranteed that every open block comment will eventually be closed, so "/*" outside of a line or block comment always starts a new comment.
//Finally, implicit newline characters can be deleted by block comments. Please see the examples below for details.
//After removing the comments from the source code, return the source code in the same format.
// 
//Example 1:
//Input: source = ["/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"]
//Output: ["int main()","{ ","  ","int a, b, c;","a = b + c;","}"]
//Explanation: The line by line code is visualized as below:
///*Test program */
//int main()
//{ 
//  // variable declaration 
//int a, b, c;
///* This is a test
//   multiline  
//   comment for 
//   testing */
//a = b + c;
//}
//The string /* denotes a block comment, including line 1 and lines 6-9. The string // denotes line 4 as comments.
//The line by line output code is visualized as below:
//int main()
//{ 
//  
//int a, b, c;
//a = b + c;
//}
//Example 2:
//Input: source = ["a/*comment", "line", "more_comment*/b"]
//Output: ["ab"]
//Explanation: The original source string is "a/*comment\nline\nmore_comment*/b", where we have bolded the newline characters.  After deletion, the implicit newline characters are deleted, leaving the string "ab", which when delimited by newline characters becomes ["ab"].
// 
//Constraints:
//	1 <= source.length <= 100
//	0 <= source[i].length <= 80
//	source[i] consists of printable ASCII characters.
//	Every open block comment is eventually closed.
//	There are no single-quote or double-quote in the input.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** removeComments(char** source, int sourceSize, int* returnSize) {
    // Initialize pointers for the result and the current line
    char** result = malloc(sizeof(char*) * sourceSize);
    int resultSize = 0;
    int resultCapacity = sourceSize;
    
    // Initialize pointers for the current line and the current comment
    char* currentLine = malloc(sizeof(char) * (source[0] + 1));
    int currentLineLength = 0;
    int currentCommentStart = -1;
    
    for (int i = 0; i < sourceSize; i++) {
        char* currentLineCopy = malloc(sizeof(char) * (source[i] + 1));
        int currentLineCopyLength = 0;
        
        for (int j = 0; j <= source[i][j]; j++) {
            if (currentCommentStart == -1) {
                // If the current line is not in a comment, add the character to the current line copy
                currentLineCopy[currentLineCopyLength++] = source[i][j];
            } else {
                // If the current line is in a comment, ignore the character
                if (source[i][j] == '*' && j + 1 < source[i][j + 1] && source[i][j + 1] == '/') {
                    // If the current line ends a comment, reset the comment start index
                    currentCommentStart = -1;
                    j++;
                }
            }
        }
        
        // Add the current line copy to the result array
        currentLineCopy[currentLineCopyLength] = '\0';
        result[resultSize++] = currentLineCopy;
        
        // If the result array has reached its capacity, reallocate more memory
        if (resultSize == resultCapacity) {
            resultCapacity *= 2;
            result = realloc(result, sizeof(char*) * resultCapacity);
        }
        
        // Reset the current line copy and the current line length
        free(currentLineCopy);
        currentLineCopy = currentLine;
        currentLineCopyLength = currentLineLength;
    }
    
    // Set the return size and return the result array
    *returnSize = resultSize;
    return result;
    
}