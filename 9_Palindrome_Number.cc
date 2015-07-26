class Solution {
public:
	bool isPalindrome(int x) {
		if(x < 0) return false;
		int n = 0, tmp = x;
		while(tmp) {
			tmp = tmp/10;
			n++;
		}	
		for(int i = 0, j = n-1; i < j; i++, j--) {
			int a = x/(int)pow(10, i)%10, b = x/(int)pow(10, j)%10;
			if(a != b)
				return false;
		}
		return true;
	}

	//if negative then false
	//n stand for how many numbers in x
	//a, b stand for each number pair, and we check them

	//test case --> < 0 should return false
	//Input:-2147447412
	//Output:true
	//Expected:false

	//x/pow(10, i)%10  --> 错误的写法
	//pow: double pow (double base, double exponent);
	//运算符的优先级：/ 和 % 是一样的，而且都是左结合
	//对于运算符"/"，如果两个操作数的类型都是整数，则相除的结果是一个整数
	//如果两个操作数中有一个的类型是浮点型，则相除的结果是一个浮点数
	//对于%，两个操作数都必须是整数类型  --> 错误的原因
};
