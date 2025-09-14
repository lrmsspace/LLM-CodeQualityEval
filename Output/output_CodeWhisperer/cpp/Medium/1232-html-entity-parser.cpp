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
class Solution {
public:
    string entityParser(string text) {
        string res = "";
        int i = 0;
        while (i < text.length()) {
            if (text[i] == '&') {
                int j = i;
                while (j < text.length() && text[j] != ';') {
                    j++;
                }
                string s = text.substr(i, j - i + 1);
                if (s == "&quot;") {
                    res += "\"";
                } else if (s == "&apos;") {
                    res += "'";
                } else if (s == "&amp;") {
                    res += "&";
                } else if (s == "&gt;") {
                    res += ">";
                } else if (s == "&lt;") {
                    res += "<";
                } else if (s == "&frasl;") {
                    res += "/";
                } else {
                    res += s;
                }
                i = j + 1;
            } else {
                res += text[i];
                i++;
            }
        }
        return res;
        
    }
};