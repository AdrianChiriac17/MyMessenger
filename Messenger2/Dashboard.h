#pragma once
#using <System.dll>
#include "DatabaseHelper.h"
#include "ConversationHelper.h"
#include "User.h"
#include "RecentConvos.h"

namespace Messenger2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{

	/// TIMER FOR THE LISTS TO UPDATE 2 TIMES PER SECOND
	private: System::Windows::Forms::Timer^ updateUserListsTimer;


	///USER FOR THIS SPECIFIC SESSION
	private: User^ currentUser;

	///CONSTRUCTOR
	public:
		Dashboard(User^ user)
		{
			InitializeComponent();
			this->currentUser = user;
			lbWelcome->Text = "Welcome back, " + user->username + "!";
		}

	///DESTRUCTOR
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ lbWelcome;
	private: System::Windows::Forms::Label^ lbUserlist;
	private: System::Windows::Forms::Label^ lbActiveUsers;
	private: System::Windows::Forms::ListBox^ listboxActiveUsers;
	private: System::Windows::Forms::Label^ lbAllUsers;
	private: System::Windows::Forms::ListBox^ listboxAllUsers;
	private: System::Windows::Forms::Label^ lbTutorialDM;

	private: System::Windows::Forms::Button^ btnRefreshAllUserList;

	protected:

	protected:

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
			this->lbWelcome = (gcnew System::Windows::Forms::Label());
			this->lbUserlist = (gcnew System::Windows::Forms::Label());
			this->lbActiveUsers = (gcnew System::Windows::Forms::Label());
			this->listboxActiveUsers = (gcnew System::Windows::Forms::ListBox());
			this->lbAllUsers = (gcnew System::Windows::Forms::Label());
			this->listboxAllUsers = (gcnew System::Windows::Forms::ListBox());
			this->lbTutorialDM = (gcnew System::Windows::Forms::Label());
			this->btnRefreshAllUserList = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbWelcome
			// 
			this->lbWelcome->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbWelcome->Location = System::Drawing::Point(12, 8);
			this->lbWelcome->Name = L"lbWelcome";
			this->lbWelcome->Size = System::Drawing::Size(1148, 54);
			this->lbWelcome->TabIndex = 0;
			this->lbWelcome->Text = L"Welcome back";
			this->lbWelcome->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbUserlist
			// 
			this->lbUserlist->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbUserlist->Location = System::Drawing::Point(898, 9);
			this->lbUserlist->Name = L"lbUserlist";
			this->lbUserlist->Size = System::Drawing::Size(254, 55);
			this->lbUserlist->TabIndex = 1;
			this->lbUserlist->Text = L"User list";
			this->lbUserlist->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbActiveUsers
			// 
			this->lbActiveUsers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbActiveUsers->Location = System::Drawing::Point(894, 77);
			this->lbActiveUsers->Name = L"lbActiveUsers";
			this->lbActiveUsers->Size = System::Drawing::Size(144, 27);
			this->lbActiveUsers->TabIndex = 2;
			this->lbActiveUsers->Text = L"Active Users:";
			// 
			// listboxActiveUsers
			// 
			this->listboxActiveUsers->Enabled = false;
			this->listboxActiveUsers->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listboxActiveUsers->FormattingEnabled = true;
			this->listboxActiveUsers->ItemHeight = 25;
			this->listboxActiveUsers->Location = System::Drawing::Point(898, 111);
			this->listboxActiveUsers->Name = L"listboxActiveUsers";
			this->listboxActiveUsers->Size = System::Drawing::Size(254, 404);
			this->listboxActiveUsers->TabIndex = 3;
			// 
			// lbAllUsers
			// 
			this->lbAllUsers->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbAllUsers->Location = System::Drawing::Point(14, 126);
			this->lbAllUsers->Name = L"lbAllUsers";
			this->lbAllUsers->Size = System::Drawing::Size(144, 27);
			this->lbAllUsers->TabIndex = 4;
			this->lbAllUsers->Text = L"All Users:";
			// 
			// listboxAllUsers
			// 
			this->listboxAllUsers->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listboxAllUsers->FormattingEnabled = true;
			this->listboxAllUsers->ItemHeight = 25;
			this->listboxAllUsers->Location = System::Drawing::Point(19, 156);
			this->listboxAllUsers->Name = L"listboxAllUsers";
			this->listboxAllUsers->Size = System::Drawing::Size(781, 354);
			this->listboxAllUsers->TabIndex = 5;
			this->listboxAllUsers->SelectedIndexChanged += gcnew System::EventHandler(this, &Dashboard::listboxAllUsers_SelectedIndexChanged);
			// 
			// lbTutorialDM
			// 
			this->lbTutorialDM->AutoSize = true;
			this->lbTutorialDM->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTutorialDM->Location = System::Drawing::Point(14, 62);
			this->lbTutorialDM->Name = L"lbTutorialDM";
			this->lbTutorialDM->Size = System::Drawing::Size(754, 25);
			this->lbTutorialDM->TabIndex = 6;
			this->lbTutorialDM->Text = L"To start a new conversation, double-click one of the users from the All Users lis"
				L"t.";
			// 
			// btnRefreshAllUserList
			// 
			this->btnRefreshAllUserList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnRefreshAllUserList->Location = System::Drawing::Point(323, 531);
			this->btnRefreshAllUserList->Name = L"btnRefreshAllUserList";
			this->btnRefreshAllUserList->Size = System::Drawing::Size(173, 37);
			this->btnRefreshAllUserList->TabIndex = 8;
			this->btnRefreshAllUserList->Text = L"Refresh All Users";
			this->btnRefreshAllUserList->UseVisualStyleBackColor = true;
			this->btnRefreshAllUserList->Click += gcnew System::EventHandler(this, &Dashboard::btnRefreshAllUserList_Click);
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SeaShell;
			this->ClientSize = System::Drawing::Size(1172, 601);
			this->Controls->Add(this->btnRefreshAllUserList);
			this->Controls->Add(this->lbTutorialDM);
			this->Controls->Add(this->listboxAllUsers);
			this->Controls->Add(this->lbAllUsers);
			this->Controls->Add(this->listboxActiveUsers);
			this->Controls->Add(this->lbActiveUsers);
			this->Controls->Add(this->lbUserlist);
			this->Controls->Add(this->lbWelcome);
			this->Name = L"Dashboard";
			this->Text = L"Dashboard";
			this->Load += gcnew System::EventHandler(this, &Dashboard::Dashboard_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void Dashboard_Load(System::Object^ sender, System::EventArgs^ e)
	{
		updateUserListsTimer = gcnew System::Windows::Forms::Timer();
		updateUserListsTimer->Interval = 1000;
		//1000 means 1 second
		updateUserListsTimer->Tick += gcnew EventHandler(this, &Dashboard::UpdateActiveUserList);
		updateUserListsTimer->Start();
		
		LoadUserLists();
	};

	private: System::Void UpdateActiveUserList(System::Object^ sender, System::EventArgs^ e)
	{
		listboxActiveUsers->Items->Clear();
		List<String^>^ activeUsers = DatabaseHelper::GetActiveUsers();
		for each (String ^ user in activeUsers)
		{
			listboxActiveUsers->Items->Add(user);
		}
	}

	private: System::Void DashboardForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
	{
		updateUserListsTimer->Stop();
	}

	public: void LoadUserLists()
	{
		// Clear existing items from ListBoxes
		listboxActiveUsers->Items->Clear();
		listboxAllUsers->Items->Clear();

		// Get the lists of active users and all users from DatabaseHelper
		List<String^>^ activeUsers = DatabaseHelper::GetActiveUsers();
		List<String^>^ allUsers = DatabaseHelper::GetAllUsers();

		// Add active users to ListBox1 (Active Users)
		for each (String ^ user in activeUsers)
		{
			listboxActiveUsers->Items->Add(user);
		}

		// Add all users to ListBox2 (All Users)
		for each (String ^ user in allUsers)
		{
			listboxAllUsers->Items->Add(user);
		}
	}

	//In case someone creates an account while another session is open
	private: System::Void btnRefreshAllUserList_Click(System::Object^ sender, System::EventArgs^ e)
	{
		LoadUserLists();
	}

	private: System::Void listboxAllUsers_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (listboxAllUsers->SelectedItem != nullptr)
		{
			String^ selectedUserstr = listboxAllUsers->SelectedItem->ToString();
			String^ currentUserstr = currentUser->username;
			ConversationHelper::OpenConversation(currentUserstr, selectedUserstr, currentUser);
		}
	}



private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	RecentConversations::DisplayRecentConversations(currentUser->username);
}
};//end of class

}//end of namespace
