#include <iostream>
#include <time.h>
#include <stdlib.h>
#include<math.h>
#include "GameObject.h"
#include "Trainer.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
using namespace std; 

Trainer::Trainer():GameObject('T'){ 
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    current_center = 0;
    current_gym = 0;
    speed = 5;
    is_IN_GYM = false;
    is_at_center = false;
    health = 20;
    experience = 0;
    destination = Point2d(0,0);
    cout <<  "Trainer default constructed" << endl;
}

Trainer::Trainer(char in_code):GameObject(in_code){
    speed = 5;
    is_IN_GYM = false;
    is_at_center = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    current_center = 0;
    current_gym = 0;
    destination = Point2d(0,0);
    cout <<  "Trainer constructed" << endl;
    state = STOPPED;
}

Trainer::Trainer(string in_name, int in_id, char in_code, unsigned int in_speed, Point2d in_loc):GameObject(in_loc,in_id,in_code){ 
    speed = in_speed;
    name = in_name;
    is_IN_GYM = false;
    is_at_center = false;
    health = 20;
    experience = 0;
    PokeDollars = 0;
    current_gym = 0;
    battles_to_buy = 0;
    potions_to_buy = 0;
    current_center = 0;
    destination = Point2d(0,0);
    cout <<  "Trainer constructed" << endl;
}

Trainer::~Trainer(){
    cout <<  "Trainer destructed." << endl;
}

string Trainer::GetName(){
    return name;
}

void Trainer::SetupDestination(Point2d d){
    destination = d;
    delta = (d - location)*(speed/GetDistanceBetween(destination, location));
}

void Trainer::StartMoving(Point2d d){ 
    if(state == AT_CENTER){
        current_center -> RemoveOneTrainer();
    }if(state == IN_GYM){
        current_gym -> RemoveOneTrainer();
    }
    SetupDestination(d);
    destination = d;
    if(location.x == d.x &&location.y == d.y){ 
        cout <<  display_code << id_num << ": I'm already there" << endl;
    }else if(health == 0){ 
        cout <<  display_code << id_num << ": My pokemon have fainted but you cannot see me." << endl;
    }else{
        state = MOVING;
        cout <<  display_code << id_num <<  "OMY" << endl;
    }

}

void Trainer::StartMovingToGym(PokemonGym* gym){ 
    if(state == IN_GYM){
        current_gym -> RemoveOneTrainer();
    }
    if(state == AT_CENTER){
        current_center -> RemoveOneTrainer();
    }
    SetupDestination(gym -> GetLocation());
    destination = gym -> GetLocation();
    current_gym = gym; 
    if(location.x == gym -> GetLocation().x &&location.y == gym -> GetLocation().y){
        cout <<  display_code << id_num << ": I am already there" << endl;
    }else if(health == 0){ 
        cout <<  display_code << id_num << ": My Pokemon fainted I can't move to gym…" << endl;
    }else{
        cout <<  display_code << id_num <<  ": OMY " <<  gym -> GetId() << endl;
        state = MOVING_TO_GYM;
    }
}

void Trainer::StartMovingToCenter(PokemonCenter* center){
    if(state == AT_CENTER){
        current_center -> RemoveOneTrainer();
    }if(state == IN_GYM){
        current_gym -> RemoveOneTrainer();
    }
    current_center = center; 
    SetupDestination(center -> GetLocation());
    destination = center -> GetLocation();
    if(location.x == center -> GetLocation().x &&location.y == center -> GetLocation().y){
        cout <<  display_code << id_num << ": I am already at the Center!" << endl;
    }else if(health == 0){ 
        cout <<  display_code << id_num << ": My pokemon have fainted " << endl;
    }else{
        state = MOVING_TO_CENTER;
        cout <<  display_code << id_num <<  ": OMY " <<  center -> GetId() << endl;
    }
        
}

void Trainer::StartBattling(unsigned int num_battles){ 
    if(health == 0 ){
        cout <<  display_code << id_num << ": My Pokemon has fainted. No more battles for me..." << endl;
    }else if(PokeDollars<current_gym -> GetPokeDollarCost(num_battles)){
        cout <<  display_code << id_num <<  ": Not enough money" << endl;
    }else if(health < current_gym -> GetHealthCost(num_battles)){ 
        cout <<  display_code << id_num <<  ": Cannot battle! The Trainer will faint" << endl;
    }else if(current_gym -> passed()){
        cout <<  display_code << id_num <<  ": Cannot battle! No trainers left" << endl;
    }else if(state != IN_GYM){
        cout <<  display_code << id_num <<  ": I can only battle in a PokemonGym! " << endl;
    }else{
        state = BATTLING_IN_GYM;
        cout <<  display_code << id_num << ": Started to battle at the PokemonGym " << current_gym -> GetId() << " with " << current_gym -> GetNumBattlesRemaining() << " battles." << endl;
        battles_to_buy = num_battles;        
    }

}

void Trainer::StartRecoveringHealth(unsigned int num_potions){ 
    if(state != AT_CENTER){
        cout <<  display_code << id_num <<  ": I can only recover health at a Pokemon Center! " << endl;
    }else if(!current_center -> HasPotions()){
        cout <<  display_code << id_num <<  ": Cannot recover! No potion remaining in this Pokemon Center" << endl;
    }else if(PokeDollars<current_center -> GetPokeDollarCost(num_potions)){
        cout <<  display_code << id_num <<  ": Not enough money to recover health" << endl;
    }else{
        state = RECOVERING_HEALTH;
        cout <<  display_code << id_num << ": Started recovering  " << num_potions << " potions at Pokemon Center  " << current_center -> GetId() << endl;
        potions_to_buy=num_potions; 
    }
}

void Trainer::Stop(){
    state = STOPPED;
    cout <<  display_code << id_num << ": Stopping..." << endl;
}

bool Trainer::HasFainted(){
    if(health == 0){
        return true;
    }else{
        return false;
    }
        
}

bool Trainer::ShouldBeVisible(){
    if(HasFainted()){
        return false;
    }else{
        return true;
    }
}

void Trainer::ShowStatus(){ 
    cout << name << " status:" << endl;;
    cout.precision(2);
    cout << "Health: " << health << endl;
    cout << "Pokedollars: " << PokeDollars << endl;
    cout << "Experience: " << experience << endl;
    GameObject::ShowStatus();
    switch(state){
        case STOPPED:
            cout << "stopped" << endl;;
            break;
        case AT_CENTER:
            cout << "INSIDE of PokemonCenter " << current_center -> GetId() << endl;;
            break;
        case RECOVERING_HEALTH: 
            cout << "recovering health in Pokemon Center " <<  current_center -> GetId() << endl;
            break;
        case MOVING:
            cout << "moving at " << speed << " to destination " << destination << " at  " << delta << endl;
            break;
        case MOVING_TO_GYM:
            cout << "going to PokemonGym " << current_gym -> GetId() << " at  " << speed << " at  " << delta << endl;
            break;
        case MOVING_TO_CENTER:
            cout << "going to PokemonCenter " << current_center -> GetId() << " at " << speed << " at  " << delta << endl;
            break;
        case IN_GYM:
            cout <<  "INSIDE of PokemonGym " << current_gym -> GetId() << endl;
            break;
        case BATTLING_IN_GYM: 
            cout << "battling in PokemonGym " << current_gym -> GetId() << endl;
            break;
        case FAINTED:
            cout <<  "Trainer has Fainted." << endl;
            break;
    }   

}

bool Trainer::Update(){ 
    if(health == 0){
        cout  << name  << " is out of health and cannot move." << endl;
        state = FAINTED;
    }
    switch(state){
        case STOPPED:{
            return false;
            break;
        }
        case IN_GYM:{
            return false;
            break;
        }
        case AT_CENTER:{
            return false;
            break;
        }
        case MOVING:{
            return UpdateLocation();
            break;
        }
        case MOVING_TO_GYM:{
            if(UpdateLocation()){ 
                current_gym -> AddOneTrainer();
                state = IN_GYM;
                return true;
                break;
            }else {
                return false;
                break;
            }       
        }
        case MOVING_TO_CENTER:{
            if(UpdateLocation()){
                current_center -> AddOneTrainer(); 
                state = AT_CENTER;
                return true;
                break;
            }else{
                return false;
                break;
            }
        }
        case BATTLING_IN_GYM:{ 
            health = health - current_gym -> GetHealthCost(battles_to_buy);
            PokeDollars = PokeDollars - current_gym -> GetPokeDollarCost(battles_to_buy);
            unsigned int expg = current_gym -> TrainPokemon(battles_to_buy);
            experience = experience + expg;
            cout  <<  name <<  " completed " <<  battles_to_buy << " battle(s)!" << endl;
            cout  <<  name  << " gained "  <<  expg  <<  "experience!" << endl;
            state = IN_GYM;
            return true;
            break;
        }
        case RECOVERING_HEALTH:{ 
            int potions_used = current_center -> DistributePotion(potions_to_buy);
            health = health+potions_used*5;
            PokeDollars = PokeDollars - current_center -> GetPokeDollarCost(potions_used);
            cout  <<  name <<  " recovered " <<  potions_used * 5  <<  " health!"  <<  endl;
            cout  <<  name  <<  " bought "  <<  potions_used  <<  "potion(s)!"  <<  endl;
            state = AT_CENTER;
            return true;
            break;
        }
    }
}

bool Trainer::UpdateLocation(){
    health = health - 1;
    PokeDollars = PokeDollars + GetRandomAmountOfPokeDollars();
    if(fabs((destination - location).y) <= fabs(delta.y) && fabs((destination - location).x) <= fabs(delta.x)){ 
        state = STOPPED;
        location = destination;
        cout  <<  display_code  <<  id_num  <<  ": I'm at location"  <<  endl;
        return true;
    }else{
        if(fabs((destination - location).x) > fabs(delta.x) && fabs((destination - location).y) > fabs(delta.y)){
            location.x = location.x + delta.x;
            location.y = location.y + delta.y;
        }else if(fabs((destination - location).x) <= fabs(delta.x)){
            location.x = destination.x;
            location.y = location.y + delta.y;
        }else if(fabs((destination - location).y) <= fabs(delta.y)){
            location.y = destination.y;
            location.x = location.x + delta.x;
        }
        cout  <<  display_code  <<  id_num  <<  ": steps "  << endl;
        return false;
    }
}
        
double GetRandomAmountOfPokeDollars(){ 
    srand(time(NULL));
    double rnum = ((double)rand())/((double) RAND_MAX)*2.0;
    return 1000;
}



