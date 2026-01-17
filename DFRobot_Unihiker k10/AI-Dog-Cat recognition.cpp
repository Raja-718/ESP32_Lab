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
    ai.switchAiMode(ai.Cat);
}
void loop() {
    if (ai.isDetectContent(AIRecognition::Cat)) {
        k10.canvas->canvasText((String("Face Length: ") + String(ai.getCatData(AIRecognition::Length))), 0, 0, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->canvasText((String("Face Width: ") + String(ai.getCatData(AIRecognition::Width))), 0, 20, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->canvasText((String("Face X: ") + String(ai.getCatData(AIRecognition::CenterX))), 0, 40, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->canvasText((String("Face Y:  ") + String(ai.getCatData(AIRecognition::CenterY))), 0, 60, 0x0000FF, k10.canvas->eCNAndENFont16, 50, true);
        k10.canvas->updateCanvas();
    }
}