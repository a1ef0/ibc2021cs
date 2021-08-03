#include <iostream>
#include <vector>

using namespace std;

int fin(int n){
    int a1 = 0, a2 = 1, s = 0;
    for (int i = 0; i < n; ++i){
        s = a1 + a2;
        a1 = a2;
        a2 = s;
    }
    return a1;
}

float avg(vector<int> arr){
    int s = 0;
    int n = arr.size();
    for (int e : arr){
        s += e;
    }
    return (float) s/n;
}

vector<int> bubble_sort(vector<int> vec){
    int n = vec.size();
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j){
            if (vec[i] < vec[j]) swap(vec[i], vec[j]);
        }
    }
    return vec;
}


int main(){
    int n, t;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> t;
        a[i] = t;
    }
    a = bubble_sort(a);
    for (int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
    return 0;
}