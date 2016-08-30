#include "AdjustColorsForm.h"

using namespace Photosmith;

AdjustColorsForm::AdjustColorsForm()
{
	SetContrastValue(0);
	SetBrightnessValue(0);

	InitializeComponent();
}

AdjustColorsForm::~AdjustColorsForm()
{
	if(components)
	{
		delete components;
	}
}

System::Void AdjustColorsForm::ConfirmButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	SetBrightnessValue(brightessTrackBar->Value);
	SetContrastValue((float) contrastTrackBar->Value/10);
}


int AdjustColorsForm::GetBrightnessValue()
{
	return brightnessValue;
}

void AdjustColorsForm::SetBrightnessValue(int value)
{
	brightnessValue = value;
}

float AdjustColorsForm::GetContrastValue()
{
	return contrastValue;
}

void AdjustColorsForm::SetContrastValue(float value)
{
	contrastValue = value;
}

