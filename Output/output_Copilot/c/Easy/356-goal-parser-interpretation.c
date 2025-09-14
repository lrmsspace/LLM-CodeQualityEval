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
    char* result = (char*)malloc(100 * sizeof(char));
    int i = 0, j = 0;
    while (command[i] != '\0') {
        if (command[i] == 'G') {
            result[j] = 'G';
            j++;
        } else if (command[i] == '(' && command[i + 1] == ')') {
            result[j] = 'o';
            j++;
            i++;
        } else {
            result[j] = 'a';
            result[j + 1] = 'l';
            j += 2;
            i += 2;
        }
        i++;
    }
    result[j] = '\0';
    return result;
}