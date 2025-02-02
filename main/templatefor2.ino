
//import stuff?

int task2Main() {

    float distance = getDistance();

    if (distance < MIN_SONIC_DISTANCE){
        if (getColor()==red){
            stop(); 
            turnRight();
            turnRight(); 
            drive();
        }
        else if(getColor()==blue){
        // turns left
            stop(); 
            turnLeft();
            drive();
        }
        else if(getColor()==green){
        // turn right
            stop(); 
            turnRight();
            drive();
        } else {
            // continue straight
            drive();
        }
    }
}
