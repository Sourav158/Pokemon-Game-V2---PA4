using namespace std;
#include "GameCommand.h"

int main(){
    Model model;
    View view;
    model.ShowStatus();
    model.Display(view);
    while(true){ 
        DoCommands(model, view);
    }
}

