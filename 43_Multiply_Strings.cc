class Solution {
public:
	string multiply(string num1, string num2) {
		if(num1.empty() || num2.empty()) return "0";
		int n1 = num1.size(), n2 = num2.size();
		vector<int> num(n1 + n2, 0);  //num[0] left for carry, num[0] is highest
		for(int i = 0; i < n1; i++) {
			for(int j = 0; j < n2; j++) {
				num[i+j+1] = (num1[i] - '0') * (num2[j] - '0');
			}
		}	
		int carry = 0;
		for(int i = n1 + n2 - 1; i >= 0; i--) {
			num[i] = num[i] + carry;
			carry = num[i]/10;
			num[i] = num[i]%10;
		}
		string ret;
		bool firstNotZero = false;
		for(int i = 0; i < n1 + n2; i++) {
			if(!firstNotZero && num[i] == 0) continue;
			else {
				firstNotZero = true;
				ret += num[i] + '0';
			}
		}
		if(!ret) return "0";
		return ret;
	}

	//use num to store each result
	//then from low to high, adjuect the result to 0-9, with carry
	//then convert vector<int> to string, care for the first leading 0s

	//test case  --> need firstNotZero to escape leading 0s
	//Input:"0", "0"
	//Output:"00"
	//Expected:"0"


	//test case --> need check if ret == null, then return "0" rather than ""
	//Input:"0", "0"
	//Output:""
	//Expected:"0"
};
