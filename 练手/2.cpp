#include <vector>
#include <iostream>

using namespace std;

template<typename T>
const T& findMax(const vector<T>& vec,int size){
	int idx=0;
	for(int i=0;i<size;i++){
		if(vec[i]>vec[idx]){
			idx=i;
		}
	}
	return vec[idx];
}

template<typename T>
const T& findMax(const T* arr,int size){
	int idx=0;
	for(int i=0;i<size;i++){
		if(arr[i]>arr[idx]){
			idx=i;
		}
	}
	return arr[idx];
}

template<typename T>
class Box{
private:
	T content;
public:
	Box(const T& t):content(t){}
	const T& getcontent()const;
};

template<typename T>
const T& Box<T>::getcontent()const{
	return this->content;
}




int main() {
    // 测试数组版本
    int intArr[] = {3, 7, 2, 9, 5};
    const int& maxInt = findMax(intArr, 5);
    cout << "int数组最大值: " << maxInt << endl;
    
    double dblArr[] = {2.5, 1.8, 3.14, 0.99};
    const double& maxDbl = findMax(dblArr, 4);
    cout << "double数组最大值: " << maxDbl << endl;
    
    // 测试vector版本
    vector<int> vec = {10, 20, 30, 15, 25};
    const int& maxVec = findMax(vec, 5);
    cout << "vector最大值: " << maxVec << endl;
    
    // 测试Box类模板
    Box<int> intBox(42);
    cout << "Box<int>内容: " << intBox.getcontent() << endl;
    
    Box<string> strBox("Hello World");
    cout << "Box<string>内容: " << strBox.getcontent() << endl;
    
    return 0;
}
