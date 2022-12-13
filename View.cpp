#include "View.h"

    View::View(){
        size = 11;
        size = 2;
        origin = Point2d();
    }

    bool View::GetSubscripts(int &out_x, int &out_y, Point2d location){
        out_x = (location.x - origin.x) / size;
        out_y = (location.y - origin.y) / size;
        if((out_x < view_maxsize && out_x >= 0) && (out_y < view_maxsize && out_y >= 0)) 
            return true;
        else 
            cout << " An object is outside the display" << endl;
            return false;
    }

    void View::Clear(){
        for(int x = 0; x<view_maxsize; x++){
            for (int y = 0; y<view_maxsize; y++){
                grid[x][y][0] = '.';
            }
        }
    }

    void View::Plot(GameObject* ptr){
        int x,y;
        bool point = GetSubscripts(x,y, ptr -> GetLocation());
        if(point){
            if(grid[y][x][0] == '.' && ptr -> ShouldBeVisible()) {
                ptr -> DrawSelf(&grid[y][x][0]);
                }
            else if (ptr->ShouldBeVisible()){
                grid[y][x][0] = '*'; 
                grid[y][x][1] = ' ';
                }
        }
    }

    void View::Draw(){
        for(int x = (view_maxsize / size) ; x >= 0; x--){
            if(x % 2 == 0){
                if((x * size) < 10) cout << x * size << " ";
                else cout << x * size;
            }
            else{
                cout << "  ";
            }
            for(int y = 0; y <= view_maxsize / size; y++){
                if(grid[x][y][0] == '.') cout << ". ";
                else cout << grid[x][y][0] << grid[x][y][1];  
            }
            cout << endl;
        }
        cout << "  ";
        for(int x = 0; x <= (view_maxsize / size) ; x++){
            if(x % 2 == 0){
                if((x * size) < 10) cout << x * size << " ";
                else cout << x * size;
            }else {
                cout << "  ";
            }
    }
    cout << endl;
    }