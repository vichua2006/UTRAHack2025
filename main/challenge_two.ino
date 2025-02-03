enum ChallengeTwoState {
    INIT,
    WAIT_FOR_WALL,
    TURN_INSTRUCTION,
    DONE
};

ChallengeTwoState challengeTwoState = ChallengeTwoState::INIT;

color currColor;
float distance;

void setChallengeTwoState(enum ChallengeTwoState state);
void setChallengeTwoState(enum ChallengeTwoState state) {
    challengeTwoState = state;
    Serial.print("State changed to: ");
    switch(state) {
        case ChallengeTwoState::INIT:
            Serial.println("INIT");
            break;
        case ChallengeTwoState::WAIT_FOR_WALL:
            Serial.println("WAIT_FOR_WALL");
            break;
        case ChallengeTwoState::TURN_INSTRUCTION:
            Serial.println("TURN_INSTRUCTION");
            break;
        case ChallengeTwoState::DONE:
            Serial.println("DONE");
            break;
    }
}

void challengeTwo(int def) {
  timeSave();
    switch(challengeTwoState) {
        case ChallengeTwoState::INIT:
            drive();
            Serial.print("Dist: ");
            Serial.println(getDistance());
            
            if(isColorFound()) {
                setChallengeTwoState(ChallengeTwoState::WAIT_FOR_WALL);
            }
            // if(getDistance() < DISTANCE_THRESHOLD) {
            //   stop();
            //   delay(1000);
            //   setChallengeTwoState(ChallengeTwoState::TURN_INSTRUCTION);
            // }
            break;
        case ChallengeTwoState::WAIT_FOR_WALL:
            drive();

            distance = getDistance();
            Serial.print("EYOOOO: ");
            Serial.println(distance);
            if (distance < DISTANCE_THRESHOLD) {
                stop();
                delay(1000);
                setChallengeTwoState(ChallengeTwoState::TURN_INSTRUCTION);
            }
            break;
        case ChallengeTwoState::TURN_INSTRUCTION:
            currColor = getColor();
            switch(currColor) {
                case red:
                    turnRight();
                    turnRight();
                    delay(1000);
                    setChallengeTwoState(ChallengeTwoState::WAIT_FOR_WALL);
                    break;
                case blue:
                    turnLeft();
                    delay(1000);
                    setChallengeTwoState(ChallengeTwoState::WAIT_FOR_WALL);
                    break;
                case green:
                    turnRight();
                    delay(1000);
                    setChallengeTwoState(ChallengeTwoState::WAIT_FOR_WALL);
                    break;
                case error:
                    delay(1000);
                    stop();
                    setChallengeTwoState(ChallengeTwoState::DONE);
                    break;
            }
            break;
        case ChallengeTwoState::DONE:
            break;
    }
}
