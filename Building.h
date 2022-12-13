#ifndef BUILDING_H
#define BUILDING_H
#include "GameObject.h"
using namespace std;
class Building : public GameObject{
 private:
  unsigned int trainer_count = 0 ;
 public: 
  Building();
  Building(char, int, Point2d);
  void AddOneTrainer();
  void RemoveOneTrainer();
  void ShowStatus();
  bool ShouldBeVisible();
};
#endif
