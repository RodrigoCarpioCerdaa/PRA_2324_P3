#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2324_P1/ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;//Número de elementos almacenados actualmente en la tabla hash.
	int max;//Tamaño de la tabla hash(cubetas)
	ListLinked<TableEntry<V>>* table;//tabla de cubetas representadas por un array de punteros a listas enlazadas(tipo ListLinked) que almacenan los pares key->value
	int h(std::string key){
		int i=0;
		char c;
		int suma;
		std::size_t tamano = key.size();
		for(int i; i<tamano; i++){
			c = key.at(i);
			c = int(c);
			suma += c;
		}
		return suma%max;
	}

    public:
	void insert(std::string key, V value) override{	
		int cubeta = h(key);
		int posicion = table[cubeta].search(key);
		if (posicion != -1){
			throw std::runtime_error("la clave ya existe 1");
		}
		else{
			table[cubeta].insert(table[cubeta].size(), TableEntry(key, value));
			n++;
		}
	
	}
	V search(std::string key) override{
		int cubeta = h(key);
		int posicion = table[cubeta].search(key);

		if (posicion >= 0){
			V valor = table[cubeta].get(posicion).value;
			return valor;

		}
		else{
			std::runtime_error("no se encuentra la clave 1");
		}
	}
	V remove(std::string key) override{
		int cubeta = h(key);
		int posicion = table[cubeta].search(key);
		if(posicion >= 0){
			V pepe =table[cubeta].get(posicion);
			table[cubeta].remove(pepe);
			n--;
		}
		else{
			std::runtime_error("no se encuentra la clave 2");
		}
	}
	int entries() override{
		return n;
		
	}
	HashTable(int size){
		table = new ListLinked<TableEntry<V>>[size];
		n++;
		max = size;
	}
	~HashTable(){
		delete[] table;
	}
	int capacity(){
		return max;
	}
	friend std::ostream&operator<<(std::ostream &out, const HashTable<V> &th){
		out <<"=============="<<std::endl;

		for(int i=0; i < th.max; i++){
			out <<"Cubeta "<< i<<std::endl << "List => ["<<std::endl<<th.table[i]<<std::endl<<"]"<<std::endl;
		}
		out << "=============="<<std::endl;
		return out;
	}
	V operator[](std::string key){
		int cubeta = h(key);
		int posicion = table[cubeta].search(key);
		if(posicion >=0){
			return table[cubeta].get(posicion).value;
		}
		else{
			throw std::runtime_error("no se ha podido encontrar la clave");
		}
	}
        	
};

#endif
