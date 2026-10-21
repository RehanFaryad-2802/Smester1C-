#include <iostream>
using namespace std;

int main() {
    cout << "Enter first and last number: " ;
    int start, end;
    cin>>start>>end;
    for (int i = start; i <= end; i++)
    {
        if (i<2) continue;
        bool isPrime = true;
        for (int j = 2; j*j <= i; j++)
        {
            if(i%j==0){
                isPrime = false; break;
            }
        }
        if(isPrime){
            cout << "Prime: " << i << endl;
        }
    }
        
    return 0;
}