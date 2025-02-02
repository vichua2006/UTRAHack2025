void ledBlink() {
    ledOn();
    delay(500);
    ledOff();
    delay(500);
}

void ledOn() {
    digitalWrite(LED_PIN, HIGH);
    // analogWrite(LED_PIN, 255);
}

void ledOff() {
    digitalWrite(LED_PIN, LOW);
    // analogWrite(LED_PIN, 0);
}
