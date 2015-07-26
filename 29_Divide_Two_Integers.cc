class Solution {
public:
	int divide(int dividend, int divisor) {
		if(divisor == 0) return 0;
		bool flag = (dividend < 0) ^ (divisor < 0);
		long Dividend = labs(dividend), Divisor = labs(divisor);
		long ret = 0;
		while(Dividend >= Divisor) {
			long c = Divisor;
			for(int i = 0; (c << i) <= Dividend; i++) {
				Dividend -= c << i;
				ret += 1 << i;
			}
		}
		if(flag) ret = -ret;
		if(ret > INT_MAX) ret = INT_MAX;  //-INT_MIN / -1 will overflow
		return ret;
	}
	//实现整数除法，不断的去试探，每次减去的数成倍增加，如果超过了就再从头再来
	//This problem can be solved based on the fact that any number can be converted to the format of the following:
	//num=a_0*2^0+a_1*2^1+a_2*2^2+...+a_n*2^n
	//The time complexity is O(logn).

	//Last executed input:-1010369383, -2147483648 TLE
	//-2147483648 abs will overflow --> Dividend and Divisor should be long
	
	//Input:-2147483648, -1
	//Output:0
	//Expected:2147483647   --> abs --> labs

	//type size
	//int 4
	//long 8
	//long long 8
};
