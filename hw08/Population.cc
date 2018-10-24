#include "Population.h"
#include "Fish.h"

Population::Population() {
    this->head = NULL;
    this->count = 0;
}

void Population::add() {
    Fish* newborn = new Fish();
    if (count == 0) {
        newborn->next = head;
        head = newborn;
    } else {
        tail->next = newborn;
        tail = newborn;
    }
    count += 1;
}

void Population::remove(Fish*& dead) {
    if (head == dead) {
        if (head->next == NULL) {
            head = NULL;
        } else {
            head = head->next;
        }
    } else {
        Fish* previous = head;
        while(previous->next != NULL && previous->next != dead) {
            prev = prev->next;
        }
        if (prev->next == NULL) {
            //test
        } else {
            previous->next = previous->next->next;
        }
    }
    delete(dead);
    dead = NULL;
}

int Population::size() {
    return count;
}

