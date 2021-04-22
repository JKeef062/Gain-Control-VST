/*
 ==============================================================================
                HEADER FILE FOR THE UI WINDOW OF THE PLUGIN
 ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "SliderLookAndFeel.h"


class GainSliderAudioProcessorEditor  : public juce::AudioProcessorEditor, 
                                        public juce::Slider::Listener
{
public:
    GainSliderAudioProcessorEditor (GainSliderAudioProcessor&);
    ~GainSliderAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    // Define what happens when the slider listener detects a change in slider value
    void sliderValueChanged(juce::Slider* slider) override;

private:
    juce::ImageComponent background;    // Background image 
    SliderLookAndFeel slider_appear;    // Slider appearance
    juce::Slider gainSlider;            // Actual gain control component
    GainSliderAudioProcessor& audioProcessor;   // Object that implements all DSP processing

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainSliderAudioProcessorEditor)
};
