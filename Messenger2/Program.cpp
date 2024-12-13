#include "LoginForm.h"
#include "Dashboard.h"
#include "RegisterForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Messenger2::LoginForm loginForm;

	User^ user = nullptr;
	while (1)
	{
		Messenger2::LoginForm loginForm;
		loginForm.ShowDialog();

		if (loginForm.switchToRegister)
		{
			Messenger2::RegisterForm registerForm;
			registerForm.ShowDialog();

			if (registerForm.switchToLogin)
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

	if (user != nullptr)
	{
		/*
		MessageBox::Show("Succesful authentification of " + user->username, "Program.cpp", MessageBoxButtons::OK);
		*/
		Messenger2::Dashboard dashboard(user);
		Application::Run(% dashboard);
	}
	else
	{
		MessageBox::Show("Authentification canceled", "Program.cpp", MessageBoxButtons::OK);
	}

}