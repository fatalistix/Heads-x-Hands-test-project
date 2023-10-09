//
// Created by vyacheslav on 10/9/23.
//

#ifndef HEADS_X_HANDS_TEST_PROJECT_PLAYER_H
#define HEADS_X_HANDS_TEST_PROJECT_PLAYER_H

#include "Creature.h"

class Player : public Creature {
public:
    Player(uint8_t attackValue, uint8_t defenceValue, uint32_t health, uint32_t damageLowBound, uint32_t damageHighBound);
    void heal();
    bool healAvailable();
protected:
    uint8_t numOfHeals = 0;
    const uint8_t MAX_NUM_OF_HEALS = 4;
    const double HEAL_PERCENT = 0.3;
    const uint32_t maxHealth;
};

#endif //HEADS_X_HANDS_TEST_PROJECT_PLAYER_H
