using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

public ref class RecentConversations
{
public:
    static void DisplayRecentConversations(String^ currentUser)
    {
        // List of recent conversations
        List<String^>^ recentConvos = gcnew List<String^>();

        // Path where the conversation files are stored
        String^ convoDirectory = "C:\\Users\\Adrian\\source\\repos\\Messenger2\\Data\\Conversations";

        // Get all files in the directory
        array<String^>^ convoFiles = Directory::GetFiles(convoDirectory, "*.txt");

        for each (String ^ convoFile in convoFiles)
        {
            // Read the conversation file
            String^ fileContent = File::ReadAllText(convoFile);

            // Split the file content into lines
            array<String^>^ lines = fileContent->Split('\n');

            // Check if the file contains the current user's name
            if (lines->Length > 0 && lines[0]->Contains(currentUser))
            {
                // Extract the other user's name (assuming the name is right after user1)
                String^ otherUser = ExtractOtherUser(convoFile, currentUser);

                // Get the last message from the conversation
                String^ lastMessage = GetLastMessage(lines, currentUser, otherUser);

                // Format the output
                String^ displayText = otherUser + "\n" + "[" + currentUser + "]: " + lastMessage;
                recentConvos->Add(displayText);
            }
        }

        // Display the recent conversations
        System::Diagnostics::Debug::WriteLine("RECENT CONVERSATIONS");
        for each (String ^ convo in recentConvos)
        {
            System::Diagnostics::Debug::WriteLine(convo);
            System::Diagnostics::Debug::WriteLine("\n");
        }
    }

private:
    // Extract the other user's name from the conversation file
    static String^ ExtractOtherUser(String^ convoFile, String^ currentUser)
    {
        // Assuming the file name follows a pattern like "user1-user2.txt"
        array<String^>^ fileNameParts = convoFile->Split('-');
        if (fileNameParts[0] == currentUser)
        {
            return fileNameParts[1]->Substring(0, fileNameParts[1]->LastIndexOf("."));
        }
        return fileNameParts[0]->Substring(0, fileNameParts[0]->LastIndexOf("."));
    }

    // Get the last message from the conversation
    static String^ GetLastMessage(array<String^>^ lines, String^ currentUser, String^ otherUser)
    {
        String^ lastMessage = "";
        for (int i = lines->Length - 1; i >= 0; i--)
        {
            // Skip empty lines
            if (String::IsNullOrWhiteSpace(lines[i]))
                continue;

            // Find the last message sent by either user
            if (lines[i]->Contains(currentUser) || lines[i]->Contains(otherUser))
            {
                lastMessage = lines[i];
                break;
            }
        }
        return lastMessage;
    }
};