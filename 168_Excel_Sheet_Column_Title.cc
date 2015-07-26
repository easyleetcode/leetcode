class Solution {
public:
	string convertToTitle(int n) {
		string ret;
		while(n) {
			ret.insert(0, 1, (n-1)%26 + 'A');
			n = (n-1)/26;
		}
		return ret;
	}

	//注意要把n转换为n-1
	//其实就是一种26进制的表示方法
};
