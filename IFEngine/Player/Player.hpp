//
//  Player.hpp
//  Ramshackle
//
//  Created by David Sweetman on 12/18/15.
//  Copyright © 2015 tinfish. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "Character.hpp"
#include "Powerable.hpp"
#include <string>

NS_RAM_OPEN

extern std::string PlayerDidRunOutOfPowerNotification;

class Subsystem;
class PowerSupply;
class EmotionalState;
struct EmotionalStateData;

class Player : public Character, Powerable {
    
    int _energyUsageLevel;
    PowerSupply *_powerSupply;
    std::vector<Subsystem*> _subsystems;
    bool _isPoweredOn;
    EmotionalState *_emotionalState;
    
protected:
    Player();
    ~Player();
    
public:
    static Player* makeNew();
    
    virtual void playTurn();
    
    int getEnergyUsageLevel() { return _energyUsageLevel; };
    bool getIsPowerdOn() { return _isPoweredOn; };
    EmotionalState* getEmotionalState() { return _emotionalState; };
    
    void connectPowerSupply(PowerSupply *powerSupply);
    PowerOnResult powerOn();
    
    void applyEmotion(EmotionalStateData emotions);

};

NS_RAM_CLOSE

#endif /* Player_hpp */
