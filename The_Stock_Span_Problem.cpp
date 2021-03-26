#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector <int> Stock_Span_Problem(vector<int> Prices){

    vector<int> ans;
    stack<pair<int,int>> st;

    for(auto prices: Prices){
        int days=1;

        while(!st.empty() && st.top().first <= prices){
            days+=st.top().second;
            st.pop();
        }
        st.push({prices,days});
        ans.push_back(days);
    }
    return ans;
}

int main(){

    vector<int> s={100,80,60,70,60,75,85};
    vector<int> res=Stock_Span_Problem(s);

    for(auto i : res){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;

}