#pragma once

#include "../include/Object.h"

#include "../include/Ocean.h"

Object::Object (Cell * cell, ObjType objType){
    this->cell = cell;
    this->objType = objType;
}

void Object::setCell (Cell * cell){
    this->cell = cell;
}

Object * Object::createObject(Cell * cell) {
    return nullptr;
}

