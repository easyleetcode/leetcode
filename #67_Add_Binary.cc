class Solution {
public:
	string addBinary(string a, string b) {
		string ret;
		int i = a.size() - 1, j = b.size() - 1;
		int carry = 0;
		while(i >= 0 || j >= 0) {
			int va = 0, vb = 0;
			if(i >= 0) {
				va = a[i] - '0';
				i--;
			}
			if(j >= 0) {
				vb = b[j] - '0';
				j--;
			}
			int sum = va + vb + carry;
			ret.insert(0, 1, sum%2 + '0');
			carry = sum/2;
		}
		if(carry) ret.insert(0, 1, '1');
		return ret;
	}
};
