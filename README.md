# GainSlider-VST
This repo contains the source code for a basic gain control VST3 plugin written in JUCE. This plugin is an improvement on the original plugin code provided by, The Audio Programmer, in his video "Juce Tutorial 64 - Building Your First Plug-In (2020 Update)." The plugin allows the user to reduce the channel gain by 60.0dB or boost it up to 20.0dB.

<img src="https://github.com/JKeef062/Gain-Control-VST/blob/main/Imgs/PluginInReaper.PNG" width="800" height="519">

## How to Use the Plugin
      1. Download the folder Plugin from this repository
      2. You can find, and run, the stand alone plugin by navigating to '<location_of_folder_download>/Plugin/Standalone Plugin/' and running GainSlider.exe
      4. If you wish to use this plugin in a DAW or other program that supports vst3s:
         - Configure the program of your choosing to look for vst plugins in the '<location_of_folder_download>/Plugin/VST3/' directory.
         - Load the plugin into the audio chain and enjoy!


## How To Update/Change the Plugin
      1. Download and install JUCE v6.0.8 or higher
      2. Create a new basic plugin and title it "GainSlider"
      3. Move, or copy the contents of, the PluginEditor.cpp, PluginEditor.h, PluginProcessor.cpp, PluginProcessor.h, SliderLookAndFeel.h, and SliderLookAndFeel.cpp files into the GainSlider/Source directory
      4. Edit these files in any way you desire 
         - NOTE: Visual Studio and Xcode are supported by JUCE and will likely be the easiest options for adding your own functionality.
