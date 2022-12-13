#include "Trainer.h"
#include "View.h"
using namespace std;

#ifndef MODEL_H
#define MODEL_H

class Model{
    private:
        int time;
        int num_objects;
        int num_trainers;
        int num_centers;
        int num_gyms;
        GameObject* object_ptrs[10];
        Trainer * trainer_ptrs[10];
        PokemonCenter * center_ptrs[10];
        PokemonGym * gym_ptrs[10];
    public:
        Model();
        int GetTime();
        ~Model();
        Trainer* GetTrainerPtr(int id);
        PokemonCenter* GetPokemonCenterPtr(int id);
        PokemonGym* GetPokemonGymPtr(int id);
        bool Update();
        bool TrainerIsVisible1();
        bool TrainerIsVisible2();
        void Display(View& view);
        void ShowStatus();

};
#endif