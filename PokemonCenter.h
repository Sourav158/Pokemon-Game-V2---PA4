#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H
#include "Building.h"
using namespace std;
class PokemonCenter : public Building{
  
 private:
    unsigned int potion_capacity = 100;
    unsigned int num_potions_remaining = potion_capacity;
    double pokedollar_cost_per_potion; 
 public: 
  PokemonCenter();
  PokemonCenter(int, double, unsigned int, Point2d);
  ~PokemonCenter();
  bool HasPotions();
  unsigned int GetNumPotionRemaining();
  bool CanAffordPotion(unsigned int, double);
  double GetPokeDollarCost(unsigned int);
  unsigned int DistributePotion(unsigned int);
  bool Update();
  void ShowStatus();

};
enum PokemonCenterStates{POTIONS_AVAILABLE = 0, NO_POTIONS_AVAILABLE = 1};
#endif
