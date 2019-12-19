//
// Created by Mehedi on 19-Dec-19.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

//#define I 1
//#define V 5
//#define X 10
//#define L 50
//#define C 100
//#define D 500
//#define M 1000

using namespace std;

vector<int> numbers;
string romanGlobal = "";
int divisorFunction(int number) {
    int x = (log10(number)) + 1;
    int divisor;
    switch (x) {
        case 4:
            divisor = 1000;
            break;
        case 3:
            divisor = 100;
            break;
        case 2:
            divisor = 10;
            break;
        case 1:
            divisor = 1;
            break;
        default:
            cout<<"Error!! Entered at default clause at divisorFunction"<<endl;
            break;
    }
    return divisor;
}

void romanNumeral(int number) {
    int temp = number;
    string roman="";
    while (temp > 0) {
        int divisor = divisorFunction(temp);
        int a = temp / divisor;
        numbers.push_back(a * divisor);
        temp = temp - (a * divisor);
    }
    for (int i : numbers) {
        if (i >= 1000 && i <= 3000) {
            switch (i) {
                case 1000:
                    roman.push_back('M');
                    break;
                case 2000:
                    roman.push_back('M');
                    roman.push_back('M');
                    break;
                case 3000:
                    roman.push_back('M');
                    roman.push_back('M');
                    roman.push_back('M');
                    break;
                default:
                    cout<<"Error!! Entered at default clause at for loop 1000<=i<3000"<<endl;
                    break;
            }
        } else if (i >= 500 && i < 1000) {
            switch (i) {
                case 500:
                    roman.push_back('D');
                    break;
                case 600:
                    roman.push_back('D');
                    roman.push_back('C');
                    break;
                case 700:
                    roman.push_back('D');
                    roman.push_back('C');
                    roman.push_back('C');
                    break;
                case 800:
                    roman.push_back('D');
                    roman.push_back('C');
                    roman.push_back('C');
                    break;
                case 900:
                    roman.push_back('C');
                    roman.push_back('M');
                    break;
                default:
                    cout<<"Error!! Entered at default clause at for loop 500<=i<1000"<<endl;
                    break;
            }
        } else if (i >= 100 && i < 500) {
            switch (i) {
                case 100:
                    roman.push_back('C');
                    break;
                case 200:
                    roman.push_back('C');
                    roman.push_back('C');
                    break;
                case 300:
                    roman.push_back('C');
                    roman.push_back('C');
                    roman.push_back('C');
                    break;
                case 400:
                    roman.push_back('C');
                    roman.push_back('D');
                    break;
                default:
                    cout<<"Error!! Entered at default clause at for loop 100<=i<500"<<endl;
                    break;
            }
        } else if (i >= 50 && i < 100) {
            switch (i) {
                case 50:
                    roman.push_back('L');
                    break;
                case 60:
                    roman.push_back('L');
                    roman.push_back('X');
                    break;
                case 70:
                    roman.push_back('L');
                    roman.push_back('X');
                    roman.push_back('X');
                    break;
                case 80:
                    roman.push_back('L');
                    roman.push_back('X');
                    roman.push_back('X');
                    roman.push_back('X');
                    break;
                case 90:
                    roman.push_back('X');
                    roman.push_back('C');
                default:
                    cout<<"Error!! Entered at default clause at for loop 50<=i<100"<<endl;
                    break;
            }
        } else if(i>=10&&i<50){
            switch (i) {
                case 10:
                    roman.push_back('X');
                    break;
                case 20:
                    roman.push_back('X');
                    roman.push_back('X');
                    break;
                case 30:
                    roman.push_back('X');
                    roman.push_back('X');
                    roman.push_back('X');
                    break;
                case 40:
                    roman.push_back('X');
                    roman.push_back('L');
                    break;
                default:
                    cout<<"Error!! Entered at default clause at for loop 10<=i<40"<<endl;
                    break;
            }
        } else if(i>=5&&i<10){
            switch (i) {
                case 5:
                    roman.push_back('V');
                    break;
                case 6:
                    roman.push_back('V');
                    roman.push_back('I');
                    break;
                case 7:
                    roman.push_back('V');
                    roman.push_back('I');
                    roman.push_back('I');
                    break;
                case 8:
                    roman.push_back('V');
                    roman.push_back('I');
                    roman.push_back('I');
                    roman.push_back('I');
                    break;
                case 9:
                    roman.push_back('I');
                    roman.push_back('X');
                default:
                    cout<<"Error!! Entered at default clause at for loop 5<=i<10"<<endl;
                    break;
            }
        } else if (i>=1&&i<5){
            switch (i) {
                case 1:
                    roman.push_back('I');
                    break;
                case 2:
                    roman.push_back('I');
                    roman.push_back('I');
                    break;
                case 3:
                    roman.push_back('I');
                    roman.push_back('I');
                    roman.push_back('I');
                    break;
                case 4:
                    roman.push_back('I');
                    roman.push_back('V');
                    break;
                default:
                    cout<<"Error!! Entered at default clause at for loop 1<=i<5"<<endl;
                    break;
            }
        } else{
            cout<<"Error!! Entered at else clause"<<endl;
        }
    }
    cout<<roman<<endl;
}
