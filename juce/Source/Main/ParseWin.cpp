/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "ParseWin.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
#include "purescript.h"
#include "Main/Main.h"
//[/MiscUserDefs]

//==============================================================================
ParseWin::ParseWin ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    _txtSrc.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (_txtSrc.get());
    _txtSrc->setMultiLine (true);
    _txtSrc->setReturnKeyStartsNewLine (true);
    _txtSrc->setReadOnly (false);
    _txtSrc->setScrollbarsShown (true);
    _txtSrc->setCaretVisible (true);
    _txtSrc->setPopupMenuEnabled (true);
    _txtSrc->setText (String());

    _txtSrc->setBounds (40, 80, 900, 400);

    _txtDst.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (_txtDst.get());
    _txtDst->setMultiLine (true);
    _txtDst->setReturnKeyStartsNewLine (true);
    _txtDst->setReadOnly (false);
    _txtDst->setScrollbarsShown (true);
    _txtDst->setCaretVisible (true);
    _txtDst->setPopupMenuEnabled (true);
    _txtDst->setText (String());

    _txtDst->setBounds (40, 496, 900, 400);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 600);


    //[Constructor] You can add your own custom stuff here..
	_txtSrc.get()->addListener(this);
    //[/Constructor]
}

ParseWin::~ParseWin()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    _txtSrc = nullptr;
    _txtDst = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ParseWin::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ParseWin::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void ParseWin::textEditorTextChanged(TextEditor &txtEdt)
{
	if (&txtEdt == _txtSrc.get())
	{
		_txtDst.get()->setText(purescript::unbox<juce::String>(Main::getParseResultString()(txtEdt.getText())));
	}
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ParseWin" componentName=""
                 parentClasses="public Component, TextEditor::Listener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="800" initialHeight="600">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTEDITOR name="new text editor" id="6e89aa47cb966f77" memberName="_txtSrc"
              virtualName="" explicitFocusOrder="0" pos="40 80 900 400" initialText=""
              multiline="1" retKeyStartsLine="1" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="c2bd58971f2f68ad" memberName="_txtDst"
              virtualName="" explicitFocusOrder="0" pos="40 496 900 400" initialText=""
              multiline="1" retKeyStartsLine="1" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

