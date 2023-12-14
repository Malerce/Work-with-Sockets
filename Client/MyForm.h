#pragma once
#include <windows.h>
#include <Windows.h>
#include <sstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <msclr/marshal_cppstd.h>
#include <algorithm>
#include <tlhelp32.h>
namespace WFtry2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;
	//using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Label^ label3;
	private:
		Dictionary<String^, IntPtr>^ handleDictionary;
	private:List<String^>^ arrID = gcnew List<String^>();
	private:List<IntPtr>^ arrHand = gcnew List<IntPtr>();
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Timer^ timer1;
	private:DWORD* priorityClasses = new DWORD[8];
		   
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
		   

	//private: vector<Process> arr = new vector<Process>();
	private: BindingList<String^>^ dataList = gcnew BindingList<String^>();
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::ComponentModel::IContainer^ components;

	
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(828, 69);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 77);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Створити процес";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(25, 41);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(555, 448);
			this->dataGridView1->TabIndex = 2;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Name";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Status";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Priority";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Width = 125;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Time";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Width = 125;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(651, 69);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(141, 20);
			this->checkBox1->TabIndex = 3;
			this->checkBox1->Text = L"Процес табуляції";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(651, 95);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(75, 20);
			this->checkBox2->TabIndex = 4;
			this->checkBox2->Text = L"Proteus";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(651, 121);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(141, 20);
			this->checkBox3->TabIndex = 5;
			this->checkBox3->Text = L"tracert google.com";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(651, 147);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(138, 20);
			this->checkBox4->TabIndex = 6;
			this->checkBox4->Text = L"Процес Фібоначі";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(807, 280);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(104, 49);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Встановити пріорітет";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(628, 347);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(104, 56);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Призупинити процес";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(755, 347);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(104, 56);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Відновити процес";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(882, 347);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(104, 56);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Завершити процес";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(628, 424);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 16);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Кількість ядер";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(628, 241);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 13;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(755, 424);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(104, 56);
			this->button7->TabIndex = 14;
			this->button7->Text = L"Встановити кількість ядер";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(625, 222);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 16);
			this->label2->TabIndex = 15;
			this->label2->Text = L"ID процесу";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(631, 458);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 16;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Control;
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(734, 244);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 16);
			this->label3->TabIndex = 17;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"ABOVE_NORMAL_PRIORITY_CLASS", L"BELOW_NORMAL_PRIORITY_CLASS",
					L"HIGH_PRIORITY_CLASS", L"IDLE_PRIORITY_CLASS", L"NORMAL_PRIORITY_CLASS",
					L"REALTIME_PRIORITY_CLASS"
			});
			this->comboBox1->Location = System::Drawing::Point(628, 280);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(173, 24);
			this->comboBox1->TabIndex = 18;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::OnTimerTick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1185, 578);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:void OnTimerTick(Object^ sender, EventArgs^ e){
		checkIfAllRun();
		refreshTable(); 
	}
	private: void refreshTable() {
		for (int i = 0; i < arrID->Count; i++) {
			::FILETIME F, M, C, D;
			GetProcessTimes(reinterpret_cast<HANDLE>(arrHand[i].ToInt64()), &F, &M, &C, &D);
			double timeP = FileTimeToTimestamp(C) + FileTimeToTimestamp(D);
			dataGridView1->Rows[FindRowIndexByData(arrID[i])]->Cells[4]->Value = timeP;
			dataGridView1->Refresh();
		}
	}
	private: void checkIfAllRun() {
		for (int i = 0; i < arrID->Count; i++) {
			if (CheckProcessStatus(reinterpret_cast<HANDLE>(arrHand[i].ToInt64())) != "R"){
				DeleteRow(FindRowIndexByData(arrID[i]));
				arrID->Remove(arrID[i]);
				arrHand->Remove(arrHand[i]);				
			}
			
		}
	}
	private: DWORD takeDword(String^ str) {
		if (str == "ABOVE_NORMAL_PRIORITY_CLASS") {
			return priorityClasses[0];
		}
		if (str == "BELOW_NORMAL_PRIORITY_CLASS") {
			return priorityClasses[1];
		}
		if (str == "HIGH_PRIORITY_CLASS") {
			return priorityClasses[2];
		}
		if (str == "IDLE_PRIORITY_CLASS") {
			return priorityClasses[3];
		}
		if (str == "NORMAL_PRIORITY_CLASS") {
			return priorityClasses[4];
		}
		if (str == "PROCESS_MODE_BACKGROUND_BEGIN") {
			return priorityClasses[5];
		}
		if (str == "PROCESS_MODE_BACKGROUND_END") {
			return priorityClasses[6];
		}
		if (str == "REALTIME_PRIORITY_CLASS") {
			return priorityClasses[7];
		}
		return priorityClasses[7];
	}
	private: HANDLE StringToHandle(String^ str) {
			IntPtr ptr = Marshal::StringToHGlobalUni(str);
			HANDLE handle = (HANDLE)ptr.ToPointer();
			Marshal::FreeHGlobal(ptr);
			return handle;
	}	
	private: double FileTimeToTimestamp(const ::FILETIME& fileTime) {
		ULARGE_INTEGER uli;
		uli.LowPart = fileTime.dwLowDateTime;
		uli.HighPart = fileTime.dwHighDateTime;
		return static_cast<long long>(uli.QuadPart)/10000000.0;
	}
	private: void setExe(int id) {
		HANDLE pSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		if (pSnap == INVALID_HANDLE_VALUE) {
			return ;
		}

		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);

		if (!Process32First(pSnap, &pe32)) {
			CloseHandle(pSnap);
			return ;
		}

		do {
			if (pe32.th32ProcessID == id) {
				break;
			}
			//_tprintf(_T("Process ID: %d, Parent Process ID: %d, Name: %s\n"), pe32.th32ProcessID, pe32.th32ParentProcessID, pe32.szExeFile);
		} while (Process32Next(pSnap, &pe32));
		std::cout << pe32.szExeFile;
		CloseHandle(pSnap);
		dataGridView1->Rows[FindRowIndexByData(L""+id)]->Cells[1]->Value = msclr::interop::marshal_as<String^>(pe32.szExeFile);
		dataGridView1->Refresh();
		return;
	}
	private:const char* CheckProcessStatus(HANDLE hProcess) {
		if (hProcess) {
			DWORD exitCode;
			if (GetExitCodeProcess(hProcess, &exitCode)) {
				if (exitCode == STILL_ACTIVE) {
					return "R";
				}
				else {
					return "S";
				}
			}
			else {
				return "E";
			}
		}
		else {
			return "E";
		}
	}	
	private:int FindRowIndexByData(String^ targetData) {
		for (int rowIndex = 0; rowIndex < dataGridView1->RowCount; rowIndex++) {
			String^ rowData = safe_cast<String^>(dataGridView1->Rows[rowIndex]->Cells[0]->Value);

			if (String::Equals(rowData, targetData, StringComparison::OrdinalIgnoreCase)) {
				return rowIndex; 
			}
		}

		return -1;
	}
	private: void UpdatePriority(int rowIndex, String^ priority) {
		if (rowIndex >= 0 && rowIndex < dataGridView1->RowCount) {
			dataGridView1->Rows[rowIndex]->Cells[3]->Value = priority;
			dataGridView1->Refresh();
		}
	}
	private: void UpdateStatus(int rowIndex, String^ status) {
		if (rowIndex >= 0 && rowIndex < dataGridView1->RowCount) {
			dataGridView1->Rows[rowIndex]->Cells[2]->Value = status;
			dataGridView1->Refresh();
		}
	}	
	private:bool SuspendProcess(DWORD processId) {
		HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

		THREADENTRY32 threadEntry;
		threadEntry.dwSize = sizeof(THREADENTRY32);

		Thread32First(hThreadSnapshot, &threadEntry);

		do
		{
			if (threadEntry.th32OwnerProcessID == processId)
			{
				HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE,
					threadEntry.th32ThreadID);
			
				SuspendThread(hThread);
				CloseHandle(hThread);
			}
		} while (Thread32Next(hThreadSnapshot, &threadEntry));
	
		CloseHandle(hThreadSnapshot);
		return true;
	}
	private:bool ResumeProcess(DWORD processId) {
	HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

	THREADENTRY32 threadEntry;
	threadEntry.dwSize = sizeof(THREADENTRY32);

	Thread32First(hThreadSnapshot, &threadEntry);

	do
	{
		if (threadEntry.th32OwnerProcessID == processId)
		{
			HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE,
				threadEntry.th32ThreadID);

			ResumeThread(hThread);
			CloseHandle(hThread);
		}
	} while (Thread32Next(hThreadSnapshot, &threadEntry));
	
	CloseHandle(hThreadSnapshot);
	return true;
}	
	private:void DeleteRow(int rowIndex) {
		if (rowIndex >= 0) {
			dataGridView1->Rows->RemoveAt(rowIndex);
			dataGridView1->Refresh();
		}
		else {
			MessageBox::Show("Invalid row index");
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		priorityClasses[0] = ABOVE_NORMAL_PRIORITY_CLASS;
		priorityClasses[1] = BELOW_NORMAL_PRIORITY_CLASS;
		priorityClasses[2] = HIGH_PRIORITY_CLASS;
		priorityClasses[3] = IDLE_PRIORITY_CLASS;
		priorityClasses[4] = NORMAL_PRIORITY_CLASS;
		priorityClasses[5] = PROCESS_MODE_BACKGROUND_BEGIN;
		priorityClasses[6] = PROCESS_MODE_BACKGROUND_END;
		priorityClasses[7] = REALTIME_PRIORITY_CLASS;
		if (checkBox1->Checked) {
			STARTUPINFO si;
			PROCESS_INFORMATION pi;
			ZeroMemory(&si, sizeof(STARTUPINFO));
			si.cb = sizeof(STARTUPINFO);
			char* s = "E:\\Visual Studio\\OS_lab3\\x64\\Debug\\OS_lab3.exe 0 3 0.01";
			if (!CreateProcess(NULL, s, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
			{
				std::cout << "The new process is not creared. " << std::endl
					<< "Check a name of the process. " << std::endl;

			}
			arrID->Add(L"" + pi.dwProcessId);
			arrHand->Add(static_cast<IntPtr>(pi.hProcess));
			DWORD dwordVar = GetPriorityClass(pi.hProcess);
			std::stringstream q;
			q << dwordVar;
			std::string str = q.str();
			array<String^>^ rowValues = { L"" + pi.dwProcessId,"",msclr::interop::marshal_as<String^>(CheckProcessStatus(pi.hProcess)), msclr::interop::marshal_as<String^>(str) ,"5" };

			dataGridView1->Rows->Add(rowValues);
			setExe(pi.dwProcessId);
		}
		if (checkBox2->Checked) {
			STARTUPINFO si;
			PROCESS_INFORMATION pi;
			ZeroMemory(&si, sizeof(STARTUPINFO));
			si.cb = sizeof(STARTUPINFO);
			char* s = "C:\\Program Files (x86)\\Labcenter Electronics\\Proteus 8 Professional\\BIN\\PDS.exe";
			if (!CreateProcess(NULL, s, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
			{
				std::cout << "The new process is not created. " << std::endl
					<< "Check a name of the process. " << std::endl;

			}
			arrID->Add(L"" + pi.dwProcessId);
			arrHand->Add(static_cast<IntPtr>(pi.hProcess));
			DWORD dwordVar = GetPriorityClass(pi.hProcess);
			std::stringstream q;
			q << dwordVar;
			std::string str = q.str();
			array<String^>^ rowValues = { L"" + pi.dwProcessId,"",msclr::interop::marshal_as<String^>(CheckProcessStatus(pi.hProcess)), msclr::interop::marshal_as<String^>(str) ,"5" };
			dataGridView1->Rows->Add(rowValues);
			setExe(pi.dwProcessId);
		}
		if (checkBox3->Checked) {
			STARTUPINFO si;
			PROCESS_INFORMATION pi;
			ZeroMemory(&si, sizeof(STARTUPINFO));
			si.cb = sizeof(STARTUPINFO);
			char* s = "tracert google.com";
			if (!CreateProcess(NULL, s, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
			{
				std::cout << "The new process is not created. " << std::endl
					<< "Check a name of the process. " << std::endl;

			}
			arrID->Add(L"" + pi.dwProcessId);
			arrHand->Add(static_cast<IntPtr>(pi.hProcess));
			DWORD dwordVar = GetPriorityClass(pi.hProcess);
			std::stringstream q;
			q << dwordVar;
			std::string str = q.str();
			array<String^>^ rowValues = { L"" + pi.dwProcessId,"",msclr::interop::marshal_as<String^>(CheckProcessStatus(pi.hProcess)), msclr::interop::marshal_as<String^>(str) ,"" };
			dataGridView1->Rows->Add(rowValues);
			setExe(pi.dwProcessId);
		}
		if (checkBox4->Checked) {
			STARTUPINFO si;
			PROCESS_INFORMATION pi;
			ZeroMemory(&si, sizeof(STARTUPINFO));
			si.cb = sizeof(STARTUPINFO);
			char* s = "E:\\Visual Studio\\Fibonachi\\x64\\Debug\\Fibonachi.exe 30";
			if (!CreateProcess(NULL, s, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
			{
				std::cout << "The new process is not created. " << std::endl
					<< "Check a name of the process. " << std::endl;

			}
			arrID->Add(L"" + pi.dwProcessId);
			arrHand->Add(static_cast<IntPtr>(pi.hProcess));
			DWORD dwordVar = GetPriorityClass(GetCurrentProcess());
			std::stringstream q;
			q << dwordVar;
			std::string str = q.str();
			array<String^>^ rowValues = { L"" + pi.dwProcessId,"",msclr::interop::marshal_as<String^>(CheckProcessStatus(pi.hProcess)), msclr::interop::marshal_as<String^>(str) ,"" };
			dataGridView1->Rows->Add(rowValues);
			setExe(pi.dwProcessId);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int id = Convert::ToInt32(textBox1->Text);
		bool check = false;
		int i = -1;
		for each (String ^ item in arrID) {
			i++;
			if (textBox1->Text == item) {
				check = true;
				break;
			}
		}
		if (check) {
			label3->Text = "";
			HANDLE h = reinterpret_cast<HANDLE>(arrHand[i].ToInt64());
			SetPriorityClass(h, takeDword(comboBox1->SelectedItem->ToString()));
			DWORD dwordValue = GetPriorityClass(h);
			int maxLength = snprintf(nullptr, 0, "%lu", dwordValue) + 1;
			char* charPr = new char[maxLength];
			snprintf(charPr, maxLength, "%lu", dwordValue);
			UpdatePriority(FindRowIndexByData(textBox1->Text), marshal_as<String^>(charPr));
		}
		else {
			label3->Text = "Помилка, такого ID не існує";
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		int id = Convert::ToInt32(textBox1->Text);
		bool check = false;
		int i = -1;
		for each (String ^ item in arrID) {
			i++;
			if (textBox1->Text == item) {
				check = true;
				break;
			}
		}
		if (check) {
			label3->Text = "";
			HANDLE h = reinterpret_cast<HANDLE>(arrHand[i].ToInt64());
			SuspendProcess(Convert::ToUInt32(textBox1->Text));
			UpdateStatus(FindRowIndexByData(arrID[i]), L"S");
		}
		else {
			label3->Text = "Помилка, такого ID не існує";
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		int id = Convert::ToInt32(textBox1->Text);
		bool check = false;
		int i = -1;
		for each (String ^ item in arrID) {
			i++;
			if (textBox1->Text == item) {
				check = true;
				break;
			}
		}
		if (check) {
			label3->Text = "";
			HANDLE h = reinterpret_cast<HANDLE>(arrHand[i].ToInt64());
			ResumeProcess(Convert::ToUInt32(textBox1->Text));
			UpdateStatus(FindRowIndexByData(arrID[i]), L"R");
		}
		else {
			label3->Text = "Помилка, такого ID не існує";
		}
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	int id = Convert::ToInt32(textBox1->Text);
	bool check = false;
	int i = -1;
	for each (String ^ item in arrID) {
		i++;
		if (textBox1->Text == item) {
			check = true;
			break;
		}
	}
	if (check) {
		label3->Text = "";
		HANDLE h = reinterpret_cast<HANDLE>(arrHand[i].ToInt64());
		TerminateProcess(h, 100);
		DeleteRow(FindRowIndexByData(textBox1->Text));
		arrID->Remove(arrID[i]);
		arrHand->Remove(arrHand[i]);
	}
	else {
		label3->Text = "Помилка, такого ID не існує";
	}
}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		int id = Convert::ToInt32(textBox1->Text);
		bool check = false;
		int i = -1;
		for each (String ^ item in arrID) {
			i++;
			if (textBox1->Text == item) {
				check = true;
				break;
			}
		}
		if (check) {
			HANDLE h = reinterpret_cast<HANDLE>(arrHand[i].ToInt64());
			String^ val = textBox2->Text->ToString();
			int result;
			Int32::TryParse(val, result);
			if (result > 6 || result < 1) {
				label3->Text = "Помилка, стільки ядер немає";
			}
			DWORD_PTR mask = 1 << result;
			if (SetProcessAffinityMask(h,  mask) != 0) {
			}
			else {
				std::cerr << "Помилка при зміні відповідності процесу для ядра." << std::endl;
			}
		}
		else {
			label3->Text = "Помилка, такого ID не існує";
		}

	}
};
}
