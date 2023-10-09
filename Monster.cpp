//
// Created by vyacheslav on 10/9/23.
//

#include "Monster.h"

Monster::Monster(uint8_t attackValue, uint8_t defenceValue, uint32_t health, uint32_t damageLowBound,
                 uint32_t damageHighBound) : Creature(attackValue, defenceValue, health, damageLowBound, damageHighBound) {
}