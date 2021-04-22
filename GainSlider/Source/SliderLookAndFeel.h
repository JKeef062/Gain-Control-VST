/*
  ==============================================================================

    SliderLookAndFeel.h
    Created: 2 Apr 2021 3:25:47pm
    Author:  Jared Keefer

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class SliderLookAndFeel  : public juce::LookAndFeel_V4
{
public:
    SliderLookAndFeel();
    ~SliderLookAndFeel() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SliderLookAndFeel)
};
