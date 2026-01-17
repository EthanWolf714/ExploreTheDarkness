#include "game.h"

Game::Game(){
    
}

Game::~Game(){

}

void Game::Update(){
    
    HandleInput();
    player.Update();
}

void Game::Draw(){
    player.Draw();
}

void Game::HandleInput(){
    player.Move();
}

Vector2 Game::GetPlayerPosition(){
    return player.GetPosition();
}

