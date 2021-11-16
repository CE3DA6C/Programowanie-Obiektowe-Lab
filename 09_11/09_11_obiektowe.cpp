//Polimorfizn, dziedziczenie

class A{
public:
	virtual void foo(){}
}
class B: public A{
	public:
		void foo(){}
	~B(){} //nadpisany destruktor
}

int main(){
	A *pa = new B;
	pa -> foo();
	delete pa; //ok, bo nadpisalismy destruktor
}
// A a = B(); //poprawne

// żeby A mogło zamknąć B destruktor musi być wirtualny
// konstruktor nie może być wirtualny
// prywatne metody klasy A pozostają prywatne, klasa B ich nie widzi
