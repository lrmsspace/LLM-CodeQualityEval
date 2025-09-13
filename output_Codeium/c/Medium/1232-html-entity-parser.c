/**https://leetcode.com/problems/html-entity-parser/ */
//HTML entity parser is the parser that takes HTML code as input and replace all the entities of the special characters by the characters itself.
//The special characters and their entities for HTML are:
//	Quotation Mark: the entity is &quot; and symbol character is ".
//	Single Quote Mark: the entity is &apos; and symbol character is '.
//	Ampersand: the entity is &amp; and symbol character is &.
//	Greater Than Sign: the entity is &gt; and symbol character is >.
//	Less Than Sign: the entity is &lt; and symbol character is <.
//	Slash: the entity is &frasl; and symbol character is /.
//Given the input text string to the HTML parser, you have to implement the entity parser.
//Return the text after replacing the entities by the special characters.
// 
//Example 1:
//Input: text = "&amp; is an HTML entity but &ambassador; is not."
//Output: "& is an HTML entity but &ambassador; is not."
//Explanation: The parser will replace the &amp; entity by &
//Example 2:
//Input: text = "and I quote: &quot;...&quot;"
//Output: "and I quote: \"...\""
// 
//Constraints:
//	1 <= text.length <= 105
//	The string may contain any possible characters out of all the 256 ASCII characters. 
char* entityParser(char* text) {
    int len = strlen(text);
    char* result = (char*)malloc(len + 1); // Allocate memory for the result
    int index = 0; // Index for the result array

    for (int i = 0; i < len; i++) {
        if (text[i] == '&') {
            if (strncmp(&text[i], "&quot;", 6) == 0) {
                result[index++] = '"';
                i += 5;
            } else if (strncmp(&text[i], "&apos;", 6) == 0) {
                result[index++] = '\'';
                i += 5;
            } else if (strncmp(&text[i], "&amp;", 5) == 0) {
                result[index++] = '&';
                i += 4;
            } else if (strncmp(&text[i], "&gt;", 4) == 0) {
                result[index++] = '>';
                i += 3;
            } else if (strncmp(&text[i], "&lt;", 4) == 0) {
                result[index++] = '<';
                i += 3;
            } else if (strncmp(&text[i], "&frasl;", 7) == 0) {
                result[index++] = '/';
                i += 6;
            } else {
                result[index++] = text[i];
            }
        } else {
            result[index++] = text[i];
        }
    }
    result[index] = '\0'; // Null-terminate the result string
    return result;
}