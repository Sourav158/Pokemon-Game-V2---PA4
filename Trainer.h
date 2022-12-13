#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include <iostream>
#include <math.h>
using namespace std;

#ifndef TRAINER_H
#define TRAINER_H
enum TrainerStates {
    STOPPED = 0,
    MOVING = 1,
    FAINTED = 2,
    AT_CENTER = 3,
    IN_GYM = 4,
    MOVING_TO_CENTER = 5,
    MOVING_TO_GYM = 6,
    BATTLING_IN_GYM = 7,
    RECOVERING_HEALTH = 8
};
class Trainer : public GameObject{
    public:
        Trainer();
        Trainer (char in_code);
        Trainer(string in_name, int in_id, char in_code, unsigned int in_speed,Point2d in_loc);
        string GetName();
        void StartMoving(Point2d dest);
        void StartMovingToGym(PokemonGym* gym);
        void StartMovingToCenter(PokemonCenter* center);
        void StartBattling(unsigned int num_battles);
        void StartRecoveringHealth(unsigned int num_potions);
        void Stop();
        bool HasFainted();
        bool ShouldBeVisible();
        void ShowStatus();
        bool Update();
        virtual ~Trainer();
    
    protected:
        bool UpdateLocation();
        void SetupDestination(Point2d dest);
    
    private:
        double speed;
        bool is_at_center;
        bool is_IN_GYM;
        unsigned int health;
        unsigned int experience;
        double PokeDollars;
        unsigned int battles_to_buy;
        unsigned int potions_to_buy;
        string name;
        PokemonCenter* current_center;
        PokemonGym* current_gym;
        Point2d destination;
        Vector2d delta;
};

double GetRandomAmountOfPokeDollars();

#endif