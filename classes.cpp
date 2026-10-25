#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Str
{
private:
    string String;

    string reveserWord(string n){
        string word;
        for (int i=n.length()-1;i>=0;i--) {
            word+=n[i];
        }
        return word;
    }
public:
    Str(string n) : String(n) {};

    vector<string> getStrArr()
    {
        vector<string> Arr = {};
        string word;
        for (char ch : String)
        {
            if (ch != ' ')
            {
                word += ch;
            }
            else
            {
                Arr.push_back(word);
                word = "";
            }
        }
        if (!word.empty())
            Arr.push_back(word);
        return Arr;
    }

    void printWords()
    {
        for (const string item : getStrArr())
        {
            cout << item << endl;
        }
    }
    
    string reverse()
    {
        string result = "";
        for (int i = String.length() - 1; i >= 0; i--)
        {
            result += String[i];
        }

        return result;
    }

    void print(){
        cout<< String;
    }

    vector<string> Palindrome (){
        vector<string> v;
        for (const auto& item : getStrArr()) { 
            if(item.length()>1 &&item==reveserWord(item)) v.push_back(item);
         }
        return v;
    }

    int length(){
        int total=0;
        for (const auto& item : getStrArr()) {
            total++;
        }
        return total;
    }

    int chrLength(){
        return String.length();
    }
};

int main()
{

    Str test("This");
    for (const auto& item : test.Palindrome()) {
        cout<<item;
    }
    
    return 0;
}