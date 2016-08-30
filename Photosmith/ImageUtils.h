#pragma once
#include <vector>

using namespace std;
using namespace System;
using namespace System::Drawing;

vector<float> ComputeHistogram(Bitmap^ image);

Bitmap^ ZoomIn(Bitmap^ image);

Bitmap^ ZoomOut(Bitmap^ image);

Bitmap^ ZoomOut(Bitmap^ image, int divHeight, int divWidth);

Bitmap^ RotateLeft(Bitmap^ image);

Bitmap^ RotateRight(Bitmap^ image);

Bitmap^ InvertYAxis(Bitmap^ image);

Bitmap^ InvertXAxis(Bitmap^ image);

Bitmap^ EqualizeHistogram(Bitmap^ image);

Bitmap^ ConvertToNegative(Bitmap^ image);		

Bitmap^ ConvertToGrayscale(Bitmap^ image);

Bitmap^ Quantize(Bitmap^ image, int numShades);

Bitmap^ Convolve(Bitmap^ image, array<array<float>^>^ kernel, bool clamping);

Bitmap^ AdjustColors(Bitmap^ image, float contrastValue, int brightnessValue);