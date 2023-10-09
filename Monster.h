//
// Created by vyacheslav on 10/9/23.
//

#ifndef HEADS_X_HANDS_TEST_PROJECT_MONSTER_H
#define HEADS_X_HANDS_TEST_PROJECT_MONSTER_H


#include "Creature.h"

class Monster : public Creature {
public:
    Monster(uint8_t attackValue, uint8_t defenceValue, uint32_t health, uint32_t damageLowBound, uint32_t damageHighBound);
};


#endif //HEADS_X_HANDS_TEST_PROJECT_MONSTER_H
