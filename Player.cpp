#include "Player.h"
#include <stdexcept>

Player::Player(uint8_t attackValue, uint8_t defenceValue, uint32_t health, uint32_t damageLowBound,
               uint32_t damageHighBound) : Creature(attackValue, defenceValue, health, damageLowBound, damageHighBound), maxHealth(health) {
}

bool Player::healAvailable() {
    return this->numOfHeals < MAX_NUM_OF_HEALS;
}

void Player::heal() {
    if (!isDead() && healAvailable()) {
        if ((1. - HEAL_PERCENT) * maxHealth < health) {
            health = maxHealth;
        } else {
            health += uint32_t(maxHealth * 0.3);
        }
        ++numOfHeals;
        return;
    }
    throw std::invalid_argument("no heal available");
}