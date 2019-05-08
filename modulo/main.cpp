#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void permute(string select, string remain, long &maks, long broj){

    if(remain == ""){
        long temp = atol( select.c_str() );
        if(temp < broj && temp % 8 == 5 )
            maks = temp;
        return;
    }

    for(int i=0;remain[i];++i){
        string wk(remain);
        permute(select + remain[i], wk.erase(i, 1), maks, broj);
    }
}

struct great
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

int main()
{
    string broj;
    long maks=-1;

    cout << "Upisi broj: " << endl;
    cin >> broj;
    int polje[broj.length()];
    long temp = atol( broj.c_str() );
    long b = temp;
    for (int i = 0; i < broj.length(); i++){
        polje[i] = temp%10;
        temp /= 10;
    }

    std::sort(broj.begin(), broj.end(), great());
    permute("", broj, maks, b);
    cout << "perm: "<< maks<< endl;

    return 0;
}
