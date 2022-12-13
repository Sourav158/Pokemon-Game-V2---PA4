#include <iostream>
#include "GameObject.h"

using namespace std;

        GameObject::GameObject(char in_code){
            display_code = in_code;
            id_num = 1;
            state = 0;
            cout << "GameObject constructed" << endl;
        }

        GameObject::GameObject(Point2d in_loc, int in_id, char in_code){
            display_code = in_code;
            id_num = in_id;
            state = 0;
            location = in_loc;
            cout << "GameObject constructed" << endl;
        }

        GameObject::~GameObject(){
            cout << "Gameobject destructed" << endl;
        }
        Point2d GameObject::GetLocation(){
            return location;
        }
        int GameObject::GetId(){
            return id_num;
        }
        char GameObject::GetState(){
            return state;
        }
        void GameObject::ShowStatus(){
            cout << "\t"<<display_code << id_num << " at " << location << endl;
        }
        void GameObject::DrawSelf(char * ptr){
            *ptr = display_code;
            *(ptr + 1) = static_cast<char> (id_num + '0');
        }
