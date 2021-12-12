#include "jumper.h"
#include <algorithm>

using namespace std;

Jumper::Jumper() {
}

/* Check if animal p can jump over a river
   The 'steps' argument is used to control how many river cells to test.
   Call isJumpable(board, p, y, x, 2) to test if p can do a horizontal river jump (2 steps)
   Call isJumpable(board, p, y, x, 3) to test if p can do a vertical river jump (3 steps)
   Return true if p can jump and false otherwise (e.g. due to blocking by a Rat in river)
 */
bool Jumper::isJumpable(Board* board, Piece* p, int y, int x, int steps) {
    /* TODO: Add code to check if p can jump over 'steps' river squares 
             to the destination(y, x) */
    if(steps == 3){
      Piece * p1 = nullptr;
      Piece * p2 = nullptr;
      Piece * p3 = nullptr;

      if(y < p -> getY()){
        if(y != p -> getY() - 4)  return false;
        p1 = board -> get(p -> getY() - 1,p -> getX());
        p2 = board -> get(p -> getY() - 2,p -> getX());
        p3 = board -> get(p -> getY() - 3,p -> getX());
        if(board->isRiver(
            p -> getY() - 1,
            p -> getX()) == false)  return false;
        
        if(board->isRiver(
            p -> getY() - 2,
            p -> getX()) == false)  return false;

        if(board->isRiver(
            p -> getY() - 3,
            p -> getX()) == false)  return false;
      }

      if(y > p -> getY()){
        if(y != p -> getY() + 3)  return false;

        p1 = board->get(p->getY()+1, p->getX());
        p2 = board->get(p->getY()+2, p->getX());
        p3 = board ->get(p -> getY() + 3, p -> getX());
        if(board->isRiver(
            p -> getY() + 1,
            p -> getX()) == false)  return false;
        
        if(board->isRiver(
            p -> getY() + 2,
            p -> getX()) == false)  return false;
        
        if(board->isRiver(
            p -> getY() + 3,
            p -> getX()) == false)  return false;
      }

      if(p1 != EMPTY || p2 != EMPTY || p3 != EMPTY)  return false;
    }
    else{
      Piece * p1 = nullptr;
      Piece * p2 = nullptr;
    

      if(x < p->getX()){
        if(x != p -> getX() - 3)  return false;
        p1 = board->get(p->getY(),p->getX()-1);
        p2 = board->get(p->getY(), p->getX()-2);
    
        if(board->isRiver(
            p -> getY(),
            p -> getX() - 1) == false)  return false;
        
        if(board->isRiver(
            p -> getY(),
            p -> getX() - 2) == false)  return false;

      }

      if(x > p->getX()){
        if(x != p -> getX() + 3)  return false;
        p1 = board->get(p->getY(), p->getX()+1);
        p2 = board->get(p->getY(), p->getX()+2);
        if(board->isRiver(
            p -> getY(),
            p -> getX() + 1) == false)  return false;
        
        if(board->isRiver(
            p -> getY(),
            p -> getX() + 2) == false)  return false;
      }

      if(p1 != EMPTY || p2!=EMPTY) return false; 
    }

    return true;

}