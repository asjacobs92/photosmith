#include "CustomZoomOutForm.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>

using namespace Photosmith;
using namespace msclr::interop;

CustomZoomOutForm::CustomZoomOutForm()
{
	SetDivWidth(0);
	SetDivHeight(0);
	InitializeComponent();
}

CustomZoomOutForm::~CustomZoomOutForm()
{
	if (components)
	{
		delete components;
	}
}

System::Void CustomZoomOutForm::ConfirmButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(!(marshal_as<std::string>(widthTextBox->Text).empty()))
	{
		try 
		{
			SetDivWidth(int::Parse(widthTextBox->Text));
		} 
		catch (Exception^ e) 
		{
			SetDivWidth(0);
		}
	}

	if(!(marshal_as<std::string>(heightTextBox->Text).empty()))
	{
		try 
		{
			SetDivHeight(int::Parse(heightTextBox->Text));
		} 
		catch (Exception^ e) 
		{
			SetDivHeight(0);
		}
	}

}

int CustomZoomOutForm::GetDivWidth()
{
	return divWidth;
}

void CustomZoomOutForm::SetDivWidth(int divW)
{
	divWidth = divW;
}

int CustomZoomOutForm::GetDivHeight()
{
	return divHeight;
}

void CustomZoomOutForm::SetDivHeight(int divH)
{
	divHeight = divH;
}
