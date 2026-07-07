#include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;


int gcd(int a,int b){
	while(b){
		int tmp=a%b;
		a=b;
		b=tmp;
	}
	return a;
}


pair<int,int> simplify(int u,int d){
	bool is_positive=(u>0&&d>0)||(u<0&&d<0);
	u=u>0?u:-u;
	d=d>0?d:-d;
	int g=gcd(u,d);
	u=is_positive?u:-u;
	return make_pair((u/g),(d/g));
}



class Fraction{
private:
	int numerator;
	int denominator;
public:
	Fraction(int a=0,int b=1){
		if(b==0){
			throw invalid_argument("分母不能为0");
		}
		reset(a,b);
	}
	
	int get_numerator()const{
		return numerator;
	}
	int get_denominator()const{
		return denominator;
	}
	
	void reset(int a=0,int b=1){
		if(b==0){
                	throw invalid_argument("分母不能为0");
                }
		auto [u,d]=simplify(a,b);
		numerator=u;
		denominator=d;
	}



	Fraction operator+(const Fraction& r)const{
		int u1=numerator;
		int d1=denominator;
		int u2=r.get_numerator();
		int d2=r.get_denominator();

		int d=d1*d2;
		int u=u1*d2+d1*u2;
		return Fraction(u,d);
	}
	
	friend ostream& operator<<(ostream& os,const Fraction& frac);

};


	ostream& operator<<(ostream& os,const Fraction& frac){
		os<<frac.get_numerator()<<'/'<<frac.get_denominator();
		return os;
	}




int main(){
    try {
        Fraction f1(1,2);
        Fraction f2(1,3);
        Fraction f3 = f1 + f2;
        cout << f1 << " + " << f2 << " = " << f3 << endl;

        Fraction f4(-1,2);
        Fraction f5(1,-3);
        cout << f4 << " + " << f5 << " = " << (f4 + f5) << endl;

        Fraction f6(2,4);
        cout << "2/4 = " << f6 << endl;

        // 测试异常
        try {
            Fraction f7(1,0);
        } catch (const invalid_argument& e) {
            cout << "捕获异常: " << e.what() << endl;
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
