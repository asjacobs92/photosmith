#pragma once

namespace Photosmith {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class QuantizeForm : public System::Windows::Forms::Form
	{
		public:
			QuantizeForm();

			int GetNumberOfShades();

			void SetNumberOfShades(int shades);

		protected:
			~QuantizeForm();
		
		private:
			int numShades;

			System::ComponentModel::Container ^components;

			System::Windows::Forms::Label^  numShadesLabel;

			System::Windows::Forms::Button^  confirmButton;

			System::Windows::Forms::TextBox^  numShadesTextBox;

	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->numShadesTextBox = (gcnew System::Windows::Forms::TextBox());
				this->confirmButton = (gcnew System::Windows::Forms::Button());
				this->numShadesLabel = (gcnew System::Windows::Forms::Label());
				this->SuspendLayout();
				// 
				// numShadesTextBox
				// 
				this->numShadesTextBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->numShadesTextBox->Location = System::Drawing::Point(130, 7);
				this->numShadesTextBox->Name = L"numShadesTextBox";
				this->numShadesTextBox->Size = System::Drawing::Size(100, 20);
				this->numShadesTextBox->TabIndex = 0;
				// 
				// confirmButton
				// 
				this->confirmButton->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->confirmButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
				this->confirmButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->confirmButton->ForeColor = System::Drawing::Color::White;
				this->confirmButton->Location = System::Drawing::Point(87, 43);
				this->confirmButton->Name = L"confirmButton";
				this->confirmButton->Size = System::Drawing::Size(75, 23);
				this->confirmButton->TabIndex = 1;
				this->confirmButton->Text = L"Confirm";
				this->confirmButton->UseVisualStyleBackColor = true;
				this->confirmButton->Click += gcnew System::EventHandler(this, &QuantizeForm::ConfirmButton_Click);
				// 
				// numShadesLabel
				// 
				this->numShadesLabel->AutoSize = true;
				this->numShadesLabel->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				this->numShadesLabel->ForeColor = System::Drawing::Color::White;
				this->numShadesLabel->Location = System::Drawing::Point(12, 9);
				this->numShadesLabel->Name = L"numShadesLabel";
				this->numShadesLabel->Size = System::Drawing::Size(102, 13);
				this->numShadesLabel->TabIndex = 2;
				this->numShadesLabel->Text = L"Number of shades : ";
				// 
				// QuantizeForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->AutoSize = true;
				this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				this->ClientSize = System::Drawing::Size(242, 78);
				this->Controls->Add(this->numShadesLabel);
				this->Controls->Add(this->confirmButton);
				this->Controls->Add(this->numShadesTextBox);
				this->ForeColor = System::Drawing::Color::Black;
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				this->MaximizeBox = false;
				this->MinimizeBox = false;
				this->Name = L"QuantizeForm";
				this->ShowInTaskbar = false;
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
				this->Text = L"Quantize Image";
				this->TopMost = true;
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion

			System::Void ConfirmButton_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
