/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class BasicPluginAudioProcessorEditor  : public AudioProcessorEditor,
                                         private Slider::Listener
{
public:
    BasicPluginAudioProcessorEditor (BasicPluginAudioProcessor&);
    ~BasicPluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged(Slider* slider) override;
    void toggleState();
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    BasicPluginAudioProcessor& processor;

    Slider midiVolume;

    ToggleButton midiMute;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BasicPluginAudioProcessorEditor)
};
