// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}
void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;
    if (first == nullptr) {
        first = newCar;
        first->next = first;
        first->prev = first;
        return;
    }
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
}
int Train::getOpCount() {
    return countOp;
}
int Train::getLength() {
    if (first == nullptr)
        return 0;
    countOp = 0;
    Car* current = first;
    current->light = true;
    int steps = 0;
    while (true) {
        current = current->next;
        steps++;
        countOp++;
        if (current->light) {
            current->light = false;
            Car* back = current;
            for (int i = 0; i < steps; i++) {
                back = back->prev;
                countOp++;
            }
            if (!back->light) {
                return steps;
            }
        }
    }
}
