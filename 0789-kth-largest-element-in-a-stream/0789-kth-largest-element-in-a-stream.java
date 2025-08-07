class KthLargest {
    private int k;
    Queue<Integer> q;

    public KthLargest(int k, int[] nums) {
        this.k = k;
        q = new PriorityQueue<>();
        for (int i = 0; i < nums.length; i++) {
            q.add(nums[i]);
        }
    }

    public int add(int val) {
        
        q.add(val);
        while(q.size() > k){
            q.poll();
        }
        return q.peek();
    }
}