#include "MainWindow.h"

using namespace Photosmith;

MainWindow::MainWindow() 
{
	SetImageLoaded(false);
	InitializeComponent();
}

MainWindow::~MainWindow()
{
	if (components)
	{
		delete components;
	}
}

System::Void MainWindow::OpenButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

	openFileDialog->Title = "Open Image";
	openFileDialog->Filter = "Jpeg Files (*.jpg, *.jpeg) | *.jpg;*.jpeg;";

	if(openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if(openFileDialog->FileName != nullptr) 
		{
			originalImageBox->Image = gcnew Bitmap(openFileDialog->FileName);
			modifiedImageBox->Image = gcnew Bitmap(openFileDialog->FileName);
			SetImageLoaded(true);
		}
	}
	delete openFileDialog;
}

System::Void MainWindow::SaveButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();

		saveFileDialog->Title = "Save Image";
		saveFileDialog->Filter = "Jpeg Files (*.jpg, *.jpeg) | *.jpg;*.jpeg;";

		if(saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if(saveFileDialog->FileName != nullptr) 
			{
				try
				{
					modifiedImageBox->Image->Save(saveFileDialog->FileName);
					MessageBox::Show(this, "Image succesfully saved.", "Success!", 
						MessageBoxButtons::OK, MessageBoxIcon::Information);
				} 
				catch(Exception^ e) 
				{
					MessageBox::Show(this, "The image couldn't be saved.", "Oops, something went wrong.", 
						MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
		delete saveFileDialog;
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::ExitButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	MainWindow::Close();
}

System::Void MainWindow::CopyButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		delete modifiedImageBox->Image;
		modifiedImageBox->Image = (Bitmap^) originalImageBox->Image->Clone();
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::InvertYButton_Click(System::Object^sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		modifiedImageBox->Image = InvertYAxis((Bitmap^) modifiedImageBox->Image);
		modifiedImageBox->Update();
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::InvertXButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		modifiedImageBox->Image = InvertXAxis((Bitmap^) modifiedImageBox->Image);
		modifiedImageBox->Update();
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::NegativeButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		modifiedImageBox->Image = ConvertToNegative((Bitmap^) modifiedImageBox->Image);
		modifiedImageBox->Update();
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::GrayscaleButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		modifiedImageBox->Image = ConvertToGrayscale((Bitmap^) modifiedImageBox->Image);
		modifiedImageBox->Update();
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::QuantizeButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		QuantizeForm^ qForm = gcnew QuantizeForm();
		if(qForm->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			int numShades = qForm->GetNumberOfShades();
			if (numShades > 0 && numShades <= 256)
			{
				modifiedImageBox->Image = Quantize((Bitmap^) modifiedImageBox->Image, numShades);
				modifiedImageBox->Update();
			} 
			else 
			{
				MessageBox::Show(this, "Please type numbers between 1 and 256.", "Oops, something went wrong.", 
						MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		delete qForm;
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::AdjustColorsButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		AdjustColorsForm^ acForm = gcnew AdjustColorsForm();
		if(acForm->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			float contrastValue = acForm->GetContrastValue();
			int brightnessValue = acForm->GetBrightnessValue();

			modifiedImageBox->Image = AdjustColors((Bitmap^) modifiedImageBox->Image, contrastValue, brightnessValue);
			modifiedImageBox->Update();
		}
		delete acForm;
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::HistogramButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		HistogramForm^ hForm = gcnew HistogramForm((Bitmap^) modifiedImageBox->Image);
		hForm->ShowDialog();
	}
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::EqualizeButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		modifiedImageBox->Image = EqualizeHistogram((Bitmap^) modifiedImageBox->Image);
		modifiedImageBox->Update();
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::ConvolveButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		ConvolveForm^ cForm = gcnew ConvolveForm();
		if(cForm->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			bool clamping = cForm->GetClamping();
			array<array<float>^>^ kernel = cForm->GetKernel();

			modifiedImageBox->Image = Convolve((Bitmap^) modifiedImageBox->Image, kernel, clamping);
			modifiedImageBox->Update();
		}
		delete cForm;
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::RotateLeftButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		modifiedImageBox->Image = RotateLeft((Bitmap^) modifiedImageBox->Image);
		modifiedImageBox->Update();
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::ZoomOutButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	zoomOutButton->Image = Image::FromFile("Resource/zoomOutMouseDown.png");
}

System::Void MainWindow::RotateRightButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		modifiedImageBox->Image = RotateRight((Bitmap^) modifiedImageBox->Image);
		modifiedImageBox->Update();
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::ZoomInButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		modifiedImageBox->Image = ZoomIn((Bitmap^) modifiedImageBox->Image);
		modifiedImageBox->Update();
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
			
System::Void MainWindow::ZoomOutButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		modifiedImageBox->Image = ZoomOut((Bitmap^) modifiedImageBox->Image);
		modifiedImageBox->Update();
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::CustomZoomOutMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(HasImageLoaded())
	{
		CustomZoomOutForm^ zoForm = gcnew CustomZoomOutForm();
		if(zoForm->ShowDialog() == Windows::Forms::DialogResult::OK)
		{
			int divWidth = zoForm->GetDivWidth();
			int divHeight = zoForm->GetDivHeight();
			if (divWidth != 0 && divHeight != 0)
			{
				modifiedImageBox->Image = ZoomOut((Bitmap^) modifiedImageBox->Image, divHeight, divWidth);
				modifiedImageBox->Update();
			} 
			else 
			{
				MessageBox::Show(this, "Please type only numbers greater than 0.", "Oops, something went wrong.", 
						MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		delete zoForm;
	} 
	else 
	{
		MessageBox::Show(this, "Please load an image into the canvas.", "No image loaded.", 
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}

System::Void MainWindow::OpenButton_MouseUp(System::Object^sender, System::Windows::Forms::MouseEventArgs^ e)
{
	openButton->Image = Image::FromFile("Resource/open.png");
}

System::Void MainWindow::OpenButton_MouseDown(System::Object^sender, System::Windows::Forms::MouseEventArgs^ e)
{
	openButton->Image = Image::FromFile("Resource/openMouseDown.png");
}

System::Void MainWindow::SaveButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	saveButton->Image = Image::FromFile("Resource/save.png");
}

System::Void MainWindow::SaveButton_MouseDown(System::Object^sender, System::Windows::Forms::MouseEventArgs^ e)
{
	saveButton->Image = Image::FromFile("Resource/saveMouseDown.png");
}

System::Void MainWindow::CopyButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	copyButton->Image = Image::FromFile("Resource/copyMouseDown.png");
}
			
System::Void MainWindow::CopyButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	copyButton->Image = Image::FromFile("Resource/copy.png");
}

System::Void MainWindow::InvertYButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	invertYButton->Image = Image::FromFile("Resource/invertY.png");
}

System::Void MainWindow::InvertYButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	invertYButton->Image = Image::FromFile("Resource/invertYMouseDown.png");
}

System::Void MainWindow::InvertXButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	invertXButton->Image = Image::FromFile("Resource/invertX.png");
}

System::Void MainWindow::InvertXButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	invertXButton->Image = Image::FromFile("Resource/invertXMouseDown.png");
}

System::Void MainWindow::RotateLeftButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	rotateLeftButton->Image = Image::FromFile("Resource/rotateLeft.png");
}

System::Void MainWindow::RotateLeftButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	rotateLeftButton->Image = Image::FromFile("Resource/rotateLeftMouseDown.png");
}

System::Void MainWindow::RotateRightButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	rotateRightButton->Image = Image::FromFile("Resource/rotateRight.png");
}

System::Void MainWindow::RotateRightButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	rotateRightButton->Image = Image::FromFile("Resource/rotateRightMouseDown.png");
}

System::Void MainWindow::ZoomInButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	zoomInButton->Image = Image::FromFile("Resource/zoomIn.png");
}

System::Void MainWindow::ZoomInButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	zoomInButton->Image = Image::FromFile("Resource/zoomInMouseDown.png");
}

System::Void MainWindow::ZoomOutButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	zoomOutButton->Image = Image::FromFile("Resource/zoomOut.png");
}

bool MainWindow::HasImageLoaded()
{
	return imageLoaded;
}

void MainWindow::SetImageLoaded(bool imageLoaded)
{
	MainWindow::imageLoaded = imageLoaded;
}

[ STAThreadAttribute ]
int main() 
{
	Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew MainWindow());

	return 0;
}
