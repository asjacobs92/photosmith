#include "HistogramForm.h"

using namespace Photosmith;


HistogramForm::HistogramForm()
{
	InitializeComponent();
	HistogramForm::image = gcnew Bitmap(256,256);
}

HistogramForm::HistogramForm(Bitmap^ image)
{
	InitializeComponent();
	HistogramForm::image = image;
}

HistogramForm::~HistogramForm()
{
	if (components)
	{
		delete components;
	}
}

System::Void HistogramForm::HistogramPicutreBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	vector<float> histogram = ComputeHistogram(image);
	Graphics^ graph = e->Graphics;

	int highestValue = 0;
	for(int i = 0; i < histogram.size(); i++)
	{
		if(histogram[i] > highestValue)
		{
			highestValue = histogram[i];
		}
	}

	if(highestValue > 0)
	{
		Pen^ pen = gcnew Pen(Color::Blue, 1.8);
		int height = histogramPicutreBox->Height;
		for (int i = 0,  j = 0; i < histogram.size(); i++, j += 2)
		{
			if(histogram[i] > 0)
			{
				graph->DrawLine(pen, j, height - (height * Math::Log10(histogram[i])/Math::Log10(highestValue)), j, height);
			}
		}
		delete pen;
	}
}