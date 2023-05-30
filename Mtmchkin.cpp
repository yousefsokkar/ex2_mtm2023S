#include "Mtmchkin.h"

Mtmchkin::~Mtmchkin() {
    delete[] m_cardsArray;
}

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
        : m_player(playerName), m_numOfCards(numOfCards), m_game_status(GameStatus::MidGame), m_nextIndex(0) {

    m_cardsArray = new const Card*[numOfCards];

    for (int i = 0; i < numOfCards; i++) {
        m_cardsArray[i] = &cardsArray[i];
    }
}

void Mtmchkin::playNextCard() {
    const Card* currCard = m_cardsArray[m_nextIndex];
    m_nextIndex++;

    if (m_nextIndex == m_numOfCards) {
        m_nextIndex = 0;
    }

    currCard->printInfo();
    currCard->applyEncounter(m_player);

    if (m_player.isKnockedOut()) {
        m_game_status = GameStatus::Loss;
    }

    if (m_player.getLevel() == 10) {
        m_game_status = GameStatus::Win;
    }

    m_player.printInfo();
}

bool Mtmchkin::isOver() const {
    return (m_game_status != GameStatus::MidGame);
}

GameStatus Mtmchkin::getGameStatus() const {
    return m_game_status;
}
Mtmchkin::Mtmchkin(const Mtmchkin& other)
        : m_player(other.m_player), m_numOfCards(other.m_numOfCards),
          m_game_status(other.m_game_status), m_nextIndex(other.m_nextIndex) {

    m_cardsArray = new const Card*[other.m_numOfCards];

    for (int i = 0; i < other.m_numOfCards; i++) {
        m_cardsArray[i] = other.m_cardsArray[i];
    }
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& other) {
    if (this == &other) {
        return *this;
    }

    delete[] m_cardsArray;
    m_cardsArray = new const Card*[other.m_numOfCards];

    m_numOfCards = other.m_numOfCards;
    m_nextIndex = other.m_nextIndex;
    m_player = other.m_player;

    for (int i = 0; i < other.m_numOfCards; i++) {
        m_cardsArray[i] = other.m_cardsArray[i];
    }

    return *this;
}

