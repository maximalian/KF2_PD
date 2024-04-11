#pragma once
#include "Ctrl.h"
#include <stdlib.h>
#include <time.h>
#include "SettingsWindow.h"
#include <msclr/marshal_cppstd.h>



Ctrl* control;

namespace KF2PD {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;


	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ ControlArea;
		   float ctrlAreaMargins = 5;
		   int cellCountAtStart = 15;
		   float borderWidth = (this->Size.Width - this->ClientSize.Width) / 2;
		   float titleBarWidth = this->Size.Height - this->ClientSize.Height - borderWidth * 2;
	private: System::Windows::Forms::PictureBox^ Player1Image;
		   Image^ playerHumanImg = Image::FromFile("resources\\PlayerIcon.png");
		   Image^ playerCompImg = Image::FromFile("resources\\CompIcon.png");
		   Image^ settingsImg = Image::FromFile("resources\\SettingsIcon.png");
		   Image^ infoImg= Image::FromFile("resources\\InfoIcon.png");
		   KF2PD::SettingsWindow setWind;
		   		
	private: System::Windows::Forms::PictureBox^ Player2Image;
	private: System::Windows::Forms::Label^ Player1Label;

	private: System::Windows::Forms::Label^ Player2Label;
	private: System::Windows::Forms::Label^ Player1Score;
	private: System::Windows::Forms::Label^ Player2Score;
	private: System::Windows::Forms::PictureBox^ SettingsImage;
	private: System::Windows::Forms::PictureBox^ InfoImage;
	private: System::Windows::Forms::Label^ PlayerWinText;


		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->ControlArea = (gcnew System::Windows::Forms::PictureBox());
			this->Player1Image = (gcnew System::Windows::Forms::PictureBox());
			this->Player2Image = (gcnew System::Windows::Forms::PictureBox());
			this->Player1Label = (gcnew System::Windows::Forms::Label());
			this->Player2Label = (gcnew System::Windows::Forms::Label());
			this->Player1Score = (gcnew System::Windows::Forms::Label());
			this->Player2Score = (gcnew System::Windows::Forms::Label());
			this->SettingsImage = (gcnew System::Windows::Forms::PictureBox());
			this->InfoImage = (gcnew System::Windows::Forms::PictureBox());
			this->PlayerWinText = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ControlArea))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player1Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player2Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SettingsImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InfoImage))->BeginInit();
			this->SuspendLayout();
			// 
			// ControlArea
			// 
			this->ControlArea->Location = System::Drawing::Point(12, 29);
			this->ControlArea->Name = L"ControlArea";
			this->ControlArea->Size = System::Drawing::Size(682, 57);
			this->ControlArea->TabIndex = 0;
			this->ControlArea->TabStop = false;
			this->ControlArea->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainWindow::ControlArea_Paint);
			this->ControlArea->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::ControlArea_MouseClick);
			// 
			// Player1Image
			// 
			this->Player1Image->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Player1Image.Image")));
			this->Player1Image->Location = System::Drawing::Point(12, 119);
			this->Player1Image->Name = L"Player1Image";
			this->Player1Image->Size = System::Drawing::Size(103, 131);
			this->Player1Image->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Player1Image->TabIndex = 1;
			this->Player1Image->TabStop = false;
			this->Player1Image->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainWindow::Player1Image_Paint);
			// 
			// Player2Image
			// 
			this->Player2Image->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Player2Image.Image")));
			this->Player2Image->Location = System::Drawing::Point(591, 119);
			this->Player2Image->Name = L"Player2Image";
			this->Player2Image->Size = System::Drawing::Size(103, 131);
			this->Player2Image->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Player2Image->TabIndex = 2;
			this->Player2Image->TabStop = false;
			this->Player2Image->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainWindow::Player2Image_Paint);
			// 
			// Player1Label
			// 
			this->Player1Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Player1Label->AutoSize = true;
			this->Player1Label->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Player1Label->Location = System::Drawing::Point(31, 255);
			this->Player1Label->Name = L"Player1Label";
			this->Player1Label->Size = System::Drawing::Size(63, 19);
			this->Player1Label->TabIndex = 3;
			this->Player1Label->Text = L"label1";
			this->Player1Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Player2Label
			// 
			this->Player2Label->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Player2Label->AutoSize = true;
			this->Player2Label->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Player2Label->Location = System::Drawing::Point(617, 255);
			this->Player2Label->Name = L"Player2Label";
			this->Player2Label->Size = System::Drawing::Size(63, 19);
			this->Player2Label->TabIndex = 4;
			this->Player2Label->Text = L"label1";
			this->Player2Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Player1Score
			// 
			this->Player1Score->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Player1Score->AutoSize = true;
			this->Player1Score->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Player1Score->Location = System::Drawing::Point(31, 97);
			this->Player1Score->Name = L"Player1Score";
			this->Player1Score->Size = System::Drawing::Size(63, 19);
			this->Player1Score->TabIndex = 5;
			this->Player1Score->Text = L"label1";
			this->Player1Score->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Player2Score
			// 
			this->Player2Score->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Player2Score->AutoSize = true;
			this->Player2Score->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->Player2Score->Location = System::Drawing::Point(617, 97);
			this->Player2Score->Name = L"Player2Score";
			this->Player2Score->Size = System::Drawing::Size(63, 19);
			this->Player2Score->TabIndex = 6;
			this->Player2Score->Text = L"label1";
			this->Player2Score->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SettingsImage
			// 
			this->SettingsImage->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->SettingsImage->Location = System::Drawing::Point(397, 233);
			this->SettingsImage->Name = L"SettingsImage";
			this->SettingsImage->Size = System::Drawing::Size(41, 38);
			this->SettingsImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->SettingsImage->TabIndex = 7;
			this->SettingsImage->TabStop = false;
			this->SettingsImage->Click += gcnew System::EventHandler(this, &MainWindow::SettingsImage_Click);
			// 
			// InfoImage
			// 
			this->InfoImage->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->InfoImage->Location = System::Drawing::Point(318, 233);
			this->InfoImage->Name = L"InfoImage";
			this->InfoImage->Size = System::Drawing::Size(41, 38);
			this->InfoImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->InfoImage->TabIndex = 8;
			this->InfoImage->TabStop = false;
			this->InfoImage->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainWindow::InfoImage_MouseClick);
			// 
			// PlayerWinText
			// 
			this->PlayerWinText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->PlayerWinText->AutoSize = true;
			this->PlayerWinText->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayerWinText->Location = System::Drawing::Point(297, 142);
			this->PlayerWinText->Name = L"PlayerWinText";
			this->PlayerWinText->Size = System::Drawing::Size(0, 25);
			this->PlayerWinText->TabIndex = 9;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(706, 283);
			this->Controls->Add(this->PlayerWinText);
			this->Controls->Add(this->InfoImage);
			this->Controls->Add(this->SettingsImage);
			this->Controls->Add(this->Player2Score);
			this->Controls->Add(this->Player1Score);
			this->Controls->Add(this->Player2Label);
			this->Controls->Add(this->Player1Label);
			this->Controls->Add(this->Player2Image);
			this->Controls->Add(this->Player1Image);
			this->Controls->Add(this->ControlArea);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MainWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"KF-2 Game";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->Resize += gcnew System::EventHandler(this, &MainWindow::MainWindow_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ControlArea))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player1Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Player2Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SettingsImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InfoImage))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ControlArea_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ grp = e->Graphics;
		control->DrawControl(grp);
		Player1Score->Text = "score: " + control->getPlayerScore(0).ToString();
		Player2Score->Text = "score: " + control->getPlayerScore(1).ToString();
	}
	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
		control = new Ctrl(ControlArea->Width, ControlArea->Height, setWind.cellsCountAtStart, 0.75f, 25);
		//speletaju icons un teksta uzstadisana
		Player1Image->Anchor = AnchorStyles::Left | AnchorStyles::Bottom;
		//kurs speletajs iet pirmais
		control->setMakingMoveStatus(0, true);
		recalculateWindowElements(false);
	}
	private: System::Void MainWindow_Resize(System::Object^ sender, System::EventArgs^ e) {
		ControlArea->Width = this->ClientSize.Width - ctrlAreaMargins * 2;
		control->RecalculateSizes(ControlArea->Width, ControlArea->Height);
		ControlArea->Invalidate();
	}
	private: System::Void ControlArea_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		control->checkCursorLocation(e->X, e->Y, true);
		//if AI move
		if (control->getmakingMoveStatus(1) && !setWind.playingAgainstHuman && control->getButtonsCount() > 0) {
			control->makeAIMove(setWind.AIAlgorithmMiniMax, setWind.AIVisionStrength);
		}
		recalculateWindowElements(false);
		ControlArea->Invalidate();
		Player1Image->Invalidate();
		Player2Image->Invalidate();
	}
	private: System::Void Player1Image_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ grp = e->Graphics;
		control->DrawPlayer1Status(grp, Player1Image->Width, Player1Image->Height);
	}

	private: System::Void Player2Image_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ grp = e->Graphics;
		control->DrawPlayer2Status(grp, Player2Image->Width, Player2Image->Height);
	}
	private: System::Void SettingsImage_Click(System::Object^ sender, System::EventArgs^ e) {
		control->clearRoundMovesFile();

		setWind.Location = Point(this->Location.X + borderWidth, this->Location.Y + borderWidth + titleBarWidth);
		setWind.Width = this->ClientSize.Width;
		setWind.Height = this->ClientSize.Height;
		setWind.ShowDialog();
		recalculateWindowElements(setWind.needGameRestart);
	}
	private: void recalculateWindowElements(bool needGameRestart) {
		if (needGameRestart) {
			delete control;
			control = nullptr;
			control = new Ctrl(ControlArea->Width, ControlArea->Height, setWind.cellsCountAtStart, 0.75f, 25);
			if (setWind.player1MoveFirst) {
				control->setMakingMoveStatus(0, true);
				control->setMakingMoveStatus(1, false);
			}
			else {
				control->setMakingMoveStatus(0, false);
				control->setMakingMoveStatus(1, true);
				if (!setWind.playingAgainstHuman) control->makeAIMove(setWind.AIAlgorithmMiniMax, setWind.AIVisionStrength);
			}
		}
		PlayerWinText->Text = "";
		//Window sizes
		borderWidth = (this->Size.Width - this->ClientSize.Width) / 2;
		titleBarWidth = this->Size.Height - this->ClientSize.Height - borderWidth * 2;
		//window izmeru mainisana atkariba no jauniem parametriem
		control->RecalculateSizes(ControlArea->Width, ControlArea->Height);

		float ctrlAreaMinWIdth = control->GetControlAreaMinWidth();
		if (this->ClientSize.Width - 2 * ctrlAreaMargins >= ctrlAreaMinWIdth) {
			ControlArea->Width = this->ClientSize.Width - 2 * ctrlAreaMargins;
		}
		else {
			ControlArea->Width = ctrlAreaMinWIdth;
		}
		//window maksimala un minimala izmeru uzstadisana
		Drawing::Size siz;
		siz.Width = setWind.needGameRestart ? ctrlAreaMinWIdth + 2 * ctrlAreaMargins + borderWidth : ctrlAreaMargins * 2 + ControlArea->Width + borderWidth;
		siz.Height = 350;
		this->MinimumSize = siz;
		Screen^ scr = Screen::PrimaryScreen;
		siz.Width = scr->Bounds.Width;
		siz.Height = scr->Bounds.Height;
		this->MaximumSize = siz;
		this->Size = setWind.needGameRestart ? this->MinimumSize : this->Size;
		//loga izvade ekrana centra
		if (setWind.needGameRestart) {
			this->Location = Point(siz.Width / 2 - this->Width / 2, siz.Height / 2 - this->Height / 2);
		}
		ControlArea->Location = Point(this->ClientSize.Width / 2 - ControlArea->Width / 2, ctrlAreaMargins);

		//speletaju icons izmeru uzstade
		int imgHeight = this->ClientSize.Height / 2;
		Player1Image->Height = imgHeight;
		Player1Image->Image = playerHumanImg;
		Player1Image->Width = playerHumanImg->Width * imgHeight / playerHumanImg->Height;
		Player2Image->Height = imgHeight;
		if (setWind.playingAgainstHuman) {
			Player2Image->Image = playerHumanImg;
			Player2Image->Width = playerHumanImg->Width * imgHeight / playerHumanImg->Height;
			Player2Label->Text = setWind.player2Name;
		}
		else {
			Player2Image->Image = playerCompImg;
			Player2Image->Width = playerCompImg->Width * imgHeight / playerCompImg->Height;
			Player2Label->Text = "AI";
		}
		//speletaju elementu pozisijas uzstade
		Player1Image->Location = Point(ctrlAreaMargins, this->ClientSize.Height - Player1Image->Height - Player1Label->Height - ctrlAreaMargins);
		Player1Label->Text = setWind.player1Name;
		Player1Label->Location = Point(Player1Image->Location.X + Player1Image->Width / 2 - Player1Label->Width / 2, Player1Image->Location.Y - Player1Label->Height);
		Player2Image->Location = Point(this->ClientSize.Width - Player2Image->Width - ctrlAreaMargins, this->ClientSize.Height - Player2Image->Height - Player2Label->Height - ctrlAreaMargins);
		Player2Label->Location = Point(Player2Image->Location.X + Player2Image->Width / 2 - Player2Label->Width / 2, Player2Image->Location.Y - Player2Label->Height);
		Player1Score->Text = "score: " + control->getPlayerScore(0).ToString();
		Player2Score->Text = "score: " + control->getPlayerScore(1).ToString();
		Player1Score->Location = Point(Player1Image->Location.X + Player1Image->Width / 2 - Player1Score->Width / 2, this->ClientSize.Height - Player1Score->Height - ctrlAreaMargins);
		Player2Score->Location = Point(Player2Image->Location.X + Player2Image->Width / 2 - Player2Score->Width / 2, this->ClientSize.Height - Player2Score->Height - ctrlAreaMargins);
		control->setPlayerIndicatorSize(Player1Image->Height / 10);
		//buttons settings configuration
		float settButtonsSize = this->ClientSize.Height / 10;
		SettingsImage->Image = settingsImg;
		SettingsImage->Height = settButtonsSize;
		SettingsImage->Width = SettingsImage->Height;
		SettingsImage->Location = Point(this->ClientSize.Width / 2 + SettingsImage->Width, Player1Score->Location.Y + Player1Score->Height - SettingsImage->Height);
		InfoImage->Image = infoImg;
		InfoImage->Height = settButtonsSize;
		InfoImage->Width = InfoImage->Height;
		InfoImage->Location = Point(this->ClientSize.Width / 2 - InfoImage->Width * 2, Player1Score->Location.Y + Player1Score->Height - InfoImage->Height);
		ControlArea->Invalidate();
		Player1Image->Invalidate();
		Player2Image->Invalidate();
		setWind.needGameRestart = false;
		//parbaude vai jaturpina speli
		if (control->playerHasWin()) {
			bool player1Hasmore = control->getPlayerScore(0) > control->getPlayerScore(1) ? true : false;
			bool player2Hasmore = control->getPlayerScore(1) > control->getPlayerScore(0) ? true : false;

			std::string player1NameStr = marshal_as<std::string>(Player1Label->Text);
			std::string player2NameStr = marshal_as<std::string>(Player2Label->Text);

			control->writeRoundResultsToFile(player1NameStr, player2NameStr, setWind.AIAlgorithmMiniMax, setWind.AIVisionStrength, control->getPlayerScore(0), control->getPlayerScore(1));

			// Izmantojiet pašreizējo laiku un apmeklētos mezglus, kā arī spēlētāju rezultātus
			if (player1Hasmore) {
				PlayerWinText->Text = setWind.player1Name + " has won!";
			}
			else if (player2Hasmore) {
				PlayerWinText->Text = setWind.player2Name + " has won!";
			}
			else {
				PlayerWinText->Text = "Draw!";
			}
		}
		PlayerWinText->Location = Point(this->ClientSize.Width / 2 - PlayerWinText->Width / 2, Player1Label->Location.Y);
	}
	private: System::Void InfoImage_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		String^ pravila;
		pravila = "Players take turns \n" +
			"For merging cells with a sum higher than 7:\t+1 point\n" +
			"For merging cells with a sum less than 7:\t-1 point\n" +
			"For merging cells with a sum equal to 7:\t+2 points\n\n" +
			"Cells with a sum greater than 7:\n->combined into new cell with value 1\n" +
			"Cells with a sum less than 7:\n->combined into new cell with value 3\n" +
			"Cells with a sum equal to 7:\n->combined into new cell with value 2";
		MessageBox::Show(pravila, "Game rules", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
};
}