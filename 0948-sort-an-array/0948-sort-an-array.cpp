class Solution {
public:

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    int mx = *max_element(arr.begin(), arr.end());
    int ex = 1;

    vector<vector<int>> vec(10);
    while (mx / ex > 0) {
        for (int num : arr) {
            vec[(num / ex) % 10].push_back(num);
        }

        int idx = 0;
        for (int i = 0; i < 10; i++) {
            for (int num : vec[i]) {
                arr[idx++] = num;
            }
            vec[i].clear();
        }

        ex *= 10;
    }
}

void radixSortForAll(vector<int>& arr) {
    if (arr.empty()) return;

    vector<int> pos, neg;
    for (int num : arr) {
        if (num >= 0)
            pos.push_back(num);
        else
            neg.push_back(-num); 
    }

    radixSort(pos);
    radixSort(neg);

    arr.clear();

    
    for (int i = neg.size() - 1; i >= 0; i--) {
        arr.push_back(-neg[i]);
    }

   
    for (int num : pos) {
        arr.push_back(num);
    }
}

vector<int> sortArray(vector<int>& nums) {
    radixSortForAll(nums);
    return nums;
}
};
