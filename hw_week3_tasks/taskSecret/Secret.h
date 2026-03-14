#pragma once
class Secret
{
	private:
		char* task;
		char* password;
		int loginFails;
public:
	Secret();
	Secret(const char* _task, const char* _password);
	Secret(const Secret& other);
	Secret& operator=(const Secret& other);
	~Secret();
	const char* getTask(const char* pwd);
	void setPassword(const char* newPassword, const char* oldPassword);
	void setTask(const char* newTask, const char* pwd);
	int getLoginFails() const;
};

