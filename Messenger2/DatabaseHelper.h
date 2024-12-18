#pragma once
#include "User.h"
#using <System.dll>
using namespace System;
using namespace System::Data::SqlClient;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

public ref class DatabaseHelper
{
public:

    ///AUTHENTIFICATE USER  (Let user in)
    static User^ AuthenticateUser(String^ username, String^ password)
    {
        String^ connectionString = "Data Source=localhost\\sqlexpress;Initial Catalog=mymessenger;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";

        SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
        sqlConnection->Open();

        String^ sqlQuery = "SELECT * FROM Users WHERE username=@username AND password=@password;";
        SqlCommand^ command = gcnew SqlCommand(sqlQuery, sqlConnection);
        command->Parameters->AddWithValue("@username", username);
        command->Parameters->AddWithValue("@password", password);

        SqlDataReader^ reader = command->ExecuteReader();
        if (reader->Read()) {
            User^ user = gcnew User();
            user->Id = reader->GetInt32(0);
            user->username = reader->GetString(1);
            user->password = reader->GetString(2);

            sqlConnection->Close();
            return user;
        }

        sqlConnection->Close();
        return nullptr;
    }

    ///LOG IN USER
    static void SetUserActive(int userId)
    {
        String^ connectionString = "Data Source=localhost\\sqlexpress;Initial Catalog=mymessenger;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";

        SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
        sqlConnection->Open();


        SqlCommand^ command = gcnew SqlCommand(
            "UPDATE Users SET IsActive = 1 WHERE Id = @UserId",
            sqlConnection
        );
        command->Parameters->AddWithValue("@UserId", userId);

        command->ExecuteNonQuery();
        sqlConnection->Close();
    }

    ///LOGOUT USER
    static void SetUserInactive(int userId)
    {
        String^ connectionString = "Data Source=localhost\\sqlexpress;Initial Catalog=mymessenger;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";

        SqlConnection^ sqlConnection = gcnew SqlConnection(connectionString);
        sqlConnection->Open();


        SqlCommand^ command = gcnew SqlCommand(
            "UPDATE Users SET IsActive = 0 WHERE Id = @UserId",
            sqlConnection
        );
        command->Parameters->AddWithValue("@UserId", userId);

        command->ExecuteNonQuery();
        sqlConnection->Close();
    }

    ///REGISTER USER
    static void RegisterUser(String^ username, String^ password)
    {
        String^ connectionString = "Data Source=localhost\\sqlexpress;Initial Catalog=mymessenger;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
        SqlConnection sqlConnection(connectionString);
        sqlConnection.Open();

        String^ sqlQuery = "INSERT INTO Users " +
            "(username, password) VALUES" + "(@username,@password);";
        SqlCommand command(sqlQuery, % sqlConnection);

        command.Parameters->AddWithValue("@username", username);
        command.Parameters->AddWithValue("@password", password);

        command.ExecuteNonQuery();
    }

    ///GET USER ID BY USER USERNAME
    static int GetIdByUsername(String^ username)
    {
        String^ connectionString = "Data Source=localhost\\sqlexpress;Initial Catalog=mymessenger;Integrated Security=True;Encrypt=True;TrustServerCertificate=True";
        SqlConnection sqlConnection(connectionString);
        sqlConnection.Open();
        
        String^ sqlQuery = "SELECT Id FROM Users WHERE username=@username;";
        SqlCommand command(sqlQuery, % sqlConnection);

        command.Parameters->AddWithValue("@username", username);

        SqlDataReader^ reader = command.ExecuteReader();
        if (reader->Read())
        {
            return reader->GetInt32(0); //return the Id of the user
        }
        else
        {
            return -1; //return -1 if the user is not found (this shouldn't happen after registration)
        }
    }

    static List<String^>^ GetActiveUsers()
    {
        List<String^>^ activeUsers = gcnew List<String^>();

        try {
            String^ connectionString="Data Source = localhost\\sqlexpress; Initial Catalog = mymessenger; Integrated Security = True; Encrypt = True; TrustServerCertificate = True;";

            SqlConnection sqlConnection(connectionString);
            sqlConnection.Open();

            String^ sqlQuery = "SELECT username FROM Users WHERE isActive = 1";
            SqlCommand command(sqlQuery, %sqlConnection);

            SqlDataReader^ reader = command.ExecuteReader();

            while (reader->Read() /*cat timp mai citesc cate ceva*/)
            {
                String^ currentUser = reader->GetString(0);
                activeUsers->Add(currentUser);
            }

            reader->Close();
        }
        catch (Exception^ e)
        {
            MessageBox::Show("Error loading active users: " + e->Message);

        }

        return activeUsers;
    }

    static List<String^>^ GetAllUsers()
    {
        List<String^>^ allUsers = gcnew List<String^>();

        try {
            String^ connectionString = "Data Source = localhost\\sqlexpress; Initial Catalog = mymessenger; Integrated Security = True; Encrypt = True; TrustServerCertificate = True;";

            SqlConnection sqlConnection(connectionString);
            sqlConnection.Open();

            String^ sqlQuery = "SELECT username FROM Users;";
            
            SqlCommand command(sqlQuery, % sqlConnection);
            SqlDataReader^ reader = command.ExecuteReader();

            while (reader->Read())
            {
                String^ currUser = reader->GetString(0);
                allUsers->Add(currUser);
            }
            
            reader->Close();
        }
        catch (Exception^ e)
        {
            MessageBox::Show("Error loading all users: " + e->Message);
        }

        return allUsers;
    }

};