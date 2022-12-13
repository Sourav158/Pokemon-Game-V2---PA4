#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Point2d.h"

using namespace std;

class GameObject{
    protected:
        Point2d location;
        int id_num;
        char display_code;
        char state;
    public:
        GameObject(char in_code);

        GameObject(Point2d in_loc, int in_id, char in_code);
        virtual ~GameObject();
        Point2d GetLocation();
        int GetId();
        char GetState();
        virtual void ShowStatus();
        virtual bool Update() = 0;
        virtual bool ShouldBeVisible() = 0;
        void DrawSelf(char * ptr);

};
#endif