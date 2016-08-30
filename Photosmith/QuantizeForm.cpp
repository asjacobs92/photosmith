#include "QuantizeForm.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>

using namespace Photosmith;
using namespace msclr::interop;

QuantizeForm::QuantizeForm()
{
	SetNumberOfShades(0);
	InitializeComponent();
}

QuantizeForm::~QuantizeForm()
{
	if (components)
	{
		delete components;
	}
}

System::Void QuantizeForm::ConfirmButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(!(marshal_as<std::string>(numShadesTextBox->Text).empty()))
	{
		try 
		{
			SetNumberOfShades(int::Parse(numShadesTextBox->Text));
		} 
		catch (Exception^ e) 
		{
			SetNumberOfShades(-1);
		}
	}
}

int QuantizeForm::GetNumberOfShades()
{
	return numShades;
}

void QuantizeForm::SetNumberOfShades(int shades)
{
	numShades = shades;
}
