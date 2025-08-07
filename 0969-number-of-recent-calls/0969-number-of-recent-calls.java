	class RecentCounter {
		int[] arr;
		int i;
		int j;

		public RecentCounter() {
			arr = new int[10000];
			i = 0;
			j = 0;
		}

		public int ping(int t) {
			arr[i++] = t;
			while (arr[j] < t - 3000) {
				j++;
			}
			return i - j;
		}
	}