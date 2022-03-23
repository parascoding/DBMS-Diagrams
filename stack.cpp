#include<bits/stdc++.h>
using namespace std;
fstream file;

class Car{
    int model;
    string manufacturer;
    float power;
public:
    Car(){};
    int getModel();
    void setModel(int model);
    string getManufacturer();
    void setManufacturer(string manufacturer);
    float getPower();
    void setPower(float power);
};

int Car::getModel() {
    return this->model;
}

void Car::setModel(int model) {
    this->model = model;
}

string Car::getManufacturer() {
    return this->manufacturer;
}

void Car::setManufacturer(string manufacturer) {
    this->manufacturer = manufacturer;
}

float Car::getPower() {
    return this->power;
}

void Car::setPower(float power) {
    this->power = power;
}

template <class T> class Stack{
    int size;
    int top;
    T *a;
public:
    Stack(int x){
        top=-1;
        size=x;
        a=new T[size];
    }

    void push(T);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
};

template <class T> void Stack<T>::push(T val){
    if(isFull()){
        file<<"Error : Stack is already full\n";
    }
    a[++top]=val;
    // file<<"Pushed "<<val<<endl;
}


template <class T> T Stack<T>::pop(){
    if(isEmpty()){
        file<<"Error : Stack is already empty\n";
    }
    T temp=a[top--];
    // file<<temp<<" popped\n";
    return temp;
}
template <class T> T Stack<T>::peek(){
    if(isEmpty()){
        file<<"Error : Stack is already empty\n";
    }
    T temp=a[top];
    // file<<temp<<" is on top\n";
    return temp;
}
template <class T> bool Stack<T>::isEmpty(){
    return top==-1;
}
template <class T> bool Stack<T>::isFull(){
    return top==size-1;
}


int main(){
    file.open("output2.txt",ios::trunc | ios::out | ios::in);
    Stack<int> st(5);
    for(int i=0;i<5;i++){
        st.push(i);
    }

    for(int i=5;i>0;i--){
        st.pop();
    }

    
    Stack<float> st_float(5);
    for(int i=0;i<5;i++){
        st_float.push((i*10)/3.0);
    }

    for(int i=5;i>0;i--){
        st_float.pop();
    }
    
        
    Stack<string> st_string(5);
    for(int i=0;i<5;i++){
        st_string.push(to_string(i*123)+"@#");
    }

    for(int i=5;i>0;i--){
        st_string.pop();
    }

    Stack<Car> st_car(2);
    Car car1;
    car1.setManufacturer("Hyundai");
    car1.setModel(123);
    car1.setPower(200);

    st_car.push(car1);


    Car car2;
    car1.setManufacturer("Tata");
    car1.setModel(250);
    car1.setPower(300);

    st_car.push(car2);
    
    st_car.pop();
    st_car.pop();
    return 0;
}
