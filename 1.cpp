#include <iostream>
using namespace std;
int main(){
   int LA[3] = {}, i;
   cout << "Array:" << endl;
   for(i = 0; i < 5; i++) {
      LA[i] = i + 2;
      cout << "LA[" << i <<"] = " << LA[i] << endl;
   }
   return 0;
}