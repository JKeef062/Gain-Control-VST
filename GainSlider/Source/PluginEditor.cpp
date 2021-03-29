/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainSliderAudioProcessorEditor::GainSliderAudioProcessorEditor (GainSliderAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make Slider visible in the plugin window. 
    // Set Gain Control type, min/max value, and interval.
    // This gain control will be a knob that increases by the interval with a mouse hold -> drag North
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 25);
    gainSlider.setRange(-60.0f, 10.0f, 0.01f);  // Set range to proper decibels
    gainSlider.setValue(0.0f);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

GainSliderAudioProcessorEditor::~GainSliderAudioProcessorEditor()
{
}

//==============================================================================
void GainSliderAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::black);
}

// Set size, and location of child components within the plugin window
void GainSliderAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth()/2 - 100, getHeight()/2 - 100, 200, 200);
}

// Update processor variable to hold the current value of the slider whenever the
// listener detects a change in slider value
void GainSliderAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    if (slider == &gainSlider) {
        audioProcessor.gainKnobVal = gainSlider.getValue();
    }
}
