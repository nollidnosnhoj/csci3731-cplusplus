#include <iostream>
#include <string>
#include "Population.h"
#include "Fish.h"

// constructor
Population::Population() {
    this->head = NULL;
    this->count = 0;
}

// destructor
Population::~Population() {
    
}

// add new fish to population
void Population::add() {
    // create fish
    Fish* newborn = new Fish();
    // if head is NULL, set newborn to head
    if (!head) {
        newborn->next = head;
        head = newborn;
    } else { // put fish to end of list
        Fish* ptr = head;
        while(ptr->next != NULL) ptr = ptr->next;
        ptr->next = newborn;
    }
    // increment fish count
    ++count;
}

// remove fish given the fish (this method is the only one that can delete fishes)
void Population::remove(Fish* dead) {
    // if the head fish is the one
    if (head == dead) {
        // if there's only one fish, there kill that fish
        if (!head->next) {
            head = NULL;
        } else {
            // if there's another fish after head, then set the head to the other fish.
            head = head->next;
        }
    } else {
        // create previous fish pointer
        Fish* prev = head;
        // traverse through the fish until the end, or until you found the dead fish
        while (prev->next && prev->next != dead) {
            prev = prev->next;
        }
        // if the pointer reached the last fish, and the next fish is null. then return
        if (!prev->next) {
            return;
        } else {
            // delete the dead fish that's between the prev next fish and the next next fish
            // (ptr) (dead fish) (prev->next->next)
            prev->next = prev->next->next;
        }
    }
    // delete the dead fish
    delete(dead);
    dead = NULL;
    // decrement fish count
    --count;
}

// print fishes in population
void Population::print() const {
    Fish* ptr = head;
    while (ptr) {
        std::cout << *ptr << std::endl;
        ptr = ptr->next;
    }
}

// return the size of the population
int Population::size() const {
    return count;
}

// return a pointer to the fish specified by the index
Fish* Population::get(int index) const {
    // if the index is within boundaries
    if (index > -1 && index < count) {
        Fish* captured = head;
        int ptr = 0;
        while (ptr < index) {
            captured = captured->next;
            ++ptr;
        }
        return captured;
    }
    return NULL;
}