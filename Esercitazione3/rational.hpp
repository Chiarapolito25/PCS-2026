#pragma once
#define STACK_SIZE 8
//per gestire i casi in cui si ha infinito o NaN, ho utilizzato delle variabili booleane, che mi segnano true se
//ho il caso in cui il numero razionale è infinito o indeterminato. In particolare l'oggetto rational è definito 
//=inf se num!=0 e den==0, =NaN se den==num==0; 
using namespace std;

template<typename I> requires std::integral<I>
//costruttore di default
class rational 
{
	I num_;
	I den_;
	
	int MCD(int a, int b){
		
		a=std::abs(a);
		b=std::abs(b);
		int resto;
		if (a>=b){
			while (b != 0) {
				resto = a % b;
				a = b;
				b = resto;
			}
			return a;
		}
		else{
			while (a != 0) {
				resto = b% a;
				b= a;
				a= resto;
			}
			return b;
		}
		
    }
	
	
	void semplificazione(){
		int m;
		if (den_!=0){
			m=MCD(num_,den_);
			num_=num_/m;
			den_=den_/m;
		}
		if (den_<0){
			num_ = -num_;
			den_ = -den_;
		}
	}	


public:
	rational(): num_(I{0}),den_(I{1}){}
	//inizializzo numeratore e denominatore (se non lo facessi, il calcolatore 
	//inizializzerebbe num=den=0 e questo poi mi da errore nella divisione)


	//costruttore user-defined:prende in input pnum e pden
	rational(const I& pnum, const I&pden) : num_(pnum), den_(pden){	
		//quello che scrivo dopo i ":" significa che voglio inizializzare 
		//direttamente i membri num_ e den_ con i valori in input
		if (den_==0 && num_!=0){
			num_= I{1};
		}
		if (den_==0 && num_==0){} //se invece ho 0/0--> NaN
		else{
			semplificazione();
		}
	}
	//se invece ho 0/0--> NaN
	

	//per legge i valori di num e den all'esterno della classe, ovvero per esempio nel main
	I num() const { return num_;}
	I den() const { return den_;}


	//implementazione dell'incremento +=
	//quando scrivo a+=b --> this=a, other=back
	//a/b + c/d = (a*d+c*b)/b*d
	rational& operator+=(const rational& other){
		if ((den_==0 && num_==0)||(other.den_==0 && other.num_==0)){ //0/0 corrisponde a NaN
			num_=I{0};
			den_=I{0};
		}
		if ((den_==0 && num_!=0)||(other.den_==0 && other.num_!=0)){
			num_=I{1};
			den_=I{0};
		}
		else{
			num_= (num_*other.den_)+(other.num_*den_);
			den_=den_*other.den_;
		}
		return *this;
	}
	
	//implementazione della somma
	rational operator+(const rational& other) const{
		rational ret = *this; // Faccio una copia di rational e la chiamo ret
		ret += other;        // Uso il += che abbiamo scritto prima tra rational e other
		ret.semplificazione();
		return ret;          // Restituisco il nuovo oggetto
	}
	
	//spiegazione del perchè ho due funzioni:
	// "operator+=" è quello che modifica l'oggetto. Prende il numero attuale, gli somma other seguendo la formula del minimo comune multiplo 
	//e sovrascrive i valori interni
	
	//"operator+" crea una copia del numero attuale (rational ret = *this), usa la funzione operator+= per sommare other alla copia (ret += other).
	// infine restituisce la copia --> posso scrivere c = a + b; senza che a e b vengano modificati.
	
	
	
	//implementazione del decremento -=
	///b -c/d = (a*d-c*b)/b*d
	rational& operator-=(const rational& other){
		if ((den_==0 && num_==0)||(other.den_==0 && other.num_==0)){ //0/0 corrisponde a NaN
			num_=I{0};
			den_=I{0};
		}
		if ((den_==0 && num_!=0)||(other.den_==0 && other.num_!=0)){
			num_=I{1};
			den_=I{0};
		}
		else{
			num_= (num_*other.den_)-(other.num_*den_);
			den_=den_*other.den_;
		}
		
		return *this;
	}
	
	//implementazione della differenza
	rational operator-(const rational& other) const{
		rational ret = *this;
		ret -= other; 
		ret.semplificazione();		
		return ret;         
	}
	
	//implementazione di *
	rational& operator*=(const rational& other){
		if ((den_==0 && num_==0)||(other.den_==0 && other.num_==0)){ //0/0 corrisponde a NaN
			num_=I{0};
			den_=I{0};
		}
		if ((den_==0 && num_!=0)||(other.den_==0 && other.num_!=0)){
			num_=I{1};
			den_=I{0};
		}
		else{
			num_ *=other.num_;
			den_ *=other.den_;
		}
		
		return *this;
	}
	
	//implementazione del prodotto 
	
	rational operator*(const rational& other) const{
		rational ret=*this;
		ret*=other;
		ret.semplificazione();
		return ret;
	}
	
	//implementazione di "/"
	// a/b : c/d= a/b *d/c
	rational& operator/=(const rational& other){
		if ((den_==0 && num_==0)||(other.den_==0 && other.num_==0)){ //0/0 corrisponde a NaN
			num_=I{0};
			den_=I{0};
			return *this;
		}
		if ((den_==0 && num_!=0)||(other.num_==0)){ //il secondo termine si capovolge, quindi deve avere numeratore diverso da 0 per essere ben definito
			num_=I{1};
			den_=I{0};
		}
		else{ //Poichè il secondo termine della divisione si capovolge, se ho infinito=1/0, allora la divisione per infinito è ben definita
			den_ *=other.num_;
			num_ *=other.den_;
			
		}
		
		return *this;
	}
	
	rational operator/(const rational& other) const{
		rational ret=*this;
		ret/=other;
		ret.semplificazione();
		return ret;
	}
};

template<typename T> 
	// definisco l'operatore <<
	ostream&
	operator<<(ostream& os, const rational<T>& v)
	{
		if (v.num()==0 && v.den()==0){
			return os << "NaN";
		}
		if (v.num()!=0 && v.den()==0){
			if (v.num()<0){
				return os << "-inf";
			}
			if (v.num()>0){
				return os << "inf";
			}
			return os;
		}
		else{
			os << v.num() << "/" << v.den();
			return os;
		}
		
	}