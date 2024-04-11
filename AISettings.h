#pragma once

namespace KF2PD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AISettings
	/// </summary>
	public ref class AISettings : public System::Windows::Forms::Form
	{
	public:
		AISettings(void)
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
		~AISettings()
		{
			if (components)
			{
				delete components;
			}
		}
	public:
		bool algorithmMiniMax = true;
		int AIVisionStrengthValue = 3;

	private: System::Windows::Forms::Button^ saveBtn;
	private: System::Windows::Forms::Button^ exitBtn;
	private: System::Windows::Forms::Label^ Label;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ radioButtonMinMax;
	private: System::Windows::Forms::RadioButton^ radioButtonAlphaBeta;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::NumericUpDown^ AIVisionStrength;






	protected:

	private:
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
			this->exitBtn = (gcnew System::Windows::Forms::Button());
			this->Label = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->radioButtonAlphaBeta = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonMinMax = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->AIVisionStrength = (gcnew System::Windows::Forms::NumericUpDown());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AIVisionStrength))->BeginInit();
			this->SuspendLayout();
			// 
			// saveBtn
			// 
			this->saveBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->saveBtn->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->saveBtn->Location = System::Drawing::Point(22, 281);
			this->saveBtn->Name = L"saveBtn";
			this->saveBtn->Size = System::Drawing::Size(115, 32);
			this->saveBtn->TabIndex = 13;
			this->saveBtn->Text = L"Save";
			this->saveBtn->UseVisualStyleBackColor = true;
			this->saveBtn->Click += gcnew System::EventHandler(this, &AISettings::saveBtn_Click);
			// 
			// exitBtn
			// 
			this->exitBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->exitBtn->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exitBtn->Location = System::Drawing::Point(143, 281);
			this->exitBtn->Name = L"exitBtn";
			this->exitBtn->Size = System::Drawing::Size(115, 32);
			this->exitBtn->TabIndex = 13;
			this->exitBtn->Text = L"Cancel";
			this->exitBtn->UseVisualStyleBackColor = true;
			this->exitBtn->Click += gcnew System::EventHandler(this, &AISettings::exitBtn_Click);
			// 
			// Label
			// 
			this->Label->AutoSize = true;
			this->Label->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 14, System::Drawing::FontStyle::Italic));
			this->Label->Location = System::Drawing::Point(18, 9);
			this->Label->Name = L"Label";
			this->Label->Size = System::Drawing::Size(119, 23);
			this->Label->TabIndex = 3;
			this->Label->Text = L"AI Settings";
			// 
			// panel1
			// 
			this->panel1->AccessibleRole = System::Windows::Forms::AccessibleRole::RadioButton;
			this->panel1->Controls->Add(this->radioButtonAlphaBeta);
			this->panel1->Controls->Add(this->radioButtonMinMax);
			this->panel1->Location = System::Drawing::Point(180, 95);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(148, 20);
			this->panel1->TabIndex = 14;
			// 
			// radioButtonAlphaBeta
			// 
			this->radioButtonAlphaBeta->AutoSize = true;
			this->radioButtonAlphaBeta->Location = System::Drawing::Point(73, 3);
			this->radioButtonAlphaBeta->Name = L"radioButtonAlphaBeta";
			this->radioButtonAlphaBeta->Size = System::Drawing::Size(77, 17);
			this->radioButtonAlphaBeta->TabIndex = 7;
			this->radioButtonAlphaBeta->Text = L"Alpha-Beta";
			this->radioButtonAlphaBeta->UseVisualStyleBackColor = true;
			// 
			// radioButtonMinMax
			// 
			this->radioButtonMinMax->AutoSize = true;
			this->radioButtonMinMax->Checked = true;
			this->radioButtonMinMax->Location = System::Drawing::Point(3, 3);
			this->radioButtonMinMax->Name = L"radioButtonMinMax";
			this->radioButtonMinMax->Size = System::Drawing::Size(64, 17);
			this->radioButtonMinMax->TabIndex = 6;
			this->radioButtonMinMax->TabStop = true;
			this->radioButtonMinMax->Text = L"MiniMax";
			this->radioButtonMinMax->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Small", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->label1->Location = System::Drawing::Point(18, 100);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 24);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Algorithm";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Small", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(18, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(155, 24);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Forward forecast";
			// 
			// trackBar1
			// 
			this->trackBar1->LargeChange = 1;
			this->trackBar1->Location = System::Drawing::Point(180, 50);
			this->trackBar1->Maximum = 4;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(91, 45);
			this->trackBar1->TabIndex = 4;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar1->Value = 3;
			this->trackBar1->ValueChanged += gcnew System::EventHandler(this, &AISettings::trackBar1_ValueChanged);
			// 
			// AIVisionStrength
			// 
			this->AIVisionStrength->Location = System::Drawing::Point(277, 50);
			this->AIVisionStrength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->AIVisionStrength->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->AIVisionStrength->Name = L"AIVisionStrength";
			this->AIVisionStrength->Size = System::Drawing::Size(32, 20);
			this->AIVisionStrength->TabIndex = 16;
			this->AIVisionStrength->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->AIVisionStrength->ValueChanged += gcnew System::EventHandler(this, &AISettings::AIVisionStrength_ValueChanged);
			// 
			// AISettings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(576, 325);
			this->Controls->Add(this->AIVisionStrength);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->Label);
			this->Controls->Add(this->exitBtn);
			this->Controls->Add(this->saveBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AISettings";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"AISettings";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->AIVisionStrength))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void trackBar1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		AIVisionStrength->Value = trackBar1->Value;
	}
	private: System::Void AIVisionStrength_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		trackBar1->Value = Convert::ToInt32(AIVisionStrength->Value);
	}
	private: System::Void saveBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		algorithmMiniMax = radioButtonMinMax->Checked ? true : false;
		AIVisionStrengthValue = Convert::ToInt32(AIVisionStrength->Value);
		this->Close();
	}
	private: System::Void exitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}