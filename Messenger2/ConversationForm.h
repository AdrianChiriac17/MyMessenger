#pragma once
#include "User.h"
#include <cliext/list>

namespace Messenger2 {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	public ref class ConversationForm : public System::Windows::Forms::Form
	{
	private:
		String^ currentUserName;
		String^ selectedUser;
		String^ filePath;

	public:
		static List<String^>^ openConvos = gcnew List<String^>();

	private: System::Windows::Forms::RichTextBox^ richTextBoxConvo;
		   User^ currentUser;
	
	public:
		//CONSTRUCTOR
		ConversationForm(User^ user, String^ sUser, String^ fileP)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			//initializing of the variables
			this->currentUser = user;
			this->currentUserName = currentUser->username;
			this->selectedUser = sUser;
			this->filePath = fileP;

			//adds the current conversation to the list
			openConvos->Add(selectedUser);

			//Custom Window title
			if (currentUserName != selectedUser)
				this->Text = "Conversation with " + selectedUser;
			else
				this->Text = "Conversation with yourself!";

			//Actual Important part of the constructor
			LoadConversationFile();
		}

	protected:
		//DESTRUCTOR
		~ConversationForm()
		{
			openConvos->Remove(selectedUser);
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBoxConvo = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to this convoform";
			// 
			// richTextBoxConvo
			// 
			this->richTextBoxConvo->Location = System::Drawing::Point(23, 52);
			this->richTextBoxConvo->Name = L"richTextBoxConvo";
			this->richTextBoxConvo->Size = System::Drawing::Size(443, 350);
			this->richTextBoxConvo->TabIndex = 1;
			this->richTextBoxConvo->Text = L"";
			// 
			// ConversationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(493, 460);
			this->Controls->Add(this->richTextBoxConvo);
			this->Controls->Add(this->label1);
			this->Name = L"ConversationForm";
			this->Text = L"ConversationForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public:
		void LoadConversationFile()
		{
			try
			{
				// Read the file's content
				String^ conversationContent = File::ReadAllText(filePath);
				richTextBoxConvo->Text = conversationContent;

				// Scroll to the bottom
				richTextBoxConvo->SelectionStart = richTextBoxConvo->Text->Length;
				richTextBoxConvo->ScrollToCaret();
			}
			catch (Exception^ e)
			{
				MessageBox::Show("Failed to load conversation: " + e->Message, "Error", MessageBoxButtons::OK);
			}
		}

	};//end of class
}//end of namespace
