#pragma once
#include<vector>
#include<cstdlib>
#include<ctime>
namespace Lab62 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Column1 });
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(672, 281);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->MinimumWidth = 8;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 150;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(126, 472);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 62);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Знайти";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(339, 472);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 26);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(339, 523);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 26);
			this->textBox2->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(470, 472);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"size row";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(475, 526);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"size col";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(696, 653);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int rows = Convert::ToInt32(textBox1->Text);
		int cols = Convert::ToInt32(textBox2->Text);
		std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
		Random^ rand = gcnew Random();

		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();

		for (int j = 0; j < cols; j++) {
			dataGridView1->Columns->Add("Column" + j, "Column " + (j + 1));
		}

		int maxAbsElement = 0;
		int maxAbsRow = 0, maxAbsCol = 0;

		for (int i = 0; i < rows; i++)
		{
			dataGridView1->Rows->Add();
			for (int j = 0; j < cols; j++)
			{
				int num = rand->Next(-100, 101); 
				matrix[i][j] = num;
				dataGridView1->Rows[i]->Cells[j]->Value = num;

				if (Math::Abs(num) > Math::Abs(maxAbsElement)) {
					maxAbsElement = num;
					maxAbsRow = i;
					maxAbsCol = j;
				}
			}
		}

		String^ result = String::Format("Найбільший за модулем елемент: {0}\nЗнаходиться в комірці: [{1}, {2}]",
			maxAbsElement, maxAbsRow, maxAbsCol);
		MessageBox::Show(result, "Результат");
	
	}
	};
}
