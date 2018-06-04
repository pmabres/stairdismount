//
// Created by pancho on 04-Jun-18.
//

#ifndef GAME_ENTITYMANAGER_H
#define GAME_ENTITYMANAGER_H


class EntityManager
{
public:
    EntityManager();
    virtual ~EntityManager();
    void addEntity(IEntity entity);
};


#endif //GAME_ENTITYMANAGER_H
