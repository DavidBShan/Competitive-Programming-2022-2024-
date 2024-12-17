#include <bits/stdc++.h>
using namespace std;

bool fun(deque<int> arr, int start){
    deque<int>dq;
    if(start){
        dq.push_back(arr.front());
        arr.pop_front();
    }else{
        dq.push_back(arr.back());
        arr.pop_back();
    }
    //cout << dq.front() << " " << dq.back()<<endl;
    //cout << dq.back() << " " << dq.front() << endl;
    while(!arr.empty()){
        if(dq.front()+1 == arr.back()){
            //cout << arr.back();
            dq.push_front(arr.back()); arr.pop_back();
        }else if(dq.front()+1 == arr.front()){
            //cout << arr.front();
            dq.push_front(arr.front()); arr.pop_front();
        }else if(dq.back()-1 == arr.back()){
            //cout << arr.back();
            dq.push_back(arr.back()); arr.pop_back();
        }else if(dq.back()-1 == arr.front()){
            //cout << arr.front();
            dq.push_back(arr.front()); arr.pop_front();
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    int T; cin >> T;
    for(int i = 0, N, page; i < T; i++){
        cin >> N; deque<int> arr;
        for(int j = 1, temp; j <= N; j++){
            cin >> temp; arr.push_back(temp);
        }
        if(fun(arr, 0) || fun(arr, 1)) cout << "Case #"<<i+1<<": yes"<<endl;
        else cout << "Case #"<<i+1<<": no"<<endl;
    }
}