#include <iostream>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

struct BigIntContainer
{
    string bignum;
    int digitnum;
};

int charToInt(char ch)
{
    return ch - '0';
}

void addition(BigIntContainer &num1, BigIntContainer &num2)
{
    if (num1.bignum.empty() || num2.bignum.empty()) {
        cout << "Error: Empty BigIntContainer detected." << endl;
        return;
    }
    BigIntContainer result;
    int maxi = max(num1.digitnum, num2.digitnum);
    int mini = min(num1.digitnum, num2.digitnum);
    vector<int> v;
    v.push_back((charToInt(num1.bignum[maxi - 1]) + charToInt(num2.bignum[mini - 1])) % 10);
    
    if(num1.digitnum!=num2.digitnum){
    for (int i = 0; i < abs(maxi - mini ); i++)
    {
        if (num1.digitnum == maxi)
        {
            num2.bignum = '0'+num2.bignum;
        }
        else
        {
            num1.bignum = '0'+num1.bignum;
        }
    }
    cout<<"Num1:"<<num1.bignum<<" Num2:"<<num2.bignum<<endl;
    }
    
    if (num1.digitnum == maxi)
        num2.digitnum = maxi;
    if (num2.digitnum == maxi)
        num1.digitnum = maxi;

    for (int i = 1; i < maxi; i++)
    {
        int sum = (charToInt(num1.bignum[maxi - i - 1]) + charToInt(num2.bignum[maxi - i - 1])) % 10;
        int carry = (charToInt(num1.bignum[maxi - i ]) + charToInt(num2.bignum[maxi - i ])) / 10;
        v.push_back((sum + carry) % 10);
    }
    reverse(v.begin(), v.end());
    ostringstream oss;
    for (const auto &num : v)
    {
        oss << num;
    }
    result.bignum = oss.str();
    cout << result.bignum << '\n';
}
