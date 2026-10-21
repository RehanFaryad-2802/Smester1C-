#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include<ctime>
#include <vector>
using namespace std;

void Stay(int a=1000);
void clean();
void PrintSequence(const vector<int>);
void GameOver(int i);
void Play();

vector<string> colors = {"Red", "Green", "Blue", "White"};
vector<int> Seq = {};
vector<int> userSeq = {};

bool isGameOver = false;
int max_level = 4;
char procede='n';
int roundNo = 0;
int totalWon = 0;

int main() {
    while(true){
        Play();
        if(!isGameOver){
            cout << "Wish to Play agin (y/n):";
            cin>>procede;
            if (procede =='y'){
                procede = 'n';
            }else{
                if(roundNo>0){
                    cout << "You score " << totalWon << " out of " << roundNo << " Matches." << endl;
                }
                break;
            }
        }else{
            break;
        }
    }
    return 0;
}
void Play(){
    srand(time(0));
    userSeq = {};
    Seq = {};
    isGameOver = false;
    procede='n';
    roundNo++;
    clean();
    while (procede !='y'){
        cout<<"Start Game? (y/n): ";
        cin>>procede;
        if(procede=='n'){
            isGameOver = true;
            break;
        }
    }

    clean();
    for (int j = 0; j < max_level; j++){
        if(isGameOver) break;
        Seq.push_back(rand()%4);
        cout << "Round "<< roundNo <<"\n";
        cout << "Your Color to Remember: " << endl;
        PrintSequence(Seq);
        clean();
        cout << "Round "<< roundNo <<"\n";
        cout << "1=[Red] 2=[Green] 3=[Blue] 4=[White]\n";
        int c;
        userSeq = {};
        for(int i = 0; i< Seq.size();i++){
            cout << "Enter your sequence of number With Space: ";
            cin>>c;
            c--;
            if(c<0) {
                isGameOver = true;
                break;
            }
            userSeq.push_back(c);
            if(Seq[i] != c){
                GameOver(j);
                isGameOver = true;
            }
        }
        if(!isGameOver)  clean();
        }
    if(!isGameOver){
        cout << "You Won!" << endl;
        cout << "You score " << max_level << " out of " << max_level<< "." << endl;
        totalWon++;

    }
}

void PrintSequence(const vector<int> list){
    cout << "[" << colors[list.back()] << "]" << endl;
    Stay();
}

void Stay(int a){
    Sleep(a);
}

void GameOver(int k){
    clean();
    cout << "1=[Red] 2=[Green] 3=[Blue] 4=[White]\n";
    if(!userSeq.empty()){
        cout << "Your Sequence: " << endl;
        for(int color: userSeq){
            cout << color+1 << " ";
        }
        cout << "\nActual Sequence: " << endl;
        for(int color: Seq){
            cout << color+1 << " ";
        }
    }
    cout << endl << "You Lost!" << endl;
    cout << "You score " << k << " out of " << max_level<< " in this match." << endl;
}

void clean(){
    system("cls");
}