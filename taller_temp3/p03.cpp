#include <bits/stdc++.h>

using namespace std;

int main(){

    int n_boys; cin >> n_boys;
    priority_queue <int> boys;

    while(n_boys--){
        int ability; cin >> ability;
        boys.push(ability);
    }

    int n_girls; cin >> n_girls;
    priority_queue <int> girls;

    while(n_girls--){
        int ability; cin >> ability;
        girls.push(ability);
    }

    int count = 0;
    while(not girls.empty() and not boys.empty()){
        if (abs(girls.top() - boys.top()) <= 1){
            count += 1;
            girls.pop();
            boys.pop();
        }
        else {
            if (girls.top() > boys.top()){
                girls.pop();
            }
            else {
                boys.pop();
            }
        }
    }
    cout << count << endl;
}