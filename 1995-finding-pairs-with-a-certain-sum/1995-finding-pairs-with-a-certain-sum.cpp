class FindSumPairs {
public:
    vector<int> nums1, nums2;
	map<int, int> m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
		this->nums1 = nums1;
		this->nums2 = nums2;
		for (int i = 0; i < nums2.size(); i++) {
			m[nums2[i]]++;
		}
    }
    
    void add(int index, int val) {
		m[nums2[index]]--;
        this->nums2[index] += val;
		m[nums2[index]]++;
    }
    
    int count(int tot) {
		int cnt=0;
        for(int i = 0; i < nums1.size(); i++){
			int rem = tot - nums1[i];
			if(m.find(rem) != m.end()){
				cnt+=m[rem];
			}
		}
		return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */