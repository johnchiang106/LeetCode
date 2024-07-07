class Solution {
    public long minimumDifference(int[] nums) {
        int n3 = nums.length;
        int n2 = n3*2/3, n = n3/3;
        long[] front = new long[n+1], back = new long[n+1];
        PriorityQueue<Integer> frontQ = new PriorityQueue<>(Comparator.reverseOrder());
        long sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            frontQ.add(nums[i]);
        }
        front[0] = sum;
        for(int i = 1; i <= n; ++i){
            if(frontQ.peek() > nums[n-1+i]){
                frontQ.add(nums[n-1+i]);
                sum += nums[n-1+i] - frontQ.poll();
            }
            front[i] = sum;
        }

        PriorityQueue<Integer> backQ = new PriorityQueue<>();
        sum = 0;
        for(int i = n3 - 1; i >= n2; --i){
            sum += nums[i];
            backQ.add(nums[i]);
        }
        back[0] = sum;
        for(int i = 1; i <= n; ++i){
            if(backQ.peek() < nums[n2-i]){
                backQ.add(nums[n2-i]);
                sum += nums[n2-i] - backQ.poll();
            }
            back[i] = sum;
        }

        long ans = Long.MAX_VALUE;
        for(int i = 0; i <= n; ++i){
            ans = Math.min(ans, front[i] - back[n-i]);
        }
        return ans;
    }
}