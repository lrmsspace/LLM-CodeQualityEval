/**https://leetcode.com/problems/most-popular-video-creator/ */
//You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creators[i], has an id of ids[i], and has views[i] views.
//The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.
//	If multiple creators have the highest popularity, find all of them.
//	If multiple videos have the highest view count for a creator, find the lexicographically smallest id.
//Note: It is possible for different videos to have the same id, meaning that ids do not uniquely identify a video. For example, two videos with the same ID are considered as distinct videos with their own viewcount.
//Return a 2D array of strings answer where answer[i] = [creatorsi, idi] means that creatorsi has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.
// 
//Example 1:
//Input: creators = ["alice","bob","alice","chris"], ids = ["one","two","three","four"], views = [5,10,5,4]
//Output: [["alice","one"],["bob","two"]]
//Explanation:
//The popularity of alice is 5 + 5 = 10.
//The popularity of bob is 10.
//The popularity of chris is 4.
//alice and bob are the most popular creators.
//For bob, the video with the highest view count is "two".
//For alice, the videos with the highest view count are "one" and "three". Since "one" is lexicographically smaller than "three", it is included in the answer.
//Example 2:
//Input: creators = ["alice","alice","alice"], ids = ["a","b","c"], views = [1,2,2]
//Output: [["alice","b"]]
//Explanation:
//The videos with id "b" and "c" have the highest view count.
//Since "b" is lexicographically smaller than "c", it is included in the answer.
// 
//Constraints:
//	n == creators.length == ids.length == views.length
//	1 <= n <= 105
//	1 <= creators[i].length, ids[i].length <= 5
//	creators[i] and ids[i] consist only of lowercase English letters.
//	0 <= views[i] <= 105
class Solution {
    public List<List<String>> mostPopularCreator(String[] creators, String[] ids, int[] views) {
        Map<String, Integer> creatorViews = new HashMap<>();
        Map<String, List<String[]>> creatorVideos = new HashMap<>();
        int maxViews = 0;
        for (int i = 0; i < creators.length; i++) {
            String creator = creators[i];
            String id = ids[i];
            int view = views[i];
            creatorViews.put(creator, creatorViews.getOrDefault(creator, 0) + view);
            if (!creatorVideos.containsKey(creator)) {
                creatorVideos.put(creator, new ArrayList<>());
            }
            creatorVideos.get(creator).add(new String[] { id, String.valueOf(view) });
            maxViews = Math.max(maxViews, creatorViews.get(creator));
        }
        List<List<String>> result = new ArrayList<>();
        for (String creator : creatorVideos.keySet()) {
            if (creatorViews.get(creator) == maxViews) {
                List<String[]> videos = creatorVideos.get(creator);
                videos.sort((a, b) -> {
                    if (Integer.parseInt(a[1]) == Integer.parseInt(b[1])) {
                        return a[0].compareTo(b[0]);
                    }
                    return Integer.parseInt(b[1]) - Integer.parseInt(a[1]);
                });
                List<String> list = new ArrayList<>();
                list.add(creator);
                list.add(videos.get(0)[0]);
                result.add(list);
            }
        }
        return result;     
    }
}