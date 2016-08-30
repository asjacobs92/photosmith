#pragma once
#include <vector>
#include <algorithm>   
#include "ImageUtils.h"

namespace Photosmith {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class HistogramForm : public System::Windows::Forms::Form
	{
		public:
			HistogramForm();
			
			HistogramForm(Bitmap^ image);

		protected:
			~HistogramForm();

		private:
			System::Drawing::Bitmap^ image;

			System::ComponentModel::Container^ components;

			System::Windows::Forms::Label^  greyscaleLabel;

			System::Windows::Forms::PictureBox^ histogramPicutreBox;


	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(HistogramForm::typeid));
				this->histogramPicutreBox = (gcnew System::Windows::Forms::PictureBox());
				this->greyscaleLabel = (gcnew System::Windows::Forms::Label());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->histogramPicutreBox))->BeginInit();
				this->SuspendLayout();
				// 
				// histogramPicutreBox
				// 
				this->histogramPicutreBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), 
					static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
				this->histogramPicutreBox->Location = System::Drawing::Point(12, 12);
				this->histogramPicutreBox->Name = L"histogramPicutreBox";
				this->histogramPicutreBox->Size = System::Drawing::Size(512, 350);
				this->histogramPicutreBox->TabIndex = 0;
				this->histogramPicutreBox->TabStop = false;
				this->histogramPicutreBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &HistogramForm::HistogramPicutreBox_Paint);
				// 
				// greyscaleLabel
				// 
				this->greyscaleLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->greyscaleLabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->greyscaleLabel->ForeColor = System::Drawing::Color::White;
				this->greyscaleLabel->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"greyscaleLabel.Image")));
				this->greyscaleLabel->Location = System::Drawing::Point(12, 369);
				this->greyscaleLabel->Name = L"greyscaleLabel";
				this->greyscaleLabel->Size = System::Drawing::Size(512, 20);
				this->greyscaleLabel->TabIndex = 1;
				// 
				// HistogramForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->ClientSize = System::Drawing::Size(535, 398);
				this->Controls->Add(this->greyscaleLabel);
				this->Controls->Add(this->histogramPicutreBox);
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				this->MaximizeBox = false;
				this->MinimizeBox = false;
				this->Name = L"HistogramForm";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"Histogram";
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->histogramPicutreBox))->EndInit();
				this->ResumeLayout(false);

			}
	#pragma endregion

			System::Void HistogramPicutreBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);

	};
}
