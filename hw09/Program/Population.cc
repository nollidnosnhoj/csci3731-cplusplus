#include <iostream>
#include <string>
#include "Population.h"
#include "Fish.h"
#include "Exception.h"

// Constructor (initalize length and head pointer)
Population::Population() {
    this->head = NULL;
    this->count = 0;
}

// Destructor (delete all nodes if any)
Population::~Population() {
    Fish* ptr = head;
    Fish* temp;

    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        delete (temp);
    }
}

// Adds fish into population. Takes a fish pointer as an argument
// This method should only be called during the fish's birth (fish's constructor is called).
void Population::add(Fish* newborn) {
    if (newborn->next != NULL) {
        throw Exception("Not a newborn");
    } else {
        if (!head) {
            newborn->next = head;
            head = newborn;
        } else {
            Fish* ptr = head;
            while(ptr->next != NULL) {
                ptr = ptr->next;
            } 
            ptr->next = newborn;
        }
        ++count;
    }
}

// Removes a specific fish from the population. Takes a fish pointer as an argument.
// This method should only be called when the fish is destroyed (fish's destructor is called).
void Population::remove(Fish* dead) {
    if (count > 0) {
        if (head == dead) {
            if (!head->next) {
                head = NULL;
            } else {
                head = head->next;
            }
        } else {
            Fish* prev = head;
            while (prev->next && prev->next != dead) {
                prev = prev->next;
            }
            if (!prev->next) {  // if the fish does not exist within the linked list
                throw Exception("Fish does not exist within population");
            } else {    // move the previous fish's next to the next next (skipping the removed fish)
                prev->next = prev->next->next;
            }
        }
        dead = NULL;
        --count;
    } else {
        throw Exception("There's nothing to remove.");
    }
}

// Print out the current fishes in population.
void Population::print() const {
    Fish* ptr = head;
    while (ptr) {
        std::cout << *ptr << std::endl;
        ptr = ptr->next;
    }
}

// Return the population size
int Population::size() const {
    return count;
}

// Returns the fish pointer given the specific index in the linked list (population).
Fish* Population::get(int index) const {
    if (index > -1 && index < count) {
        Fish* captured = head;
        int ptr = 0;
        while (ptr < index) {
            captured = captured->next;
            ++ptr;
        }
        return captured;
    } else {
        throw Exception("Index is out of bounds");
    }
}