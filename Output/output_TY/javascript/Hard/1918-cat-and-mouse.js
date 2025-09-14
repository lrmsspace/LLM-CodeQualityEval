/**https://leetcode.com/problems/cat-and-mouse/ */
//A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.
//The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.
//The mouse starts at node 1 and goes first, the cat starts at node 2 and goes second, and there is a hole at node 0.
//During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].
//Additionally, it is not allowed for the Cat to travel to the Hole (node 0).
//Then, the game can end in three ways:
//	If ever the Cat occupies the same node as the Mouse, the Cat wins.
//	If ever the Mouse reaches the Hole, the Mouse wins.
//	If ever a position is repeated (i.e., the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.
//Given a graph, and assuming both players play optimally, return
//	1 if the mouse wins the game,
//	2 if the cat wins the game, or
//	0 if the game is a draw.
// 
//Example 1:
//Input: graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
//Output: 0
//Example 2:
//Input: graph = [[1,3],[0],[3],[0,2]]
//Output: 1
// 
//Constraints:
//	3 <= graph.length <= 50
//	1 <= graph[i].length < graph.length
//	0 <= graph[i][j] < graph.length
//	graph[i][j] != i
//	graph[i] is unique.
//	The mouse and the cat can always move. 
/**
 * @param {number[][]} graph
 * @return {number}
 */
var catMouseGame = function(graph) {
    let n = graph.length;
    let dp = Array(n).fill(0).map(() => Array(n).fill(0).map(() => Array(n).fill(-1)));
    let mouseTurn = true;
    let mouseWin = 1;
    let catWin = 2;
    let draw = 0;
    let mouseWinState = 1;
    let catWinState = 2;
    let drawState = 0;
    let mouseWinState2 = 3;
    let catWinState2 = 4;
    let drawState2 = 5;
    let mouseWin2 = 6;
    let catWin2 = 7;
    let draw2 = 8;
    let mouseWin3= 9;
    let catWin3 = 10;
    let draw3 = 11;
    let mouseWin4 = 12;
    let catWin4 = 13;
    let draw4 = 14;

    let dfs = function(mouse, cat, turn, state) {
        if (mouse === cat) {
            return catWin;
        }
        if (mouse === 0) {
            return mouseWin;
        }
        if (turn === n * 2) {
            return draw;
        }
        if (dp[mouse][cat][turn] !== -1) {
            return dp[mouse][cat][turn];
        }
        let res = mouseTurn ? mouseWin : catWin;
        let nextState = mouseTurn ? mouseWinState : catWinState;
        let nextState2 = mouseTurn ? mouseWinState2 : catWinState2;
        let nextState3 = mouseTurn ? mouseWin3 : catWin3;
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (i !== j) {
                dfs(i, j, 0, mouseWinState);
                dfs(i, j, 0, mouseWinState2);
                dfs(i, j, 0, mouseWin3);
            }
        }
    }
    for (let turn = 1; turn <= n * 2; turn++) {
        for (let mouse = 1; mouse < n; mouse++) {
            for (let cat = 1; cat < n; cat++) {
                if (mouse === cat) {
                    continue;
                }
                let res = mouseTurn ? mouseWin : catWin;
                let nextState = mouseTurn ? mouseWinState : catWinState;
                let nextState2 = mouseTurn ? mouseWinState2 : catWinState2;
                let nextState3 = mouseTurn ? mouseWin3 : catWin3;
                if (mouseTurn) {
                    for (let nextMouseof graph[mouse]) {
                        let nextState = dfs(nextMouse, cat, turn + 1, nextState);
                    }
                }
            }
        }
    }
    return dfs(1, 2, 0, mouseWinState);
};