#include <iostream>
using namespace std;
class Base {
public:
    int* ptr;
    Base(int i = 1) {
        cout << "Base Kurucu" << endl;
        ptr = new int(i);

    }
    //farklı bellek gözleri için 
    //Kopyalama kurucusu
    Base(const Base& b) {

        ptr = new int(*b.ptr);
    }
    //: Kalıtım Yıkıcı ( Destructor ) Methodun Kullanılması herhangi bir parametre almıyor yıkıcıda delete ile 
    ~Base() {
        cout << "base yikici" << endl;
        delete ptr;
    }
};
class Derived : public Base {
public:
    int* ptr2;
    Derived(int i = 2, int j = 2) : Base(i) {
        cout << "Derived kurucu" << endl;
        ptr2 = new int(j);
    }
    //d nesneyi ptr2 değeri ata
    Derived(const Derived& d) :Base(d) {
        cout << "derived kopyalama kurucusu " << endl;
        ptr2 = new int(*d.ptr2);
    }//taban sınıfın kurucusununa taban sınıfın parametresi~Derived(
    ~Derived() {
        cout << "Derived yikici Kurucu " << endl;
        delete ptr2;

    }
};
int main()
{/*
    Base b(100);
    return 0;
    cout << b.ptr << "Derived kurucu " << *b.ptr << endl;
    Base xb = b;
    cout << xb.ptr << "\t" << *xb.ptr << endl;
    */
    Derived d;
    //hangi belekte  
    cout << d.ptr2 << "\t" << *d.ptr2 << endl;
    Derived xd = d;
    cout << xd.ptr2 << "\t" << *d.ptr2 << endl;
    cout << endl << endl; //aynı belleği gösteriyor

    cout << d.ptr << "\t" << *d.ptr;//d  üsütündeki pointerin hangi adreste 
    cout << xd.ptr << "\t" << *xd.ptr << endl;
}


