#include "Object.h"

Object::Object(std::string libelle, bool active):Updatable(active),_libelle(libelle)
{
    //ctor
}

Object::~Object()
{
    //dtor
}
