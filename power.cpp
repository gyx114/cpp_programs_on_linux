#include <iostream>
using namespace std;

template<int x,unsigned y>
struct power{
	constexpr static int val=power<x,y-1>::val*x;
};

template<int x>
struct power<x,0>{
	constexpr static int val=1;
};

int main(){
	cout<<"7^6="<<power<7,6>::val<<endl;
}





