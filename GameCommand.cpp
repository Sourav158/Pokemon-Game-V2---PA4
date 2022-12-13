//#include "Trainer.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"
#include <stdlib.h>
using namespace std;

void DoMoveCommand(Model& model, int trainer_id, Point2d p1){
    if(model.GetTrainerPtr(trainer_id) == 0){
        cout << "Error: Enter a valid command!" << endl;
    } else{
        model.GetTrainerPtr(trainer_id) -> StartMoving(p1);
        cout <<  "Moving " << model.GetTrainerPtr(trainer_id) -> GetName()  << "to" << p1 << endl;
    }
}

void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id){
    if(model.GetTrainerPtr(trainer_id) == 0 || model.GetPokemonGymPtr(gym_id) == 0){
        cout << "Error: Enter a valid command!" << endl;
    } else{
        cout <<  "Moving " << model.GetTrainerPtr(trainer_id) -> GetName()  << " to the gym " << gym_id << endl;
        model.GetTrainerPtr(trainer_id) -> StartMovingToGym(model.GetPokemonGymPtr(gym_id));
    }
}

void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id){
    if(model.GetTrainerPtr(trainer_id) == 0 || model.GetPokemonCenterPtr(center_id) == 0){
        cout << "Error: Enter a valid command!" << endl;
    } else{
        model.GetTrainerPtr(trainer_id) -> StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
        cout <<  "Moving " << model.GetTrainerPtr(trainer_id) -> GetName()  << " to the center " << center_id << endl;
    }
}

void DoStopCommand(Model& model, int trainer_id){
    if(model.GetTrainerPtr(trainer_id) == 0){
        cout << "Error: Enter a valid command!" << endl;
    }else {
        model.GetTrainerPtr(trainer_id) -> Stop();
        cout <<  "Stopping " << model.GetTrainerPtr(trainer_id) -> GetName() << endl;
    }
}

void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed){
    if(model.GetTrainerPtr(trainer_id) == 0){
        cout << "Error: Enter a valid command!" << endl;
    }else{
        cout  << "Recovering " << model.GetTrainerPtr(trainer_id) -> GetName()  << "'s health." << endl;
        model.GetTrainerPtr(trainer_id) -> StartRecoveringHealth(potions_needed);
    }              
}

void DoBattleCommand(Model& model, int trainer_id, unsigned int battles){ 
    if(model.GetTrainerPtr(trainer_id) == 0){
        cout << "Error: Enter a valid command!" << endl;
    } else{
        cout  <<  model.GetTrainerPtr(trainer_id) -> GetName()  << " is battling." << endl;
        model.GetTrainerPtr(trainer_id) -> StartBattling(battles);
    }
}


void DoAdvanceCommand(Model& model, View& view){
    model.Update();
    model.ShowStatus();
    view.Clear();
    model.Display(view);
    view.Draw();
}

void DoRunCommand(Model& model, View& view){ 
    int startTime = model.GetTime();
    while(model.GetTime() != startTime+5){
        if(!model.Update()){
            model.ShowStatus();
            view.Clear();
            model.Display(view);
            view.Draw();
            break;
        } else{
            model.ShowStatus();
            view.Clear();
            model.Display(view);
            view.Draw();
        }
    }
}

void DoCommands(Model& model, View& view){ 
    model.ShowStatus();
    model.ShowStatus();
    view.Clear();
    model.Display(view);
    view.Draw();
    cout  <<  "Please input command:";
    char command;
    cin>>command;
    while(command != 'q'){
        switch(command){
            case 'a':{
                cout <<  "Advancing one tick." << endl;
                DoAdvanceCommand(model, view);
                break;
            }
            case 'r':{
                cout <<  "Running" << endl;
                DoRunCommand(model, view);
                break;
            }
            case 'm':{
                int id;
                double x, y;
                cin>>id>>x>>y;
                cout  << "Moving " << id << " to (" << x << "," << y << ")" << endl;
                Point2d p1(x,y);
                DoMoveCommand(model, id,p1);
                model.ShowStatus();
                view.Clear();
                model.Display(view);
                view.Draw();
                break;
            }
            case 'g':{
                int id1, id2;
                cin>>id1>>id2;
                cout << "Moving " << id1  << " to pokemon gym " << id2 << endl;
                DoMoveToGymCommand(model, id1,id2);
                model.ShowStatus();
                view.Clear();
                model.Display(view);
                view.Draw();
                break;
            }
            case 'c':{
                int id1, id2;
                cin>>id1>>id2;
                cout << "Moving " << id1  << " to pokemon center " << id2 << endl;
                DoMoveToCenterCommand(model, id1,id2);
                model.ShowStatus();
                view.Clear();
                model.Display(view);
                view.Draw();
                break;
            }
            case 'p':{ 
                int id, potion_amount;
                cin >> id >> potion_amount;
                cout << id << " Buying " << potion_amount << " potions." << endl;
                DoRecoverInCenterCommand(model, id, potion_amount);
                model.Update();
                model.ShowStatus();
                view.Clear();
                model.Display(view);
                view.Draw();
                break;
            }
            case 's':{
                int id;
                cin>>id;
                cout << "Stopping " << id << endl;
                DoStopCommand(model, id);
                model.ShowStatus();
                view.Clear();
                model.Display(view);
                view.Draw();
                break;
            }
            case 'b':{
                int id, battle_amount;
                cin >> id >> battle_amount;
                cout << id << " Fighting " << battle_amount << " battles." << endl;
                DoBattleCommand(model, id, battle_amount);
                model.Update();
                model.ShowStatus();
                view.Clear();
                model.Display(view);
                view.Draw();
                break;
            }
        }
        cout  <<  "Please input command:";
        cin>>command;
    }
}