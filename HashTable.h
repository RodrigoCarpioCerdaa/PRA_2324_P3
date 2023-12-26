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
		for(int a=0; a<max; a++){
			if(key == table.key){
				throw std::runtime_error("ya existe esta key");
			}
			else{
				table (key, value);
				n++;
			}
		}
	}
	V search(std::string key) override{
		for(int a=0; a<max; a++){
			if(key == table.key){
				return table.value;
			}
			else{
				throw std::runtime_error("no existe esta key");
			}
		}
	}
	V remove(std::string key) override{
		for(int a=0; a<max; a++){
			if(key == table.key){
				table.key = nullptr;
				n--;
			}
			else{
				throw std::runtime_error("no existe esta key 2");
			}
		}
	}
	int entries() override{
		return n;
		
	}
        
};

#endif
