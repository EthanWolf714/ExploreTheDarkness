#ifndef GAME_H
#define GAME_H
#include "player.h"
class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void Update();
    void HandleInput();
    Vector2 GetPlayerPosition();
    

private:
    Player player;
    
};

#endif