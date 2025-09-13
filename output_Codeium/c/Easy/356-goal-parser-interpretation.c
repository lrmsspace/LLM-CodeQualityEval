/**https://leetcode.com/problems/goal-parser-interpretation/ */
//You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.
//Given the string command, return the Goal Parser's interpretation of command.
// 
//Example 1:
//Input: command = "G()(al)"
//Output: "Goal"
//Explanation: The Goal Parser interprets the command as follows:
//G -> G
//() -> o
//(al) -> al
//The final concatenated result is "Goal".
//Example 2:
//Input: command = "G()()()()(al)"
//Output: "Gooooal"
//Example 3:
//Input: command = "(al)G(al)()()G"
//Output: "alGalooG"
// 
//Constraints:
//	1 <= command.length <= 100
//	command consists of "G", "()", and/or "(al)" in some order.


char * interpret(char * command){
    int n = strlen(command);
    char *result = (char *)malloc((n + 1) * sizeof(char));
    int index = 0;
    
    for (int i = 0; i < n; i++) {
        if (command[i] == 'G') {
            result[index++] = 'G';
        } else if (command[i] == '(' && command[i + 1] == ')') {
            result[index++] = 'o';
            i++;
        } else if (command[i] == '(' && command[i + 1] == 'a' && command[i + 2] == 'l' && command[i + 3] == ')') {
            result[index++] = 'a';
            result[index++] = 'l';
            i += 3;
        }
    }
    
    result[index] = '\0';
    return result;

}