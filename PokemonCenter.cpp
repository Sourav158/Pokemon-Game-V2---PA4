#include <iostream>
using namespace std;
#include "PokemonCenter.h"

PokemonCenter:: PokemonCenter(){
    display_code = 'C';
    potion_capacity = 100;
    num_potions_remaining = potion_capacity;
    pokedollar_cost_per_potion = 5;
    state = POTIONS_AVAILABLE;
    cout <<  "PokemonCenter default constructed" << endl; 
}
PokemonCenter::  PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2d in_loc):Building('C', in_id, in_loc){
    potion_capacity = potion_cap;
    num_potions_remaining = potion_capacity;
    pokedollar_cost_per_potion = potion_cost;
    state = POTIONS_AVAILABLE;
    cout <<   "PokemonCenter constructed" << endl; 

}
PokemonCenter::~PokemonCenter(){
    cout << "Pokemon Center destructed" << endl;
}
  bool PokemonCenter::HasPotions(){
      if(num_potions_remaining > 0){
          return true;
      } else return false;
  }

  unsigned int PokemonCenter::GetNumPotionRemaining(){
      return num_potions_remaining;
  }

  bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget){
      if(potion * pokedollar_cost_per_potion <= budget){
          return true;
      } else return false;
  }
  double PokemonCenter::GetPokeDollarCost(unsigned int potion){
      return potion * pokedollar_cost_per_potion;
  }
  unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed = 0){
      if(num_potions_remaining >= potion_needed){
        num_potions_remaining -= potion_needed;
        return potion_needed;
      } else{
          int i = num_potions_remaining;
          num_potions_remaining = 0;
          return i;
      }
  }
  bool PokemonCenter:: Update(){
      if (num_potions_remaining == 0 && state != NO_POTIONS_AVAILABLE){
          display_code = 'c';
          state = NO_POTIONS_AVAILABLE;
            cout << "Pokemon Center " << id_num << " has ran out of potions" << endl;
            return true;                  
        } else {
            return false;
        }
  }
  void PokemonCenter::ShowStatus(){
      cout << "PokemonCenter status: " << endl;
      Building :: ShowStatus();
      cout << "\tPokedollars per potion: " << pokedollar_cost_per_potion
      << endl << "\tHas " << num_potions_remaining << " potion(s) remaining" << endl;
  }