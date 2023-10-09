#ifndef HEADS_X_HANDS_TEST_PROJECT_CREATURE_H
#define HEADS_X_HANDS_TEST_PROJECT_CREATURE_H

#include <cstdint>
#include <iostream>

class Creature {
public:
    Creature(uint8_t attackValue, uint8_t defenceValue, uint32_t health, uint32_t damageLowBound, uint32_t damageHighBound);
    [[nodiscard]] bool isDead() const;
    void attack(Creature & another) const;
    friend std::ostream& operator<<(std::ostream& os, const Creature & c);

protected:
    uint8_t attackValue;
    uint8_t defenceValue;
    uint32_t health;
    uint32_t damageLowBound;
    uint32_t damageHighBound;
};



#endif //HEADS_X_HANDS_TEST_PROJECT_CREATURE_H
