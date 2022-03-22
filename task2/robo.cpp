#include "robo.h"
#include "utils.h"

Robo::Robo(string owner)
{    
  
    id = generate_hex(10);
    addOwner(owner);
}

void Robo::addOwner(string owner)
{
    ownners.push_back(owner);
}
void Robo::deleteOwner(string name)
{
    std::vector<string>::iterator position = std::find(ownners.begin(), ownners.end(), name);
    
    if (position != ownners.end())
        ownners.erase(position);
        
}

/*
Robo::~Robo()
{

}*/