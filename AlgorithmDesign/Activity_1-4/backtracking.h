/**
 * About: Erick Alfredo Garcia Huerta - A01708119
 *
 */

#ifndef TC2038_BACKTRACKING_H
#define TC2038_BACKTRACKING_H

#include <iostream>
#include <array>

// Length and width of the matrix.
const int x = 4;
const int y = 4;

using namespace std;

class Labyrinth{
public:
    Labyrinth();
    ~Labyrinth();
    int createMaze(int lab[x][y]); // Create the maze based in the input on the user
    int navigate(int, int, int lab[x][y]); // Moves the mouse to the sides or up/down
private:
    // Analyze methods to search for a viable path
    bool analyzePathRight(int, int, int lab[x][y]);
    bool analyzePathLeft(int, int, int lab[x][y]);
    bool analyzePathUp(int, int, int lab[x][y]);
    bool analyzePathDown(int, int , int lab[x][y]);
};

bool Labyrinth::analyzePathRight(int w, int h, int (*lab)[4]) {
    if(lab[w+1][h] == 1){
        return true;
    }

    return false;
}

bool Labyrinth::analyzePathLeft(int w, int h, int (*lab)[4]) {
    if(lab[w-1][h] == 1){
        return true;
    }

    return false;
}

bool Labyrinth::analyzePathUp(int w, int h, int (*lab)[4]) {
    if(lab[w][h-1] == 1){
        return true;
    }

    return false;
}

bool Labyrinth::analyzePathDown(int w, int h, int (*lab)[4]) {
    if(lab[w][h+1] == 1){
        return true;
    }

    return false;
}

int Labyrinth::navigate(int w, int h, int (*lab)[4]) {
    if(w == x && h == y){
        return (*lab)[4];
    }else if(analyzePathRight(w, h, lab)){
        if(lab[w][h-1] != 0){
            lab[w][h-1] = 0;
        }
        if(lab[w][h+1] != 0){
            lab[w][h+1] = 0;
        }
        if(lab[w-1][h] != 0){
            lab[w-1][h] = 0;
        }
        navigate(w+1, h, lab);
    }else if(analyzePathLeft(w, h, lab)){
        if(lab[w][h-1] != 0){
            lab[w][h-1] = 0;
        }
        if(lab[w][h+1] != 0){
            lab[w][h+1] = 0;
        }
        if(lab[w+1][h] != 0){
            lab[w+1][h] = 0;
        }
        navigate(w-1, h, lab);
    }else if(analyzePathDown(w, h, lab)){
        if(lab[w][h-1] != 0){
            lab[w][h-1] = 0;
        }
        if(lab[w+1][h] != 0){
            lab[w+1][h] = 0;
        }
        if(lab[w-1][h] != 0){
            lab[w-1][h] = 0;
        }
        navigate(w, h+1, lab);
    }else if(analyzePathUp(w, h, lab)){
        if(lab[w][h+1] != 0){
            lab[w][h+1] = 0;
        }
        if(lab[w+1][h] != 0){
            lab[w+1][h] = 0;
        }
        if(lab[w-1][h] != 0){
            lab[w-1][h] = 0;
        }
        navigate(w, h-1, lab);
    }

    return (*lab)[4];
}

#endif //TC2038_BACKTRACKING_H