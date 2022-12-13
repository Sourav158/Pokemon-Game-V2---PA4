#include "Building.h"
using namespace std;

Building:: Building() : GameObject('B'){
  cout << "Building constructed" << endl;
}

Building:: Building(char in_code, int in_id, Point2d in_loc) :GameObject(in_loc, in_id, in_code){
  cout << "Building Constructed" << endl;
}
void Building::AddOneTrainer(){
  trainer_count++;
}
void Building::RemoveOneTrainer(){
  trainer_count--;
}
void Building::ShowStatus(){
  cout << "\t" <<display_code << id_num << " located at " << location;
  if (trainer_count == 1) cout << endl << "\t" << trainer_count << " trainers are in this building" << endl;
  else cout << endl << "\t"<< trainer_count << " trainers are in this building" << endl;
    
}
bool Building::ShouldBeVisible(){
  return true;
}

