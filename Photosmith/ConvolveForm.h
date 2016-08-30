#pragma once

namespace Photosmith {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ConvolveForm : public System::Windows::Forms::Form
	{
		public:
			ConvolveForm();

			bool GetClamping();

			void SetClamping(bool clamp);

			array<array<float>^>^ GetKernel();

		protected:
			~ConvolveForm();

		private: 
			bool clamping;

			array<array<float>^>^ kernel;

			System::Windows::Forms::Button^  confirmButton;

			System::Windows::Forms::GroupBox^  radioButtonsGroup;
			
			System::Windows::Forms::RadioButton^  customRadioButton;

			System::Windows::Forms::RadioButton^  sobelHxRadioButton;

			System::Windows::Forms::RadioButton^  sobelHyRadioButton;

			System::Windows::Forms::RadioButton^  highPassRadioButton;

			System::Windows::Forms::RadioButton^  gaussianRadioButton;
			
			System::Windows::Forms::RadioButton^  laplacianRadioButton;

			System::Windows::Forms::RadioButton^  prewittHxRadioButton;

			System::Windows::Forms::RadioButton^  prewittHyRadioButton;


			System::Windows::Forms::TableLayoutPanel^  kernelTable;

			System::Windows::Forms::TextBox^  kernelValue1TextBox;

			System::Windows::Forms::TextBox^  kernelValue2TextBox;

			System::Windows::Forms::TextBox^  kernelValue3TextBox;

			System::Windows::Forms::TextBox^  kernelValue4TextBox;

			System::Windows::Forms::TextBox^  kernelValue5TextBox;

			System::Windows::Forms::TextBox^  kernelValue6TextBox;

			System::Windows::Forms::TextBox^  kernelValue7TextBox;

			System::Windows::Forms::TextBox^  kernelValue8TextBox;

			System::Windows::Forms::TextBox^  kernelValue9TextBox;


			System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->gaussianRadioButton = (gcnew System::Windows::Forms::RadioButton());
				this->radioButtonsGroup = (gcnew System::Windows::Forms::GroupBox());
				this->sobelHyRadioButton = (gcnew System::Windows::Forms::RadioButton());
				this->sobelHxRadioButton = (gcnew System::Windows::Forms::RadioButton());
				this->highPassRadioButton = (gcnew System::Windows::Forms::RadioButton());
				this->prewittHyRadioButton = (gcnew System::Windows::Forms::RadioButton());
				this->prewittHxRadioButton = (gcnew System::Windows::Forms::RadioButton());
				this->customRadioButton = (gcnew System::Windows::Forms::RadioButton());
				this->kernelTable = (gcnew System::Windows::Forms::TableLayoutPanel());
				this->kernelValue9TextBox = (gcnew System::Windows::Forms::TextBox());
				this->kernelValue8TextBox = (gcnew System::Windows::Forms::TextBox());
				this->kernelValue7TextBox = (gcnew System::Windows::Forms::TextBox());
				this->kernelValue6TextBox = (gcnew System::Windows::Forms::TextBox());
				this->kernelValue5TextBox = (gcnew System::Windows::Forms::TextBox());
				this->kernelValue4TextBox = (gcnew System::Windows::Forms::TextBox());
				this->kernelValue3TextBox = (gcnew System::Windows::Forms::TextBox());
				this->kernelValue2TextBox = (gcnew System::Windows::Forms::TextBox());
				this->kernelValue1TextBox = (gcnew System::Windows::Forms::TextBox());
				this->laplacianRadioButton = (gcnew System::Windows::Forms::RadioButton());
				this->confirmButton = (gcnew System::Windows::Forms::Button());
				this->radioButtonsGroup->SuspendLayout();
				this->kernelTable->SuspendLayout();
				this->SuspendLayout();
				// 
				// gaussianRadioButton
				// 
				this->gaussianRadioButton->AutoSize = true;
				this->gaussianRadioButton->ForeColor = System::Drawing::Color::White;
				this->gaussianRadioButton->Location = System::Drawing::Point(18, 22);
				this->gaussianRadioButton->Name = L"gaussianRadioButton";
				this->gaussianRadioButton->Size = System::Drawing::Size(101, 17);
				this->gaussianRadioButton->TabIndex = 1;
				this->gaussianRadioButton->TabStop = true;
				this->gaussianRadioButton->Text = L"Gaussian kernel";
				this->gaussianRadioButton->UseVisualStyleBackColor = true;
				this->gaussianRadioButton->CheckedChanged += gcnew System::EventHandler(this, &ConvolveForm::GaussianRadioButton_CheckedChanged);
				// 
				// radioButtonsGroup
				// 
				this->radioButtonsGroup->Controls->Add(this->sobelHyRadioButton);
				this->radioButtonsGroup->Controls->Add(this->sobelHxRadioButton);
				this->radioButtonsGroup->Controls->Add(this->highPassRadioButton);
				this->radioButtonsGroup->Controls->Add(this->prewittHyRadioButton);
				this->radioButtonsGroup->Controls->Add(this->prewittHxRadioButton);
				this->radioButtonsGroup->Controls->Add(this->customRadioButton);
				this->radioButtonsGroup->Controls->Add(this->kernelTable);
				this->radioButtonsGroup->Controls->Add(this->laplacianRadioButton);
				this->radioButtonsGroup->Controls->Add(this->gaussianRadioButton);
				this->radioButtonsGroup->ForeColor = System::Drawing::Color::White;
				this->radioButtonsGroup->ImeMode = System::Windows::Forms::ImeMode::NoControl;
				this->radioButtonsGroup->Location = System::Drawing::Point(12, 12);
				this->radioButtonsGroup->Name = L"radioButtonsGroup";
				this->radioButtonsGroup->Size = System::Drawing::Size(260, 398);
				this->radioButtonsGroup->TabIndex = 2;
				this->radioButtonsGroup->TabStop = false;
				this->radioButtonsGroup->Text = L"Choose the kernel";
				// 
				// sobelHyRadioButton
				// 
				this->sobelHyRadioButton->AutoSize = true;
				this->sobelHyRadioButton->ForeColor = System::Drawing::Color::White;
				this->sobelHyRadioButton->Location = System::Drawing::Point(18, 91);
				this->sobelHyRadioButton->Name = L"sobelHyRadioButton";
				this->sobelHyRadioButton->Size = System::Drawing::Size(100, 17);
				this->sobelHyRadioButton->TabIndex = 9;
				this->sobelHyRadioButton->TabStop = true;
				this->sobelHyRadioButton->Text = L"Sobel Hy kernel";
				this->sobelHyRadioButton->UseVisualStyleBackColor = true;
				this->sobelHyRadioButton->CheckedChanged += gcnew System::EventHandler(this, &ConvolveForm::SobelHyRadioButton_CheckedChanged);
				// 
				// sobelHxRadioButton
				// 
				this->sobelHxRadioButton->AutoSize = true;
				this->sobelHxRadioButton->ForeColor = System::Drawing::Color::White;
				this->sobelHxRadioButton->Location = System::Drawing::Point(18, 68);
				this->sobelHxRadioButton->Name = L"sobelHxRadioButton";
				this->sobelHxRadioButton->Size = System::Drawing::Size(100, 17);
				this->sobelHxRadioButton->TabIndex = 8;
				this->sobelHxRadioButton->TabStop = true;
				this->sobelHxRadioButton->Text = L"Sobel Hx kernel";
				this->sobelHxRadioButton->UseVisualStyleBackColor = true;
				this->sobelHxRadioButton->CheckedChanged += gcnew System::EventHandler(this, &ConvolveForm::SobelHxRadioButton_CheckedChanged);
				// 
				// highPassRadioButton
				// 
				this->highPassRadioButton->AutoSize = true;
				this->highPassRadioButton->ForeColor = System::Drawing::Color::White;
				this->highPassRadioButton->Location = System::Drawing::Point(19, 160);
				this->highPassRadioButton->Name = L"highPassRadioButton";
				this->highPassRadioButton->Size = System::Drawing::Size(142, 17);
				this->highPassRadioButton->TabIndex = 5;
				this->highPassRadioButton->TabStop = true;
				this->highPassRadioButton->Text = L"Generic high-pass kernel";
				this->highPassRadioButton->UseVisualStyleBackColor = true;
				this->highPassRadioButton->CheckedChanged += gcnew System::EventHandler(this, &ConvolveForm::HighPassRadioButton_CheckedChanged);
				// 
				// prewittHyRadioButton
				// 
				this->prewittHyRadioButton->AutoSize = true;
				this->prewittHyRadioButton->ForeColor = System::Drawing::Color::White;
				this->prewittHyRadioButton->Location = System::Drawing::Point(18, 137);
				this->prewittHyRadioButton->Name = L"prewittHyRadioButton";
				this->prewittHyRadioButton->Size = System::Drawing::Size(105, 17);
				this->prewittHyRadioButton->TabIndex = 7;
				this->prewittHyRadioButton->TabStop = true;
				this->prewittHyRadioButton->Text = L"Prewitt Hy kernel";
				this->prewittHyRadioButton->UseVisualStyleBackColor = true;
				this->prewittHyRadioButton->CheckedChanged += gcnew System::EventHandler(this, &ConvolveForm::PrewittHyRadioButton_CheckedChanged);
				// 
				// prewittHxRadioButton
				// 
				this->prewittHxRadioButton->AutoSize = true;
				this->prewittHxRadioButton->ForeColor = System::Drawing::Color::White;
				this->prewittHxRadioButton->Location = System::Drawing::Point(18, 114);
				this->prewittHxRadioButton->Name = L"prewittHxRadioButton";
				this->prewittHxRadioButton->Size = System::Drawing::Size(105, 17);
				this->prewittHxRadioButton->TabIndex = 6;
				this->prewittHxRadioButton->TabStop = true;
				this->prewittHxRadioButton->Text = L"Prewitt Hx kernel";
				this->prewittHxRadioButton->UseVisualStyleBackColor = true;
				this->prewittHxRadioButton->CheckedChanged += gcnew System::EventHandler(this, &ConvolveForm::PrewittHxRadioButton_CheckedChanged);
				// 
				// customRadioButton
				// 
				this->customRadioButton->AutoSize = true;
				this->customRadioButton->ForeColor = System::Drawing::Color::White;
				this->customRadioButton->Location = System::Drawing::Point(18, 183);
				this->customRadioButton->Name = L"customRadioButton";
				this->customRadioButton->Size = System::Drawing::Size(92, 17);
				this->customRadioButton->TabIndex = 4;
				this->customRadioButton->TabStop = true;
				this->customRadioButton->Text = L"Custom kernel";
				this->customRadioButton->UseVisualStyleBackColor = true;
				this->customRadioButton->CheckedChanged += gcnew System::EventHandler(this, &ConvolveForm::CustomRadioButton_CheckedChanged);
				// 
				// kernelTable
				// 
				this->kernelTable->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Inset;
				this->kernelTable->ColumnCount = 3;
				this->kernelTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
				this->kernelTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
				this->kernelTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
				this->kernelTable->Controls->Add(this->kernelValue9TextBox, 2, 2);
				this->kernelTable->Controls->Add(this->kernelValue8TextBox, 1, 2);
				this->kernelTable->Controls->Add(this->kernelValue7TextBox, 0, 2);
				this->kernelTable->Controls->Add(this->kernelValue6TextBox, 2, 1);
				this->kernelTable->Controls->Add(this->kernelValue5TextBox, 1, 1);
				this->kernelTable->Controls->Add(this->kernelValue4TextBox, 0, 1);
				this->kernelTable->Controls->Add(this->kernelValue3TextBox, 2, 0);
				this->kernelTable->Controls->Add(this->kernelValue2TextBox, 1, 0);
				this->kernelTable->Controls->Add(this->kernelValue1TextBox, 0, 0);
				this->kernelTable->Enabled = false;
				this->kernelTable->Location = System::Drawing::Point(42, 206);
				this->kernelTable->Name = L"kernelTable";
				this->kernelTable->RowCount = 3;
				this->kernelTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
				this->kernelTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
				this->kernelTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
				this->kernelTable->Size = System::Drawing::Size(180, 180);
				this->kernelTable->TabIndex = 3;
				// 
				// kernelValue9TextBox
				// 
				this->kernelValue9TextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->kernelValue9TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->kernelValue9TextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
				this->kernelValue9TextBox->ForeColor = System::Drawing::Color::White;
				this->kernelValue9TextBox->Location = System::Drawing::Point(123, 142);
				this->kernelValue9TextBox->Name = L"kernelValue9TextBox";
				this->kernelValue9TextBox->Size = System::Drawing::Size(51, 13);
				this->kernelValue9TextBox->TabIndex = 8;
				this->kernelValue9TextBox->Text = L"0";
				this->kernelValue9TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				// 
				// kernelValue8TextBox
				// 
				this->kernelValue8TextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->kernelValue8TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->kernelValue8TextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
				this->kernelValue8TextBox->ForeColor = System::Drawing::Color::White;
				this->kernelValue8TextBox->Location = System::Drawing::Point(64, 142);
				this->kernelValue8TextBox->Name = L"kernelValue8TextBox";
				this->kernelValue8TextBox->Size = System::Drawing::Size(51, 13);
				this->kernelValue8TextBox->TabIndex = 7;
				this->kernelValue8TextBox->Text = L"0";
				this->kernelValue8TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				// 
				// kernelValue7TextBox
				// 
				this->kernelValue7TextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->kernelValue7TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->kernelValue7TextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
				this->kernelValue7TextBox->ForeColor = System::Drawing::Color::White;
				this->kernelValue7TextBox->Location = System::Drawing::Point(5, 142);
				this->kernelValue7TextBox->Name = L"kernelValue7TextBox";
				this->kernelValue7TextBox->Size = System::Drawing::Size(51, 13);
				this->kernelValue7TextBox->TabIndex = 6;
				this->kernelValue7TextBox->Text = L"0";
				this->kernelValue7TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				// 
				// kernelValue6TextBox
				// 
				this->kernelValue6TextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->kernelValue6TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->kernelValue6TextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
				this->kernelValue6TextBox->ForeColor = System::Drawing::Color::White;
				this->kernelValue6TextBox->Location = System::Drawing::Point(123, 83);
				this->kernelValue6TextBox->Name = L"kernelValue6TextBox";
				this->kernelValue6TextBox->Size = System::Drawing::Size(51, 13);
				this->kernelValue6TextBox->TabIndex = 5;
				this->kernelValue6TextBox->Text = L"0";
				this->kernelValue6TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				// 
				// kernelValue5TextBox
				// 
				this->kernelValue5TextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->kernelValue5TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->kernelValue5TextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
				this->kernelValue5TextBox->ForeColor = System::Drawing::Color::White;
				this->kernelValue5TextBox->Location = System::Drawing::Point(64, 83);
				this->kernelValue5TextBox->Name = L"kernelValue5TextBox";
				this->kernelValue5TextBox->Size = System::Drawing::Size(51, 13);
				this->kernelValue5TextBox->TabIndex = 4;
				this->kernelValue5TextBox->Text = L"0";
				this->kernelValue5TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				// 
				// kernelValue4TextBox
				// 
				this->kernelValue4TextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->kernelValue4TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->kernelValue4TextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
				this->kernelValue4TextBox->ForeColor = System::Drawing::Color::White;
				this->kernelValue4TextBox->Location = System::Drawing::Point(5, 83);
				this->kernelValue4TextBox->Name = L"kernelValue4TextBox";
				this->kernelValue4TextBox->Size = System::Drawing::Size(51, 13);
				this->kernelValue4TextBox->TabIndex = 3;
				this->kernelValue4TextBox->Text = L"0";
				this->kernelValue4TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				// 
				// kernelValue3TextBox
				// 
				this->kernelValue3TextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->kernelValue3TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->kernelValue3TextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
				this->kernelValue3TextBox->ForeColor = System::Drawing::Color::White;
				this->kernelValue3TextBox->Location = System::Drawing::Point(123, 24);
				this->kernelValue3TextBox->Name = L"kernelValue3TextBox";
				this->kernelValue3TextBox->Size = System::Drawing::Size(51, 13);
				this->kernelValue3TextBox->TabIndex = 2;
				this->kernelValue3TextBox->Text = L"0";
				this->kernelValue3TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				// 
				// kernelValue2TextBox
				// 
				this->kernelValue2TextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->kernelValue2TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->kernelValue2TextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
				this->kernelValue2TextBox->ForeColor = System::Drawing::Color::White;
				this->kernelValue2TextBox->Location = System::Drawing::Point(64, 24);
				this->kernelValue2TextBox->Name = L"kernelValue2TextBox";
				this->kernelValue2TextBox->Size = System::Drawing::Size(51, 13);
				this->kernelValue2TextBox->TabIndex = 1;
				this->kernelValue2TextBox->Text = L"0";
				this->kernelValue2TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				// 
				// kernelValue1TextBox
				// 
				this->kernelValue1TextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
				this->kernelValue1TextBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->kernelValue1TextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
				this->kernelValue1TextBox->ForeColor = System::Drawing::Color::White;
				this->kernelValue1TextBox->Location = System::Drawing::Point(5, 24);
				this->kernelValue1TextBox->Name = L"kernelValue1TextBox";
				this->kernelValue1TextBox->Size = System::Drawing::Size(51, 13);
				this->kernelValue1TextBox->TabIndex = 0;
				this->kernelValue1TextBox->Text = L"0";
				this->kernelValue1TextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				// 
				// laplacianRadioButton
				// 
				this->laplacianRadioButton->AutoSize = true;
				this->laplacianRadioButton->ForeColor = System::Drawing::Color::White;
				this->laplacianRadioButton->Location = System::Drawing::Point(18, 45);
				this->laplacianRadioButton->Name = L"laplacianRadioButton";
				this->laplacianRadioButton->Size = System::Drawing::Size(103, 17);
				this->laplacianRadioButton->TabIndex = 2;
				this->laplacianRadioButton->TabStop = true;
				this->laplacianRadioButton->Text = L"Laplacian kernel";
				this->laplacianRadioButton->UseVisualStyleBackColor = true;
				this->laplacianRadioButton->CheckedChanged += gcnew System::EventHandler(this, &ConvolveForm::LaplacianRadioButton_CheckedChanged);
				// 
				// confirmButton
				// 
				this->confirmButton->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->confirmButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
				this->confirmButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->confirmButton->ForeColor = System::Drawing::Color::White;
				this->confirmButton->Location = System::Drawing::Point(106, 417);
				this->confirmButton->Name = L"confirmButton";
				this->confirmButton->Size = System::Drawing::Size(75, 23);
				this->confirmButton->TabIndex = 3;
				this->confirmButton->Text = L"Confirm";
				this->confirmButton->UseVisualStyleBackColor = true;
				this->confirmButton->Click += gcnew System::EventHandler(this, &ConvolveForm::ConfirmButton_Click);
				// 
				// ConvolveForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->ClientSize = System::Drawing::Size(284, 452);
				this->Controls->Add(this->confirmButton);
				this->Controls->Add(this->radioButtonsGroup);
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				this->MaximizeBox = false;
				this->MinimizeBox = false;
				this->Name = L"ConvolveForm";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"Convolve";
				this->radioButtonsGroup->ResumeLayout(false);
				this->radioButtonsGroup->PerformLayout();
				this->kernelTable->ResumeLayout(false);
				this->kernelTable->PerformLayout();
				this->ResumeLayout(false);

			}
	#pragma endregion

			System::Void ConfirmButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void CustomRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		
			System::Void SobelHxRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

			System::Void SobelHyRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

			System::Void HighPassRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

			System::Void GaussianRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
			
			System::Void LaplacianRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

			System::Void PrewittHxRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

			System::Void PrewittHyRadioButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	};
}
