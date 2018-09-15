#include "AbstractGeom.h"

AbstractGeom::AbstractGeom()
{
    //ctor
}

AbstractGeom::~AbstractGeom()
{
    //dtor
}

bool AbstractGeom::colisaoX(float var){
    if(this->GetalturaInicialX() > var &&  var < this->GetalturaFinalX()){
        return true;
    }
    return false;
}

bool AbstractGeom::colisaoY(float var){
    if(this->GetalturaInicialY() > var &&  var < this->GetalturaFinalY()){
        return true;
    }
    return false;
}

bool AbstractGeom::colisaoZ(float var){
    if(this->GetalturaInicialZ() > var &&  var < this->GetalturaFinalZ()){
        return true;
    }
    return false;
}
