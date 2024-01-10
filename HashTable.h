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
		int suma = 0;
		for(size_t i=0; i<key.length(); i++){
			suma += static_cast<int>(key.at(i));
		}
		return suma % max;
	}


    public:
	void insert(std::string key, V value) override{	
		TableEntry<V> c (key,value);

		int r = h(key);
		for(int i=0;i<table[r].size();i++){
			if(table[r].get(i)==c){
				throw std::runtime_error("ya existe esta clave");
			}
		}
		table[r].append(c);
		n++;
	}
	V search(std::string key) override{
		TableEntry c (key, 0);
		int r = h(key);
		for(int i=0; i<table[r].size();i++){
			if(table[r].get(i)==c){
				return table[r].get(i).value;
			}
		
		}
		throw std::runtime_error("no se encuentra la key 1");
	}
	V remove(std::string key) override{
		TableEntry c (key, 0);
		int r = h(key);
		for(int i=0; i<table[r].size();i++){
			if(table[r].get(i) == c){
				
				V inigo = table[r].remove(i).value;
				n--;
				return inigo;
			}
		}
		throw std::runtime_error("no se encuentra la key 2");
	}
	int entries() override final{
		return n;
		
	}
	HashTable(int size){
		table = new ListLinked<TableEntry<V>>[size];
		n = 0;
		max = size;
	}
	~HashTable(){
		delete[] table;
	}
	int capacity(){
		return max;
	}
	friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
		out << "HashTable [entries: "<< th.n <<", capacity: " << th.max << "]"<< std::endl;
		out <<"=================="<<std::endl;

		for (int i = 0; i < th.max; i++){
			out<<"Cubeta "<<i<<std::endl<<"List =>  ["<<std::endl<<th.table[i]<<std::endl<<"]"<<std::endl;
		}

		out <<"=================="<<std::endl;
		return out;	
	}
	V operator[](std::string key){
		return search(key);
	}
        	
};

#endif
