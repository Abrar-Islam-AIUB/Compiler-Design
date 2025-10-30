// Find the average value of the elements of an array.
#include<iostream>
using namespace std;
#include "1.5.h"

void avg(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    float res=float(sum)/n;
    cout<<"Average is::"<<res<<endl;
}
/*
int main(){
    int n;
    cout<<"enter size::"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Please enter::"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    avg(arr,n);

}*/