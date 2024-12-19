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
	using namespace System::Runtime::InteropServices;

	public ref class ConversationForm : public System::Windows::Forms::Form
	{

	private:
		Timer^ timerReloadConvo;
		String^ currentUserName;
		String^ selectedUser;
		String^ filePath;

	public:
		static List<String^>^ openConvos = gcnew List<String^>();


	private: System::Windows::Forms::RichTextBox^ richTextBoxMessage;
	private: System::Windows::Forms::Button^ sendButton;
	private: System::Windows::Forms::RichTextBox^ richTextBoxConvo;



	User^ currentUser;
	
	public:
		//CONSTRUCTOR
		ConversationForm(User^ user, String^ sUser, String^ fileP)
		{
			InitializeComponent();
			//initializing of the variables
			this->currentUser = user;
			this->currentUserName = currentUser->username;
			this->selectedUser = sUser;
			this->filePath = fileP;

			// Initialize Timer
			timerReloadConvo = gcnew Timer();
			timerReloadConvo->Interval = 100; // Set the interval to 500 milliseconds (0.5 seconds)
			timerReloadConvo->Tick += gcnew EventHandler(this, &ConversationForm::OnTimerTickReload);

			timerReloadConvo->Start();

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
				delete components;
			StopTimer();
		}

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
			this->richTextBoxMessage = (gcnew System::Windows::Forms::RichTextBox());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->richTextBoxConvo = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// richTextBoxMessage
			// 
			this->richTextBoxMessage->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBoxMessage->Location = System::Drawing::Point(13, 435);
			this->richTextBoxMessage->Name = L"richTextBoxMessage";
			this->richTextBoxMessage->Size = System::Drawing::Size(589, 36);
			this->richTextBoxMessage->TabIndex = 2;
			this->richTextBoxMessage->Text = L"";
			// 
			// sendButton
			// 
			this->sendButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->sendButton->FlatAppearance->BorderSize = 0;
			this->sendButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sendButton->Font = (gcnew System::Drawing::Font(L"Wingdings", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->sendButton->ForeColor = System::Drawing::Color::SteelBlue;
			this->sendButton->Location = System::Drawing::Point(598, 423);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(65, 64);
			this->sendButton->TabIndex = 3;
			this->sendButton->Text = L"";
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &ConversationForm::sendButton_Click);
			// 
			// richTextBoxConvo
			// 
			this->richTextBoxConvo->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->richTextBoxConvo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBoxConvo->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->richTextBoxConvo->Location = System::Drawing::Point(13, 35);
			this->richTextBoxConvo->Name = L"richTextBoxConvo";
			this->richTextBoxConvo->ReadOnly = true;
			this->richTextBoxConvo->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBoxConvo->Size = System::Drawing::Size(635, 372);
			this->richTextBoxConvo->TabIndex = 4;
			this->richTextBoxConvo->Text = L"";
			// 
			// ConversationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(675, 490);
			this->Controls->Add(this->richTextBoxConvo);
			this->Controls->Add(this->sendButton);
			this->Controls->Add(this->richTextBoxMessage);
			this->Name = L"ConversationForm";
			this->Text = L"ConversationForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	//De aici sunt functiile implementate manual
	
	public:
	//ACEASTA METODA INCARCA CONVERSATIA IN RICHTEXTBOX
	void LoadConversationFile()
	{
		try
		{
			String^ conversationContent = File::ReadAllText(filePath);
			richTextBoxConvo->Text = conversationContent;

			richTextBoxConvo->SelectionStart = richTextBoxConvo->Text->Length;
			richTextBoxConvo->ScrollToCaret();
				
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Failed to load conversation: " + e->Message, "Error", MessageBoxButtons::OK);
		}
	}

	//ACEASTA METODA INCARCA CATE O LINIE IN FIECARE FISIER
	void SaveMessageToFile()
	{
		String^ actualMessage = richTextBoxMessage->Text;
		String^ fullMessage = "";
		fullMessage = "[" + currentUserName + "]: " + actualMessage;
		fullMessage = fullMessage->TrimEnd(gcnew array<Char> {'\n', '\r', '\t'});

		// Open the file to append text
		StreamWriter^ writer = gcnew StreamWriter(filePath, true);
		writer->Write("\n" + fullMessage);
		writer->Close(); 
	}
		
	//ACEASTA FUNCTIE DECIDE CE SE INTAMPLA CAND APAS PE OK
	private: System::Void sendButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SaveMessageToFile();
		richTextBoxMessage->Clear();
	}

	//ACEASTA FUNCTIE OPRESTE TIMER-UL, este apelata in DESTRUCTOR
	public: void StopTimer()
	{
		timerReloadConvo->Stop();
	}

	//ACEASTA FUNCTIE VERIFICA DE 10 ORI PE SECUNDA DACA S AU MODIFICAT FISIERELE 
	public: void OnTimerTickReload(Object^ sender, EventArgs^ e)
	{
		String^ currentText = richTextBoxConvo->Text;

		StreamReader^ reader = gcnew StreamReader(filePath);
		String^ fileContent = reader->ReadToEnd();
		reader->Close();

		NormalizeLineEndings(currentText);
		NormalizeLineEndings(fileContent);

		if (currentText != fileContent)
		{
			//DebugDifferences(currentText, fileContent);
			LoadConversationFile();
		}
		
	}

	void NormalizeLineEndings(String^% text)
	{
		text = text->Replace("\r\n", "\n"); // Convert CRLF to LF
		text = text->Replace("\r", "\n");   // Convert CR to LF (in case any stray CRs exist)
	}

	/* FARA ASTA NU PUTEAM */
	/*
	void DebugDifferences(String^ currentText, String^ fileContent)
	{
		// Normalize line endings
		NormalizeLineEndings(currentText);
		NormalizeLineEndings(fileContent);

	    // Convert String^ to char arrays
		array<char>^ currentTextArray = gcnew array<char>(currentText->Length);
		array<char>^ fileContentArray = gcnew array<char>(fileContent->Length);

		// Copy the characters into the char arrays
		for (int i = 0; i < currentText->Length; i++)
			currentTextArray[i] = (char)currentText[i];
		for (int i = 0; i < fileContent->Length; i++)
			fileContentArray[i] = (char)fileContent[i];
		
		// Find the minimum length to avoid accessing out of bounds
		int minLength = Math::Min(currentTextArray->Length, fileContentArray->Length);

		// Check each character in both arrays
		for (int i = 0; i < minLength; i++)
		{
			if (currentTextArray[i] != fileContentArray[i])
			{
				// Print the position and the ASCII values of the differing characters
				System::Diagnostics::Debug::WriteLine("Difference at position " + i);
				System::Diagnostics::Debug::WriteLine("RichTextBox character: '" + currentTextArray[i] + "' ASCII: " + (int)currentTextArray[i]);
				System::Diagnostics::Debug::WriteLine("File Content character: '" + fileContentArray[i] + "' ASCII: " + (int)fileContentArray[i]);
				break;  // Stop after the first difference
			}
		}

		// If one string is longer than the other, log that too
		if (currentTextArray->Length != fileContentArray->Length)
		{
			System::Diagnostics::Debug::WriteLine("Strings have different lengths!");
			System::Diagnostics::Debug::WriteLine("RichTextBox length: " + currentTextArray->Length);
			System::Diagnostics::Debug::WriteLine("File Content length: " + fileContentArray->Length);
		}

		System::Diagnostics::Debug::WriteLine("Fair enough, n ai diferente"); 
	}
	*/
	
};//end of class
}//end of namespace
