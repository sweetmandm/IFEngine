//
//  Player.cpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#include "Player.hpp"
#include "PowerSupply.hpp"
#include "Subsytem.hpp"
#include "NotificationSystem.hpp"
#include "EmotionalState.hpp"

NS_RAM_OPEN

std::string PlayerDidRunOutOfPowerNotification = "PlayerDidRunOutOfPowerNotification";

#pragma mark - Init

Player::Player() :
_powerSupply(nullptr),
_energyUsageLevel(0)
{ }

Player::~Player() {
    SAFE_DELETE(_powerSupply);
}

Player* Player::makeNew()
{
    auto player = new Player();
    auto emotions = MakeEmoData(.happiness = 0, .motivation = 0, .fear = 0, .anger = 0);
    player->_emotionalState = new EmotionalState(emotions);
    return player;
}

#pragma mark - Turns

void Player::playTurn()
{
    if (_powerSupply != nullptr) {
        _powerSupply->playTurn();
    }
    
    if (_isPoweredOn) {
        PowerUsageResult result = _powerSupply->usePower(_energyUsageLevel);
        if (result == PowerUsageResultNotEnoughPower) {
            NotificationSystem::postNotification(PlayerDidRunOutOfPowerNotification, this);
        }
    }
}

#pragma mark - Power

void Player::connectPowerSupply(PowerSupply *powerSupply)
{
    _powerSupply = powerSupply;
    powerOn();
}

PowerOnResult Player::powerOn()
{
    if (_powerSupply == nullptr) {
        return PowerOnResultNoPower;
    }
    if (_powerSupply->getRemainingPower() < _energyUsageLevel) {
        return PowerOnResultNotEnoughPower;
    }
    _isPoweredOn = true;
    return PowerOnResultRunning;
}

void Player::applyEmotion(EmotionalStateData emotions)
{
    _emotionalState->apply(emotions);
}

NS_RAM_CLOSE
