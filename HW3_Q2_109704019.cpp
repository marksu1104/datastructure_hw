#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void spanfun(int day,vector<int> &v,vector<int> &span,stack<int> &s){
    if(s.empty() == false){

         if(v[day] >= v[s.top()]){
            while(s.empty() == false){
                if(v[day] < v[s.top()] ){
                    break;
                }
                s.pop();
            }
        }

    }

    if(s.empty() == false){
        span.push_back(day-s.top());
    }
    else{
        span.push_back(day+1);
    }

    s.push(day);
}

int main(){

    int n,points,day = 0;
    vector<int> v1,v2,span1,span2;
    stack<int> s1,s2;
    cin >> n;
    v1.reserve(n);
    v2.reserve(n);

    for(int k = 0; k < n ; k++){
        cin >> v1[k];
        v2[n-1-k] = v1[k]; 
    }

    for(int k = 0; k < n ; k++){
        spanfun(day,v1,span1,s1);
        spanfun(day,v2,span2,s2);
        day ++;
    }

    for(int i = 0; i < span1.size(); i++){
        cout << span1[i]+span2[span1.size()-1-i]-1 << " ";
    }

    return 0; 
}