/*
 ==============================================================================
                            UI IMPLEMENTATION
 ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


GainSliderAudioProcessorEditor::GainSliderAudioProcessorEditor (GainSliderAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Initialize the background image and make it visible
    background.setImage(juce::ImageCache::getFromMemory(BinaryData::MarbleBG_w_Logo_png, BinaryData::MarbleBG_w_Logo_pngSize));
    background.setImagePlacement(juce::RectanglePlacement::stretchToFit);
    addAndMakeVisible(background);

    // Make Slider visible in the plugin window. 
    // Set Gain Control type, min/max value, and interval.
    // This gain control will be a knob that increases by the interval with a mouse hold -> drag North
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    gainSlider.setLookAndFeel(&slider_appear);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 25);
    gainSlider.setRange(-60.0f, 10.0f, 0.01f);  // Set range to proper decibels
    gainSlider.setSkewFactorFromMidPoint(0.0f);
    gainSlider.setValue(audioProcessor.gainKnobVal);
    gainSlider.addListener(this);
    gainSlider.setSize(200, 200);
    addAndMakeVisible(gainSlider);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(300, 400);
}


GainSliderAudioProcessorEditor::~GainSliderAudioProcessorEditor()
{
}


void GainSliderAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //juce::Image bkgrnd = juce::ImageCache::getFromMemory(BinaryData::MarbleBG_jpg, BinaryData::MarbleBG_jpgSize);
    //g.drawImageAt(bkgrnd, 0.0f, 0.0f);
}


// Set size, and location of child components within the plugin window
void GainSliderAudioProcessorEditor::resized()
{
    // Resize the backgound to fill the entire new window size
    background.setBounds(getLocalBounds());

    // Adjust the gain slider to match the new size of the window
    float sliderExpansionRate = 0.5;
    int winWidth = getWidth(), winHeight = getHeight();

    gainSlider.setBounds(winWidth/2 - gainSlider.getWidth()/2, 
                         winHeight/2 - gainSlider.getHeight()/2 + winHeight*0.1, 
                         200 + sliderExpansionRate*(winWidth-300), 
                         200 + sliderExpansionRate*(winHeight-400));
}


// Update processor variable to hold the current value of the slider whenever the
// listener detects a change in slider value
void GainSliderAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    if (slider == &gainSlider) {
        audioProcessor.gainKnobVal = gainSlider.getValue();
    }
}
