#include<bits/stdc++.h>

using namespace std;

string convert_to_roman(int n){

    string s = "";

    vector<int> num{1,4,5,9,10,40,50,90,100,400,500,900,1000};
    vector<string> sym{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i =12;
    while(n>0){

        int div = n/num[i];
        n = n%num[i];
        while(div--){
            s += sym[i];
        }
        i--;
    }
    return s;
}



int main(){
    int n;
    cin>>n;
    cout<<convert_to_roman(n);
    return 0;
}