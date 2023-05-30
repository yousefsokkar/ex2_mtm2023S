#include "Player.h"
#include "utilities.h"
#include <iostream>
#include <utility>
Player::Player(const Player& other)
        : m_name(other.m_name), m_level(other.m_level), m_force(other.m_force),
          m_maxHP(other.m_maxHP), m_HP_HealthPoints(other.m_HP_HealthPoints), m_coins(other.m_coins) {
}

// Getter and Setter for level
int Player::getLevel() const {
    return m_level;
}


Player :: Player(std :: string name_arg,int maxHP_arg,int force_arg){
    m_name = std::move(name_arg);
    m_level = 1;
    m_coins = 0;
    if (force_arg <= 0) {
        m_force = 5;
    }
    else {
        m_force = force_arg;
    }
    if (maxHP_arg <= 0) {
        m_maxHP = 100;
        m_HP_HealthPoints = 100;
    }
    else {
        m_maxHP = maxHP_arg;
        m_HP_HealthPoints = maxHP_arg;
    }
}


void Player::printInfo() const {
    printPlayerInfo(m_name.c_str(), m_level, m_force, m_HP_HealthPoints, m_coins);
}


Player& Player::operator=(const Player& other) {
    if (this == &other) {
        return *this;
    }
    m_name = other.m_name;
    m_level = other.m_level;
    m_force = other.m_force;
    m_maxHP = other.m_maxHP;
    m_HP_HealthPoints = other.m_HP_HealthPoints;
    m_coins = other.m_coins;
    return *this;
}


Player::~Player() = default;


void Player::heal(int extra_HP) {
    if(extra_HP<0){
        return;
    }
    m_HP_HealthPoints += extra_HP;
    if(m_HP_HealthPoints > m_maxHP){
        m_HP_HealthPoints = m_maxHP;
    }
}


bool Player::isKnockedOut() const {
    if(m_HP_HealthPoints<=0){
        return true;
    }else{
        return false;
    }
}


bool Player::pay(int price) {
    if(m_coins < price){
        return false;
    }else{
        m_coins-=price;
        return true;
    }
}


void Player::levelUp (){
    if (m_level<10){
        m_level=m_level+1;
    }
}


void Player:: buff (int add_force){
    if(add_force >= 0){
        m_force = m_force + add_force;
    }
}


void Player:: damage(int damagePoints){
    if(damagePoints<0){
        return;
    }
    if(m_HP_HealthPoints<damagePoints){
        m_HP_HealthPoints=0;
        return;
    }
    m_HP_HealthPoints=m_HP_HealthPoints-damagePoints;
}


void Player:: addCoins(int extra_coins){
    if(extra_coins >= 0){
        m_coins=m_coins+extra_coins;
    }
}


int  Player:: getAttackStrength() const{
    return m_level+m_force;
}

