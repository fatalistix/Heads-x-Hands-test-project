#include "Creature.h"
#include <stdexcept>
#include <string>

Creature::Creature(uint8_t attackValue, uint8_t defenceValue, uint32_t health, uint32_t damageLowBound, uint32_t damageHighBound) {
    if (attackValue <= 0 || 30 < attackValue) {
        throw std::invalid_argument("attackValue cannot be less then one or greater then 30");
    }
    if (defenceValue <= 0 || 30 < defenceValue) {
        throw std::invalid_argument("defenceValue cannot be less then one or greater then 30");
    }
    if (health <= 0) {
        throw std::invalid_argument("health cannot be less then one");
    }
    if (damageHighBound < damageLowBound) {
        throw std::invalid_argument("damageHighBound cannot be less then damageLowBound");
    }

    this->attackValue = attackValue;
    this->defenceValue = defenceValue;
    this->health = health;
    this->damageLowBound = damageLowBound;
    this->damageHighBound = damageHighBound;
}

bool Creature::isDead() const {
    return !health;
}

uint8_t rollDice() {
    return (std::rand() % 6) + 1;
}

bool successRoll(uint8_t val) {
    return val == 5 || val == 6;
}

uint32_t randomInRange(uint32_t low, uint32_t high) {
    return (rand() % (high - low + 1)) + low;
}

void Creature::attack(Creature & another) const {
    if (this == &another) {
        throw std::invalid_argument("cannot attack myself");
    }
    if (another.isDead()) {
        throw std::invalid_argument("attacked creature is already dead");
    }
    int attackMod = this->attackValue - another.defenceValue + 1;
    if (attackMod <= 0) {
        attackMod = 1;
    }

    for (int i = 0; i < attackMod; ++i) {
        if (successRoll(rollDice())) {
            uint32_t damage = randomInRange(damageLowBound, damageHighBound);
            if (damage > another.health) {
                another.health = 0;
            } else {
                another.health -= damage;
            }
            break;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Creature & c) {
    os << "Creature{ attack: " << int(c.attackValue) << ", defence: " << int(c.defenceValue) << ", health: " << c.health << ", damage: [ " << c.damageLowBound << ", " << c.damageHighBound << " ] }";
    return os;
}