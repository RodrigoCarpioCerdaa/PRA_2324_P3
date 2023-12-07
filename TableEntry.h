#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V> 
class TableEntry {
    public:
	    std::string key;
	    V value;

	    TableEntry(std::string key, V value){
	    	this->key = key;
		this->value = value;
	    }
	    TableEntry(std::string key){
	    	this-> key = key;
		this-> value = nullptr;
	    }
	    TableEntry(){
	    	this->key = "";
		this-> value = nullptr;
	    }
	    friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
	    	return (te1.key == te2.key);
	    }
	    friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){
	    	return (te1.key != te2.key);
	    }
	    friend std::ostream&operator<<(std::ostream &out, const TableEntry<V> &te){
	    	return out << te.key << " " << te.value << std::endl;
	    }
    
};

#endif
