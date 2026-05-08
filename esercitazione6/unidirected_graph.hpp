#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iterator>
#include <stdexcept> //fornisce classi come std::out_of_range o std::invalid_argument 
					//per "lanciare" un segnale d'allarme
#include "unidirected_edge.hpp"
using namespace std;

// per rappresentare un grafo utilizzo una lista di adiacenza (perchè devo cercare i vicini,
//quindi a livello computazionale mi conviene la lista piuttosto che la matrice.
//la lista di adiacenza è un'unione di un erray (che rappresenta i vertici) 
//e una lista (che rappresenta i collegamenti tra gli archi. Per implementare la lista di adicenza: 
//std::map che tiene i nodi ordinati
//o std::unordered_map dove i nodi non sono ordinati; veloce per trovare i vicini
//std::set se voglio cercare un arco specifico : mi crea un elenco di archi unici e ordinati
//


template<typename T>
class unidirected_graph {
private:
	// Rappresentazione tramite lista di adiacenza
    // La map funge da "Array" di nodi, la list rappresenta la "Lista" dei vicini
	map<T,list<T>> adj_list;
	//ogni nodo è uno scalare
	//key=nodo, valore associato=lista dei nodi vicini
	
	// Mantengo anche un set di archi e nodi per facilitare le operazioni richieste: all_edges(), edge_number() e edge_at()
	set<unidirected_edge<T>> edges; // Insieme unico di archi 
	
	//Il set<unidirected_edge> edges usa l'operatore < che ho implementato per tenere gli archi in ordine. 
	//Questo ordine è quello che permette ai metodi edge_number() e edge_at() di funzionare. 
	//Senza la classe arco, non potrei dire "dammi il terzo arco", perché nella lista di adiacenza i collegamenti sono sparsi.
	
public:
	// Costruttore di default
    unidirected_graph() {};

    // Costruttore di copia di default
	unidirected_graph(const unidirected_graph& other){};
	
	// funzione neighbours()
	list<T> neighbours(const T node){
		auto search=adj_list.find(node);//.find mi restituisce un interatore al nodo.
		//se l'elemento non viene trovato, mi ritorna l'iteratore di fine end()
		if (search!=adj_list.end()){
			// la freccia mi da l'elemento a cui punta l'iteratore search
			//poichè la lista è fatta da (key, value),first si riferisce a key, second a value= lista dei vicini
			return search-> second;
			
		}
		return{}; //se il nodo non è nel grafo
	}
	
	//funzione add_edges
	void add_edges(const unidirected_edge<T>& e){ 
		if (edges.find(e) == edges.end()) { //se non lo trovo già nell'insieme degli archi
            edges.insert(e);
			adj_list[e.from()].push_back(e.to()); //prendo la riga della matrice di adiacenza 
			//che corrisponde al primo nodo e aggiungo nella lista associata il secondo nodo
			//faccio lo stesso per il secondo nodo: aggiungo alla lista a lui associata il primo nodo
            adj_list[e.to()].push_back(e.from());
		}
	}
	
	//funzione all_edges() e all_nodes()
	set<unidirected_edge<T>> all_edges()const{
		return edges;
	}
	
	set<T> all_nodes() const{
		set<T> nodes(adj_list.size());
	
		for (auto it = adj_list.begin(); it != adj_list.end(); it++) { //utilizzo l'iteratore it per scorrere rungo la lista di adiacenza
		//alternativamente posso scrivere for(auto& nodo : adj_list), dove nodo è una variabile locale temporanea che rappresenta l'elemento corrente
			nodes.insert(it->first); // 'it->first' è il nodo corrente: it è l'iteratore, quindi la freccia mi da l'elemento a cui punta l'iteratore
			//insert è una funzione dei set
		}
		return nodes;
	}
	
	
	//funzione edge_number(): dato un arco, ne restituisce a sua numerazione all'interno del grafo
	//la funzione set crea archi ordinati
	int edge_number(unidirected_edge<T> e){
		int count=0;
		for (auto it = edges.begin(); it != edges.end(); it++) {//mi muovo lungo edges (=set di archi) con l'iteratore it
			// Se trovo l'arco cercato, restituisco la posizione attuale
			if (*it == e) {
				return count;
			}
			count++; // Altrimenti incrementiamo il contatore
		}
    // Se l'arco non esiste nel grafo
    return -1; 
	}
	
	//edge at()= dato un numero d’arco, restituisce il corrispondente oggetto arco all’interno del grafo
	unidirected_edge<T> edge_at(int index) const{
		auto it = edges.begin(); //utilizzo l'iteratore per spostarmi lungo il set edges
		// Sposto l'iteratore in avanti di 'index' volte
		for (int i = 0; i < index; i++) {
			if (it==edges.end()|| index<0){
				break;
			}
			it++;
		}
		// Ora 'it' punta esattamente all'arco nella posizione richiesta
		return *it;
	}
	
	unidirected_graph<T> operator-(const unidirected_graph& other) const {
        unidirected_graph<T> result;
        for (const auto& e : edges) { //utilizzo l'iteratore per muovermi lungo edges, con e variabile temporanea che contiene l'arco in edges
			// Se l'arco non è presente nel grafo 'other', lo aggiungiamo al risultato
            if (other.edges.find(e) == other.edges.end()) {
                result.add_edges(e);
            }
        }
        return result;
    }
	//other.edges.find(e): Cerca l'arco e all'interno dell'insieme di archi del secondo grafo
	//this-> serve solo a dire: "Usa la scatola edges che appartiene a questo grafo specifico
	// ":" significa dentro a, ovvero per ogni elemento che si trova dentro a this->edges




};