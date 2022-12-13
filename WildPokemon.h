#include <iostream>
#include "Point2d.h"
#include "Trainer.h"
#include "GameObject.h"
#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H
using namespace std;

enum WildStates {
    IN_ENVIRONMENT = 1,
    DEAD = 2,
    FOLLOWING_TRAINER = 3
};

class WildPokemon: public GameObject {
    protected:
        double attack;
        double health;
        bool variant;
        bool in_combat;
        string name;
        Trainer* current_trainer;
    public:
        WildPokemon();
        WildPokemon(string, double, double, bool, int, Point2D);
        void follow(Trainer*);
        bool get_variant();
        double get_attack();
        double get_health();
        bool get_in_combat();
        bool Update();
        void ShowStatus();
        bool IsAlive();
};
#endif
