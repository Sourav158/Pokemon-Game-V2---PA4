#include "PokemonGym.h"
using namespace std;

    PokemonGym::PokemonGym(){
        display_code = 'G';
        state = NOT_DEFEATED;
        max_number_of_battles = 10;
        num_battle_remaining = max_number_of_battles;
        health_cost_per_battle = 1;
        PokeDollar_cost_per_battle = 1.0;
        experience_per_battle = 2;
        cout << "PokemonGym default constructed" << endl;
    }
    PokemonGym::PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2d in_loc):Building('G',in_id, in_loc ){
        max_number_of_battles = max_battle;
        num_battle_remaining = max_number_of_battles;
        state = NOT_DEFEATED;
        health_cost_per_battle = health_loss;
        experience_per_battle = exp_per_battle;
        PokeDollar_cost_per_battle = PokeDollar_cost;
        cout << "PokemonGym constructed" << endl;
    }
    PokemonGym::~PokemonGym(){
        cout << "Pokemon Gym Destructed" << endl;
    }
    double PokemonGym::GetPokeDollarCost(unsigned int battle_qty){
        return battle_qty*PokeDollar_cost_per_battle;
    }
    unsigned int PokemonGym::GetHealthCost(unsigned int battle_qty){
        return health_cost_per_battle*battle_qty;
    }
    unsigned int PokemonGym::GetNumBattlesRemaining(){
        return num_battle_remaining;
    }
    bool PokemonGym::IsAbleToBattle(unsigned int battle_qty, double budget,  unsigned int health){
        if(budget > GetPokeDollarCost(battle_qty) && health > GetHealthCost(battle_qty)){
            return true;
        } else
            return false;
        
    }
    unsigned int PokemonGym::TrainPokemon(unsigned int battle_units){
        if(num_battle_remaining >= battle_units){
            num_battle_remaining -= battle_units;
            return battle_units * experience_per_battle;
        } else {
            int temp = num_battle_remaining;
            num_battle_remaining = 0;
            return temp;
        } 
    }
    bool PokemonGym::Update(){
        if(passed() && state != DEFEATED){
            state = DEFEATED;
            display_code = 'g';
            cout << display_code << id_num << " has been defeated." << endl; 
            return true; 
        } else return false;
    }

    bool PokemonGym::passed(){
        if (num_battle_remaining == 0){
            return true;
        } else return false;
    }
    void PokemonGym::ShowStatus(){
        cout << "Pokemon gym status:" << endl; 
        Building :: ShowStatus();
        cout << "\tMax number of battles: " << max_number_of_battles << endl;
        cout << "\tHealth cost per battle: " << health_cost_per_battle << endl;
        cout << "\tPokedollar per battle: " << PokeDollar_cost_per_battle <<endl;
        cout << "\tExperience per battle: " << experience_per_battle<< endl;
        cout << "\t" << num_battle_remaining << " battles(s) are remaining for this Pokemongym" << endl; 

    }
