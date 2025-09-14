/**https://leetcode.com/problems/stickers-to-spell-word/ */
//We are given n different types of stickers. Each sticker has a lowercase English word on it.
//You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
//Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.
//Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and target was chosen as a concatenation of two random words.
// 
//Example 1:
//Input: stickers = ["with","example","science"], target = "thehat"
//Output: 3
//Explanation:
//We can use 2 "with" stickers, and 1 "example" sticker.
//After cutting and rearrange the letters of those stickers, we can form the target "thehat".
//Also, this is the minimum number of stickers necessary to form the target string.
//Example 2:
//Input: stickers = ["notice","possible"], target = "basicbasic"
//Output: -1
//Explanation:
//We cannot form the target "basicbasic" from cutting letters from the given stickers.
// 
//Constraints:
//	n == stickers.length
//	1 <= n <= 50
//	1 <= stickers[i].length <= 10
//	1 <= target.length <= 15
//	stickers[i] and target consist of lowercase English letters.
/**
 * @param {string[]} stickers
 * @param {string} target
 * @return {number}
 */
var minStickers = function(stickers, target) {
    const dp = new Map();
    const stickerCount = stickers.map(sticker => {
        const count = Array(26).fill(0);
        for (const char of sticker) {
            count[char.charCodeAt(0) - 97]++;
        }
        return count;
    });

    function dfs(targetCount) {
        if (targetCount.every(count => count === 0)) return 0;
        const key = targetCount.join(',');
        if (dp.has(key)) return dp.get(key);

        let minStickers = Infinity;
        for (const sticker of stickerCount) {
            const newTargetCount = targetCount.slice();
            for (let i = 0; i < 26; i++) {
                newTargetCount[i] = Math.max(0, newTargetCount[i] - sticker[i]);
            }
            minStickers = Math.min(minStickers, dfs(newTargetCount) + 1);
        }

        dp.set(key, minStickers);
        return minStickers;
    }

    const targetCount = Array(26).fill(0);
    for (const char of target) {
        targetCount[char.charCodeAt(0) - 97]++;
    }

    const result = dfs(targetCount);
    return result === Infinity ? -1 : result;    
};