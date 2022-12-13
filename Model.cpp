//#include "Trainer.h"
#include "Model.h"
#include "View.h"
using namespace std;

Model::Model(){
    time = 0;
    num_objects = 6;
    num_trainers = 2;
    num_centers = 2;
    num_gyms = 2;
    Point2d p1(5,1);
    Point2d g2(5, 5); 
    Point2d p2(10, 1);
    Point2d c1(1, 20);
    Point2d c2(10, 20); 
    Point2d g1(0, 0);
    trainer_ptrs[0] = new Trainer("Ash", 1, 'T', 5, p1);
    object_ptrs[0] = trainer_ptrs[0];
    trainer_ptrs[1] = new Trainer("Misty", 2, 'T', 2, p2);
    object_ptrs[1] = trainer_ptrs[1]; 
    center_ptrs[1] = new PokemonCenter(2, 2, 200, c2);
    object_ptrs[3] = center_ptrs[1];    
    gym_ptrs[1] = new PokemonGym(20, 5, 7.5, 4, 2, g2);
    object_ptrs[5] = gym_ptrs[1];
    center_ptrs[0] = new PokemonCenter(1, 1, 100, c1);
    object_ptrs[2] = center_ptrs[0]; 
    gym_ptrs[0] = new PokemonGym(10, 1, 2, 3, 1, g1);
    object_ptrs[4] = gym_ptrs[0];    
    cout << "Model default constructed" << endl;
}

Model::~Model(){
    cout << "Model destructed." << endl;
}

Trainer* Model::GetTrainerPtr(int id){
    int check = 0;
    for(int x = 0; x < num_trainers; x++){
        if(trainer_ptrs[x] -> GetId() == id){
            check = 1;
            return trainer_ptrs[x];
        }
    }
    if(check == 0){
        return 0;
    }
}

PokemonCenter* Model::GetPokemonCenterPtr(int id){
    int check = 0;
    for(int x = 0; x < num_centers; x++){
        if(center_ptrs[x] -> GetId() == id){
            check = 1;
            return center_ptrs[x];
        }
    }
    if(check == 0){
        return 0;
    }
}

PokemonGym* Model::GetPokemonGymPtr(int id){
    int check = 0;
    for(int x = 0; x < num_gyms; x++){
        if(gym_ptrs[x] -> GetId() == id){
            check = 1;
            return gym_ptrs[x];
        }
    }
    if(check == 0){
        return 0;
    }
}

bool Model::Update(){ 
    time++;
    if(trainer_ptrs[0] -> HasFainted() && trainer_ptrs[1] -> HasFainted()){
        cout << "GAME OVER: You lose!" << endl;
        return false;
    }else if(gym_ptrs[0]->passed()&&gym_ptrs[1]->passed()){
        cout << "GAME OVER: You win!" << endl;
        return false;
    }else {
        for(int x = 0; x < num_objects; x++){
            if(object_ptrs[x] -> Update()){
                    return true;
            }
        }
    }
}
void Model::Display(View& view){
    cout<< "Time: " << time << endl;
    for(int x = 0; x < num_objects; x++){
        if(x == 1 || x == 0){
            if(!TrainerIsVisible1()){
                view.Clear();
            }if(!TrainerIsVisible2()){
                view.Clear();
                if(TrainerIsVisible1()){
                    view.Plot(object_ptrs[0]);
                }
            }else{
                view.Plot(object_ptrs[x]);
            }
        }else {
            view.Plot(object_ptrs[x]);
        }
    }
}
void Model::ShowStatus(){
    for(int x = 0; x < num_objects; x++){
        object_ptrs[x] -> ShowStatus();
    }
}
bool Model::TrainerIsVisible1(){
    return trainer_ptrs[0] -> ShouldBeVisible();}
bool Model::TrainerIsVisible2(){
    return trainer_ptrs[1] -> ShouldBeVisible();}
int Model::GetTime(){
    return time;}