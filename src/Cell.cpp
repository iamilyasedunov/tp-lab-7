#pragma once

#include "../include/Cell.h"

Object * Cell::getObject() {

    return obj;

}

void Cell::setObject(Object * obj){

    this->obj = obj;

}

void Cell::clear(){

    obj = nullptr;

}

Ocean * Cell::getOcean(){
    return ocean;
}

ObjType Cell::getObjType(){

    if (obj == nullptr)
        return ObjTypeEnd;

    return obj->objType;

}