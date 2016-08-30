#pragma once
#include "ImageUtils.h"
#include "ConvolveForm.h"
#include "QuantizeForm.h"
#include "HistogramForm.h"
#include "AdjustColorsForm.h"
#include "CustomZoomOutForm.h"

namespace Photosmith 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainWindow : public System::Windows::Forms::Form
	{

		public:
			MainWindow();

			bool HasImageLoaded();

			void SetImageLoaded(bool imageLoaded);

		protected:
			~MainWindow();

		private: 
			/***********************************************
			*				PRIVATE VARIABLES			   *
			************************************************/

			bool imageLoaded;

			System::ComponentModel::Container^ components;

			System::Windows::Forms::PictureBox^  modifiedImageBox;

	        System::Windows::Forms::Panel^  modifiedImageBoxPanel;

			System::Windows::Forms::PictureBox^  originalImageBox;

			System::Windows::Forms::Panel^  originalPictureBoxPanel;


			System::Windows::Forms::MenuStrip^  menuBar;

			System::Windows::Forms::ToolStripMenuItem^  fileMenu;

			System::Windows::Forms::ToolStripMenuItem^  openMenuItem;

			System::Windows::Forms::ToolStripMenuItem^  exitMenuItem;

			System::Windows::Forms::ToolStripMenuItem^  saveMenuItem;


			System::Windows::Forms::ToolStripMenuItem^  editMenu;

			System::Windows::Forms::ToolStripMenuItem^  zoomInMenuItem;

	        System::Windows::Forms::ToolStripMenuItem^  zoomOutMenuItem;

			System::Windows::Forms::ToolStripMenuItem^  negativeMenuItem;

			System::Windows::Forms::ToolStripMenuItem^  quantizeMenuItem;

			System::Windows::Forms::ToolStripMenuItem^  equalizeMenuItem;

			System::Windows::Forms::ToolStripMenuItem^  convolveMenuItem;

			System::Windows::Forms::ToolStripMenuItem^  grayscaleMenuItem;

			System::Windows::Forms::ToolStripMenuItem^  rotateLeftMenuItem;

			System::Windows::Forms::ToolStripMenuItem^  rotateRightMenuItem;

			System::Windows::Forms::ToolStripMenuItem^  invertYAxisMenuItem;

			System::Windows::Forms::ToolStripMenuItem^  invertXAxisMenuItem;

			System::Windows::Forms::ToolStripMenuItem^  adjustColorsMenuItem;

	        System::Windows::Forms::ToolStripMenuItem^  customZoomOutMenuItem;

	        System::Windows::Forms::ToolStripMenuItem^  defaultZoomOutMenuItem;


			System::Windows::Forms::ToolStripMenuItem^  toolsMenu;

			System::Windows::Forms::ToolStripMenuItem^  histogramMenuItem;


			System::Windows::Forms::ToolStrip^  toolBar;

			System::Windows::Forms::ToolStripButton^  openButton;

			System::Windows::Forms::ToolStripButton^  saveButton;

			System::Windows::Forms::ToolStripButton^  copyButton;

			System::Windows::Forms::ToolStripButton^  zoomInButton;

	        System::Windows::Forms::ToolStripButton^  zoomOutButton;

			System::Windows::Forms::ToolStripButton^  invertYButton;

			System::Windows::Forms::ToolStripButton^  invertXButton;

			System::Windows::Forms::ToolStripButton^  rotateLeftButton;

			System::Windows::Forms::ToolStripButton^  rotateRightButton;

			System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;

			System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;

			#pragma region AutoGeneratedCode
			void InitializeComponent(void)
			{
				System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
				this->originalImageBox = (gcnew System::Windows::Forms::PictureBox());
				this->menuBar = (gcnew System::Windows::Forms::MenuStrip());
				this->fileMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->openMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->saveMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->exitMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->editMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->adjustColorsMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->rotateLeftMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->rotateRightMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->invertYAxisMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->invertXAxisMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->negativeMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->grayscaleMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->equalizeMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->quantizeMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->convolveMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->zoomInMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->zoomOutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->defaultZoomOutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->customZoomOutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->toolsMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->histogramMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->toolBar = (gcnew System::Windows::Forms::ToolStrip());
				this->openButton = (gcnew System::Windows::Forms::ToolStripButton());
				this->saveButton = (gcnew System::Windows::Forms::ToolStripButton());
				this->copyButton = (gcnew System::Windows::Forms::ToolStripButton());
				this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
				this->invertYButton = (gcnew System::Windows::Forms::ToolStripButton());
				this->invertXButton = (gcnew System::Windows::Forms::ToolStripButton());
				this->rotateRightButton = (gcnew System::Windows::Forms::ToolStripButton());
				this->rotateLeftButton = (gcnew System::Windows::Forms::ToolStripButton());
				this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
				this->zoomInButton = (gcnew System::Windows::Forms::ToolStripButton());
				this->zoomOutButton = (gcnew System::Windows::Forms::ToolStripButton());
				this->modifiedImageBox = (gcnew System::Windows::Forms::PictureBox());
				this->originalPictureBoxPanel = (gcnew System::Windows::Forms::Panel());
				this->modifiedImageBoxPanel = (gcnew System::Windows::Forms::Panel());
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->originalImageBox))->BeginInit();
				this->menuBar->SuspendLayout();
				this->toolBar->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->modifiedImageBox))->BeginInit();
				this->originalPictureBoxPanel->SuspendLayout();
				this->modifiedImageBoxPanel->SuspendLayout();
				this->SuspendLayout();
				// 
				// originalImageBox
				// 
				this->originalImageBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), 
					static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
				this->originalImageBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				resources->ApplyResources(this->originalImageBox, L"originalImageBox");
				this->originalImageBox->Name = L"originalImageBox";
				this->originalImageBox->TabStop = false;
				// 
				// menuBar
				// 
				this->menuBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)));
				resources->ApplyResources(this->menuBar, L"menuBar");
				this->menuBar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fileMenu, this->editMenu, 
					this->toolsMenu});
				this->menuBar->Name = L"menuBar";
				// 
				// fileMenu
				// 
				this->fileMenu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->fileMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->openMenuItem, 
					this->saveMenuItem, this->exitMenuItem});
				this->fileMenu->ForeColor = System::Drawing::Color::White;
				resources->ApplyResources(this->fileMenu, L"fileMenu");
				this->fileMenu->Name = L"fileMenu";
				// 
				// openMenuItem
				// 
				this->openMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->openMenuItem->ForeColor = System::Drawing::Color::White;
				resources->ApplyResources(this->openMenuItem, L"openMenuItem");
				this->openMenuItem->Name = L"openMenuItem";
				this->openMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::OpenButton_Click);
				// 
				// saveMenuItem
				// 
				this->saveMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->saveMenuItem->ForeColor = System::Drawing::Color::White;
				resources->ApplyResources(this->saveMenuItem, L"saveMenuItem");
				this->saveMenuItem->Name = L"saveMenuItem";
				this->saveMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::SaveButton_Click);
				// 
				// exitMenuItem
				// 
				this->exitMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->exitMenuItem->ForeColor = System::Drawing::Color::White;
				resources->ApplyResources(this->exitMenuItem, L"exitMenuItem");
				this->exitMenuItem->Name = L"exitMenuItem";
				this->exitMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::ExitButton_Click);
				// 
				// editMenu
				// 
				this->editMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {this->adjustColorsMenuItem, 
					this->rotateLeftMenuItem, this->rotateRightMenuItem, this->invertYAxisMenuItem, this->invertXAxisMenuItem, this->negativeMenuItem, 
					this->grayscaleMenuItem, this->equalizeMenuItem, this->quantizeMenuItem, this->convolveMenuItem, this->zoomInMenuItem, this->zoomOutMenuItem});
				this->editMenu->ForeColor = System::Drawing::Color::White;
				this->editMenu->Name = L"editMenu";
				resources->ApplyResources(this->editMenu, L"editMenu");
				// 
				// adjustColorsMenuItem
				// 
				this->adjustColorsMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->adjustColorsMenuItem->ForeColor = System::Drawing::Color::White;
				this->adjustColorsMenuItem->Name = L"adjustColorsMenuItem";
				resources->ApplyResources(this->adjustColorsMenuItem, L"adjustColorsMenuItem");
				this->adjustColorsMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::AdjustColorsButton_Click);
				// 
				// rotateLeftMenuItem
				// 
				this->rotateLeftMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->rotateLeftMenuItem->ForeColor = System::Drawing::Color::White;
				this->rotateLeftMenuItem->Name = L"rotateLeftMenuItem";
				resources->ApplyResources(this->rotateLeftMenuItem, L"rotateLeftMenuItem");
				this->rotateLeftMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::RotateLeftButton_Click);
				// 
				// rotateRightMenuItem
				// 
				this->rotateRightMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->rotateRightMenuItem->ForeColor = System::Drawing::Color::White;
				this->rotateRightMenuItem->Name = L"rotateRightMenuItem";
				resources->ApplyResources(this->rotateRightMenuItem, L"rotateRightMenuItem");
				this->rotateRightMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::RotateRightButton_Click);
				// 
				// invertYAxisMenuItem
				// 
				this->invertYAxisMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->invertYAxisMenuItem->ForeColor = System::Drawing::Color::White;
				this->invertYAxisMenuItem->Name = L"invertYAxisMenuItem";
				resources->ApplyResources(this->invertYAxisMenuItem, L"invertYAxisMenuItem");
				this->invertYAxisMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::InvertYButton_Click);
				// 
				// invertXAxisMenuItem
				// 
				this->invertXAxisMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->invertXAxisMenuItem->ForeColor = System::Drawing::Color::White;
				this->invertXAxisMenuItem->Name = L"invertXAxisMenuItem";
				resources->ApplyResources(this->invertXAxisMenuItem, L"invertXAxisMenuItem");
				this->invertXAxisMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::InvertXButton_Click);
				// 
				// negativeMenuItem
				// 
				this->negativeMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->negativeMenuItem->ForeColor = System::Drawing::Color::White;
				this->negativeMenuItem->Name = L"negativeMenuItem";
				resources->ApplyResources(this->negativeMenuItem, L"negativeMenuItem");
				this->negativeMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::NegativeButton_Click);
				// 
				// grayscaleMenuItem
				// 
				this->grayscaleMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->grayscaleMenuItem->ForeColor = System::Drawing::Color::White;
				this->grayscaleMenuItem->Name = L"grayscaleMenuItem";
				resources->ApplyResources(this->grayscaleMenuItem, L"grayscaleMenuItem");
				this->grayscaleMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::GrayscaleButton_Click);
				// 
				// equalizeMenuItem
				// 
				this->equalizeMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->equalizeMenuItem->ForeColor = System::Drawing::Color::White;
				this->equalizeMenuItem->Name = L"equalizeMenuItem";
				resources->ApplyResources(this->equalizeMenuItem, L"equalizeMenuItem");
				this->equalizeMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::EqualizeButton_Click);
				// 
				// quantizeMenuItem
				// 
				this->quantizeMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->quantizeMenuItem->ForeColor = System::Drawing::Color::White;
				this->quantizeMenuItem->Name = L"quantizeMenuItem";
				resources->ApplyResources(this->quantizeMenuItem, L"quantizeMenuItem");
				this->quantizeMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::QuantizeButton_Click);
				// 
				// convolveMenuItem
				// 
				this->convolveMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->convolveMenuItem->ForeColor = System::Drawing::Color::White;
				this->convolveMenuItem->Name = L"convolveMenuItem";
				resources->ApplyResources(this->convolveMenuItem, L"convolveMenuItem");
				this->convolveMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::ConvolveButton_Click);
				// 
				// zoomInMenuItem
				// 
				this->zoomInMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->zoomInMenuItem->ForeColor = System::Drawing::Color::White;
				this->zoomInMenuItem->Name = L"zoomInMenuItem";
				resources->ApplyResources(this->zoomInMenuItem, L"zoomInMenuItem");
				this->zoomInMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::ZoomInButton_Click);
				// 
				// zoomOutMenuItem
				// 
				this->zoomOutMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->zoomOutMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->defaultZoomOutMenuItem, 
					this->customZoomOutMenuItem});
				this->zoomOutMenuItem->ForeColor = System::Drawing::Color::White;
				this->zoomOutMenuItem->Name = L"zoomOutMenuItem";
				resources->ApplyResources(this->zoomOutMenuItem, L"zoomOutMenuItem");
				// 
				// defaultZoomOutMenuItem
				// 
				this->defaultZoomOutMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->defaultZoomOutMenuItem->ForeColor = System::Drawing::Color::White;
				this->defaultZoomOutMenuItem->Name = L"defaultZoomOutMenuItem";
				resources->ApplyResources(this->defaultZoomOutMenuItem, L"defaultZoomOutMenuItem");
				this->defaultZoomOutMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::ZoomOutButton_Click);
				// 
				// customZoomOutMenuItem
				// 
				this->customZoomOutMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->customZoomOutMenuItem->ForeColor = System::Drawing::Color::White;
				this->customZoomOutMenuItem->Name = L"customZoomOutMenuItem";
				resources->ApplyResources(this->customZoomOutMenuItem, L"customZoomOutMenuItem");
				this->customZoomOutMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::CustomZoomOutMenuItem_Click);
				// 
				// toolsMenu
				// 
				this->toolsMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->histogramMenuItem});
				this->toolsMenu->ForeColor = System::Drawing::Color::White;
				this->toolsMenu->Name = L"toolsMenu";
				resources->ApplyResources(this->toolsMenu, L"toolsMenu");
				// 
				// histogramMenuItem
				// 
				this->histogramMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), 
					static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(34)));
				this->histogramMenuItem->ForeColor = System::Drawing::Color::White;
				this->histogramMenuItem->Name = L"histogramMenuItem";
				resources->ApplyResources(this->histogramMenuItem, L"histogramMenuItem");
				this->histogramMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::HistogramButton_Click);
				// 
				// toolBar
				// 
				this->toolBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->toolBar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {this->openButton, this->saveButton, 
					this->copyButton, this->toolStripSeparator, this->invertYButton, this->invertXButton, this->rotateRightButton, this->rotateLeftButton, 
					this->toolStripSeparator2, this->zoomInButton, this->zoomOutButton});
				resources->ApplyResources(this->toolBar, L"toolBar");
				this->toolBar->Name = L"toolBar";
				// 
				// openButton
				// 
				resources->ApplyResources(this->openButton, L"openButton");
				this->openButton->BackColor = System::Drawing::Color::Transparent;
				this->openButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				this->openButton->Name = L"openButton";
				this->openButton->Click += gcnew System::EventHandler(this, &MainWindow::OpenButton_Click);
				this->openButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::OpenButton_MouseDown);
				this->openButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::OpenButton_MouseUp);
				// 
				// saveButton
				// 
				this->saveButton->BackColor = System::Drawing::Color::Transparent;
				resources->ApplyResources(this->saveButton, L"saveButton");
				this->saveButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				this->saveButton->Name = L"saveButton";
				this->saveButton->Click += gcnew System::EventHandler(this, &MainWindow::SaveButton_Click);
				this->saveButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::SaveButton_MouseDown);
				this->saveButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::SaveButton_MouseUp);
				// 
				// copyButton
				// 
				this->copyButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				resources->ApplyResources(this->copyButton, L"copyButton");
				this->copyButton->Name = L"copyButton";
				this->copyButton->Click += gcnew System::EventHandler(this, &MainWindow::CopyButton_Click);
				this->copyButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::CopyButton_MouseDown);
				this->copyButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::CopyButton_MouseUp);
				// 
				// toolStripSeparator
				// 
				this->toolStripSeparator->Name = L"toolStripSeparator";
				resources->ApplyResources(this->toolStripSeparator, L"toolStripSeparator");
				// 
				// invertYButton
				// 
				this->invertYButton->BackColor = System::Drawing::Color::Transparent;
				this->invertYButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				resources->ApplyResources(this->invertYButton, L"invertYButton");
				this->invertYButton->Name = L"invertYButton";
				this->invertYButton->Click += gcnew System::EventHandler(this, &MainWindow::InvertYButton_Click);
				this->invertYButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::InvertYButton_MouseDown);
				this->invertYButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::InvertYButton_MouseUp);
				// 
				// invertXButton
				// 
				this->invertXButton->BackColor = System::Drawing::Color::Transparent;
				this->invertXButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				resources->ApplyResources(this->invertXButton, L"invertXButton");
				this->invertXButton->Name = L"invertXButton";
				this->invertXButton->Click += gcnew System::EventHandler(this, &MainWindow::InvertXButton_Click);
				this->invertXButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::InvertXButton_MouseDown);
				this->invertXButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::InvertXButton_MouseUp);
				// 
				// rotateRightButton
				// 
				this->rotateRightButton->BackColor = System::Drawing::Color::Transparent;
				this->rotateRightButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				resources->ApplyResources(this->rotateRightButton, L"rotateRightButton");
				this->rotateRightButton->Name = L"rotateRightButton";
				this->rotateRightButton->Click += gcnew System::EventHandler(this, &MainWindow::RotateRightButton_Click);
				this->rotateRightButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::RotateRightButton_MouseDown);
				this->rotateRightButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::RotateRightButton_MouseUp);
				// 
				// rotateLeftButton
				// 
				this->rotateLeftButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				resources->ApplyResources(this->rotateLeftButton, L"rotateLeftButton");
				this->rotateLeftButton->Name = L"rotateLeftButton";
				this->rotateLeftButton->Click += gcnew System::EventHandler(this, &MainWindow::RotateLeftButton_Click);
				this->rotateLeftButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::RotateLeftButton_MouseDown);
				this->rotateLeftButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::RotateLeftButton_MouseUp);
				// 
				// toolStripSeparator2
				// 
				this->toolStripSeparator2->Name = L"toolStripSeparator2";
				resources->ApplyResources(this->toolStripSeparator2, L"toolStripSeparator2");
				// 
				// zoomInButton
				// 
				this->zoomInButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				resources->ApplyResources(this->zoomInButton, L"zoomInButton");
				this->zoomInButton->Name = L"zoomInButton";
				this->zoomInButton->Click += gcnew System::EventHandler(this, &MainWindow::ZoomInButton_Click);
				this->zoomInButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::ZoomInButton_MouseDown);
				this->zoomInButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::ZoomInButton_MouseUp);
				// 
				// zoomOutButton
				// 
				this->zoomOutButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				resources->ApplyResources(this->zoomOutButton, L"zoomOutButton");
				this->zoomOutButton->Name = L"zoomOutButton";
				this->zoomOutButton->Click += gcnew System::EventHandler(this, &MainWindow::ZoomOutButton_Click);
				this->zoomOutButton->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::ZoomOutButton_MouseDown);
				this->zoomOutButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::ZoomOutButton_MouseUp);
				// 
				// modifiedImageBox
				// 
				this->modifiedImageBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), 
					static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
				this->modifiedImageBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				resources->ApplyResources(this->modifiedImageBox, L"modifiedImageBox");
				this->modifiedImageBox->Name = L"modifiedImageBox";
				this->modifiedImageBox->TabStop = false;
				// 
				// originalPictureBoxPanel
				// 
				resources->ApplyResources(this->originalPictureBoxPanel, L"originalPictureBoxPanel");
				this->originalPictureBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), 
					static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
				this->originalPictureBoxPanel->Controls->Add(this->originalImageBox);
				this->originalPictureBoxPanel->Name = L"originalPictureBoxPanel";
				// 
				// modifiedImageBoxPanel
				// 
				resources->ApplyResources(this->modifiedImageBoxPanel, L"modifiedImageBoxPanel");
				this->modifiedImageBoxPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), 
					static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
				this->modifiedImageBoxPanel->Controls->Add(this->modifiedImageBox);
				this->modifiedImageBoxPanel->Name = L"modifiedImageBoxPanel";
				// 
				// MainWindow
				// 
				resources->ApplyResources(this, L"$this");
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)), 
					static_cast<System::Int32>(static_cast<System::Byte>(46)));
				this->Controls->Add(this->modifiedImageBoxPanel);
				this->Controls->Add(this->originalPictureBoxPanel);
				this->Controls->Add(this->toolBar);
				this->Controls->Add(this->menuBar);
				this->ForeColor = System::Drawing::Color::Transparent;
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
				this->MainMenuStrip = this->menuBar;
				this->MaximizeBox = false;
				this->Name = L"MainWindow";
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->originalImageBox))->EndInit();
				this->menuBar->ResumeLayout(false);
				this->menuBar->PerformLayout();
				this->toolBar->ResumeLayout(false);
				this->toolBar->PerformLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->modifiedImageBox))->EndInit();
				this->originalPictureBoxPanel->ResumeLayout(false);
				this->originalPictureBoxPanel->PerformLayout();
				this->modifiedImageBoxPanel->ResumeLayout(false);
				this->modifiedImageBoxPanel->PerformLayout();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
			#pragma endregion


			/***********************************************
			*				PRIVATE METHODS				   *
			************************************************/
			
			System::Void OpenButton_Click(System::Object^ sender, System::EventArgs^ e);
			 
			System::Void SaveButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void CopyButton_Click(System::Object^ sender, System::EventArgs^ e);


			System::Void ZoomInButton_Click(System::Object^ sender, System::EventArgs^ e);
			
			System::Void ZoomOutButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void InvertYButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void InvertXButton_Click(System::Object^ sender, System::EventArgs^ e);
			
			System::Void NegativeButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void ConvolveButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void EqualizeButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void QuantizeButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void HistogramButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void GrayscaleButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void RotateLeftButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void RotateRightButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void AdjustColorsButton_Click(System::Object^ sender, System::EventArgs^ e);

			System::Void CustomZoomOutMenuItem_Click(System::Object^ sender, System::EventArgs^ e);


			System::Void OpenButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void SaveButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
			
			System::Void CopyButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);	

			System::Void CopyButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void SaveButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void OpenButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void ZoomInButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
			
			System::Void ZoomOutButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void ZoomInButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
			
			System::Void ZoomOutButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void InvertYButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void InvertXButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void InvertYButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void InvertXButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void RotateLeftButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void RotateRightButton_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void RotateLeftButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

			System::Void RotateRightButton_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	};
}