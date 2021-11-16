/*#define MAX(x,y) ((x)>(y))?(x):(y)
template < class T, T N> // pierwszy parametr dotyczy typu, kolejny sta³ej wartoœci parametru, który przekazaliœmy

template<class T>
class Etykieta : public T { // Etykieta<float>, czyli zamiast T podstawi float,
    T pole1;
    np.Etykieta<T*> pole2;
public:
    Etykieta(T t) {
    }
};

//specjalizacja template (czêœciowa)
template <class T>
class Etykieta <T*> {
};

//specjalizacja template (ca³oœciowa)
template <>
class Etykieta<int> { //jeœli bêdzie <int*> to wybierze t¹ specjalizacje niezale¿nie od kolejnoœci
};

template <class T>
void Etykieta(T t1, T t2) {

};
Etykieta(2, 3);
Etykieta<int>(2, 3);

//specjalizacja ca³kowita dla intów
template <class T>
void Etykieta(T t1, T t2) {
}
void Etykieta(int t1, int t2) {
}
Etykieta(1, 2)

template<class T>
void Etykieta(T&& t) {
    T t2(std::forward<T&&>(t));
    t2 += "abc";
}

int appendABC(string& s) {
    string s2(s);
    s2 += "abc";
    return s2;                                            //appendABC(s);
}                                                         //appendABC(foo());
string appendABC(string&& s) {
    string s2(move(s));
    s2 += "abc";
    return s2;
}

tuple <string, string> appendABC(string& s1, string& s2) { ... }
tuple<string, string> appendABC(string&& s1, string& s2) { ... }
tuple<string, string> appendABC(string& s1, string&& s2) { ... }
tuple<string, string> appendABC(string&& s1, string&& s2) { ... }


template <class T1, class T2>
tuple<decay_t<T1>, decay_t<T2>>
appendABC(T1&& t1, T2&& t2) {
    decay_t<T1>s1(forward<T&&>(t1));
    dacay_t<T2>s2(forward<T2&&>(t2));
    s1 += "abc";
    s2 += "abc"
        tuple res(s1, s2);
    return res;
}

// wyra¿enia lambda // wzór [] () {}
//przez referencje
int x;
auto l = [&]()int{ x++; };
l();
[=, &x, &y]() {}
[&, x, y]() {x++; } // b³¹d x, przekazany przez wartoœæ i jest traktowany jako const nie da rady x++
[&, x, y]()mutable {}
[x = 2 * y](){x}
[x = move(s)](){x}
auto l = [] {},
l();
auto l = [](int x, int y) {};
l(1, 2);
auto l = [](auto a, auto b) {return a + b; }
cout << l(2, 3)
auto l = [](auto&& a, auto&& b) {return a + b; }
cout << l(2, 3);  //decltype(a)

auto main()->int {
};

template <class T>
auto foo(T t)->dectype(t()) {
};*/

#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
bool cmp(T a, T b){
    if (a > b)
        return true;
    else if (a < b)
        return false;
   }

bool cmp2(int a, int b) {
    if (a < b)
        return true;
    else if (a > b)
        return false;
}

int main() {
    bool parzysty = false;
    
    std::vector<int> liczby {4,7,1};

    /*std::sort(liczby.begin(), liczby.end(), [&, parzysty](int a, int b) 
        {
            if (parzysty)
                return (a > b);
            else
                return (a < b);
        });*/

    std::sort(liczby.begin(), liczby.end());

    bool abc = cmp(liczby[0], liczby[1]);

    for (auto i : liczby)
        std::cout << i << "\t";
    std::cout<< "\n";
    return 0;
}