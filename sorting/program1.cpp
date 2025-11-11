#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> left,vector<int> right){
    int i = 0;
    int j = 0;
    int m = left.size();
    int n = right.size();
    vector<int> sorted(m+n);
    int k=0;

    while(i<m && j<n){
        if(left[i]<right[j]){
            sorted[k] = left[i];
            i++;
        }
        else{
            sorted[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<m){
        sorted[k] = left[i];
            i++;
            k++;
    }
    while(j<n){
        sorted[k] = right[j];
            j++;
            k++;
    }
    return sorted;
}

vector<int> mergeSort(vector<int> arr,int s, int e){
    
}

int main(){
    vector<int> arr = {4,5,10,2,8,1,56,22};

    arr = mergeSort(arr,0,arr.size()-1);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}