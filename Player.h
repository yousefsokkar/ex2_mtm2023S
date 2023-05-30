#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
/**
 * Player class, each player has 6 arguments:-
 * @param name- the name of the player.
 * @param level- the current level of a player.
 * @param force- the force of the player.
 * @param maxHP- the maximum amount of HP the player can have in the game.
 * @param HP_HealthPoints- the current amount of HP points the player has.
 * @param coins- the current amount of coins the player has.
 * **/
class Player{
public:
    /**
     * the default constructor for Player.
     * **/
    Player() = default;
    /**
     * constructor for the Player class
     *
     * @param name_arg- the name of the new Player.
     * @param force_arg- the force of the new Player. (the default value is 5)
     * @param maxHP_arg- the maximum HP the new Player can have. (the default value is 100)
     *
     * @return - a new level 1 Player with 0 coins, force equal to force_arg and HP equal to the maxHP_arg entered.
     * **/
    Player(std :: string name_arg,int maxHP_arg=100, int force_arg=5);
    /**
     * Copy constructor for the Player class.
     *
     * @param- The other Player object to be copied.
     * **/
    Player(const Player&);
    /**
     * Destructor fo the Player class.
     * **/
    ~Player();
    /**
     * Gets the level of the player.
     * **/
    int getLevel() const;
    /**
     * prints the stats of the player in this format:-
     *
     * Player Details:
     * Name:
     * Level:
     * Force:
     * HP:
     * Coins:
     *
     *
     * **/
    void printInfo () const;
    /**
     * Increases the level of the player by 1.
     * **/
    void levelUp ();
    /**
     * Increases the force of the player by a specified amount.
     *
     * @param add_force- the amount to be added to the force of the player.
     * **/
    void buff (int add_force);
    /**
     * Restores the HP of the player by a specified amount.
     *
     * @param extra_HP- the amount to be added to the HP of the player.
     * **/
    void heal(int extra_HP);
    /**
     * Reduces the HP of the player by a specified amount.
     *
     * @param damagePoints- the amount of HP to be reduced from the player.
     * **/
    void damage(int damagePoints);
    /**
     * Checks if the player is knocked out (HP=0)
     *
     * @return returns true if the player is knocked out, false otherwise.
     * **/
    bool isKnockedOut() const;
    /**
     * Increases the coins of the player by a specified amount.
     *
     * @param extra_coins- the amount of coins to be added to the player.
     * **/
    void addCoins(int extra_coins);
    /**
     * Pays a specified price using the player's coins.
     *
     * @param price- The price to be paid.
     *
     * @return true if the payment was done, false otherwise.
     * **/
    bool pay(int price);
    /**
     * Gets the AttackStrength of the player.
     * **/
    int getAttackStrength() const;
    /**
     * Assignment operator for the Player class.
     *
     * @param other The other Player object to assign from.
     *
     * @return Reference to the assigned Player object.
     * **/
    Player& operator=(const Player& other);
private:
    std:: string m_name;
    int m_level;
    int m_force,m_maxHP,m_HP_HealthPoints,m_coins;

};
#endif //EX2_PLAYER_H

