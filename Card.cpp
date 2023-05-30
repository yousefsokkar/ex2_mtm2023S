//
// Created by Yosef Sokkar on 5/16/2023.
//

#include "Card.h"
#include "utilities.h"
#define WIN 1
#define LOSE 0

//===================================================================
Card::Card(CardType type, const CardStats &stats) {
    m_effect = type;
    m_stats.heal = stats.heal;
    m_stats.force = stats.force;
    m_stats.buff = stats.buff;
    m_stats.cost = stats.cost;
    m_stats.hpLossOnDefeat = stats.hpLossOnDefeat;
    m_stats.loot = stats.loot;
}

void Card::applyEncounter(Player &player) const {
    switch (m_effect) {
        case CardType::Buff:
            if(player.pay(m_stats.cost)){
                player.buff(m_stats.buff);
            }
            break;

        case CardType::Heal:
            if (player.pay(m_stats.cost)){
                player.heal(m_stats.heal);
            }
            break;

        case CardType::Treasure:
            player.addCoins(m_stats.loot);
            break;

        case CardType::Battle:
            if (player.getAttackStrength() >= m_stats.force){
                player.levelUp();
                player.addCoins(m_stats.loot);
                printBattleResult(WIN);
            }else{
                player.damage(m_stats.hpLossOnDefeat);
                printBattleResult(LOSE);
            }
            break;

    }
}

void Card :: printInfo() const{
    if(m_effect==CardType::Battle){
        printBattleCardInfo(m_stats);
    }
    if(m_effect==CardType::Buff){
        printBuffCardInfo(m_stats);
    }
    if(m_effect==CardType::Heal){
        printHealCardInfo(m_stats);
    }
    if(m_effect==CardType::Treasure){
        printTreasureCardInfo(m_stats);
    }
}

