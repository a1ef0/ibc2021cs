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

void bubble_sort(vector<int> vec){
    int n = vec.size();
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j){
            if (vec[i] < vec[j]) swap(vec[i], vec[j]);
        }
    }
}

void pr(vector<int> vec){
    int n = vec.size();
    for (int i = 0; i < n; ++i){
        cout << vec[i] << ' ';
    }
    cout << endl;
}

void merge(vector<int> vec, int beg, int mid, int end){
    int l1 = mid - beg + 1;
    int l2 = end - mid;

    vector<int> left(l1), right(l2);
    
    for (int i = 0; i < l1; i++)
        left[i] = vec[beg + i];
    
    for (int j = 0; j < l2; j++)
        right[j] = vec[mid + 1 + j];
    
    //pr(left);
    //pr(right);
    
    int i = 0, j = 0, k = beg;

    while (i < l1 && j < l2){
        if (left[i] <= right[j]){
            vec[k] = left[i];
            ++i;
        }
        else{
            vec[k] = right[j];
            ++j;
        }
        ++k;
    }

    while (i < l1){
        vec[k] = left[i];
        ++i;
        ++k;
    }

    while (j < l2){
        vec[k] = right[j];
        ++j;
        ++k;
    } 
}

void merge_sort(vector<int> vec, int beg, int end){
    if (beg >= end) return;

    int mid = beg + (end - beg)/2;

    merge_sort(vec, beg, mid);
    merge_sort(vec, mid+1, end);
    merge(vec, beg, mid, end);
}

int main(){
    int n, t;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> t;
        a[i] = t;
    }
    //bubble_sort(a);
    merge_sort(a, 0, n-1);
    for (int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}