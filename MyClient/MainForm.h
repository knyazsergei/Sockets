#pragma once
#include "Sock_manager.h"

namespace MyClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: bool connected = false;
	private: System::Windows::Forms::Button^  sendButton;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  varAInput;
	private: System::Windows::Forms::TextBox^  varBInput;


	private: System::Windows::Forms::Label^  label2;

	private:Sock_manager m_sockManager;
	private: System::Windows::Forms::TextBox^  ipInput;
	private: System::Windows::Forms::TextBox^  portInput;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  connectButton;
	private: System::Windows::Forms::Label^  resultLabel;
	private: System::Windows::Forms::Label^  label5;

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
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->varAInput = (gcnew System::Windows::Forms::TextBox());
			this->varBInput = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->ipInput = (gcnew System::Windows::Forms::TextBox());
			this->portInput = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->connectButton = (gcnew System::Windows::Forms::Button());
			this->resultLabel = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// sendButton
			// 
			this->sendButton->Location = System::Drawing::Point(66, 63);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(75, 23);
			this->sendButton->TabIndex = 0;
			this->sendButton->Text = L"Send";
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Visible = false;
			this->sendButton->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"a:";
			this->label1->Visible = false;
			// 
			// varAInput
			// 
			this->varAInput->Location = System::Drawing::Point(66, 6);
			this->varAInput->Name = L"varAInput";
			this->varAInput->Size = System::Drawing::Size(100, 20);
			this->varAInput->TabIndex = 2;
			this->varAInput->Text = L"10";
			this->varAInput->Visible = false;
			this->varAInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::varAInput_KeyPress);
			// 
			// varBInput
			// 
			this->varBInput->Location = System::Drawing::Point(66, 37);
			this->varBInput->Name = L"varBInput";
			this->varBInput->Size = System::Drawing::Size(100, 20);
			this->varBInput->TabIndex = 4;
			this->varBInput->Text = L"7";
			this->varBInput->Visible = false;
			this->varBInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::varBInput_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(35, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"b:";
			this->label2->Visible = false;
			// 
			// ipInput
			// 
			this->ipInput->Location = System::Drawing::Point(66, 37);
			this->ipInput->Name = L"ipInput";
			this->ipInput->Size = System::Drawing::Size(100, 20);
			this->ipInput->TabIndex = 5;
			this->ipInput->Text = L"127.0.0.1";
			this->ipInput->TextChanged += gcnew System::EventHandler(this, &MainForm::ipInput_TextChanged);
			this->ipInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::ipInput_KeyPress);
			// 
			// portInput
			// 
			this->portInput->Location = System::Drawing::Point(66, 6);
			this->portInput->Name = L"portInput";
			this->portInput->Size = System::Drawing::Size(100, 20);
			this->portInput->TabIndex = 6;
			this->portInput->Text = L"90";
			this->portInput->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::portInput_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 40);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Ip";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(25, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(26, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Port";
			// 
			// connectButton
			// 
			this->connectButton->Location = System::Drawing::Point(66, 63);
			this->connectButton->Name = L"connectButton";
			this->connectButton->Size = System::Drawing::Size(75, 23);
			this->connectButton->TabIndex = 9;
			this->connectButton->Text = L"connect";
			this->connectButton->UseVisualStyleBackColor = true;
			this->connectButton->Click += gcnew System::EventHandler(this, &MainForm::connectButton_Click);
			// 
			// resultLabel
			// 
			this->resultLabel->AutoSize = true;
			this->resultLabel->Location = System::Drawing::Point(80, 102);
			this->resultLabel->Name = L"resultLabel";
			this->resultLabel->Size = System::Drawing::Size(0, 13);
			this->resultLabel->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(25, 102);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(40, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Result:";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(214, 132);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->resultLabel);
			this->Controls->Add(this->connectButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->portInput);
			this->Controls->Add(this->ipInput);
			this->Controls->Add(this->varBInput);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->varAInput);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->sendButton);
			this->Name = L"MainForm";
			this->Text = L"Client";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		m_sockManager.SendInfo(varAInput->Text, varBInput->Text);

		connected = false;
		connectButton->Show();
		ipInput->Show();
		portInput->Show();
		label3->Show();
		label4->Show();

		sendButton->Hide();
		varAInput->Hide();
		varBInput->Hide();
		label1->Hide();
		label2->Hide();

		resultLabel->Text = m_sockManager.ReturnAnswer();
	}
private: System::Void connectButton_Click(System::Object^  sender, System::EventArgs^  e) {
	System::String ^ ip = ipInput->Text;
	System::String ^ port = portInput->Text;
	m_sockManager.Init(ip, port);
	connected = true;
	connectButton->Hide();
	ipInput->Hide();
	portInput->Hide();
	label3->Hide();
	label4->Hide();

	sendButton->Show();
	varAInput->Show();
	varBInput->Show();
	label1->Show();
	label2->Show();
}
private: System::Void varBInput_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) &&
			(e->KeyChar != ','))
		{
			e->Handled = true;
		}

}
private: System::Void varAInput_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) &&
		(e->KeyChar != ','))
	{
		e->Handled = true;
	}
	
}
private: System::Void portInput_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar))
	{
		e->Handled = true;
	}
}
private: System::Void ipInput_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ipInput_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (!Char::IsControl(e->KeyChar) && !Char::IsDigit(e->KeyChar) &&
		(e->KeyChar != '.'))
	{
		e->Handled = true;
	}
}
};
}
