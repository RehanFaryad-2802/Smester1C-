#include <iostream>
#include<ctime>
#include <string>

using namespace std;
string name[] = {"Rock", "Paper", "Scissors"};

string PC (){
    return name[rand()%3];
}

int main() {
    srand(time(0));
    cout<<"1 = Rock\n2 = Paper\n3 = Scissors\n";
    for (int i = 0; i < 5; i++){
        cout << "Enter 1 - 3 : ";
        int User;
        cin>>User;
        if(name[User] == PC()) cout << "Won!" << endl;else cout << "Lost!" << endl;
    }
}