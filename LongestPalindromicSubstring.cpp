#include<bits/stdc++.h>

using namespace std;

void print_mat(string s,vector<vector<int> > &v){
    for(int i=0;i<s.length();i++){
        for(int j=0;j<s.length();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


string longestPalindrome(string s) {
    
    vector<vector< int > > v(s.length(),vector<int> (s.length()));
    
    for(int i=0;i<s.length();i++)
        v[i][i] = 1;
    int max_length = 1;
    int start_point = 0;
    
    for(int i=0;i<s.length()-1;i++){
        if(s[i] == s[i+1]){
            v[i][i+1] = 1;
            start_point = i;
            max_length = 2;
        }
    }

    print_mat(s,v);

    for(int i=2;i<s.length();i++){
        for(int j=0;j<s.length()-i;j++){
            if( v[j+1][j+i-1] && s[j] == s[j+i]){
                v[j][j+i] = 1;
                max_length = max(max_length,i+1);
                start_point = j;                    
            }
            else v[j][i+j] = 0;
        }
    }

    string str = s.substr(start_point,max_length);
    return str;
}


int main(){

	string str;
	cin>>str;

	cout<<longestPalindrome(str);

	return 0;
}

