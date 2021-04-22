![GainSlider In Use](https://github.com/JKeef062/Gain-Control-VST/blob/main/Imgs/PluginInReaper.PNG)
# GainSlider-VST
This repo contains the source code for a basic gain control VST3 plugin written in JUCE. This plugin is an improvement on the original plugin code provided by, The Audio Programmer, in his video "Juce Tutorial 64 - Building Your First Plug-In (2020 Update)." The plugin allows the user to reduce the channel gain by 60.0dB or boost it up to 20.0dB.


## How to Use the Plugin
1. Download the file GainSlider/Builds/VisualStudio2019/x64/Debug/VST3/GainSlider.vst3
2. Configure the DAW of your choosing to look for vst plugins in the location you have saved GainSlider.vst3


## How To Update/Change the Plugin
1. Download and install JUCE v6.0.8 or higher
2. Create a new basic plugin and title it "GainSlider"
3. Move, or copy the contents of, the PluginEditor.cpp, PluginEditor.h, PluginProcessor.cpp, and PluginProcessor.h files into the GainSlider/Source directory
4. Edit these files using any method you wish. Visual Studio and Xcode are supported by JUCE and will likely be the easiest options.
