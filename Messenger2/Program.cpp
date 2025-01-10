#include "LoginForm.h"
#include "Dashboard.h"
#include "RegisterForm.h"
#include "Databasehelper.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	/*
	*	Acest main are rolul numai de a Porni cele 2 ferestre, Login si Register
	*	Restul Operatiilor dintre form-uri (Dashboard si Conversation) sunt realizate in interiorul
	*	codului fiecarui Form.
	*	Mai jos este logica de Login, cu tot cu Modificarea Statusului Utilizatorilor (active, inactive)
	*/

	User^ user = nullptr;
	while (1)
	{
		Messenger2::LoginForm loginForm;
		loginForm.ShowDialog();

		if (loginForm.switchToRegister)
		{
			Messenger2::RegisterForm registerForm;
			registerForm.ShowDialog();

			if (registerForm.switchToLogin == true)
			{
				continue;
			}
			else
			{
				user = registerForm.user;
				break;
			}
		}
		else
		{
			user = loginForm.user;
			break;
		}
	}

	//aici fie s-a reusit crearea unui cont, fie logarea cu unul deja existent
	if (user != nullptr)
	{
		
		//MessageBox::Show("Succesful authentification of " + user->username, "Program.cpp", MessageBoxButtons::OK)
		
		DatabaseHelper::SetUserActive(user->Id);

		Messenger2::Dashboard dashboard(user);
		Application::Run(% dashboard);

		DatabaseHelper::SetUserInactive(user->Id);

	}
	else
	{
		//in principiu, acest mesaj coincide cu apasarea butonului Cancel in LoginForm.
		MessageBox::Show("Authentification canceled", "MyMessenger", MessageBoxButtons::OK);
	}

}