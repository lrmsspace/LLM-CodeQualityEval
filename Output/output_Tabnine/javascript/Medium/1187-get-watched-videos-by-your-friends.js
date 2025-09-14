/**https://leetcode.com/problems/get-watched-videos-by-your-friends/ */
//There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.
//Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest. 
// 
//Example 1:
//Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
//Output: ["B","C"] 
//Explanation: 
//You have id = 0 (green color in the figure) and your friends are (yellow color in the figure):
//Person with id = 1 -> watchedVideos = ["C"] 
//Person with id = 2 -> watchedVideos = ["B","C"] 
//The frequencies of watchedVideos by your friends are: 
//B -> 1 
//C -> 2
//Example 2:
//Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 2
//Output: ["D"]
//Explanation: 
//You have id = 0 (green color in the figure) and the only friend of your friends is the person with id = 3 (yellow color in the figure).
// 
//Constraints:
//	n == watchedVideos.length == friends.length
//	2 <= n <= 100
//	1 <= watchedVideos[i].length <= 100
//	1 <= watchedVideos[i][j].length <= 8
//	0 <= friends[i].length < n
//	0 <= friends[i][j] < n
//	0 <= id < n
//	1 <= level < n
//	if friends[i] contains j, then friends[j] contains i
/**
 * @param {string[][]} watchedVideos
 * @param {number[][]} friends
 * @param {number} id
 * @param {number} level
 * @return {string[]}
 */
var watchedVideosByFriends = function(watchedVideos, friends, id, level) {
    // Step 1: Create a map to store the frequency of videos watched by friends
    let friendVideos = new Map();
    
    // Step 2: Iterate through the friends array
    for (let i = 0; i < friends.length; i++) {
        // Step 3: Check if the friend is not the current user
        if (i!== id) {
            // Step 4: Iterate through the videos watched by the friend
            for (let video of watchedVideos[friends[i][j]]) {
                // Step 5: Increment the frequency of the video in the map
                friendVideos.set(video, (friendVideos.get(video) || 0) + 1);
            }
        }
    }
    
    // Step 6: Create an array of videos sorted by their frequencies and alphabetically
    let sortedVideos = [...friendVideos.entries()].sort((a, b) => {
        // Step 7: Compare the frequencies
        if (a[1] === b[1]) {
            // Step 8: If frequencies are equal, compare the videos alphabetically
            return a[0].localeCompare(b[0]);
        } else {
            // Step 9: Sort in descending order of frequencies
            return b[1] - a[1];
        }
    });
    
    // Step 10: Extract the videos at the specified level
    let result = [];
    for (let [video, freq] of sortedVideos) {
        if (level === 1) {
            result.push(video);
            break;
        }
        level--;
    }
    
    // Step 11: Return the videos at the specified level
    return result;
    
};