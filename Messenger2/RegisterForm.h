#pragma once
#include "User.h"
#include "DatabaseHelper.h"
#include <iostream>
namespace Messenger2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;


	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
		{
			InitializeComponent();
		}

	protected:
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnOK;

	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbRegisterUser;

	private: System::Windows::Forms::Button^ btnSwitchToLogin;
	private: System::Windows::Forms::TextBox^ tbRegisterPassword;
	private: System::Windows::Forms::TextBox^ tbRegisterRepeatPassword;

	private: System::Windows::Forms::Label^ label4;
	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbRegisterUser = (gcnew System::Windows::Forms::TextBox());
			this->btnSwitchToLogin = (gcnew System::Windows::Forms::Button());
			this->tbRegisterPassword = (gcnew System::Windows::Forms::TextBox());
			this->tbRegisterRepeatPassword = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(896, 55);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Enter a valid username and password to register!";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(21, 72);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(358, 332);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// btnCancel
			// 
			this->btnCancel->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(558, 305);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(148, 31);
			this->btnCancel->TabIndex = 13;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &RegisterForm::btnCancel_Click);
			// 
			// btnOK
			// 
			this->btnOK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOK->Location = System::Drawing::Point(404, 305);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(148, 31);
			this->btnOK->TabIndex = 12;
			this->btnOK->Text = L"Ok";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &RegisterForm::btnOK_Click);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(414, 174);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 25);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Password";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(410, 118);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(110, 25);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Username";
			// 
			// tbRegisterUser
			// 
			this->tbRegisterUser->Location = System::Drawing::Point(537, 123);
			this->tbRegisterUser->Name = L"tbRegisterUser";
			this->tbRegisterUser->Size = System::Drawing::Size(342, 20);
			this->tbRegisterUser->TabIndex = 15;
			// 
			// btnSwitchToLogin
			// 
			this->btnSwitchToLogin->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->btnSwitchToLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnSwitchToLogin->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnSwitchToLogin->Location = System::Drawing::Point(712, 304);
			this->btnSwitchToLogin->Name = L"btnSwitchToLogin";
			this->btnSwitchToLogin->Size = System::Drawing::Size(171, 31);
			this->btnSwitchToLogin->TabIndex = 16;
			this->btnSwitchToLogin->Text = L"Go back to login";
			this->btnSwitchToLogin->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnSwitchToLogin->UseVisualStyleBackColor = true;
			this->btnSwitchToLogin->Click += gcnew System::EventHandler(this, &RegisterForm::btnSwitchToLogin_Click);
			// 
			// tbRegisterPassword
			// 
			this->tbRegisterPassword->Location = System::Drawing::Point(537, 180);
			this->tbRegisterPassword->Name = L"tbRegisterPassword";
			this->tbRegisterPassword->Size = System::Drawing::Size(342, 20);
			this->tbRegisterPassword->TabIndex = 17;
			// 
			// tbRegisterRepeatPassword
			// 
			this->tbRegisterRepeatPassword->Location = System::Drawing::Point(537, 235);
			this->tbRegisterRepeatPassword->Name = L"tbRegisterRepeatPassword";
			this->tbRegisterRepeatPassword->Size = System::Drawing::Size(342, 20);
			this->tbRegisterRepeatPassword->TabIndex = 18;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(350, 228);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(181, 47);
			this->label4->TabIndex = 19;
			this->label4->Text = L"Repeat Password";
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SeaShell;
			this->ClientSize = System::Drawing::Size(920, 447);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tbRegisterRepeatPassword);
			this->Controls->Add(this->tbRegisterPassword);
			this->Controls->Add(this->btnSwitchToLogin);
			this->Controls->Add(this->tbRegisterUser);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Name = L"RegisterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RegisterForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: bool switchToLogin = false;
	private: System::Void btnSwitchToLogin_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->switchToLogin = true;
		this->Close();
	}

	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	


	public: User^ user = nullptr;
	private: System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ username = tbRegisterUser->Text;
		String^ password = tbRegisterPassword->Text;
		String^ repeatpassword = tbRegisterRepeatPassword->Text;

		if (username->Length == 0 || password->Length == 0 || repeatpassword->Length == 0)
		{
			MessageBox::Show("All of the fields are mandatory!", "Fill all the fields", MessageBoxButtons::OK);
			return;
		}

		user = nullptr;

		if (String::Compare(password, repeatpassword) != 0)
		{
			MessageBox::Show("The two password fields are different", "Error - Passwords must be the same", MessageBoxButtons::OK);
			return;
		}


		try
		{
			DatabaseHelper::RegisterUser(username, password);
			// Registration succeeded
			user = gcnew User;
			user->username = username;
			user->password = password;
			user->isActive = true;
			user->Id = DatabaseHelper::GetIdByUsername(user->username);
			//for true (in SQL) modification of isActive (have to call SetUserActive).

			this->Close();
		}
		catch (SqlException^ sqlEx)
		{
			if (sqlEx->Number == 2627) // Unique constraint error
			{
				MessageBox::Show("Username already exists. Please choose another one.", "Registration Error", MessageBoxButtons::OK);
			}
			else
			{
				MessageBox::Show("Database error: " + sqlEx->Message, "Database Error", MessageBoxButtons::OK);
			}
			return;
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("An unexpected error occurred: " + ex->Message, "Error", MessageBoxButtons::OK);
			return;
		}
	}
};
}


