/* Copyright (C) 2018 Marcos Lessa - All Rights Reserved
 */

#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>  // std::size_t
#include <stdexcept>  // C++ exceptions

const auto DEFAULT_SIZE = 10u;

namespace structures {

template<typename T>
//! Classe pilha de um elemento T
class ArrayStack {
 public:
//! Constructor
    ArrayStack() {
        contents = new T[max_size_];
        top_ = -1;
    }

//! Construtor da pilha com tamanho passado com parametro
    explicit ArrayStack(std::size_t max) {
        max_size_ = max;
        contents = new T[max_size_];
        top_ = -1;
    }

//! Destrutor - desaloca a memoria alocada anteriormente para a pilha
    ~ArrayStack() {
        delete[] contents;
    }

//! Se a pilha nao estiver cheia, adicona um elemento a mesma
    void push(const T& data) {	 	  	 	      	    	   	      	    	     	        	 	
        if (full()) {
            throw std::out_of_range("Pilha cheia!");
        } else {
            top_ = top_ + 1;
            contents[top_] = data;
        }
    }

//! Se a pilha nao estiver vazia, desempilha o elemento em seu topo
    T pop() {
        if (!empty()) {
            top_ = top_ - 1;
            return contents[top_ + 1];
        } else {
            throw std::out_of_range("Pilha ja vazia");
        }
    }

//! Retorna o elemento no topo da pilha
    T& top() {
        if (!empty()) {
            return contents[top_];
        } else {
           throw std::out_of_range("Pilha vazia");
        }
    }

//! Se a pilha nao estiver vazia, limpa a mesma
    void clear() {
        if (!empty()) {
            // contents = new T[max_size_];
            top_ = -1;
        } else {
            throw std::out_of_range("Pilha ja vazia");
        }
    }	 	  	 	      	    	   	      	    	     	        	 	

//! Retorna o numero de elementos presentes na pilha
    std::size_t size() {
        return top_+1;
    }

//! Retorna o tamanho da pilha
    std::size_t max_size() {
        return max_size_;
    }

//! Verifica se a pilha está vazia
    bool empty() {
        return (top_ == -1);
    }

//! Verifica se a pilha está cheia
    bool full() {
        return top_ == (max_size_ -1 );
    }

 private:
    T* contents;
    int top_;
    std::size_t max_size_;
};

}  // namespace structures

#endif
	 	  	 	      	    	   	      	    	     	        	 	
