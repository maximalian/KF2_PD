#pragma once
#include "AISettings.h"

namespace KF2PD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SettingsWindow
	/// </summary>
	public ref class SettingsWindow : public System::Windows::Forms::Form
	{
	public:
		int cellsCountAtStart = 15;
		bool needGameRestart = false;
		String^ player1Name = "Biba";
		String^ player2Name = "Boba";
		bool player1MoveFirst = false;

		bool AIAlgorithmMiniMax=false;
		int AIVisionStrength = 3;

	private: System::Windows::Forms::Label^ CellsCountLabel;
	private: System::Windows::Forms::Label^ Label;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ radioButtonPlayer;
	private: System::Windows::Forms::RadioButton^ radioButtonAI;
	private: System::Windows::Forms::Label^ player1NameLabel;
	private: System::Windows::Forms::TextBox^ player1NameInput;

	private: System::Windows::Forms::Label^ player2NameLabel;
	private: System::Windows::Forms::TextBox^ player2NameInput;

	private: System::Windows::Forms::Button^ exitBtn;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::RadioButton^ firstMovePlayer1;
	private: System::Windows::Forms::RadioButton^ firstMovePlayer2;
	private: System::Windows::Forms::NumericUpDown^ CellsCoutnAtStart;
	private: System::Windows::Forms::Button^ AISettingsBtn;



	public:
		bool playingAgainstHuman = true;
		SettingsWindow(void)
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
		~SettingsWindow()
		{
			if (components)
			{
				delete components;
			}
		
		}
	private: System::Windows::Forms::Button^ saveBtn;
	protected:

	private: System::Windows::Forms::Button^ SaveButton;
	protected:
	protected:

	private:
		KF2PD::AISettings AISetWnd;
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
			this->saveBtn = (gcnew System::Windows::Forms::Button());
			this->CellsCountLabel = (gcnew System::Windows::Forms::Label());
			this->Label = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButtonPlayer = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonAI = (gcnew System::Windows::Forms::RadioButton());
			this->player1NameLabel = (gcnew System::Windows::Forms::Label());
			this->player1NameInput = (gcnew System::Windows::Forms::TextBox());
			this->player2NameLabel = (gcnew System::Windows::Forms::Label());
			this->player2NameInput = (gcnew System::Windows::Forms::TextBox());
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->firstMovePlayer2 = (gcnew System::Windows::Forms::RadioButton());
			this->firstMovePlayer1 = (gcnew System::Windows::Forms::RadioButton());
			this->CellsCoutnAtStart = (gcnew System::Windows::Forms::NumericUpDown());
			this->AISettingsBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CellsCoutnAtStart))->BeginInit();
			this->SuspendLayout();
			// 
			// saveBtn
			// 
			this->saveBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->saveBtn->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 12, System::Drawing::FontStyle::Italic));
			this->saveBtn->Location = System::Drawing::Point(22, 281);
			this->saveBtn->Name = L"saveBtn";
			this->saveBtn->Size = System::Drawing::Size(115, 32);
			this->saveBtn->TabIndex = 0;
			this->saveBtn->Text = L"Save";
			this->saveBtn->UseVisualStyleBackColor = true;
			this->saveBtn->Click += gcnew System::EventHandler(this, &SettingsWindow::saveBtn_Click);
			// 
			// CellsCountLabel
			// 
			this->CellsCountLabel->AutoSize = true;
			this->CellsCountLabel->Font = (gcnew System::Drawing::Font(L"Sitka Small", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->CellsCountLabel->Location = System::Drawing::Point(18, 50);
			this->CellsCountLabel->Name = L"CellsCountLabel";
			this->CellsCountLabel->Size = System::Drawing::Size(94, 24);
			this->CellsCountLabel->TabIndex = 2;
			this->CellsCountLabel->Text = L"Cell count";
			// 
			// Label
			// 
			this->Label->AutoSize = true;
			this->Label->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Label->Location = System::Drawing::Point(18, 9);
			this->Label->Name = L"Label";
			this->Label->Size = System::Drawing::Size(163, 23);
			this->Label->TabIndex = 3;
			this->Label->Text = L"Global Settings";
			// 
			// trackBar1
			// 
			this->trackBar1->LargeChange = 1;
			this->trackBar1->Location = System::Drawing::Point(178, 50);
			this->trackBar1->Maximum = 25;
			this->trackBar1->Minimum = 15;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(91, 45);
			this->trackBar1->TabIndex = 4;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar1->Value = 15;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &SettingsWindow::trackBar1_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Small", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label1->Location = System::Drawing::Point(18, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 24);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Game against";
			// 
			// radioButtonPlayer
			// 
			this->radioButtonPlayer->AutoSize = true;
			this->radioButtonPlayer->Checked = true;
			this->radioButtonPlayer->Location = System::Drawing::Point(3, 3);
			this->radioButtonPlayer->Name = L"radioButtonPlayer";
			this->radioButtonPlayer->Size = System::Drawing::Size(63, 17);
			this->radioButtonPlayer->TabIndex = 6;
			this->radioButtonPlayer->TabStop = true;
			this->radioButtonPlayer->Text = L"2 Player";
			this->radioButtonPlayer->UseVisualStyleBackColor = true;
			// 
			// radioButtonAI
			// 
			this->radioButtonAI->AutoSize = true;
			this->radioButtonAI->Location = System::Drawing::Point(71, 3);
			this->radioButtonAI->Name = L"radioButtonAI";
			this->radioButtonAI->Size = System::Drawing::Size(35, 17);
			this->radioButtonAI->TabIndex = 7;
			this->radioButtonAI->Text = L"AI";
			this->radioButtonAI->UseVisualStyleBackColor = true;
			// 
			// player1NameLabel
			// 
			this->player1NameLabel->AutoSize = true;
			this->player1NameLabel->Font = (gcnew System::Drawing::Font(L"Sitka Small", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->player1NameLabel->Location = System::Drawing::Point(18, 150);
			this->player1NameLabel->Name = L"player1NameLabel";
			this->player1NameLabel->Size = System::Drawing::Size(78, 24);
			this->player1NameLabel->TabIndex = 9;
			this->player1NameLabel->Text = L"Player 1";
			// 
			// player1NameInput
			// 
			this->player1NameInput->Location = System::Drawing::Point(100, 147);
			this->player1NameInput->Name = L"player1NameInput";
			this->player1NameInput->Size = System::Drawing::Size(109, 20);
			this->player1NameInput->TabIndex = 10;
			this->player1NameInput->Text = L"Biba";
			// 
			// player2NameLabel
			// 
			this->player2NameLabel->AutoSize = true;
			this->player2NameLabel->Font = (gcnew System::Drawing::Font(L"Sitka Small", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->player2NameLabel->Location = System::Drawing::Point(236, 150);
			this->player2NameLabel->Name = L"player2NameLabel";
			this->player2NameLabel->Size = System::Drawing::Size(80, 24);
			this->player2NameLabel->TabIndex = 11;
			this->player2NameLabel->Text = L"Player 2";
			// 
			// player2NameInput
			// 
			this->player2NameInput->Location = System::Drawing::Point(322, 147);
			this->player2NameInput->Name = L"player2NameInput";
			this->player2NameInput->Size = System::Drawing::Size(109, 20);
			this->player2NameInput->TabIndex = 12;
			this->player2NameInput->Text = L"Boba";
			// 
			// exitBtn
			// 
			this->exitBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->exitBtn->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 12, System::Drawing::FontStyle::Italic));
			this->exitBtn->Location = System::Drawing::Point(143, 281);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(164, 32);
			this->exitBtn->TabIndex = 13;
			this->exitBtn->Text = L"Continue game";
			this->exitBtn->UseVisualStyleBackColor = true;
			this->exitBtn->Click += gcnew System::EventHandler(this, &SettingsWindow::exitBtn_Click);
			// 
			// panel1
			// 
			this->panel1->AccessibleRole = System::Windows::Forms::AccessibleRole::RadioButton;
			this->panel1->Controls->Add(this->radioButtonPlayer);
			this->panel1->Controls->Add(this->radioButtonAI);
			this->panel1->Location = System::Drawing::Point(180, 100);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(129, 22);
			this->panel1->TabIndex = 14;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Small", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label2->Location = System::Drawing::Point(18, 200);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(112, 24);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Game starts";
			// 
			// panel2
			// 
			this->panel2->AccessibleRole = System::Windows::Forms::AccessibleRole::RadioButton;
			this->panel2->Controls->Add(this->firstMovePlayer2);
			this->panel2->Controls->Add(this->firstMovePlayer1);
			this->panel2->Location = System::Drawing::Point(180, 200);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(136, 20);
			this->panel2->TabIndex = 15;
			// 
			// firstMovePlayer2
			// 
			this->firstMovePlayer2->AutoSize = true;
			this->firstMovePlayer2->Location = System::Drawing::Point(71, 3);
			this->firstMovePlayer2->Name = L"firstMovePlayer2";
			this->firstMovePlayer2->Size = System::Drawing::Size(63, 17);
			this->firstMovePlayer2->TabIndex = 17;
			this->firstMovePlayer2->Text = L"Player 2";
			this->firstMovePlayer2->UseVisualStyleBackColor = true;
			// 
			// firstMovePlayer1
			// 
			this->firstMovePlayer1->AutoSize = true;
			this->firstMovePlayer1->Checked = true;
			this->firstMovePlayer1->Location = System::Drawing::Point(3, 3);
			this->firstMovePlayer1->Name = L"firstMovePlayer1";
			this->firstMovePlayer1->Size = System::Drawing::Size(60, 17);
			this->firstMovePlayer1->TabIndex = 16;
			this->firstMovePlayer1->TabStop = true;
			this->firstMovePlayer1->Text = L"Player1";
			this->firstMovePlayer1->UseVisualStyleBackColor = true;
			// 
			// CellsCoutnAtStart
			// 
			this->CellsCoutnAtStart->Location = System::Drawing::Point(275, 50);
			this->CellsCoutnAtStart->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 25, 0, 0, 0 });
			this->CellsCoutnAtStart->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->CellsCoutnAtStart->Name = L"CellsCoutnAtStart";
			this->CellsCoutnAtStart->Size = System::Drawing::Size(32, 20);
			this->CellsCoutnAtStart->TabIndex = 16;
			this->CellsCoutnAtStart->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->CellsCoutnAtStart->ValueChanged += gcnew System::EventHandler(this, &SettingsWindow::CellsCoutnAtStart_ValueChanged);
			// 
			// AISettingsBtn
			// 
			this->AISettingsBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->AISettingsBtn->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 12, System::Drawing::FontStyle::Italic));
			this->AISettingsBtn->Location = System::Drawing::Point(313, 281);
			this->AISettingsBtn->Name = L"AISettingsBtn";
			this->AISettingsBtn->Size = System::Drawing::Size(133, 32);
			this->AISettingsBtn->TabIndex = 17;
			this->AISettingsBtn->Text = L"AI Settings";
			this->AISettingsBtn->UseVisualStyleBackColor = true;
			this->AISettingsBtn->Click += gcnew System::EventHandler(this, &SettingsWindow::AISettingsBtn_Click);
			// 
			// SettingsWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(576, 325);
			this->Controls->Add(this->AISettingsBtn);
			this->Controls->Add(this->CellsCoutnAtStart);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->player2NameInput);
			this->Controls->Add(this->player2NameLabel);
			this->Controls->Add(this->player1NameInput);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->player1NameLabel);
			this->Controls->Add(this->Label);
			this->Controls->Add(this->CellsCountLabel);
			this->Controls->Add(this->saveBtn);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"SettingsWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"SettingsWindow";
			this->SizeChanged += gcnew System::EventHandler(this, &SettingsWindow::SettingsWindow_SizeChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CellsCoutnAtStart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void saveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		needGameRestart = true;
		player1Name = player1NameInput->Text;
		player2Name = player2NameInput->Text;
		playingAgainstHuman = radioButtonPlayer->Checked ? true : false;
		player1MoveFirst = firstMovePlayer1->Checked ? true : false;
		cellsCountAtStart = Convert::ToInt32(CellsCoutnAtStart->Value);
		AIVisionStrength = AISetWnd.AIVisionStrengthValue;
		AIAlgorithmMiniMax = AISetWnd.algorithmMiniMax ? true : false;
		this->Close();		
	}
	private: System::Void SettingsWindow_SizeChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void exitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		needGameRestart = false;
		AIVisionStrength = AISetWnd.AIVisionStrengthValue;
		AIAlgorithmMiniMax = AISetWnd.algorithmMiniMax ? true : false;
		this->Close();
	}
	private: System::Void trackBar1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		CellsCoutnAtStart->Value = trackBar1->Value;
	}
	private: System::Void CellsCoutnAtStart_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		trackBar1->Value = Convert::ToInt32(CellsCoutnAtStart->Value);
	}

	private: System::Void AISettingsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		AISetWnd.Location = Point(this->Location.X, this->Location.Y);
		AISetWnd.Width = this->ClientSize.Width;
		AISetWnd.Height = this->ClientSize.Height;
		AISetWnd.ShowDialog();
	}
};
}
