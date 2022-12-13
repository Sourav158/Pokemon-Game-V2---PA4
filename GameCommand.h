//#include "Trainer.h"
#include "Model.h"
#include "View.h"
using namespace std;

#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

void DoCommands(Model& model, View& view);
void DoStopCommand(Model& model, int trainer_id);
void DoRunCommand(Model& model, View& view);
void DoMoveCommand(Model& model, int trainer_id, Point2d p1);
void DoAdvanceCommand(Model& model, View& view);
void DoBattleCommand(Model& model, int trainer_id, unsigned int battles);
void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed);
void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id);
void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id);
#endif
