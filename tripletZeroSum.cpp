#include<bits/stdc++.h>

using namespace std;


//bruteForce

void is_triplet_possible(int index, int sum, vector<int> vl,vector<int> v, int n,set<vector<int> > &s){
    if(index > n || v.size()>3){
        v.clear();
        return;
    }
    if(v.size()==3){
        if(sum == 0){
            sort(v.begin(),v.end());
            s.insert(v);
        }else 
            v.clear();
    }
    vector<int> vi(v.begin(),v.end());
    vi.push_back(vl[index]);
    is_triplet_possible(index+1,sum+vl[index],vl,vi,n,s);
    is_triplet_possible(index+1,sum,vl,v,n,s);
}



vector<vector<int> >  find_triplets(vector<int> &v){

    set<vector<int> >s;
    vector<vector<int> > ans;

    if(v.size() <3)
        return ans;

    for(int i=0;i<v.size()-2;i++){
        vector<int> vi;
        vi.push_back(v[i]); 
        is_triplet_possible(i+1,v[i],v,vi,v.size(),s);
    }

    set<vector<int> > :: iterator it = s.begin();
    while(it != s.end()){
        ans.push_back(*it);
        it++;
    }

    return ans;

}

// O(n^2) approach  O(n) extra space
//We will store the elemets of array in hash table and for every pair of 
// numbers we will check whether the number is in hash table or not 
// if in hash table we will insert it in vector

vector<vector<int> > findTripletsOpti(vector<int> &v){

    set<vector<int> > s;
    int n= v.size();
    for(int i=0;i<n-1;i++){
        unordered_set<int> hash_tb;
        for(int j=i+1;j<n;j++){
            int x = -(v[i]+v[j]);
            if(hash_tb.find(x) != hash_tb.end() ){
                vector<int> vi{v[i],v[j],-(v[i]+v[j])};
                sort(vi.begin(),vi.end());
                s.insert(vi);
            }
            else 
                hash_tb.insert(v[j]);
        }
    }
    vector<vector<int> > ans;
    set<vector<int> > :: iterator it  = s.begin();
    while (it != s.end()){
        ans.push_back(*it);
        it++;
    }
    return ans;
}


/* 
    O(n^2) time + O(1) extra space -> sort the list
    

*/






int main(){

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    // vector<vector<int> > ans =  find_triplets(v);
    vector<vector<int> > ans = findTripletsOpti(v);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<3;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}