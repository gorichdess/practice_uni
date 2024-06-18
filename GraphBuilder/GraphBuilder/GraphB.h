#pragma once
#include "Graph.h"
#include <list>

namespace GraphBuilder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GraphB
	/// </summary>
	public ref class GraphB : public System::Windows::Forms::Form
	{
	private:
		String^ selectedFile;
		String^ selectedGraph;
		Color graphColor = Color::DarkBlue;
		float zoomX = 1;
		float zoomY = 1;

	private: System::IO::FileSystemWatcher^ fileSystemWatcher1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ XzoomNeg;

	private: System::Windows::Forms::Button^ XzooomPos;
	private: System::Windows::Forms::Button^ YzoomNeg;


	private: System::Windows::Forms::Button^ YzoomPos;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ Clear;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::Button^ chooseColor;
	private: System::Windows::Forms::ComboBox^ selectGraph;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ yMove;
	private: System::Windows::Forms::Button^ moveButton;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::TextBox^ xMove;



		   Generic::List<Graph^>^ graphs = gcnew Generic::List<Graph^>();

	public:
		GraphB(void)
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
		~GraphB()
		{
			if (components)
			{
				delete components;
			}
		}

		virtual bool ProcessCmdKey(Message% msg, Keys keyData) override
		{
			// Перехват нажатий стрелок и предотвращение их обработки для перемещения фокуса
			if (keyData == Keys::Right || keyData == Keys::Left || keyData == Keys::Up || keyData == Keys::Down)
			{
				OnKeyDown(gcnew KeyEventArgs(keyData));
				return true; 
			}

			return Form::ProcessCmdKey(msg, keyData);
		}

	private: System::Windows::Forms::Button^ openFileButton;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ okButton;
	private: System::Windows::Forms::TextBox^ textBox1;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GraphB::typeid));
			this->openFileButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->XzooomPos = (gcnew System::Windows::Forms::Button());
			this->XzoomNeg = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->YzoomPos = (gcnew System::Windows::Forms::Button());
			this->YzoomNeg = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Clear = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->chooseColor = (gcnew System::Windows::Forms::Button());
			this->selectGraph = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->xMove = (gcnew System::Windows::Forms::TextBox());
			this->yMove = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->moveButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileButton
			// 
			this->openFileButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->openFileButton->AutoSize = true;
			this->openFileButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->openFileButton->Location = System::Drawing::Point(637, 77);
			this->openFileButton->Name = L"openFileButton";
			this->openFileButton->Size = System::Drawing::Size(161, 51);
			this->openFileButton->TabIndex = 0;
			this->openFileButton->Text = L"Open File";
			this->openFileButton->UseVisualStyleBackColor = true;
			this->openFileButton->Click += gcnew System::EventHandler(this, &GraphB::openFileButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 600);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// okButton
			// 
			this->okButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->okButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13));
			this->okButton->Location = System::Drawing::Point(637, 198);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(161, 61);
			this->okButton->TabIndex = 2;
			this->okButton->Text = L"Ok";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &GraphB::okButton_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->BackColor = System::Drawing::SystemColors::Window;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13));
			this->textBox1->Location = System::Drawing::Point(623, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(188, 31);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &GraphB::textBox1_TextChanged);
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 618);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(600, 92);
			this->flowLayoutPanel1->TabIndex = 5;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GraphB::flowLayoutPanel1_Paint);
			// 
			// XzooomPos
			// 
			this->XzooomPos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->XzooomPos->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 25.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->XzooomPos->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->XzooomPos->Location = System::Drawing::Point(623, 402);
			this->XzooomPos->Name = L"XzooomPos";
			this->XzooomPos->Size = System::Drawing::Size(50, 50);
			this->XzooomPos->TabIndex = 6;
			this->XzooomPos->Text = L"+";
			this->XzooomPos->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->XzooomPos->UseVisualStyleBackColor = true;
			this->XzooomPos->Click += gcnew System::EventHandler(this, &GraphB::XzoomPos_Click);
			// 
			// XzoomNeg
			// 
			this->XzoomNeg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->XzoomNeg->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->XzoomNeg->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->XzoomNeg->Location = System::Drawing::Point(672, 402);
			this->XzoomNeg->Name = L"XzoomNeg";
			this->XzoomNeg->Padding = System::Windows::Forms::Padding(8, 0, 0, 0);
			this->XzoomNeg->Size = System::Drawing::Size(50, 50);
			this->XzoomNeg->TabIndex = 7;
			this->XzoomNeg->Text = L"-";
			this->XzoomNeg->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->XzoomNeg->UseVisualStyleBackColor = true;
			this->XzoomNeg->Click += gcnew System::EventHandler(this, &GraphB::XzoomNeg_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(623, 369);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 30);
			this->label1->TabIndex = 8;
			this->label1->Text = L"X zoom";
			// 
			// YzoomPos
			// 
			this->YzoomPos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->YzoomPos->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 25.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->YzoomPos->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->YzoomPos->Location = System::Drawing::Point(742, 402);
			this->YzoomPos->Name = L"YzoomPos";
			this->YzoomPos->Size = System::Drawing::Size(50, 50);
			this->YzoomPos->TabIndex = 9;
			this->YzoomPos->Text = L"+";
			this->YzoomPos->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->YzoomPos->UseVisualStyleBackColor = true;
			this->YzoomPos->Click += gcnew System::EventHandler(this, &GraphB::YzoomPos_Click);
			// 
			// YzoomNeg
			// 
			this->YzoomNeg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->YzoomNeg->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->YzoomNeg->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->YzoomNeg->Location = System::Drawing::Point(791, 402);
			this->YzoomNeg->Name = L"YzoomNeg";
			this->YzoomNeg->Padding = System::Windows::Forms::Padding(8, 0, 0, 0);
			this->YzoomNeg->Size = System::Drawing::Size(50, 50);
			this->YzoomNeg->TabIndex = 10;
			this->YzoomNeg->Text = L"-";
			this->YzoomNeg->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->YzoomNeg->UseVisualStyleBackColor = true;
			this->YzoomNeg->Click += gcnew System::EventHandler(this, &GraphB::YzoomNeg_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(742, 369);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 30);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Y zoom";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(618, 339);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(247, 30);
			this->label3->TabIndex = 12;
			this->label3->Text = L"--------------------------";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(666, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(126, 25);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Graph name";
			this->label4->Click += gcnew System::EventHandler(this, &GraphB::label4_Click);
			// 
			// Clear
			// 
			this->Clear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Clear->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Clear->Location = System::Drawing::Point(637, 298);
			this->Clear->Name = L"Clear";
			this->Clear->Size = System::Drawing::Size(161, 38);
			this->Clear->TabIndex = 14;
			this->Clear->Text = L"Clear";
			this->Clear->UseVisualStyleBackColor = true;
			this->Clear->Click += gcnew System::EventHandler(this, &GraphB::Clear_Click);
			// 
			// chooseColor
			// 
			this->chooseColor->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->chooseColor->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->chooseColor->Location = System::Drawing::Point(637, 134);
			this->chooseColor->Name = L"chooseColor";
			this->chooseColor->Size = System::Drawing::Size(161, 58);
			this->chooseColor->TabIndex = 15;
			this->chooseColor->Text = L"Color";
			this->chooseColor->UseVisualStyleBackColor = true;
			this->chooseColor->Click += gcnew System::EventHandler(this, &GraphB::chooseColor_Click);
			// 
			// selectGraph
			// 
			this->selectGraph->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->selectGraph->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->selectGraph->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->selectGraph->FormattingEnabled = true;
			this->selectGraph->Location = System::Drawing::Point(623, 489);
			this->selectGraph->Name = L"selectGraph";
			this->selectGraph->Size = System::Drawing::Size(188, 32);
			this->selectGraph->TabIndex = 16;
			this->selectGraph->SelectedIndexChanged += gcnew System::EventHandler(this, &GraphB::selectGraph_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(662, 461);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(130, 25);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Select Graph";
			// 
			// xMove
			// 
			this->xMove->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->xMove->BackColor = System::Drawing::SystemColors::Window;
			this->xMove->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13));
			this->xMove->Location = System::Drawing::Point(710, 555);
			this->xMove->Name = L"xMove";
			this->xMove->Size = System::Drawing::Size(101, 31);
			this->xMove->TabIndex = 18;
			// 
			// yMove
			// 
			this->yMove->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->yMove->BackColor = System::Drawing::SystemColors::Window;
			this->yMove->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13));
			this->yMove->Location = System::Drawing::Point(710, 592);
			this->yMove->Name = L"yMove";
			this->yMove->Size = System::Drawing::Size(101, 31);
			this->yMove->TabIndex = 19;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(694, 524);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(61, 25);
			this->label6->TabIndex = 20;
			this->label6->Text = L"Move";
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(644, 561);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 25);
			this->label7->TabIndex = 21;
			this->label7->Text = L"X";
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(644, 598);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(29, 25);
			this->label8->TabIndex = 22;
			this->label8->Text = L"Y";
			// 
			// moveButton
			// 
			this->moveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->moveButton->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->moveButton->Location = System::Drawing::Point(637, 643);
			this->moveButton->Name = L"moveButton";
			this->moveButton->Size = System::Drawing::Size(161, 39);
			this->moveButton->TabIndex = 23;
			this->moveButton->Text = L"Move";
			this->moveButton->UseVisualStyleBackColor = true;
			this->moveButton->Click += gcnew System::EventHandler(this, &GraphB::moveButton_Click);
			// 
			// GraphB
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(837, 722);
			this->Controls->Add(this->moveButton);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->yMove);
			this->Controls->Add(this->xMove);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->selectGraph);
			this->Controls->Add(this->chooseColor);
			this->Controls->Add(this->Clear);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->YzoomNeg);
			this->Controls->Add(this->YzoomPos);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->XzoomNeg);
			this->Controls->Add(this->XzooomPos);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->okButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->openFileButton);
			this->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MinimumSize = System::Drawing::Size(843, 769);
			this->Name = L"GraphB";
			this->Text = L"Graph Builder";
			this->Load += gcnew System::EventHandler(this, &GraphB::GraphB_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
			this->KeyDown += gcnew KeyEventHandler(this, &GraphB::Graph_KeyDown);

		}
#pragma endregion
	private: System::Void openFileButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void GraphB_Load(System::Object^ sender, System::EventArgs^ e);
    private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void okButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: void BuildGraph();
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e){}
    private: System::Void XzoomPos_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void XzoomNeg_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void YzoomPos_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void YzoomNeg_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
    private: System::Void Clear_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void chooseColor_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void selectGraph_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	private: void InitializeComboBox();
	private: System::Void moveButton_Click(System::Object^ sender, System::EventArgs^ e);
    private:  void Graph_KeyDown(Object^ sender, KeyEventArgs^ e);
};
}
