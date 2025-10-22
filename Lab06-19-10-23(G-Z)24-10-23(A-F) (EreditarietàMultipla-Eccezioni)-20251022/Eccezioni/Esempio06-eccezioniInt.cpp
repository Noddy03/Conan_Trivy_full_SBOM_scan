#include <iostream>
#include <stdexcept>
using namespace std;

int dividi(int a, int b){
	/*if (a<0 || b<0){throw invalid_argument("val negativi");}*/
	if (a<0) {throw 0;}
	if (b<0) {throw 1;}
	if (b==0) {throw 2; }
	if (a>10) {throw 3;	}
	return a/b;
}
void test(){
	int a=12, b=5;
	try{
		cout << dividi(a,b) << endl;
	}catch(const int& err){
		switch (err){
			case 0: { cout << "a negativo"<< endl; break; }
			case 1: { cout << "b negativo"<< endl; break; }
			case 2: { cout << "divisione per 0"<< endl; break; }
			case 3: { cout << "a troppo grande"<< endl; break; }
			default: cout << "ERR" << endl;
		}
	}
	
	cout << "end test" << endl;
 }

int main(int argc, char** argv) {
	test();
	return 0;
}
