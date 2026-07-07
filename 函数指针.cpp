#include <iostream>
using namespace std;

int add(int a,int b){
	return a+b;
}
int jian(int a,int b){
	return a-b;
}
int cheng(int a,int b){
	return a*b;
}
int chu(int a,int b){
	return a/b;
}

void calc(int a,int b,int (*op)(int,int)){
	cout<< op(a,b)<<endl;
}

int main(){
	calc(3,4,add);
}

