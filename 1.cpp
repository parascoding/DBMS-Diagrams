#include<iostream>
using namespace std;

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
    friend bool operator > ( Car,Car);
    friend bool operator <= ( Car,Car);
    friend bool operator < (Car, Car);
    friend bool operator == (Car,Car);
    friend ostream& operator<<(ostream& os, Car c);
    
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
bool operator < (Car c1, Car c2){
    return c1.getModel() < c2.getModel();
}
bool operator <= (Car c1, Car c2){
    return c1.getModel() <= c2.getModel();
}
bool operator > (Car c1, Car c2){
    return c1.getModel() > c2.getModel();
}
bool operator == (Car c1, Car c2){
    return c1.getModel() == c2.getModel();
}
ostream& operator<<(ostream& os, Car c)
{
    os << c.getModel();
    return os;
}

template <class A>

void merge(A a[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    A *L=new A[n1];
    A *R=new A[n2];
    for(int i=0;i<n1;i++)
        L[i]=a[l+i];
    for(int i=0;i<n2;i++) 
        R[i]=a[m+1+i];


    int i=0,j=0,k=l;

    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i++];
        }
        else
        {
            a[k]=R[j++];
        }
        k++;
        
    }
    while(i<n1)
    a[k++]=L[i++];
    while(j<n2)
    a[k++]=R[j++];
}
template <class A>
void Sort(A arr[], int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        Sort(arr, low, mid);
        Sort(arr, mid+1, high);
        merge(arr, low,mid, high);
    }
}
template <class A>
int bs(A arr[],int n,A target){
    int start=0;
    int end=n-1;
    Sort(arr, start, end);

    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            start=mid+1;
        }
        else
        {
            end = mid-1;
        }

    }
    return -1;
}

int main()
{
    char arr[6]={'a','b','c','d','e','f'};
    Car *c=new Car[2];
    c[0].setModel(250);
    c[1].setModel(150);
    Car t;
    t.setModel(150);
    int temp=bs(c,2,t);
    cout<<temp;
    return 0;
}
