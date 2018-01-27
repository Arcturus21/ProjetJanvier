#include "Enemy.h"

#define ENEMY_RADIUS 20

Enemy::Enemy(float posX, float posY) : Object("Enemy"), _shape(ENEMY_RADIUS), _collider(posX+ENEMY_RADIUS,posY+ENEMY_RADIUS,ENEMY_RADIUS)
{
    //ctor
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::Update(float elapsedTime)
{
    if(!IsActive())
        return;
}
