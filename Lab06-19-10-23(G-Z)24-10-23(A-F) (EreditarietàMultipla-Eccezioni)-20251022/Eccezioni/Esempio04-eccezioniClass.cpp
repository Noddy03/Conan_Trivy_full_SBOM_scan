#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;

class Test{
private:
	unsigned int value;	
public:	
	Test(int v) {
		try {
			if (v < 0) { 
	        	throw "ERR negative value";
	    	}
			value = v;
			cout << "class initialized with value:" << value << endl;	
		}
	    catch (...)
	    {
	        // exceptions from the initializer list and constructor are caught here
	        cout << "wrong data" << endl;
	    }
	}
};


int main(int argc, char *argv[]){
  Test var1(3);
  Test var2(-6);
  
  
  //system("PAUSE");
  return EXIT_SUCCESS;
}
