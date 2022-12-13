#include <iostream>
#include "GameObject.h"
#include "Trainer.h"
#include "Point2d.h"
#include "WildPokemon.h"
using namespace std;

WildPokemon::WildPokemon() : GameObject('W') {
    attack = 5;
    health = 2;
    name = "starter";   
    state = IN_ENVIRONMENT;
    variant = false;
    in_combat = false;
    current_trainer = NULL; 
}

WildPokemon::WildPokemon(string name_in, double attack_in, double health_in, bool variant_in, int id_in, Point2d in_loc) : GameObject(in_loc,id_in,'W') {
    name = name_in;
    attack = attack_in;
    health = health_in;
    variant = variant_in;
    state = IN_ENVIRONMENT;
    in_combat = false;
    current_trainer = NULL;
}

void WildPokemon::follow(Trainer* t) {
    if (in_combat = false) {
        cout << "pokemon"<< endl;
    }
    in_combat = true;
    current_trainer = t;   
    t -> IsFollowed();
}


bool WildPokemon::Update() {
    switch (state) {
        case IN_ENVIRONMENT:
            if ((IsAlive() == true) && (in_combat == true)) {
                state = FOLLOWING_TRAINER;
                return true;
            } else if (IsAlive() == false) {
                state = DEAD;
                return true;
            } else {
                return false;
            }
            break;
        case FOLLOWING_TRAINER:
            location = current_trainer->GetLocation();
            health = health - 1;
            if (IsAlive() == false) {
                current_trainer -> IsNotFollowed();
                in_combat = false;
                current_trainer = NULL;
                state = DEAD;
                return true;
            }else if ((in_combat == false) || (current_trainer -> HasFainted() == true) && ((in_combat == true))) {
                current_trainer -> IsNotFollowed();
                in_combat = false;
                current_trainer = NULL;
                state = IN_ENVIRONMENT;
                return false;
            }
            else {
                return true;
            }
            break;
        case DEAD:
            return true;
            break;
        default:
            return false;
            break;
    }
}

bool WildPokemon::IsAlive() {
    if (health > 0) {
        return true;
    } else {
        return false;
    }
}

void WildPokemon::ShowStatus() {
    cout << "status of:"<< name;
    GameObject::ShowStatus();
    switch (state) {
        case FOLLOWING_TRAINER:
            cout << "Currently with trainer" << endl;
            break;
        case DEAD:
            cout << health;
            cout << " Is Dead" << endl;
            break;
        default: 
            cout << "Still Alive" << endl;
            break;
    }
}

bool WildPokemon::get_variant(){
    return variant;
}

double WildPokemon::get_attack(){
    return attack;
}

double WildPokemon::get_health(){
    return health;
}

bool WildPokemon::get_in_combat(){
    return in_combat;
}
