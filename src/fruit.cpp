// Adam Tyton

#include "fruit.hpp"
#include "branch.hpp"

#define NULL 0

// CONSTRUCTOR

FRUIT_CLASS::FRUIT_CLASS() {
    CONSTRUCTOR(NULL, NULL, NULL, 0);
}


FRUIT_CLASS::FRUIT_CLASS(
        BRANCH_CLASS* parent,
        FRUIT_CLASS* prev,
        FRUIT_CLASS* next,
        unsigned int bLenght
        ) {
    CONSTRUCTOR(parent, prev, next, bLenght);
}

void FRUIT_CLASS::CONSTRUCTOR(
        BRANCH_CLASS* parent,
        FRUIT_CLASS* prev,
        FRUIT_CLASS* next,
        unsigned int bLenght
        ) {
    this->parent = parent;
    this->prev = prev;
    this->next = next;

    weight = 0;
    // from parent

    len = bLenght;
}


// --------- GETTERS ---------

unsigned int FRUIT_CLASS::getLength() {
    return len;
}

unsigned int FRUIT_CLASS::getWeight() {
    return weight;
}

BRANCH_CLASS* FRUIT_CLASS::getBranchPointer() {
    return parent;
}


// --------- SETTERS ---------

void FRUIT_CLASS::growthFruit() {
    weight += 1;
    if (parent != NULL)
        parent->addFWeight(1);
}

void FRUIT_CLASS::fadeFruit() {
    if (weight > 0)
    {
        weight -= 1;
        if (parent != NULL)
            parent->decFWeight(1);
    }
}

void FRUIT_CLASS::pluckFruit() {
    if (parent != NULL)
        parent->decFWeight(weight);
    weight = 0;
}

// OTHER METHODS
void FRUIT_CLASS::decFWeight(unsigned int x) {
    weight -= x;
    if (parent != NULL)
        parent->decFWeight(x);
}

void FRUIT_CLASS::addFWeight(unsigned int x) {
    weight += x;
    if (parent != NULL)
        parent->addFWeight(x);
}

FRUIT_CLASS* FRUIT_CLASS::getPrev()  {
    return prev;
}

FRUIT_CLASS* FRUIT_CLASS::getNext() {
    return next;
}

void FRUIT_CLASS::setPrev(FRUIT_CLASS* pFruit) {
    prev = pFruit;
}

void FRUIT_CLASS::setNext(FRUIT_CLASS* pFruit) {
    next = pFruit;
}

void FRUIT_CLASS::setLength(unsigned int bLength) {
    len = bLength;
}