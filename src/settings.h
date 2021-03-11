#ifndef SETTING.H
#define SETTINGS.H

namespace Settings{
    const int LED = 9;
    const int POT = 0;

    void initSettings(){
        pinmMode(LED, OUTPUT);
        pinMode(POT, INPUT);
    }
}

#endif
