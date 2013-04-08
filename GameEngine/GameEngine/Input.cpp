#include "Input.h"

IKeyboard* Input::sKeyboard = NULL;
IMouse* Input::sMouse = NULL;

boost::scoped_ptr<Input> Input::pInput(NULL);

Input::Input(void)
{
	sKeyboard = NULL;
	sMouse = NULL;
}

Input::Input(std::string inputMethod)
{
	SetInputMethod(inputMethod);
}

Input::~Input(void)
{
	if(sKeyboard != NULL)
	{
		delete sKeyboard;
		sKeyboard = NULL;
	}

	if(sMouse != NULL)
	{
		delete sMouse;
		sMouse = NULL;
	}
}

void Input::SetInputMethod(std::string inputMethod)
{
	if(inputMethod == "OPENGL")
	{
		sKeyboard = new OGLKeyboard;
		sMouse = new OGLMouse;
	}
	else
	{
		// TODO throw error, no input method found
	}
}

IKeyboard* Input::GetKeyboard()
{
	return sKeyboard;
}

IMouse* Input::GetMouse()
{
	return sMouse;
}

boost::scoped_ptr<Input>* Input::GetInstance()
{
	if(pInput.get() == NULL)
	{
		pInput.reset(new Input);
	}

	return &pInput;
}