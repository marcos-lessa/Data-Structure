/* Copyright (C) 2018 Marcos Lessa - All Rights Reserved
 */
 
#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ Exceptions

const auto DEFAULT_SIZE = 10u;

namespace structures {

template<typename T>
//! Classe fila de um elemento T
class ArrayQueue {
 public:
//! Construtor
    ArrayQueue() {
        contents = new T[max_size_];
        fim = -1;
        inicio = 0;
        size = 0;
    }
    
//! Construtor da fila com tamanho passado como parâmetro    
    ArrayQueue(std::size_t max) {
        inicio = 0;
        fim = -1;
        size_ = 0;
        max_size_ = max;
        contents = new T[max_size_];
    }

//! Destrutor da fila - desaloca o espaço na memória, anteriormente alocado para a fila
    ~ArrayQueue() {
        delete [] contents;
    }

//! Acresenta um elemento no fim da fila, caso a mesma nao esteja cheia
    void enqueue(const T& data) {
        if (full()) {
            throw std::out_of_range("Fila cheia");
        } else {
            
        }
    }

//! Retira o primeiro elemento da fila, caso a mesma nao esteja vazia
    T dequeue() {
        if (empty()) {
            throw std::out_of_range("Fila vazia");
        } else {
            
        }
    }

//! Retorna o primeiro elemento da fila
    T& back() {
        if (empty()) {
            throw std::out_of_range("Fila vazia");
        } else {
            
        }
    }
    
//! Limpa a fila, caso a mesma ja nao estiver vazia
    void clear() {
        if (empty()) {
            throw std::out_of_range("Fila ja vazia");
        } else {
            fim = -1;
            size_ = 0;
            inicio = 0;
        }
    }

//! Retorna a quantidade de elementos presentes na fila
    std::size_t size() {
        return size_;
    }
//! Retorna a o tamanho da fila
    std::size_t max_size() {
        return max_size_;
    }

//! Verifica se a fila esta vazia
    bool empty() {
        return size_ == 0;
    }
    
//! Verifica se a fila esta cheia
    bool full() {
        return size_ == max_size_;
    }

private:
    T* contents;
    std::size_t size_;
    int fim;
    std::size_t inicio;

};

}

#endif  // namespace structures
