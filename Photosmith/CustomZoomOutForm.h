#pragma once

namespace Photosmith {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CustomZoomOutForm : public System::Windows::Forms::Form
	{
		public:
			CustomZoomOutForm();

			int GetDivWidth();

			int GetDivHeight();

			void SetDivWidth(int divW);

			void SetDivHeight(int divH);

		protected:
			~CustomZoomOutForm();

		private: 
			int divWidth;

			int divHeight;

			System::Windows::Forms::Label^  widthLabel;

			System::Windows::Forms::Label^  heightLabel;

			System::Windows::Forms::Label^  scalingFactorsLabel;


			System::Windows::Forms::Button^  confirmButton;

			System::Windows::Forms::TextBox^  widthTextBox;

			System::Windows::Forms::TextBox^  heightTextBox;


			System::ComponentModel::Container ^components;

	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->scalingFactorsLabel = (gcnew System::Windows::Forms::Label());
				this->widthLabel = (gcnew System::Windows::Forms::Label());
				this->heightLabel = (gcnew System::Windows::Forms::Label());
				this->widthTextBox = (gcnew System::Windows::Forms::TextBox());
				this->heightTextBox = (gcnew System::Windows::Forms::TextBox());
				this->confirmButton = (gcnew System::Windows::Forms::Button());
				this->SuspendLayout();
				// 
				// scalingFactorsLabel
				// 
				this->scalingFactorsLabel->AutoSize = true;
				this->scalingFactorsLabel->Location = System::Drawing::Point(12, 9);
				this->scalingFactorsLabel->Name = L"scalingFactorsLabel";
				this->scalingFactorsLabel->Size = System::Drawing::Size(138, 13);
				this->scalingFactorsLabel->TabIndex = 0;
				this->scalingFactorsLabel->Text = L"Choose the scaling factors :";
				// 
				// widthLabel
				// 
				this->widthLabel->AutoSize = true;
				this->widthLabel->Location = System::Drawing::Point(26, 43);
				this->widthLabel->Name = L"widthLabel";
				this->widthLabel->Size = System::Drawing::Size(41, 13);
				this->widthLabel->TabIndex = 1;
				this->widthLabel->Text = L"Width :";
				// 
				// heightLabel
				// 
				this->heightLabel->AutoSize = true;
				this->heightLabel->Location = System::Drawing::Point(26, 69);
				this->heightLabel->Name = L"heightLabel";
				this->heightLabel->Size = System::Drawing::Size(44, 13);
				this->heightLabel->TabIndex = 2;
				this->heightLabel->Text = L"Height :";
				// 
				// widthTextBox
				// 
				this->widthTextBox->Location = System::Drawing::Point(73, 40);
				this->widthTextBox->Name = L"widthTextBox";
				this->widthTextBox->Size = System::Drawing::Size(100, 20);
				this->widthTextBox->TabIndex = 3;
				// 
				// heightTextBox
				// 
				this->heightTextBox->Location = System::Drawing::Point(73, 66);
				this->heightTextBox->Name = L"heightTextBox";
				this->heightTextBox->Size = System::Drawing::Size(100, 20);
				this->heightTextBox->TabIndex = 4;
				// 
				// confirmButton
				// 
				this->confirmButton->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->confirmButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
				this->confirmButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->confirmButton->ForeColor = System::Drawing::Color::White;
				this->confirmButton->Location = System::Drawing::Point(67, 103);
				this->confirmButton->Name = L"confirmButton";
				this->confirmButton->Size = System::Drawing::Size(75, 23);
				this->confirmButton->TabIndex = 5;
				this->confirmButton->Text = L"Confirm";
				this->confirmButton->UseVisualStyleBackColor = true;
				this->confirmButton->Click += gcnew System::EventHandler(this, &CustomZoomOutForm::ConfirmButton_Click);
				// 
				// CustomZoomOutForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->ClientSize = System::Drawing::Size(211, 138);
				this->Controls->Add(this->confirmButton);
				this->Controls->Add(this->heightTextBox);
				this->Controls->Add(this->widthTextBox);
				this->Controls->Add(this->heightLabel);
				this->Controls->Add(this->widthLabel);
				this->Controls->Add(this->scalingFactorsLabel);
				this->ForeColor = System::Drawing::Color::White;
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				this->MaximizeBox = false;
				this->MinimizeBox = false;
				this->Name = L"CustomZoomOutForm";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"Customized zoom out";
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion

			System::Void ConfirmButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
