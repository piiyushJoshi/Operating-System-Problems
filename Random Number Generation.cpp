#include <iostream>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class PRNG{ 
    int multiplier=1 , seed=1, increment = 1, modulus=1;
    int n;
    public:
    PRNG(){
        srand(time(0));
        n =rand();
        cout<<n<<endl;
        }
        PRNG(int seed){
            n = seed;
            cout<<n<<endl;
        }
        PRNG(int multiplier,int seed,int increment,int modulus) {
             n = (multiplier * seed + increment) % modulus;
            cout<<n<<endl;
        }
};
int main() {
    PRNG();
    PRNG(5);
    PRNG(40,1,3641,729);
}
