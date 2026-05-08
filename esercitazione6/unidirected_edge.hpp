#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

//Quando scrivo unidirected_edge(1, 5), sto creando un oggetto (una singola istanza della classe). 
//Questo oggetto ha le sue variabili private (_from e _to) dove memorizza quei due numeri. 
//È come se stessi costruendo una piccola scatola con dentro i numeri 1 e 5. 
//unidirected_edge arco_1(1, 5); -->  numeri 1 e 5 sono salvati dentro 'arco_1'


template<typename T>
class unidirected_edge {
private:
    T n_from;
    T n_to;

public:
    // Costruttore: garantisce che from < to
    unidirected_edge(T a, T b) {
		if (a<b){
			n_from = a;
			n_to = b;
		}
		else{
			n_from = b;
			n_to = a;
		}
    }

	
	// from() e to()
    T from() const { return n_from; }
    T to() const { return n_to; }
	
	// operator< 
    bool operator <(const unidirected_edge& other) const {
        if (n_from != other.n_from) { 
            return n_from < other.n_from;
        }
        return n_to < other.n_to;
    }
		//dati due nodi (a,b), (c,d), ordino in base alla prima componente (ovvero a<c) ; 
		//se a=c, allora guardo la seconda componente

	// operator==
    bool operator==(const unidirected_edge& other) const {
        return n_to==other.n_to && n_from==other.n_from;
    }
};

template <typename T>
	// operator <<
	ostream& //std::ostream indica che stiamo passando l'oggetto per riferimento
	//std::cout << a esegue la stampa di a e restituisce un riferimento a std::cout.
	//A quel punto, il risultato diventa (riferimento a cout) << b, e così via.
	//Se non usassimo & nel tipo di ritorno, il concatenamento si romperebbe dopo il primo elemento.
	operator<<(ostream& os, const unidirected_edge<T>& v)
	{
		os << "(" << v.from() << "," << v.to() << ")";
		return os;
	}
	
