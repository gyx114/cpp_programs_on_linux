#include <iostream>
using namespace std;

template<unsigned N>
struct factorial{
	constexpr static long long val=factorial<N-1>::val*N;
};

template<>
struct factorial<0>{
	constexpr static long long val=1;
};

int main(){

		cout<<10<<"!="<<factorial<10>::val<<endl;
}



