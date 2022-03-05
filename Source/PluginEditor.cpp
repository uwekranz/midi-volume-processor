/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
BasicPluginAudioProcessorEditor::BasicPluginAudioProcessorEditor (BasicPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 200);

    // these define the parameters of our slider object
    midiVolume.setSliderStyle(Slider::LinearBarVertical);
    midiVolume.setRange(0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled(true, false, this);
    midiVolume.setTextValueSuffix(" Volume");
    midiVolume.setValue(1.0);

    // this function adds the slider to the editor
    addAndMakeVisible(&midiVolume);

    // add the listener to the slider
    midiVolume.addListener(this);

    // add mute button
    midiMute.setButtonText("Mute");
    midiMute.onClick = [this] { toggleState(); };
    addAndMakeVisible(&midiMute);
}

BasicPluginAudioProcessorEditor::~BasicPluginAudioProcessorEditor() = default;

//==============================================================================

void BasicPluginAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    processor.noteOnVel = midiVolume.getValue();
}

void BasicPluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);

    g.drawFittedText("Midi Volume", 0, 0, getWidth(), 30, Justification::centred, 1);
}

void BasicPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    // sets the position and size of the slider with arguments (x, y, width, height)
    midiVolume.setBounds(40, 30, 20, getHeight() - 60);

    midiMute.setBounds(80, 40, 50, 50);
}

void BasicPluginAudioProcessorEditor::toggleState() {
    processor.noteOnVel = midiMute.getToggleState() ? 0 : midiVolume.getValue();
}
