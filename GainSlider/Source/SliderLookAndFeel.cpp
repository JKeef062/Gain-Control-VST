/*
  ==============================================================================

    SliderLookAndFeel.cpp
    Created: 2 Apr 2021 3:25:47pm
    Author:  Jared Keefer

  ==============================================================================
*/

#include <JuceHeader.h>
#include "SliderLookAndFeel.h"

//==============================================================================
SliderLookAndFeel::SliderLookAndFeel()
{
    setColour(juce::Slider::thumbColourId, juce::Colours::blue);
    setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::teal);
}

SliderLookAndFeel::~SliderLookAndFeel()
{
}


