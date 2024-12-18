#pragma once
#include "User.h"
#include "DatabaseHelper.h"
namespace Messenger2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;


	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		///CONSTRUCTOR
		LoginForm(void)
		{
			InitializeComponent();
		}

	protected:
		///DESTRUCTOR
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ Loginintoacc;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbUsername;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::Button^ btnOK;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnCreateAccount;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->Loginintoacc = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbUsername = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnCreateAccount = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// Loginintoacc
			// 
			this->Loginintoacc->Font = (gcnew System::Drawing::Font(L"Segoe UI", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Loginintoacc->Location = System::Drawing::Point(12, 61);
			this->Loginintoacc->Name = L"Loginintoacc";
			this->Loginintoacc->Size = System::Drawing::Size(544, 50);
			this->Loginintoacc->TabIndex = 0;
			this->Loginintoacc->Text = L"Login into account";
			this->Loginintoacc->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(37, 159);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Username";
			// 
			// tbUsername
			// 
			this->tbUsername->Location = System::Drawing::Point(165, 156);
			this->tbUsername->Name = L"tbUsername";
			this->tbUsername->Size = System::Drawing::Size(325, 31);
			this->tbUsername->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(37, 217);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password";
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(165, 214);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->PasswordChar = '*';
			this->tbPassword->Size = System::Drawing::Size(325, 31);
			this->tbPassword->TabIndex = 4;
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(165, 283);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(148, 31);
			this->btnOK->TabIndex = 5;
			this->btnOK->Text = L"Ok";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &LoginForm::btnOK_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->btnCancel->Location = System::Drawing::Point(342, 283);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(148, 31);
			this->btnCancel->TabIndex = 6;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &LoginForm::btnCancel_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(535, 66);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(358, 332);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// btnCreateAccount
			// 
			this->btnCreateAccount->Location = System::Drawing::Point(36, 355);
			this->btnCreateAccount->Name = L"btnCreateAccount";
			this->btnCreateAccount->Size = System::Drawing::Size(453, 41);
			this->btnCreateAccount->TabIndex = 8;
			this->btnCreateAccount->Text = L"Don\'t have an account\? Create one!";
			this->btnCreateAccount->UseVisualStyleBackColor = true;
			this->btnCreateAccount->Click += gcnew System::EventHandler(this, &LoginForm::btnCreateAccount_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SeaShell;
			this->ClientSize = System::Drawing::Size(920, 447);
			this->Controls->Add(this->btnCreateAccount);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tbUsername);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Loginintoacc);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"LoginForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LoginForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

public: User^ user = nullptr;

//ACEST BUTON INCHIDE LOGIN-UL
private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

//ACEST BUTON VERIFICA LOGINUL
private: System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ username = this->tbUsername->Text;
	String^ password = this->tbPassword->Text;

	//logica de validare
	if (username->Length == 0 || password->Length == 0)
	{
		MessageBox::Show("Username or Password fields are empty!", "Please enter mail and pass", MessageBoxButtons::OK);
		return;
	}

	user = nullptr;
	try {
		user = DatabaseHelper::AuthenticateUser(username, password);
		if (user != nullptr) {
			this->Close(); //inchidem aceasta fereastra, ne ducem la dashboard
		}
		else {
			MessageBox::Show("Invalid username or password", "Login Failed", MessageBoxButtons::OK);
		}
	}
	catch (Exception^ e) {
		MessageBox::Show("Database error: " + e->Message, "Error", MessageBoxButtons::OK);
	}
}

//ACEST BUTON NE TRECE DE LA FORMUL DE LOGIN LA FORMUL DE REGISTER
public: bool switchToRegister = false;
private: System::Void btnCreateAccount_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->switchToRegister = true;
	this->Close();
}

};
}
