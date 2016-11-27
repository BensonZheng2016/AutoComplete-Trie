#pragma once
#include "Setting.h"

namespace AutoComplete {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UI
	/// </summary>
	public ref class UI : public System::Windows::Forms::Form
	{
	public:
		UI(void)
		{
			InitializeComponent();
			InitHook();
			InitializeBackgroundWorker();
			backgroundWorker1->WorkerSupportsCancellation = true;
			dic.ImportDic(DIC_NAME);
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	public:
	private: System::Windows::Forms::Button^  Start;
	public:
		delegate void SetTextDelegate(String^ text, Label^ label);

		void SetText(String^ text, Label^ label)
		{
			// InvokeRequired required compares the thread ID of the
			// calling thread to the thread ID of the creating thread.
			// If these threads are different, it returns true.
			if (label->InvokeRequired)
			{
				SetTextDelegate^ d =
					gcnew SetTextDelegate(this, &UI::SetText);
				this->Invoke(d, gcnew array<Object^> { text, label });
			}
			else
			{
				label->Text = text;
			}
		}
	private: System::Windows::Forms::Button^  ToTrayBar;

	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  showToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::NotifyIcon^  notifyIcon;

	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  authorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  programToolStripMenuItem;
	private: System::Windows::Forms::Button^  Stop;
	private: System::Windows::Forms::Label^  Auto1;
	private: System::Windows::Forms::Label^  Auto2;
	private: System::Windows::Forms::Label^  Auto3;

	private: System::Windows::Forms::Label^  Auto4;
	private: System::Windows::Forms::Label^  Auto5;
	private: System::Windows::Forms::Label^  Auto6;

	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UI::typeid));
			this->Start = (gcnew System::Windows::Forms::Button());
			this->ToTrayBar = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->showToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->authorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->programToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->notifyIcon = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->Stop = (gcnew System::Windows::Forms::Button());
			this->Auto1 = (gcnew System::Windows::Forms::Label());
			this->Auto2 = (gcnew System::Windows::Forms::Label());
			this->Auto3 = (gcnew System::Windows::Forms::Label());
			this->Auto4 = (gcnew System::Windows::Forms::Label());
			this->Auto5 = (gcnew System::Windows::Forms::Label());
			this->Auto6 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(395, 15);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(75, 23);
			this->Start->TabIndex = 0;
			this->Start->Text = L"Start";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &UI::Start_Click);
			// 
			// ToTrayBar
			// 
			this->ToTrayBar->Location = System::Drawing::Point(395, 73);
			this->ToTrayBar->Name = L"ToTrayBar";
			this->ToTrayBar->Size = System::Drawing::Size(75, 23);
			this->ToTrayBar->TabIndex = 3;
			this->ToTrayBar->Text = L"ToTray";
			this->ToTrayBar->UseVisualStyleBackColor = true;
			this->ToTrayBar->Click += gcnew System::EventHandler(this, &UI::ToTrayBar_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->showToolStripMenuItem,
					this->aboutToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(108, 70);
			// 
			// showToolStripMenuItem
			// 
			this->showToolStripMenuItem->Name = L"showToolStripMenuItem";
			this->showToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->showToolStripMenuItem->Text = L"Show";
			this->showToolStripMenuItem->Click += gcnew System::EventHandler(this, &UI::showToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->authorToolStripMenuItem,
					this->programToolStripMenuItem
			});
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// authorToolStripMenuItem
			// 
			this->authorToolStripMenuItem->Name = L"authorToolStripMenuItem";
			this->authorToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->authorToolStripMenuItem->Text = L"Author";
			// 
			// programToolStripMenuItem
			// 
			this->programToolStripMenuItem->Name = L"programToolStripMenuItem";
			this->programToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->programToolStripMenuItem->Text = L"Program";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &UI::exitToolStripMenuItem_Click);
			// 
			// notifyIcon
			// 
			this->notifyIcon->ContextMenuStrip = this->contextMenuStrip1;
			this->notifyIcon->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"notifyIcon.Icon")));
			this->notifyIcon->Text = L"AutoComplete";
			this->notifyIcon->Visible = true;
			this->notifyIcon->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &UI::notifyIcon_MouseDoubleClick);
			// 
			// Stop
			// 
			this->Stop->Location = System::Drawing::Point(395, 44);
			this->Stop->Name = L"Stop";
			this->Stop->Size = System::Drawing::Size(75, 23);
			this->Stop->TabIndex = 4;
			this->Stop->Text = L"Stop";
			this->Stop->UseVisualStyleBackColor = true;
			this->Stop->Click += gcnew System::EventHandler(this, &UI::Stop_Click);
			// 
			// Auto1
			// 
			this->Auto1->BackColor = System::Drawing::Color::White;
			this->Auto1->Location = System::Drawing::Point(12, 23);
			this->Auto1->Name = L"Auto1";
			this->Auto1->Size = System::Drawing::Size(262, 20);
			this->Auto1->TabIndex = 5;
			// 
			// Auto2
			// 
			this->Auto2->BackColor = System::Drawing::Color::White;
			this->Auto2->Location = System::Drawing::Point(12, 43);
			this->Auto2->Name = L"Auto2";
			this->Auto2->Size = System::Drawing::Size(262, 20);
			this->Auto2->TabIndex = 6;
			// 
			// Auto3
			// 
			this->Auto3->BackColor = System::Drawing::Color::White;
			this->Auto3->Location = System::Drawing::Point(12, 63);
			this->Auto3->Name = L"Auto3";
			this->Auto3->Size = System::Drawing::Size(262, 20);
			this->Auto3->TabIndex = 8;
			// 
			// Auto4
			// 
			this->Auto4->BackColor = System::Drawing::Color::White;
			this->Auto4->Location = System::Drawing::Point(12, 83);
			this->Auto4->Name = L"Auto4";
			this->Auto4->Size = System::Drawing::Size(262, 20);
			this->Auto4->TabIndex = 7;
			// 
			// Auto5
			// 
			this->Auto5->BackColor = System::Drawing::Color::White;
			this->Auto5->Location = System::Drawing::Point(12, 103);
			this->Auto5->Name = L"Auto5";
			this->Auto5->Size = System::Drawing::Size(262, 20);
			this->Auto5->TabIndex = 10;
			// 
			// Auto6
			// 
			this->Auto6->BackColor = System::Drawing::Color::White;
			this->Auto6->Location = System::Drawing::Point(12, 123);
			this->Auto6->Name = L"Auto6";
			this->Auto6->Size = System::Drawing::Size(262, 20);
			this->Auto6->TabIndex = 9;
			// 
			// UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(509, 190);
			this->Controls->Add(this->Auto5);
			this->Controls->Add(this->Auto6);
			this->Controls->Add(this->Auto3);
			this->Controls->Add(this->Auto4);
			this->Controls->Add(this->Auto2);
			this->Controls->Add(this->Auto1);
			this->Controls->Add(this->Stop);
			this->Controls->Add(this->ToTrayBar);
			this->Controls->Add(this->Start);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"UI";
			this->TopMost = true;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &UI::UI_KeyDown);
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);

		}

		void InitializeBackgroundWorker(){
			backgroundWorker1->DoWork += gcnew DoWorkEventHandler(this, &UI::backgroundWorker1_DoWork);
			backgroundWorker1->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler(this, &UI::backgroundWorker1_RunWorkerCompleted);
		}

		void InitHook(){ //Cai dat bat ki tu tu ban phim
			inputKeyboard.type = 1;
			inputKeyboard.ki.wScan = 0;
			inputKeyboard.ki.time = 0;
			inputKeyboard.ki.dwExtraInfo = 0;
		}
#pragma endregion

	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}
	private: System::Void ToTrayBar_Click(System::Object^  sender, System::EventArgs^  e) {
		this->ShowInTaskbar = false;
		this->WindowState = FormWindowState::Minimized;
		this->Hide();
	}
	private: System::Void showToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		this->WindowState = FormWindowState::Normal;
		this->ShowInTaskbar = true;
		this->Show();
	}
	private: System::Void UI_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if ((e->Alt) && (e->KeyCode == System::Windows::Forms::Keys::F)){
			if (this->WindowState == FormWindowState::Normal){
				this->WindowState = FormWindowState::Minimized;
				this->ShowInTaskbar = false;
				this->Hide();
			}
			else{
				this->WindowState = FormWindowState::Normal;
				this->ShowInTaskbar = true;
				this->Show();
			}
		}
		if ((e->Alt) && (e->KeyCode == System::Windows::Forms::Keys::T)){
			
		}
	}

	private: System::Void notifyIcon_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->WindowState = FormWindowState::Normal;
		this->ShowInTaskbar = true;
		this->Show();
	}
private: System::Void Start_Click(System::Object^ sender, System::EventArgs^  e) {
	this->Start->Enabled = false;
	this->Stop->Enabled = true;
	backgroundWorker1->RunWorkerAsync();
}
private: System::Void Stop_Click(System::Object^ sender, System::EventArgs^  e) {
	if (backgroundWorker1->IsBusy == true)
		this->backgroundWorker1->CancelAsync();
	Stop->Enabled = false;
	Start->Enabled = true;
}
private: void backgroundWorker1_DoWork(Object^ sender, DoWorkEventArgs^ e)
{
	//lay backgroundWorker
	BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
	String^ str;
	int i;
	array<Label^> ^myLabel = gcnew array<Label^>{ Auto1, Auto2, Auto3, Auto4, Auto5, Auto6 };
	//if (GetCursorPos(&pos)){//tuong lai
		//this->Location = Point(pos.x, pos.y);
	{
		input.push_back(' ');//
		posStack.push(NULL);//
		char ctmp = ' ';
		while (true)
		{
			for (ctmp = 8; ctmp <= 190; ctmp++)
			{
				if (worker->CancellationPending){
					e->Cancel = true;
					return;
				}
				if (GetAsyncKeyState(ctmp) != -32767)//if key have not pressed
					continue;
				else{
					if (checkDau(ctmp))
					{
						input.push_back(ctmp); XuatKey(ctmp);
						if ((word.size() != 0) && flag)
						{
							dic.Insert(word, 1, 1);//hoc tu moi
							//cout << "+" << word << endl;
							//system("pause");
						}
						posStack.push(posTrieNode);//
						posTrieNode = NULL;
						word.clear();
						flag = true;
					}

					else if (ctmp == VK_TAB)//choose word
					{
						XuatKey(VK_BACK);//delete tab
						if (collect.size() == 0)
						{
							posTrieNode = NULL;
							posStack.push(NULL);
							input.push_back(' '); XuatKey(VK_SPACE);
							if (flag)
							{
								dic.Insert(word, 1, 1);//hoc tu moi
							}
						}
						else
						{

							dic.Insert(collect.front(), 1, 1);//hoc tu co san

							for (int i = input.size() - 1; i >= 0; i--)
							{
								if (!checkDau(input[i]))
								{
									input.pop_back(); XuatKey(VK_BACK);
									posStack.pop();
								}
								else
									break;
							}
							posTrieNode = NULL;
							posStack.push(NULL);
							char tmp;
							for (int i = 0; i < collect.front().size(); i++)
							{
								tmp = collect.front().at(i);
								dic.FindWordCont(tmp, posTrieNode);
								posStack.push(posTrieNode);
								input.push_back(tmp); XuatChar(tmp);
							}
							input.push_back(' '); XuatKey(VK_SPACE);
							ctmp = ' ';
							posTrieNode = NULL;
						}
						word.clear();
						flag = true;
					}
					else if (ctmp == VK_BACK) //backspace
					{
						if (input.size() == 1)
							continue;
						flag = false;
						input.pop_back();
						ctmp = input.back();
						posStack.pop();
						posTrieNode = posStack.top();
						word.clear();
					}
					else if (ctmp == VK_CAPITAL)
					{
						XuatKey(VK_BACK);
						capslockState = !capslockState;
						continue;
					}
					else
					{
						if (ctmp >= 32 && ctmp <= 126){
							if (!capslockState && ((ctmp <= 'Z') && (ctmp >= 'A')))
								ctmp += 'a' - 'A';
							word.push_back(ctmp);
							input.push_back(ctmp);
							posStack.push(posTrieNode); 
						}
					}
					collect = dic.FindWordCont(ctmp, posTrieNode);
					for (i = 0; (i < collect.size() &&(i<6));i++){
						str = gcnew String(collect[i].c_str()); //chuyen tu string sang String
						SetText(str, myLabel[i]);
					}
					for (i; i < 6;i++){///truong hop rong
						str = gcnew String(" ");
						SetText(str, myLabel[i]);
					}
				}
			}
		}
	}
}
private: void backgroundWorker1_RunWorkerCompleted(Object^ /*sender*/, RunWorkerCompletedEventArgs^ e)
{
	if (e->Cancelled)
	{
	}
	else
	{
	}
	Start->Enabled = true;
	Stop->Enabled = false;
}
};
}

void XuatKey(WORD key)
{
	// Press key
	inputKeyboard.ki.wVk = key; // virtual-key code for  key
	inputKeyboard.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &inputKeyboard, sizeof(inputKeyboard));

	// Release key
	inputKeyboard.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &inputKeyboard, sizeof(inputKeyboard));
}
void XuatString(string key)
{
	for (int i = 0; i < key.size(); i++)
	{
		XuatKey(key[i]);
	}
}
void XuatChar(char tmp)
{
	keybd_event((unsigned char)VkKeyScan(tmp), 0, 0, 0);
	keybd_event((unsigned char)VkKeyScan(tmp), 0, KEYEVENTF_KEYUP, 0);
}
void xuat(string input)
{
	//for (string::iterator it = input.begin() + 1; it != input.end(); ++it)
	for (int it = 1; it < input.size(); it++)
	{
		if ((input[it]) != 13)
			std::cout << input[it];
		else
			std::cout << endl;
	}

}

bool garbageChar(int key)
{
	switch (key)
	{
	case VK_LBUTTON:case VK_CONTROL:case VK_SHIFT:
		return true;
	default:
		return false;
	}
}
//void keyboard(CTrie& dic)

//keyboard(dic);