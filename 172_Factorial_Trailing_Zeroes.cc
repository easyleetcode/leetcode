class Solution {
public:
	int tailingZeroes(int n) {
		int ret = 0;
		while(n) {
			ret += n/5;
			n /= 5;
		}
		return ret;
	}

	//观察到末尾的0，其实是由于2*5导致的
	//因此我们只需要找到n!中有多少个质因子2和质因子5就行了
	//再进一步观察质因子5的个数，一定大于质因子2的个数  --> 因此只需要求5因子的个数就行
  //有两种方法：
	//1:用5, 25, 125去除，因为有的数不知有一个5的因子(不通过???)
	//2:被除数除以5，得到的值加到最终结果中，然后被除数除以5，循环下一次计算

	int tailingZeroes(int n) {
		int ret = 0;
		for(int i = 5; i <= n; i *= 5) {
			ret += n/i;
		}
		return ret;
	}
	//TLE

	int tailingZeroes(int n) {
		int ret = 0;
		for(int i = 5; n/i >= 1; i *= 5) {
			ret += n/i;
		}
		return ret;
	}
	//Input:1808548329
	//Output:452137080
	//Expected:452137076
};
