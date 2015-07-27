class Solution {
public:
	int mySqrt(int x) {
		if(x < 0) return -1;
		if(x == 0) return 0;
		int l = 1, r = x/2 + 1;
		while(l <= r) {
			int m = (l + r)/2;
			if(m<= x/m &&  x/(m+1) < (m+1))
				return m;
			else if(x/m < m)
				r = m - 1;
			else
				l = m + 1;
		}
		return 0;  //不会从这句退出，不过还是加上
	}

	//binary search
	//取定左界和右界，然后每次砍掉不满足条件的一半，直到左界和右界相遇
	//time : O(log n), space: O(1)

	int mySqrt(int x) {
		if(x == 0)
            return 0;
        double last = 0, cur = 1;
        while(cur != last) {
            last = cur;
            cur = (cur + x/cur)/2;        
        }
        return int(cur);
	}

	//牛顿迭代法
	//不断用(x,f(x))的切线来逼近方程x^2-a=0的根。
	//根号a实际上就是x^2-a=0的一个正实根，这个函数的导数是2x。
	//也就是说，函数上任一点(x,f(x))处的切线斜率是2x。
	//那么，x-f(x)/(2x)就是一个比x更接近的近似值。
	//代入 f(x)=x^2-a得到x-(x^2-a)/(2x)，也就是(x+a/x)/2。	
};
