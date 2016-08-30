#include "ConvolveForm.h"
#include <iostream>
#include <msclr\marshal_cppstd.h>

using namespace Photosmith;
using namespace msclr::interop;

ConvolveForm::ConvolveForm()
{
	InitializeComponent();
	
	kernel = gcnew array<array<float>^>(3);
	for(int i = 0; i < 3; i++)
	{
		kernel[i] = gcnew array<float>(3);
		for(int j = 0; j < 3; j++)
		{
			kernel[i][j] = 0;
		}
	}

	SetClamping(false);
}

ConvolveForm::~ConvolveForm()
{
	if (components)
	{
		delete components;
	}
}

System::Void ConvolveForm::ConfirmButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	int i, j = 0;
	for each (Object^ kernelValue in kernelTable->Controls)
	{
		if(!(marshal_as<std::string>(((TextBox^) kernelValue)->Text).empty()))
		{
			try 
			{
				kernel[i][j] = float::Parse(((TextBox^) kernelValue)->Text);
				j++;
				if(j > 2)
				{
					j = 0;
					i++;
				}
			} 
			catch (Exception^ e) 
			{
				MessageBox::Show(this, "Please enter only numbers in the kernel", "Invalid values!", 
						MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
}

System::Void ConvolveForm::CustomRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	kernelTable->Enabled = true;

	for each (Object^ kernelValue in kernelTable->Controls)
	{
		((TextBox^) kernelValue)->Text = "0";
	}
}

System::Void ConvolveForm::GaussianRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	kernelTable->Enabled = false;
	kernelValue1TextBox->Text = "0,0625";
	kernelValue2TextBox->Text = "0,125";
	kernelValue3TextBox->Text = "0,0625";

	kernelValue4TextBox->Text = "0,125";
	kernelValue5TextBox->Text = "0,25";
	kernelValue6TextBox->Text = "0,125";

	kernelValue7TextBox->Text = "0,0625";
	kernelValue8TextBox->Text = "0,125";
	kernelValue9TextBox->Text = "0,0625";
}
			
System::Void ConvolveForm::LaplacianRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	kernelTable->Enabled = false;
	kernelValue1TextBox->Text = "0";
	kernelValue2TextBox->Text = "-1";
	kernelValue3TextBox->Text = "0";

	kernelValue4TextBox->Text = "-1";
	kernelValue5TextBox->Text = "4";
	kernelValue6TextBox->Text = "-1";

	kernelValue7TextBox->Text = "0";
	kernelValue8TextBox->Text = "-1";
	kernelValue9TextBox->Text = "0";
}

System::Void ConvolveForm::SobelHxRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	kernelTable->Enabled = false;
	kernelValue1TextBox->Text = "-1";
	kernelValue2TextBox->Text = "0";
	kernelValue3TextBox->Text = "1";

	kernelValue4TextBox->Text = "-2";
	kernelValue5TextBox->Text = "0";
	kernelValue6TextBox->Text = "2";

	kernelValue7TextBox->Text = "-1";
	kernelValue8TextBox->Text = "0";
	kernelValue9TextBox->Text = "1";
	SetClamping(true);
}

System::Void ConvolveForm::SobelHyRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	kernelTable->Enabled = false;
	kernelValue1TextBox->Text = "-1";
	kernelValue2TextBox->Text = "-2";
	kernelValue3TextBox->Text = "-1";

	kernelValue4TextBox->Text = "0";
	kernelValue5TextBox->Text = "0";
	kernelValue6TextBox->Text = "0";

	kernelValue7TextBox->Text = "1";
	kernelValue8TextBox->Text = "2";
	kernelValue9TextBox->Text = "1";
	SetClamping(true);
}

System::Void ConvolveForm::HighPassRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	kernelTable->Enabled = false;
	kernelValue1TextBox->Text = "-1";
	kernelValue2TextBox->Text = "-1";
	kernelValue3TextBox->Text = "-1";

	kernelValue4TextBox->Text = "-1";
	kernelValue5TextBox->Text = "8";
	kernelValue6TextBox->Text = "-1";

	kernelValue7TextBox->Text = "-1";
	kernelValue8TextBox->Text = "-1";
	kernelValue9TextBox->Text = "-1";
}

System::Void ConvolveForm::PrewittHxRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	kernelTable->Enabled = false;
	kernelValue1TextBox->Text = "-1";
	kernelValue2TextBox->Text = "0";
	kernelValue3TextBox->Text = "1";

	kernelValue4TextBox->Text = "-1";
	kernelValue5TextBox->Text = "0";
	kernelValue6TextBox->Text = "1";

	kernelValue7TextBox->Text = "-1";
	kernelValue8TextBox->Text = "0";
	kernelValue9TextBox->Text = "1";
	SetClamping(true);

}

System::Void ConvolveForm::PrewittHyRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	kernelTable->Enabled = false;
	kernelValue1TextBox->Text = "-1";
	kernelValue2TextBox->Text = "-1";
	kernelValue3TextBox->Text = "-1";

	kernelValue4TextBox->Text = "0";
	kernelValue5TextBox->Text = "0";
	kernelValue6TextBox->Text = "0";

	kernelValue7TextBox->Text = "1";
	kernelValue8TextBox->Text = "1";
	kernelValue9TextBox->Text = "1";
	SetClamping(true);
}

bool ConvolveForm::GetClamping()
{
	return clamping;
}

void ConvolveForm::SetClamping(bool clamp)
{
	clamping = clamp;
}

array<array<float>^>^ ConvolveForm::GetKernel()
{
	return kernel;
}