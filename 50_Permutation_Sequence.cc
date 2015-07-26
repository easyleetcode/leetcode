class Solution {
public:
	string getPermutation(int n, int k) {
		int factorial = 1;
		string nums;
		for(int i = 1; i <= n; i++) {
			factorial *= i;
			nums += i + '0';
		}
		k--;
		string ret;
		while(n) {
			factorial /= n;
			int index = k/factorial;
			k %= factorial;
			ret += nums[index];
			nums.erase(index, 1);
			n--;
		}
		return ret;
	}

	//math method
	//(1 2 3 4 5) start with 1, 2, 3, 4, 5 : 4!
	//start with 12, 13, ... : 3!
	//then iteratively we get the index of each number and locate it
};
