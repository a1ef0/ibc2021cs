#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, t;
    cin >> n;
    if (n < 1) {
        cout << "no\n";
        return 0;
    }

    vector<int> a(n);
    set<int> se;

    for (int i = 0; i < n; ++i){
        cin >> t;
        a[i] = t;
        se.insert(t);
    }


    if (se.size() != n){
        cout << "the array is not unique!\n";
    }
    else cout << "unique\n";
    return 0;
}