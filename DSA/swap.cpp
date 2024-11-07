#include<iostream>

int main(){

    int a=10,b=20;
    int temp;
    temp=b;
    b=a;
    a=temp;
    std::cout << a ;
    std::cout << b ;
}