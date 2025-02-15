public class ProductOfNumbers {
    int[] arr;
    int idx;
    int lastIdx;

    public ProductOfNumbers() {
        this.arr = new int[40001];
        this.idx = 0;
        this.lastIdx = -1;
    }

    public void add(int num) {
        if (this.idx == 0) {
            if (num == 0) {
                this.arr[idx] = 1;
                lastIdx = this.idx;
            } else {
                this.arr[idx] = num;
            }
        } else {
            if (num == 0) {
                this.arr[idx] = 1;
                lastIdx = this.idx;
            } else {
                this.arr[idx] = num * this.arr[idx - 1];
            }
        }
        idx++;
    }

    public int getProduct(int k) {
        int start = this.idx - k;
        if (start <= this.lastIdx) {
            return 0;
        }
        return start == 0 ? arr[idx - 1] : arr[this.idx - 1] / this.arr[start-1];
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */