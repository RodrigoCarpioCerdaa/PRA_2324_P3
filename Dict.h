#ifndef DICT_H
#define DICT_H
#include <string>
#include <iostream>

template <typename V> 
class Dict {
    public:
	    std::string key;
	    V value;
	    int size;
	    	
	    void insert(std::string key, V value){
	    }
	    V search(std::string key){
	    }
	    V remove(std::string key){
		
	    }
	    int entries(){
	    	return size;	    
	    }
};

#endif
