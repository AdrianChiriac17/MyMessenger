#pragma once
#include "User.h"
#include "Dashboard.h"
#include "ConversationForm.h" 
using namespace Messenger2;
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

public ref class ConversationHelper
{
public:
    String^ currUser;
    String^ selectedUser;
    User^ user;

    ConversationHelper(String^ cUser, String^ sUser, User^ u)
    {
        this->currUser = cUser;
        this->selectedUser = sUser;
        this->user = u;
    }

    static void OpenConversation(String^ currUser, String^ selectedUser, User^ user)
    {
        // Step 1: Get the conversation file name based on user names
        String^ filePath = GetFilePath(currUser, selectedUser);

        // Step 2: Check if the file exists, and create it if necessary
        if (!File::Exists(filePath))
        {
            CreateConversationFile(filePath, currUser, selectedUser);
        }

        // Step 3: Open the conversation in the form
        OpenConversationForm(currUser, selectedUser, filePath, user);
    }

    private:
    
    //This makes the strings unique and lexicographically ordered.
    static String^ GetFilePath(String^ currUser, String^ selectedUser)
    {
        String^ folderPath = "C:\\Users\\Adrian\\source\\repos\\Messenger2\\Data\\Conversations\\";

        String^ fileName;
        if (String::Compare(currUser, selectedUser) < 0)
            fileName = currUser + "_" + selectedUser + ".txt";
        else
            fileName = selectedUser + "_" + currUser + ".txt";
        String^ finalPath = folderPath + fileName;

        return finalPath;
    }


    static void CreateConversationFile(String^ fileName, String^ currentUser, String^ selectedUser)
    {
        
        String^ firstConvoString = GetFirstMessage(currentUser, selectedUser);//Function Below
        
        //Creates a file with the string I gave it as the first Message
        File::WriteAllText(fileName, firstConvoString);
    }

    static String^ GetFirstMessage(String^ currentUser, String^ selectedUser)
    {
        DateTime now = DateTime::Now;
        String^ dateTimeString = now.ToString("f");
        String^ firstMessage = "";

        if(currentUser!= selectedUser)
        {
            firstMessage = "On " + dateTimeString + ", " + currentUser +
                " began a conversation with " + selectedUser + ".\n";
        }
        else
        {
            firstMessage = "This is a conversation with yourself.\n";
        }

        return firstMessage;
    }

    static bool IsConversationAlreadyOpen(String^ selectedUser)
    {
        return ConversationForm::openConvos->Contains(selectedUser);
    }

    static void OpenConversationForm(String^ currentUser, String^ selectedUser, String^ conversationPath, User^ user)
    {
        if (IsConversationAlreadyOpen(selectedUser))
        {
            MessageBox::Show("Conversation with " + selectedUser + " is already open in the background!");
            return;
        }
        Messenger2::ConversationForm^ conversationForm = gcnew Messenger2::ConversationForm(user, selectedUser, conversationPath);
        conversationForm->Show();
    }

};