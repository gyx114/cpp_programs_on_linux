#include <iostream>
#include <stdexcept>

using namespace std;

class Account{
private:
	double balance;
public:
	Account(double i=0):balance(i){
		if(i<0){
			throw invalid_argument("初始金额不可为负");
		}
	}
	void withdraw(double amount){
		if(amount<0){
			throw invalid_argument("取款金额不能为负");
		}
		else if(amount>balance){
			throw runtime_error("余额不足");
		}
		else{
			balance-=amount;
		}
	}
	double get_balance(){
		return balance;
	}
};


int main(){
	Account acc(1000);

	try{
		cout<<acc.get_balance()<<endl;
                acc.withdraw(500);
                cout<<acc.get_balance()<<endl;
	}
	 catch(invalid_argument &e){
                cerr<<e.what()<<endl;
        }
        catch(runtime_error &e){
                cerr<<e.what()<<endl;
        }
        catch(exception & e){
                cerr<<e.what()<<endl;
        }
        catch(...){
                cerr<<"error"<<endl;
        }

	try{
		acc.withdraw(2000);
		cout<<acc.get_balance()<<endl;
	}
	catch(invalid_argument &e){
		cerr<<e.what()<<endl;
	}
	catch(runtime_error &e){
		cerr<<e.what()<<endl;
	}
	catch(exception & e){
		cerr<<e.what()<<endl;
	}
	catch(...){
		cerr<<"error"<<endl;
	}


	try{
		acc.withdraw(-50);
		cout<<acc.get_balance()<<endl;
	}
	 catch(invalid_argument &e){
                cerr<<e.what()<<endl;
        }
        catch(runtime_error &e){
                cerr<<e.what()<<endl;
        }
        catch(exception & e){
                cerr<<e.what()<<endl;
        }
        catch(...){
                cerr<<"error"<<endl;
        }
}
