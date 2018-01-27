#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>

#include "Updatable.h"
#include "Collider.h"

class Object : public Updatable
{
    public:
        Object(std::string libelle="Object", bool active=true);
        virtual ~Object();

        virtual void Update(float elapsedTime)=0;

        ///virtual Collider& GetCollider() const=0;             ///Voir plus tard comment intégrer un système de récupération de collider générique

        void SetLibelle(std::string libelle){_libelle=libelle;};
        std::string GetLibelle(){return _libelle;};
    protected:
        std::string _libelle;
    private:
};

#endif // OBJECT_H
