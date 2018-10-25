#include <iostream>
#include "Population.h"
#include "Fish.h"

Population::Population() {
    this->head = NULL;
    this->tail = NULL;
    this->count = 0;
}

Population::~Population() {
    
}

void Population::add(Fish* newborn) {
    if (count == 0) {
        newborn->next = head;
        head = newborn;
    } else {
        tail->next = newborn;
        tail = newborn;
    }
    ++count;
}

void Population::remove(Fish* dead) {
    if (head == dead) {
        if (head->next == NULL) {
            head = NULL;
        } else {
            head = head->next;
        }
    } else {
        Fish* prev = head;
        while (prev->next != NULL && prev->next != dead) {
            prev = prev->next;
        }
        if (prev->next == NULL) {
            return;
        } else {
            prev->next = prev->next->next;
            if (prev->next == NULL) {
                tail = prev->next;
            }
        }
    }
    delete(dead);
    dead = NULL;
    --count;
}

void Population::print() const {
    Fish* ptr = head;
    while (ptr != NULL) {
        std::cout << "FISH!" <<  std::endl;
        ptr = ptr->next;
    }
}


int Population::size() const {
    return count;
}

