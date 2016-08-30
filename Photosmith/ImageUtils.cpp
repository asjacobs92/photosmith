#include "ImageUtils.h"


Bitmap^ RotateLeft(Bitmap^ image)
{
	Bitmap^ newImage = gcnew Bitmap(image->Height, image->Width);

	for(int i = 0;  i < image->Height; i++) 
	{  
		for(int j = 0; j < image->Width; j++)
		{
			newImage->SetPixel(i, image->Width - j - 1, image->GetPixel(j,i));
		}
	}

	delete image;
	return newImage;
}

Bitmap^ RotateRight(Bitmap^ image)
{
	Bitmap^ newImage = gcnew Bitmap(image->Height, image->Width);

	for(int i = 0;  i < image->Height; i++) 
	{  
		for(int j = 0; j < image->Width; j++)
		{
			newImage->SetPixel(image->Height - i - 1, j, image->GetPixel(j,i));
		}
	}

	delete image;
	return newImage;
}

Bitmap^ InvertYAxis(Bitmap^ image)
{
	Bitmap^ newImage = gcnew Bitmap(image->Width, image->Height);

	for(int i = 0;  i < image->Height; i++) 
	{  
		for(int j = 0; j < image->Width; j++)
		{
			newImage->SetPixel(image->Width - j - 1, i, image->GetPixel(j,i));
		}
	}

	delete image;
	return newImage;
}

Bitmap^ InvertXAxis(Bitmap^ image)
{
	Bitmap^ newImage = gcnew Bitmap(image->Width, image->Height);

	for(int i = 0;  i < image->Height; i++) 
	{  
		for(int j = 0; j < image->Width; j++)
		{
			newImage->SetPixel(j, image->Height - i - 1, image->GetPixel(j,i));
		}
	}

	delete image;
	return newImage;
}

Bitmap^ ConvertToGrayscale(Bitmap^ image)
{
	Bitmap^ newImage = gcnew Bitmap(image->Width, image->Height);

	for(int i = 0;  i < image->Height; i++) 
	{  
		for(int j = 0; j < image->Width; j++)
		{
			//L = 0.299*R + 0.587*G + 0.114*B
			int luminance = image->GetPixel(j,i).R * 0.299 + 
				image->GetPixel(j,i).G * 0.587 +
				image->GetPixel(j,i).B * 0.114;
			Color color = Color::FromArgb(image->GetPixel(j,i).A, luminance,luminance,luminance);
			newImage->SetPixel(j, i, color);
		}
	}

	delete image;
	return newImage;
}

Bitmap^ ConvertToNegative(Bitmap^ image)
{
	Bitmap^ newImage = gcnew Bitmap(image->Width, image->Height);

	for(int i = 0;  i < image->Height; i++) 
	{  
		for(int j = 0; j < image->Width; j++)
		{
			int newR = 255 - image->GetPixel(j,i).R;
			int newG = 255 - image->GetPixel(j,i).G;
			int newB = 255 - image->GetPixel(j,i).B;

			Color color = Color::FromArgb(image->GetPixel(j,i).A, newR,newG,newB);
			newImage->SetPixel(j, i, color);
		}
	}

	delete image;
	return newImage;
}

Bitmap^ Quantize(Bitmap^ image, int numShades)
{
	Bitmap^ newImage = gcnew Bitmap(image->Width, image->Height);

	int size = 256/numShades;
	int mean = (size - 1)/2;

	for(int i = 0;  i < image->Height; i++) 
	{  
		for(int j = 0; j < image->Width; j++)
		{
			int newR = (image->GetPixel(j,i).R/size)*size+mean;
			int newG = (image->GetPixel(j,i).G/size)*size+mean;
			int newB = (image->GetPixel(j,i).B/size)*size+mean;

			newR = (newR > 255) ? 255 : newR;
			newG = (newG > 255) ? 255 : newG;
			newB = (newB > 255) ? 255 : newB;

			Color color = Color::FromArgb(image->GetPixel(j,i).A, newR, newG, newB);
			newImage->SetPixel(j, i, color);
		}
	}

	delete image;
	return newImage;
}

Bitmap^ AdjustColors(Bitmap^ image, float contrastValue, int brightnessValue)
{
	Bitmap^ newImage = gcnew Bitmap(image->Width, image->Height);

	for(int i = 0; i < image->Height; i++)
	{
		for(int j = 0; j < image->Width; j++)
		{
			int newR = (int)image->GetPixel(j,i).R*contrastValue + brightnessValue;

			newR = (newR < 0) ? 0 : newR;
			newR = (newR > 255) ? 255 : newR;

			int newG = (int)image->GetPixel(j,i).G*contrastValue + brightnessValue;

			newG = (newG < 0) ? 0 : newG;
			newG = (newG > 255) ? 255 : newG;

			int newB = (int)image->GetPixel(j,i).B*contrastValue + brightnessValue;

			newB = (newB < 0) ? 0 : newB;
			newB = (newB > 255) ? 255 : newB;

			Color color = Color::FromArgb(image->GetPixel(j,i).A, newR, newG, newB);
			newImage->SetPixel(j, i, color);
		}
	}

	delete image;
	return newImage;
}

vector<float> ComputeHistogram(Bitmap^ image)
{
	vector<float> histogram = vector<float>(256);
	histogram.assign(256, 0);
	Bitmap^ newImage = gcnew Bitmap(image);
	newImage = ConvertToGrayscale(newImage);

	for(int i = 0; i < newImage->Height; i++)
	{
		for(int j = 0; j < newImage->Width; j++)
		{
			histogram[newImage->GetPixel(j,i).R] += 1;	
		}
	}

	delete newImage;
	return histogram;
}

Bitmap^ EqualizeHistogram(Bitmap^ image)
{
	vector<float> histogram = ComputeHistogram(image); 
	vector<float> cumulativeHistogram = vector<float>(256);
	Bitmap^ newImage = gcnew Bitmap(image->Width, image->Height);

	float scalingFactor = 255/((float)image->Width*(float)image->Height);
	cumulativeHistogram[0] = scalingFactor*histogram[0];
	for(int i = 1; i < histogram.size(); i++)
	{
		cumulativeHistogram[i] = cumulativeHistogram[i-1] + scalingFactor*histogram[i];
	}

	for(int i = 0; i < newImage->Height; i++)
	{
		for(int j = 0; j < newImage->Width; j++)
		{
			Color color = Color::FromArgb(image->GetPixel(j,i).A, 
				cumulativeHistogram[image->GetPixel(j,i).R], 
				cumulativeHistogram[image->GetPixel(j,i).G], 
				cumulativeHistogram[image->GetPixel(j,i).B]);
			newImage->SetPixel(j, i, color);	
		}
	}

	delete image;
	return newImage;
}


Bitmap^ Convolve(Bitmap^ image, array<array<float>^>^ kernel, bool clamping)
{
	image = ConvertToGrayscale(image);
	Bitmap^ newImage = gcnew Bitmap(image->Width, image->Height);

	for(int i = 1; i < image->Height - 1; i++)
	{
		for(int j = 1; j < image->Width - 1; j++)
		{
			float pixelValueR = 0;
			float pixelValueG = 0;
			float pixelValueB = 0;

			for(int k = -1; k < 2; k++)
			{
				for(int l = -1; l < 2; l++)
				{
					pixelValueR += image->GetPixel(j + l, i + k).R * kernel[abs(k-1)][abs(l-1)];
					pixelValueG += image->GetPixel(j + l, i + k).G * kernel[abs(k-1)][abs(l-1)];
					pixelValueB += image->GetPixel(j + l, i + k).B * kernel[abs(k-1)][abs(l-1)];
				}
			}

			if (clamping)
			{
				pixelValueR += 127;
				pixelValueG += 127;
				pixelValueB += 127;
			}

			pixelValueR = (pixelValueR < 0) ? 0 : pixelValueR;
			pixelValueR = (pixelValueR > 255) ? 255 : pixelValueR;

			pixelValueG = (pixelValueG < 0) ? 0 : pixelValueG;
			pixelValueG = (pixelValueG > 255) ? 255 : pixelValueG;

			pixelValueB = (pixelValueB < 0) ? 0 : pixelValueB;
			pixelValueB = (pixelValueB > 255) ? 255 : pixelValueB;

			newImage->SetPixel(j, i, Color::FromArgb(pixelValueR, pixelValueG, pixelValueB));
		}
	}

	delete image;
	return newImage;
}

Bitmap^ ZoomIn(Bitmap^ image)
{
	Bitmap^ newImage = gcnew Bitmap(image->Width*2, image->Height*2);

	for(int i = 0; i < image->Height; i++)
	{
		for(int j = 0; j < image->Width; j++)
		{
			newImage->SetPixel(2*j, 2*i, image->GetPixel(j,i));
		}
	}

	for(int i = 0; i < newImage->Height; i += 2)
	{
		for(int j = 1; j < newImage->Width - 1; j += 2)
		{
			float newR = 0.5*(newImage->GetPixel(j-1,i).R + newImage->GetPixel(j+1,i).R);
			float newG = 0.5*(newImage->GetPixel(j-1,i).G + newImage->GetPixel(j+1,i).G);
			float newB = 0.5*(newImage->GetPixel(j-1,i).B + newImage->GetPixel(j+1,i).B);

			newImage->SetPixel(j,i, Color::FromArgb(newR, newG, newB));
		}
	}

	for(int i = 1; i < newImage->Height - 1; i += 2)
	{
		for(int j = 0; j < newImage->Width; j++)
		{
			float newR = 0.5*(newImage->GetPixel(j,i-1).R + newImage->GetPixel(j,i+1).R);
			float newG = 0.5*(newImage->GetPixel(j,i-1).G + newImage->GetPixel(j,i+1).G);
			float newB = 0.5*(newImage->GetPixel(j,i-1).B + newImage->GetPixel(j,i+1).B);

			newImage->SetPixel(j,i, Color::FromArgb(newR, newG, newB));
		}
	}

	delete image;
	return newImage;
}

Bitmap^ ZoomOut(Bitmap^ image)
{
	return ZoomOut(image, 2, 2);
}

Bitmap^ ZoomOut(Bitmap^ image, int divHeight, int divWidth)
{
	Bitmap^ newImage = gcnew Bitmap(ceil(image->Width/divWidth), ceil(image->Height/divHeight));

	for(int i = 0; i < image->Height; i += divHeight)
    {
		for(int j = 0; j < image->Width; j += divWidth)
        {
			if ((j/divWidth < newImage->Width) && (i/divHeight < newImage->Height))
			{
				float rAvarage = 0;
				float gAvarage = 0;
				float bAvarage = 0;

				for(int k = i; k < i + divHeight; k++)
				{
					for(int l = j; l < j + divWidth; l++)
					{
						if (!((l > image->Width) || (l > image->Height)))
						{
							rAvarage = rAvarage + image->GetPixel(j,i).R;
							gAvarage = gAvarage + image->GetPixel(j,i).G;
							bAvarage = bAvarage + image->GetPixel(j,i).B;
						}
					}
				}
            
				rAvarage = rAvarage/(divHeight*divWidth);
				gAvarage = gAvarage/(divHeight*divWidth);
				bAvarage = bAvarage/(divHeight*divWidth);

				newImage->SetPixel(j/divWidth,i/divHeight, Color::FromArgb(rAvarage, gAvarage, bAvarage));
			}
        }
    }

	delete image;
	return newImage;
}

