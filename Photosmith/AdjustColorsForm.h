#pragma once

namespace Photosmith {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class AdjustColorsForm : public System::Windows::Forms::Form
	{
		public:
			AdjustColorsForm();

			int GetBrightnessValue();

			void SetBrightnessValue(int value);

			float GetContrastValue();

			void SetContrastValue(float value);

		protected:
			~AdjustColorsForm();

		private:
			int brightnessValue;

			float contrastValue;

			System::ComponentModel::Container ^components;

			System::Windows::Forms::Label^  contrastLabel;

			System::Windows::Forms::Label^  brightnessLabel;

			System::Windows::Forms::Label^  value255Label2;

			System::Windows::Forms::Label^  valueMinus255Label;

			System::Windows::Forms::TrackBar^  contrastTrackBar;

			System::Windows::Forms::TrackBar^  brightessTrackBar;

			System::Windows::Forms::Button^  confirmButton;

	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->contrastLabel = (gcnew System::Windows::Forms::Label());
				this->contrastTrackBar = (gcnew System::Windows::Forms::TrackBar());
				this->brightessTrackBar = (gcnew System::Windows::Forms::TrackBar());
				this->brightnessLabel = (gcnew System::Windows::Forms::Label());
				this->valueMinus255Label = (gcnew System::Windows::Forms::Label());
				this->value255Label2 = (gcnew System::Windows::Forms::Label());
				this->confirmButton = (gcnew System::Windows::Forms::Button());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->contrastTrackBar))->BeginInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->brightessTrackBar))->BeginInit();
				this->SuspendLayout();
				// 
				// contrastLabel
				// 
				this->contrastLabel->AutoSize = true;
				this->contrastLabel->ForeColor = System::Drawing::Color::White;
				this->contrastLabel->Location = System::Drawing::Point(12, 12);
				this->contrastLabel->Name = L"contrastLabel";
				this->contrastLabel->Size = System::Drawing::Size(52, 13);
				this->contrastLabel->TabIndex = 2;
				this->contrastLabel->Text = L"Contrast :";
				// 
				// contrastTrackBar
				// 
				this->contrastTrackBar->Location = System::Drawing::Point(103, 12);
				this->contrastTrackBar->Maximum = 20;
				this->contrastTrackBar->Name = L"contrastTrackBar";
				this->contrastTrackBar->Size = System::Drawing::Size(158, 45);
				this->contrastTrackBar->TabIndex = 3;
				this->contrastTrackBar->Value = 10;
				// 
				// brightessTrackBar
				// 
				this->brightessTrackBar->Location = System::Drawing::Point(103, 63);
				this->brightessTrackBar->Maximum = 255;
				this->brightessTrackBar->Minimum = -255;
				this->brightessTrackBar->Name = L"brightessTrackBar";
				this->brightessTrackBar->Size = System::Drawing::Size(158, 45);
				this->brightessTrackBar->TabIndex = 5;
				this->brightessTrackBar->TickStyle = System::Windows::Forms::TickStyle::None;
				// 
				// brightnessLabel
				// 
				this->brightnessLabel->AutoSize = true;
				this->brightnessLabel->ForeColor = System::Drawing::Color::White;
				this->brightnessLabel->Location = System::Drawing::Point(12, 63);
				this->brightnessLabel->Name = L"brightnessLabel";
				this->brightnessLabel->Size = System::Drawing::Size(62, 13);
				this->brightnessLabel->TabIndex = 4;
				this->brightnessLabel->Text = L"Brightness :";
				// 
				// valueMinus255Label
				// 
				this->valueMinus255Label->AutoSize = true;
				this->valueMinus255Label->ForeColor = System::Drawing::Color::White;
				this->valueMinus255Label->Location = System::Drawing::Point(102, 95);
				this->valueMinus255Label->Name = L"valueMinus255Label";
				this->valueMinus255Label->Size = System::Drawing::Size(28, 13);
				this->valueMinus255Label->TabIndex = 8;
				this->valueMinus255Label->Text = L"-255";
				// 
				// value255Label2
				// 
				this->value255Label2->AutoSize = true;
				this->value255Label2->ForeColor = System::Drawing::Color::White;
				this->value255Label2->Location = System::Drawing::Point(236, 95);
				this->value255Label2->Name = L"value255Label2";
				this->value255Label2->Size = System::Drawing::Size(25, 13);
				this->value255Label2->TabIndex = 9;
				this->value255Label2->Text = L"255";
				// 
				// confirmButton
				// 
				this->confirmButton->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->confirmButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
				this->confirmButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->confirmButton->ForeColor = System::Drawing::Color::White;
				this->confirmButton->Location = System::Drawing::Point(105, 142);
				this->confirmButton->Name = L"confirmButton";
				this->confirmButton->Size = System::Drawing::Size(75, 23);
				this->confirmButton->TabIndex = 10;
				this->confirmButton->Text = L"Confirm";
				this->confirmButton->UseVisualStyleBackColor = true;
				this->confirmButton->Click += gcnew System::EventHandler(this, &AdjustColorsForm::ConfirmButton_Click);
				// 
				// AdjustColorsForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->ClientSize = System::Drawing::Size(273, 177);
				this->Controls->Add(this->confirmButton);
				this->Controls->Add(this->value255Label2);
				this->Controls->Add(this->valueMinus255Label);
				this->Controls->Add(this->brightessTrackBar);
				this->Controls->Add(this->brightnessLabel);
				this->Controls->Add(this->contrastTrackBar);
				this->Controls->Add(this->contrastLabel);
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				this->MaximizeBox = false;
				this->MinimizeBox = false;
				this->Name = L"AdjustColorsForm";
				this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				this->Text = L"Color Adjustment";
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->contrastTrackBar))->EndInit();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->brightessTrackBar))->EndInit();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
	#pragma endregion

			System::Void ConfirmButton_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
