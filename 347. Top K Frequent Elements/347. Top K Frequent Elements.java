class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a,b) -> a.getValue() - b.getValue());
        Map<Integer, Integer> mp = new HashMap<>();
        for(int n: nums){
            mp.put(n, mp.getOrDefault(n,0)+1);
        }
        for(Map.Entry<Integer,Integer> pair: mp.entrySet()){
            if(pq.size() < k){
                pq.add(pair);
            }
            else if(pair.getValue() > pq.peek().getValue()){
                pq.poll();
                pq.add(pair);
            }
        }
        int[] ans = new int[k];
        for(int i = 0; i < k; ++i){
            ans[i] = pq.poll().getKey();
        }
        return ans;
    }
}