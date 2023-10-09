#include <iostream>
#include "Player.h"
#include "Monster.h"

int main() {
    Player player(15, 15, 70, 10, 20);
    std::cout << player << std::endl;
    Monster monster(20, 10, 30, 5, 8);
    std::cout << monster << std::endl;
    player.attack(monster);
    std::cout << "Monster dead = " << monster.isDead() << std::endl;
    Monster anotherMonster(30, 10, 30, 5, 8);
    std::cout << "NEW MONSTER: " << anotherMonster << std::endl;
    anotherMonster.attack(player);
    std::cout << "Player dead = " << player.isDead() << std::endl;
    if (player.isDead()) {
        std::cout << "Fail" << std::endl;
        return 0;
    } else {
        std::cout << "Survived" << std::endl;
        player.attack(anotherMonster);
        std::cout << "Another monster is dead = " << anotherMonster.isDead() << std::endl;
        std::cout << "Player stats: " << player << std::endl;
        player.heal();
        std::cout << "Player stats after hill: " << player << std::endl;
    }
    try {
        Player player1(120, 120, 0, 0, 0);
    } catch (std::invalid_argument e) {
        std::cout << "caught exception as expected: " << e.what() << std::endl;
    }
    return 0;
}
