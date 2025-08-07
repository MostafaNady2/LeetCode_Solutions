	class RecentCounter {
		ArrayList<Integer> arr ;
    public RecentCounter() {
        arr = new ArrayList<>();
    }
    
    public int ping(int t) {
        arr.add(t);
		while(arr.get(0)<t-3000){
			arr.remove(0);
		}
		return arr.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */