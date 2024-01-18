#include <iostream>
#include<string>
#include<vector>
#include <iomanip>

using namespace std;

class Message
{
protected:
	string add_up;

public:
	virtual string return_add_up() = 0;
	virtual void set_add_up(string new_msg)
	{
		add_up = new_msg;
	}
	virtual string print_add_up() = 0;
};
class text : public Message
{
public:
	//parameters counstructor
	text(string add_up_text)
	{
		add_up = add_up_text;
	}
	string return_add_up()
	{
		return add_up;
	}
	string print_add_up()
	{
		return "\"" + add_up + "\"";
	}
};
class voice : public Message
{
public:
	//parameters counstructor
	voice(string add_up_voice)
	{
		add_up = add_up_voice;
	}
	string return_add_up()
	{
		return add_up;
	}
	string print_add_up()
	{
		return add_up;
	}
};
class photo : public Message
{
public:
	//parameters counstructor
	photo(string add_up_photo)
	{
		add_up = add_up_photo;
	}
	string return_add_up()
	{
		return add_up;
	}
	string print_add_up()
	{
		return add_up;
	}
};
class sticker : public Message
{
public:
	//parameters counstructor
	sticker(string add_up_sticker)
	{
		add_up = add_up_sticker;
	}
	string return_add_up()
	{
		return add_up;
	}
	string print_add_up()
	{
		return add_up;
	}
};

class User
{
	string name;
	vector<Message*> usermessage;
public:
	User(string username)
	{
		name = username;
	}
	int find_msg(string msg)
	{
		for (int i = 0; i < usermessage.size(); i++)
		{
			if (usermessage[i]->return_add_up() == msg)
				return i;
		}
		return -1;
	}
	void add_message(Message* message)
	{
		usermessage.push_back(message);
	}
	void del_message(string message)
	{
		int to_del = find_msg(message);
		if (to_del < 0)
		{
			cout << "Message not found!" << endl;
			return;
		}
		usermessage.erase(usermessage.begin() + to_del);
	}
	void rep_message(string prev_msg, Message* new_msg)
	{
		int to_rep = find_msg(prev_msg);
		if (to_rep < 0)
		{
			cout << "Message not found!" << endl;
			return;
		}
		usermessage[to_rep]->set_add_up(new_msg->return_add_up() );
	}
};

class Manager
{
public:
	void add_user(User* user) { users.push_back(user); }

	void add_msg(Message* msg) { messages.push_back(msg); }
	void delete_message(string msg) {
		int i = find_user(msg);
		if (i < 0)
		{
			cout << "Message not found!" << endl;
			return;
		}
		users[i]->del_message(msg);
		int j = find_msg(msg);
		messages.erase(messages.begin() + j);
	}
	void replace_message(string prev_msg, Message* new_msg) {
		int i = find_user(prev_msg);
		int j = find_msg(prev_msg);
		if (i < 0)
		{
			cout << "Message not found!" << endl;
			return;
		}
		users[i]->rep_message(prev_msg, new_msg);
		if (j < 0)
		{
			cout << "Message not found!" << endl;
			return;
		}
		messages[j] = new_msg;
	}

	void print_all_msgs()
	{
		for (int i = 0; i < messages.size(); i++)
		{
			cout << "Message#" << setw(2) << setfill('0') << i << ": " << messages[i]->print_add_up() << endl;
		}
	}
private:
	vector<Message* > messages;
	vector<User*> users;
	int find_user(string msg)
	{
		for (int i = 0; i < users.size(); i++)
			if (users[i]->find_msg(msg) != -1)
				return i;
		return -1;
	}
	int find_msg(string msg)
	{
		for (int i = 0; i < messages.size(); i++)
			if (messages[i]->return_add_up() == msg)
				return i;
		return -1;
	}
};

int main()
{
	Manager messenger;
	User* Rojin = new User("Rojin");
	messenger.add_user(Rojin);
	text* txt = new text("Hello World");
	Rojin->add_message(txt);
	messenger.add_msg(txt);
	messenger.print_all_msgs();

	return 0;
}
