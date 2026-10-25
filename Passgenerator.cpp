#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

string GeneratePass(int a){
    string pass="";
    string passStr = "1[]2?/34&^%5<>,.6=_#7-*$89{}()`~\\|+@!";
    for (int i = 0; i < a; i++)
    {
        pass+=passStr[rand()% passStr.length()];
    }
    return pass;
}
void ShowHistory (vector<string> v){
    cout<<"History:\n";
    for (string i :v)
    {
        cout << i<<endl;
    }
    
}

void Copy(const char* text) {
    size_t len = strlen(text) + 1;                       
    HGLOBAL mem = GlobalAlloc(GMEM_MOVEABLE, len);       
    memcpy(GlobalLock(mem), text, len);                  
    GlobalUnlock(mem);
    OpenClipboard(0);                                    
    EmptyClipboard();                                   
    SetClipboardData(CF_TEXT, mem);                      
    CloseClipboard();      
}

int main() {
    srand(time(nullptr));
    char more = 'y', copy = 'n';
    vector<string> History={};
    int PassLength;
    cout<<"Enter pass length: ";
    cin>>PassLength;
    while (more == 'y')
    {
        system("cls");
        string NewPass = GeneratePass(PassLength);
        History.push_back(NewPass);
        cout << NewPass;
        cout<<"\nCopy? (y/n): ";
        cin>>copy;
        if(copy=='y')
           Copy(NewPass.c_str());
        else continue;
        cout<<"\nGenerate More? (y/n): ";
        cin>>more;
    }
    ShowHistory(History);
    
    return 0;
}