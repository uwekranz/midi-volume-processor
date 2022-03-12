#pragma once

#include <JuceHeader.h>

class KnobLookAndFeel : public LookAndFeel_V3 {
public:
    void drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPos,
                          const float rotaryStartAngle, const float rotaryEndAngle, Slider &slider);

};
