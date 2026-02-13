#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    bool check(char arr[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == '.') {
            count++;
            if(count == 3) return true; 
        }
        else {
            count = 0;
        }
    }
    return false;
}


    int counter(char arr[], int n){
        int count = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == '.'){
                count++;
            }
        }
        return count;
    }
};

int main() {
    solution obj;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        if(obj.check(arr, n)){
            cout << "2" << endl;
        }
        else{
            cout << obj.counter(arr, n) << endl;
        }
    }
    return 0;
}
