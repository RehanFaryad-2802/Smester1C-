#include <iostream>
#include<ctime>
#include<iomanip>

using namespace std;

int main() {
    cout << "Enter Year Month: " ;
    int year, month;
    cin >> year>>month;
    tm Time={};
    Time.tm_year = year - 1900;
    Time.tm_mon = month-1;
    Time.tm_mday = 1;
    mktime(&Time);
    int days;
    switch (month)
    {
    case 2:
        days = ((year%4==0&year%100!=0) || year%400==0)? 29:28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
    days = 30;
    break;
    default:
        days = 31;
        break;
    }
    cout << "Su Mo Tu We Th Fr Sa" << endl;
    for (int i = 0; i < Time.tm_wday; i++)
    {
        cout << "   ";
    }
    for (int j = 1; j <= days; j++)
    {
         cout << setw(2) << j<<" ";
        if((j+Time.tm_wday)%7==0) cout<< endl;
    }
    
    
    return 0;
}