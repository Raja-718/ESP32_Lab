#include "unihiker_k10.h"
#include "AIRecognition.h"

UNIHIKER_K10  k10;
uint8_t screen_dir=2;
AIRecognition ai;

void setup() {
    k10.begin();
    k10.initScreen(screen_dir);
    ai.initAi();
    k10.initBgCamerImage();
    k10.setBgCamerImage(false);
    k10.creatCanvas();
    ai.switchAiMode(ai.NoMode);
    k10.setBgCamerImage(true);
    ai.switchAiMode(ai.Move);
    ai.setMotinoThreshold(50);
    k10.rgb->write(-1, 0x0000FF);
}
void loop() {
    if (ai.isDetectContent(AIRecognition::Move)) { 
        k10.rgb->write(-1, 0xFF0000);
    }
    else {
        k10.rgb->write(-1, 0x0000FF);
    }
}