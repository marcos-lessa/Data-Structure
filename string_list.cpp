/* Copyright (C) 2018 Marcos Lessa - All Rights Reserved
 */
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#define CATCH_CONFIG_MAIN

#include <cstdint>
#include <stdexcept>  // C++ Exceptions
#include <cstring>
#include <memory>



namespace structures {


//! Classe ArrayList
template <typename T>
class ArrayList {
 public:
    //! ...
    ArrayList();

    //! ...
    explicit ArrayList(int max_size);

    //! ...
    ~ArrayList() = default;

    //! ...
    void clear();

    //! ...
    void push_back(const T& data);

    //! ...
    void push_front(const T& data);

    //! ...
    void insert(const T& data, int index);

    //! ...
    void insert_sorted(const T& data);

    //! ...
    T pop(int index);

    //! ...
    T pop_back();

    //! ...
    T pop_front();

    //! ...
    void remove(const T& data);

    //! ...
    bool full() const;

    //! ...
    bool empty() const;

    //! ...
    bool contains(const T& data) const;

    //! ...
    int find(const T& data) const;

    //! ...
    int size() const;

    //! ...
    int max_size() const;

    //! ...
    T& at(int index);

    //! ...
    T& operator[](int index);

    //! ...
    const T& at(int index) const;

    //! ...
    const T& operator[](int index) const;


 protected:
    //! ...
    std::unique_ptr<T[]> contents;
    ///! ...
    int size_;
    //! ...
    int max_size_;
    //! ...
    static const auto DEFAULT_MAX = 100u;
};

template <typename T>
structures::ArrayList<T>::ArrayList() {
    ArrayList(this->DEFAULT_MAX);
}
template <typename T>
structures::ArrayList<T>::ArrayList(int max_size) {
    this->size_ = 0;
    this->max_size_ = max_size;
    this->contents = std::unique_ptr<T[]>(new T[this->max_size_]);
}
template <typename T>
void structures::ArrayList<T>::clear() {
    this->size_ = 0;
}
template <typename T>
bool structures::ArrayList<T>::full() const {
    return this->size_ == this->max_size_;
}
template <typename T>
bool structures::ArrayList<T>::empty() const {
    return this->size_ == 0;
}
template <typename T>
bool structures::ArrayList<T>::contains(const T& data) const {
    return this->find(data) != this->size_;
}
template <typename T>
int structures::ArrayList<T>::size() const {
    return this->size_;
}
template <typename T>
int structures::ArrayList<T>::max_size() const {
    return this->max_size_;
}
template <typename T>
int structures::ArrayList<T>::find(const T& data) const {
    for (int i = 0; i < this->size_; i++) {
        if (data == this->contents[i]) {
            return i;
        }
    }
    return this->size_;
}
template <typename T>
void structures::ArrayList<T>::remove(const T& data) {
    int index = this->find(data);
    if (index < this->size_) {
        this->pop(index);
    }
}

template <typename T>
T& structures::ArrayList<T>::at(int index) {
    if (this->size_ < index || index < 0) {
        throw std::out_of_range("Erro");
    } else {
        return this->operator[](index);
    }
}
template <typename T>
T& structures::ArrayList<T>::operator[](int index) {
    return this->contents[index];
}
template <typename T>
const T& structures::ArrayList<T>::at(int index) const {
    if (this->size_ < index || index < 0) {
        throw std::out_of_range("Erro");
    } else {
        return this->operator[](index);
    }
}
template <typename T>
const T& structures::ArrayList<T>::operator[](int index) const {
    return this->contents[index];
}
template <typename T>
void structures::ArrayList<T>::push_front(const T& data) {
    if (this->full()) {
        throw std::out_of_range("Lista cheia");
    } else {
        for (int i = this->size_; i > 0; i--) {
            this->contents[i] = this->contents[i-1];
        }
        this->size_ += 1;
        this->contents[0] = data;
    }
}
template <typename T>
void structures::ArrayList<T>::push_back(const T& data) {
    if (this->full()) {
        throw std::out_of_range("Lista cheia");
    } else {
        this->contents[this->size_] = data;
        this->size_ += 1;
    }
}
template <typename T>
T structures::ArrayList<T>::pop_back() {
    if (this->empty()) {
        throw std::out_of_range("Lista vazia");
    } else {
        this->size_ -= 1;
        return this->contents[this->size_];
    }
}
template <typename T>
T structures::ArrayList<T>::pop_front() {
    if (this->empty()) {
        throw std::out_of_range("Lista vazia");
    } else {
        auto tmp = this->contents[0];

        for (int i = 0; i < this->size_ - 1; i++) {
            this->contents[i] = this->contents[i+1];
        }

        this->size_ -= 1;

        return tmp;
    }
}
template <typename T>
T structures::ArrayList<T>::pop(int index) {
    if (this->empty()) {
        throw std::out_of_range("Lista vazia");

    } else if (index >= this->size_ || index < 0) {
        throw std::out_of_range("Invalido");
    }

    auto tmp = this->contents[index];

    for (int i = index; i < this->size_-1; i++) {
        this->contents[i] = this->contents[i+1];
    }
    this->size_ -= 1;
    return tmp;
}
template <typename T>
void structures::ArrayList<T>::insert(const T& data, int index) {
    if (this->full()) {
        throw std::out_of_range("Lista cheia");
    } else if (index >= this->max_size_ || index < 0 || index > this->size_) {
        throw std::out_of_range("Erro");
    } else if (index == this->size_) {
        this->contents[this->size_] = data;
        this->size_ += 1;
    } else {
        for (int i = this->size_; i > index; i--) {
            this->contents[i] = this->contents[i-1];
        }
        this->contents[index] = data;
        this->size_ += 1;
    }
}
template <typename T>
void structures::ArrayList<T>::insert_sorted(const T& data) {
    if (this->full()) {
        throw std::out_of_range("Lista cheia");
    } else {
        int i = 0;
        while (1) {
            if (i == this->size_) {
                this->contents[this->size_] = data;
                this->size_ += 1;
                break;
            }
            if (this->contents[i] > data) {
                this->insert(data, i);
                break;
            }
            i++;
        }
    }
}

//! ArrayListString e' uma especializacao da classe ArrayList
class ArrayListString : public ArrayList<char* > {
 public:
    //! ...
    ArrayListString() : ArrayList() {}

    //! ...
    explicit ArrayListString(int max_size) : ArrayList(max_size) {}

    //! ...
    ~ArrayListString();

    //! ...
    void clear();

    //! ...
    void push_back(const char* data);

    //! ...
    void push_front(const char* data);

    //! ...
    void insert(const char* data, int index);

    //! ...
    void insert_sorted(const char* data);

    //! ...
    char* pop(int index);

    //! ...
    char* pop_back();

    //! ...
    char* pop_front();

    //! ...
    void remove(const char* data);

    //! ...
    bool contains(const char* data);

    //! ...
    int find(const char* data);
};

}  // namespace structures

structures::ArrayListString::~ArrayListString() {
    this->clear();
}

void structures::ArrayListString::clear() {
    for (int i = 0; i < this->size(); i++) {
        delete[] this->operator[](i);
    }
    ArrayList<char*>::clear();
}

void structures::ArrayListString::push_back(const char* data) {
    if (strlen(data) > 9999) {
        throw std::out_of_range("Muito grande");
    }
    char* input = new char[strlen(data) + 1];
    snprintf(input, strlen(data)+1, "%s", data);
    ArrayList<char*>::push_back(input);
}

void structures::ArrayListString::push_front(const char* data) {
    char* input = new char[strlen(data) + 1];
    snprintf(input, strlen(data)+1, "%s", data);
    ArrayList<char*>::push_front(input);
}

void structures::ArrayListString::insert(const char* data, int index) {
    if (strlen(data) > 9999) {
        throw std::out_of_range("Muito grande");
    }
    char* input = new char[strlen(data) + 1];
    snprintf(input, strlen(data)+1, "%s", data);
    ArrayList<char*>::insert(input, index);
}


void structures::ArrayListString::insert_sorted(const char* data) {
    if (this->full()) {
        throw std::out_of_range("Lista cheia");
    }  else if (strlen(data) > 9999) {
        throw std::out_of_range("Muito grande");
    }  else {
        int i = 0;
        while (1) {
            if (i == this->size()) {
                this->insert(data, this->size());
                return;
            }
            if (strcmp(operator[](i), data) > 0) {
                this->insert(data, i);
                return;
            }
            i++;
        }
    }
}

int structures::ArrayListString::find(const char* data)  {
    int i = 0;
    while (i < this->size()) {
         if (strcmp(data, this->operator[](i)) == 0) {
            return i;
    }
    i++;
    }
    return this->size();
}

char* structures::ArrayListString::pop(int index) {
    if (this->empty()) {
        throw std::out_of_range("Lista vazia");
    } else if (index >= this->size_ || index < 0) {
        throw std::out_of_range("Local invalido");
    }
    auto x = this->contents[index];
    for (int i = index; i < this->size_-1; i++) {
        this->contents[i] = this->contents[i+1];
    }
    this->size_ -= 1;
    return x;
}

char* structures::ArrayListString::pop_back() {
    if (this->empty()) {
        throw std::out_of_range("Lista vazia!");
    } else {
        this->size_ -= 1;
        return this->contents[this->size_];
    }
}

char* structures::ArrayListString::pop_front() {
    if (this->empty()) {
        throw std::out_of_range("Lista vazia!");
    } else {
        auto x = this->contents[0];
        for (int i = 0; i < this->size_ - 1; i++) {
            this->contents[i] = this->contents[i+1];
        }
        this->size_ -= 1;
        return x;
    }
}

void structures::ArrayListString::remove(const char* data) {
    int i = this->find(data);
    if (i < this->size_) {
        delete[] this->pop(i);
    }
}

bool structures::ArrayListString::contains(const char* data) {
    return this->find(data) != this->size();
}

#endif

