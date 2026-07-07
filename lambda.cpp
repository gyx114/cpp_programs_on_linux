#include <iostream>
using namespace std;

template<typename func>
void f(int a,int b,func op){
	cout<<op(a,b)<<endl;
}

int main(){
	const int gyx=114;
	int a=1;
	int b=2;
	f(a,b,[](int a,int b){return a+b;});
	f(a,b,[gyx](int a,int b){return a+b+gyx;});
}
